/*************************************************************************************
//
//  LICENSE INFORMATION
//
//  BCreator(tm)
//  Software for the control of the 3D Printer, Creator"(tm)
//
//  Copyright 2011-2012 B9Creations, LLC
//  B9Creations(tm) and B9Creator(tm) are trademarks of B9Creations, LLC
//
//  This file is part of B9Creator
//
//    B9Creator is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    B9Creator is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with B9Creator .  If not, see <http://www.gnu.org/licenses/>.
//
//  The above copyright notice and this permission notice shall be
//    included in all copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
//    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
*************************************************************************************/

#include "layoutprojectdata.h"
#include "modeldata.h"
#include "modelinstance.h"
#include "supportstructure.h"
#include "OS_Wrapper_Functions.h"
#include "loadingbar.h"
#include <QDebug>
#include <QFile>


//////////////////////////////////
//Public
//////////////////////////////////

	//constructors/destructors
    B9LayoutProjectData::B9LayoutProjectData() : QObject()
	{
		New();
	}
    B9LayoutProjectData::~B9LayoutProjectData()
	{

	}

	//File Access:
    void B9LayoutProjectData::New()//Clears out internal project data, creates a new one with defualts
	{
        LoadDefaults();
        SetDirtied(false);
	}
    bool B9LayoutProjectData::Open(QString filepath, bool withoutVisuals) //returns success
    {
        int i;
        int FileVersion;
        bool jumpout = false;

        double resx;
        double resy;
        double xp, yp, zp;//instance positions/rotations/scales
        double xr, yr, zr;
        double xs, ys, zs;
        bool flipped = false;
        int numSupports;
        int hasFoundation;

        QFile file(filepath);
        QTextStream in;
        QString buff;//for io operations
        QString modelpath;//current model this function is trying to load.
        QString filename;


        //input file operations here
        if(!file.open(QIODevice::ReadOnly))
        {
            return false;
        }
        //check file extension
        if(QFileInfo(filepath).completeSuffix().toLower() != "nstl")
            return false;


        SetDirtied(false);//presumably good from here so undirty the project

        in.setDevice(&file);//begin text streaming.
        in >> buff;
        if(buff == "ver")//we are looking at a post 1.4 b9 layout file
        {
            in >> buff;
            FileVersion = buff.toInt();//should be 14 or greater.
            in.skipWhiteSpace();
            mfilename = in.readLine();//get project name
        }
        else//old file - we need to read first line for project name
        {
            FileVersion = 13;

            in.seek(0);//go back and re-read.
            mfilename = in.readLine();//get project name
        }

        qDebug() << "Layout Version: " << FileVersion;

        buff = in.readLine();//eat startinstancelist
        while(!jumpout)
        {
            in.skipWhiteSpace();
            buff = in.readLine();//eat endinstancelist or startmodel

            if(buff != "endinstancelist")
            {
                in >> filename;
                LoadingBar loadbar(0,100);
                loadbar.useCancelButton(false);
                loadbar.setDescription("Importing: "+ filename);//导入
                QObject::connect(this,SIGNAL(PercentCompletedUpdate(qint64,qint64)),
                                 &loadbar,SLOT(setProgress(qint64,qint64)));


                in >> xp >> yp >> zp;
                in >> xr >> yr >> zr;
                in >> xs >> ys >> zs;
                in.skipWhiteSpace();
                ModelData* pNewModel = new ModelData(pMain, withoutVisuals);
                pNewModel->filename = filename;
                pNewModel->filepath = filepath;
                Triangle3D newtri;
                int triCount;
                float nx,ny,nz;
                float x0,y0,z0;
                float x1,y1,z1;
                float x2,y2,z2;
                in >> buff;//"triCount"
//                in >> buff;//
                in >> buff;
                triCount = buff.toInt();
                int cnt = 0;
                for(i=0;i<triCount;i++){//read tri info
                    in >> nx >> ny >> nz;
                    in >> x0 >> y0 >> z0;
                    in >> x1 >> y1 >> z1;
                    in >> x2 >> y2 >> z2;
                    newtri.normal.setX(nx);
                    newtri.normal.setY(ny);
                    newtri.normal.setZ(nz);
                    newtri.vertex[0].setX(x0);
                    newtri.vertex[0].setY(y0);
                    newtri.vertex[0].setZ(z0);
                    newtri.vertex[1].setX(x1);
                    newtri.vertex[1].setY(y1);
                    newtri.vertex[1].setZ(z1);
                    newtri.vertex[2].setX(x2);
                    newtri.vertex[2].setY(y2);
                    newtri.vertex[2].setZ(z2);
                    //use right hand rule for importing normals - ignore file normals..
                    newtri.UpdateNormalFromGeom();
                    newtri.UpdateBounds();
                    pNewModel->triList.push_back(newtri);
                    cnt++;
                    emit PercentCompletedUpdate(i+1,triCount);
                    QApplication::processEvents();//界面及时响应
//                    in.skipWhiteSpace();
                }
                in.skipWhiteSpace();
                in >> buff;//eat "endmodel"
                pNewModel->CenterModel();
                int displaySuccess = pNewModel->FormNormalDisplayLists();
                if(!displaySuccess)
                    return false;
                pMain->ModelDataList.push_back(pNewModel);
                B9ModelInstance* pNewInst = pNewModel->AddInstance();
                if(pNewInst != NULL)
                {
                    pNewInst->SetPos(QVector3D(xp,yp,zp));
                    pNewInst->SetRot(QVector3D(xr,yr,zr));
                    pNewInst->SetScale(QVector3D(xs,ys,zs));
                    pNewInst->UpdateBounds();//in order that zhieght is good and all.
                }
//                //version 15 added instance supports
//                // add the supports to the loaded model
                if(FileVersion >= 15)
                {
                    in.skipWhiteSpace();
                    in >> buff;//eat "beginsupports"
                    in >> numSupports;
                    in >> hasFoundation;

                    if(hasFoundation)
                    StreamInSupportInfo(pNewInst,in,true);

                    for(i = 0; i < numSupports; i++)
                    {
                        StreamInSupportInfo(pNewInst,in,false);
                    }
                    in >> buff; in.skipWhiteSpace();//eat "endsupports"
                }
//                pMain->SelectOnly(pNewInst);
            }
            else
            {
                jumpout = true;
            }
        }

        in >> buff >> resx >> resy;
//        in >> buff >> xypixel;


//		SetResolution(QVector2D(resx,resy));//cyp
//        CalculateBuildArea();
        mfilename = filepath;


        //some post load warnings for legacy layouts
        if(FileVersion < 15)
        {
            //cyp
            QMessageBox msgBox;
            msgBox.setWindowTitle("Nepho3D_Studio");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setText("This Layout was created with an older version of Nepho3d_Studio");//
            msgBox.setInformativeText("Some models may be rotated differently");//
            msgBox.setToolTip("该文件版本较旧\n某些模型可能会有不同");
            msgBox.exec();
        }

        Disable_User_Waiting_Cursor();

        emit ProjectLoaded();
        return true;
    }


    bool B9LayoutProjectData::Save(QString filepath) //returns success
    {
        unsigned int i,j,t;
        B9ModelInstance* inst;
        B9SupportStructure* pSup;
        bool instHasFoundation;

        QFile file(filepath);

        if(!file.open(QIODevice::Truncate | QIODevice::WriteOnly))
        {
            return false;
        }

        QTextStream out(&file);//begin text streaming.
        out << "ver " << LAYOUT_FILE_VERSION << '\n';
        out << filepath << '\n';//write project name

        out << "startinstancelist" << '\n';//begin model list

        Triangle3D* pTri = NULL;
        int triCount;
        QString filename;
        for(i = 0; i < pMain->GetAllInstances().size(); i++)
        {
            out << "startmodel" << '\n';//begin model list
            inst = pMain->GetAllInstances()[i];
//            inst->BakeGeometry(false);//cyp
            filename = inst->pData->GetFileName();
            out << filename << '\n';
            out << inst->GetPos().x() <<" "<< inst->GetPos().y() <<" "<< inst->GetPos().z();
            out <<" "<< inst->GetRot().x() << " "<< inst->GetRot().y() <<" "<< inst->GetRot().z();
            out <<" "<< inst->GetScale().x() << " "<< inst->GetScale().y() <<" "<< inst->GetScale().z() << '\n';
            triCount = inst->pData->triList.size();//cyp
            out << "triCount" << " " << triCount << '\n';
            LoadingBar loadbar(0,100);
            loadbar.useCancelButton(false);
            loadbar.setDescription("Exporting: "+ filename);//导入
//            QObject::connect(this,SIGNAL(PercentCompletedUpdate(qint64,qint64)),
//                             &loadbar,SLOT(setProgress(qint64,qint64)));
            for(t = 0; t < triCount; t++)
            {
                pTri = &inst->pData->triList[t];//cyp
//                exporter.WriteNextTri(pTri);
                float nx = pTri->normal.x();
                float ny = pTri->normal.y();
                float nz = pTri->normal.z();

                float x0 = pTri->vertex[0].x();
                float y0 = pTri->vertex[0].y();
                float z0 = pTri->vertex[0].z();

                float x1 = pTri->vertex[1].x();
                float y1 = pTri->vertex[1].y();
                float z1 = pTri->vertex[1].z();

                float x2 = pTri->vertex[2].x();
                float y2 = pTri->vertex[2].y();
                float z2 = pTri->vertex[2].z();

                out << nx << " "<<ny<< " "<<nz<< " ";
                out << x0 << " "<<y0<< " "<<z0<< " ";
                out << x1 << " "<<y1<< " "<<z1<< " ";
                out << x2 << " "<<y2<< " "<<z2<< '\n';

                loadbar.setProgress(t+1,triCount);
            }
            inst->UnBakeGeometry();
            out << "endmodel" << '\n';

            instHasFoundation = (bool)inst->GetBasePlate();
            out << "beginsupports " << inst->GetSupports().size() << " " << instHasFoundation << '\n';

            //DEFINiTION: if there is a foundation support, its the first one.
            if(instHasFoundation)
                StreamOutSupportInfo(inst->GetBasePlate(),out);

            for(j = 0; j < inst->GetSupports().size(); j++)
            {
                pSup = inst->GetSupports()[j];
                StreamOutSupportInfo(pSup,out);
            }
            out << "endsupports" << '\n';
        }



        out << "endinstancelist" << '\n';//end model list

        out << "resolution " << GetResolution().x() << " " << GetResolution().y() << '\n';
        out << "XYpixelsize " << GetPixelSize() << '\n';


        SetDirtied(false);
        mfilename = filepath;
        return true;
    }

	//Structure Access:
	//Gets
    bool B9LayoutProjectData::IsDirtied()
	{
		return dirtied;
	}
    QString B9LayoutProjectData::GetFileName()//untitled if not saved yet
	{
        return mfilename;
	}
    QStringList B9LayoutProjectData::GetModelFileList()
	{
		return modelfilelist;
	}
    QVector3D B9LayoutProjectData::GetBuildSpace()
    {
		return dimentions;
	}
    double B9LayoutProjectData::GetPixelSize()
	{
		return  xypixel;
	}
    double B9LayoutProjectData::GetPixelThickness()
    {
        return  zthick;
    }
    QVector2D B9LayoutProjectData::GetResolution()
	{
		return resolution;
	}
    QString B9LayoutProjectData::GetJobName()
    {
        return jobExportName;
    }
    QString B9LayoutProjectData::GetJobDescription()
    {
        return jobExportDesc;
    }



	//Sets
    void B9LayoutProjectData::SetDirtied(bool dirt)
	{
        dirtied = dirt;
	}

	
    void B9LayoutProjectData::SetBuildSpaceSize(QVector3D size)
	{


        dimentions = size;

        QSettings appSettings;
        appSettings.beginGroup("USERLAYOUT");
            appSettings.setValue("DIMENTION_X",size.x());
            appSettings.setValue("DIMENTION_Y",size.y());
        appSettings.endGroup();


		SetDirtied(true);


	}
    void B9LayoutProjectData::SetPixelSize(double size)
	{
		xypixel = size;

        QSettings appSettings;
        appSettings.beginGroup("USERLAYOUT");
            appSettings.setValue("PIXEL_SIZE",size);
        appSettings.endGroup();


		SetDirtied(true);
	}
    void B9LayoutProjectData::SetPixelThickness(double thick)
    {
        zthick = thick;

        QSettings appSettings;
        appSettings.beginGroup("USERSET");
            appSettings.setValue("Thickness",thick);
        appSettings.endGroup();

        SetDirtied(true);
    }
    void B9LayoutProjectData::SetResolution(QVector2D dim)
	{
		resolution = dim;

        QSettings appSettings;
        appSettings.beginGroup("USERLAYOUT");
        appSettings.setValue("RESOLUTION_X",dim.x());
        appSettings.setValue("RESOLUTION_Y",dim.y());
        appSettings.endGroup();

		SetDirtied(true);
	}

    void B9LayoutProjectData::SetJobName(QString name)
    {
        jobExportName = name;
    }

    void B9LayoutProjectData::SetJobDescription(QString desc)
    {
        jobExportDesc = desc;
    }




    void B9LayoutProjectData::CalculateBuildArea()
	{
		SetBuildSpaceSize(QVector3D((xypixel/1000.0)*resolution.x(),(xypixel/1000.0)*resolution.y(),dimentions.z()));
	}
    void B9LayoutProjectData::UpdateZSpace()
	{
        unsigned int i;
		double max = 0.0;

        for(i=0;i<pMain->GetAllInstances().size();i++)
        {
            B9ModelInstance* inst = pMain->GetAllInstances()[i];
            if(inst->GetMaxBound().z() > max)
                max = inst->GetMaxBound().z();
        }


		SetBuildSpaceSize(QVector3D(dimentions.x(),dimentions.y(),max));
	}


//////////////////////////////////
//Private
//////////////////////////////////

    void B9LayoutProjectData::LoadDefaults()
    {
        QSettings appSettings;

        appSettings.beginGroup("USERLAYOUT");


        mfilename = "untitled";

        //cyp 修改默认值
        SetPixelSize(appSettings.value("PIXEL_SIZE",50).toDouble());
//        if(appSettings.value("PIXEL_SIZE").toInt())
//            SetPixelSize(appSettings.value("PIXEL_SIZE").toInt());
//        else
//            SetPixelSize(50);


        if(appSettings.value("RESOLUTION_X").toInt())
            SetResolution(QVector2D(appSettings.value("RESOLUTION_X").toInt(),appSettings.value("RESOLUTION_Y").toInt()));
        else
            SetResolution(QVector2D(1280,800));//cyp 1024,768

        CalculateBuildArea();

        if(appSettings.value("DIMENTION_X").toInt())
            SetBuildSpaceSize(QVector3D(appSettings.value("DIMENTION_X").toInt(),appSettings.value("DIMENTION_Y").toInt(),0));
        else
            SetBuildSpaceSize(QVector3D(dimentions.x(),dimentions.y(),0));//cyp 默认高度

        appSettings.endGroup();

//        SetPixelThickness(50);
        appSettings.beginGroup("USERSET");
            SetPixelThickness(appSettings.value("Thickness",50).toInt());
        appSettings.endGroup();

    }

    void B9LayoutProjectData::PromptFindLostModel(B9ModelInstance* &pinst, QString modelpath)
    {
        if(pinst != NULL)
            return;//dont need to find a found thing..

        SetDirtied(true);

        //chance popup dialog asking if the user wants to manually find the file.
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText("The model: " + QFileInfo(modelpath).baseName() + " can not be located.");//("找不到模型: " + QFileInfo(modelpath).baseName());
        msgBox.setInformativeText("Do you want to locate it manually?");//需要找到它吗？
        msgBox.setToolTip("找不到模型: " + QFileInfo(modelpath).baseName()+"\n需要寻找它吗？");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Discard);
        msgBox.setDefaultButton(QMessageBox::Yes);
//        msgBox.setButtonText(QMessageBox::Yes,QString("是"));
//        msgBox.setButtonText(QMessageBox::Discard,QString("否"));
        int response = msgBox.exec();
        if(response == QMessageBox::Yes)
        {
            QString correctedfilepath = QFileDialog::getOpenFileName(0, QString(/*"查找文件: "*/ "Locate File:"+ QFileInfo(modelpath).baseName()),
                                                                     "",QString(QFileInfo(modelpath).baseName()+"(*" + QFileInfo(modelpath).suffix() + ")"));
            if(!correctedfilepath.isEmpty())
            {
                pinst = pMain->AddModel(correctedfilepath);
            }
            if(pinst == NULL)//otherwise the user failed to find one
            {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Nepho3D_Studio");
                msgBox.setText("substitute file unable to be imported.");//
                msgBox.setToolTip("该文件无法导入");
                msgBox.exec();
            }
        }
    }




    void B9LayoutProjectData::StreamOutSupportInfo(B9SupportStructure* sup, QTextStream &out)
    {
        out << "\"" << sup->GetTopAttachShape() << "\" ";
        out << "\"" << sup->GetMidAttachShape() << "\" ";
        out << "\"" << sup->GetBottomAttachShape() << "\" ";
        out << QString::number(sup->GetTopPoint().x()) << " ";
        out << QString::number(sup->GetTopPoint().y()) << " ";
        out << QString::number(sup->GetTopPoint().z()) << " ";

        out << QString::number(sup->GetBottomPoint().x()) << " ";
        out << QString::number(sup->GetBottomPoint().y()) << " ";
        out << QString::number(sup->GetBottomPoint().z()) << " ";

        out << QString::number(sup->GetTopLength()) << " ";
        out << QString::number(sup->GetBottomLength()) << " ";

        out << QString::number(sup->GetTopNormal().x()) << " ";
        out << QString::number(sup->GetTopNormal().y()) << " ";
        out << QString::number(sup->GetTopNormal().z()) << " ";

        out << QString::number(sup->GetBottomNormal().x()) << " ";
        out << QString::number(sup->GetBottomNormal().y()) << " ";
        out << QString::number(sup->GetBottomNormal().z()) << " ";

        out << QString::number(sup->GetTopAngleFactor()) << " ";
        out << QString::number(sup->GetBottomAngleFactor()) << " ";
        out << QString::number(sup->GetTopPenetration()) << " ";
        out << QString::number(sup->GetBottomPenetration()) << " ";
        out << QString::number(sup->GetTopRadius()) << " ";
        out << QString::number(sup->GetMidRadius()) << " ";
        out << QString::number(sup->GetBottomRadius()) << " ";
        out << sup->GetIsGrounded() << '\n';
    }

    void B9LayoutProjectData::StreamInSupportInfo(B9ModelInstance* pinst, QTextStream &in, bool asFoundation)
    {
        B9SupportStructure* pSup;
        QString sup_top_shape, sup_mid_shape, sup_bot_shape;
        double sup_top_point_x, sup_top_point_y, sup_top_point_z;
        double sup_bot_point_x, sup_bot_point_y, sup_bot_point_z;
        double sup_top_normal_x, sup_top_normal_y, sup_top_normal_z;
        double sup_bot_normal_x, sup_bot_normal_y, sup_bot_normal_z;
        double sup_top_angF, sup_bot_angF;
        double sup_top_len, sup_bot_len;
        double sup_top_pen, sup_bot_pen;
        double sup_top_rad, sup_mid_rad, sup_bot_rad;
        int sup_grounded;


        sup_top_shape = StreamInTextQuotes(in);
        sup_top_shape.remove("\"");

        sup_mid_shape = StreamInTextQuotes(in);
        sup_mid_shape.remove("\"");

        sup_bot_shape = StreamInTextQuotes(in);
        sup_bot_shape.remove("\"");


        in >> sup_top_point_x >> sup_top_point_y >> sup_top_point_z;
        in >> sup_bot_point_x >> sup_bot_point_y >> sup_bot_point_z;
        in >> sup_top_len >> sup_bot_len;
        in >> sup_top_normal_x >> sup_top_normal_y >> sup_top_normal_z;
        in >> sup_bot_normal_x >> sup_bot_normal_y >> sup_bot_normal_z;
        in >> sup_top_angF >> sup_bot_angF;
        in >> sup_top_pen >> sup_bot_pen;
        in >> sup_top_rad >> sup_mid_rad >> sup_bot_rad;
        in >> sup_grounded;
        in.skipWhiteSpace();//go to next line


        //APPLY...
        if(pinst == NULL)
            return;

        //add the support to the instance
        if(asFoundation)
        {
            pinst->EnableBasePlate();
            pSup = pinst->GetBasePlate();
        }
        else{
            pSup = pinst->AddSupport(QVector3D(sup_top_point_x, sup_top_point_y, sup_top_point_z),
                   QVector3D(sup_bot_point_x, sup_bot_point_y, sup_bot_point_z));
        }

        pSup->SetTopNormal(QVector3D(sup_top_normal_x, sup_top_normal_y, sup_top_normal_z));
        pSup->SetBottomNormal(QVector3D(sup_bot_normal_x, sup_bot_normal_y, sup_bot_normal_z));
        pSup->SetTopAngleFactor(sup_top_angF);
        pSup->SetBottomAngleFactor(sup_bot_angF);
        pSup->SetTopLength(sup_top_len);
        pSup->SetBottomLength(sup_bot_len);
        pSup->SetTopPenetration(sup_top_pen);
        pSup->SetBottomPenetration(sup_bot_pen);
        pSup->SetTopRadius(sup_top_rad);
        pSup->SetMidRadius(sup_mid_rad);
        pSup->SetBottomRadius(sup_bot_rad);
        pSup->SetTopAttachShape(sup_top_shape);
        pSup->SetMidAttachShape(sup_mid_shape);
        pSup->SetBottomAttachShape(sup_bot_shape);
        pSup->SetIsGrounded(sup_grounded);
    }
