/*************************************************************************************
//
//  LICENSE INFORMATION
//
//  BCreator(tm)
//  Software for the control of the 3D Printer, "Creator"(tm)
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

#include "modeldata.h"
#include "modelloader.h"
#include "loadingbar.h"

#include <QtOpenGL>
#include <QFileInfo>




//////////////////////////////////////
//Public 
//////////////////////////////////////
ModelData::ModelData(MainWindow *main, bool bypassDisplayLists)
{
    pMain = main;
	filepath = "";
    loadedcount = 0;
    displaySkipping = 0;
    bypassDispLists = bypassDisplayLists;

	maxbound = QVector3D(-999999.0,-999999.0,-999999.0);
	minbound = QVector3D(999999.0,999999.0,999999.0);

    ZLayermm = 0.05;

//    unsigned int a = size_t;
//    triList.reserve(size_t );
//    triList.clear();
//    triList.reserve(2730672);
//    std::vector<Triangle3D>().swap(triList);

}

ModelData::~ModelData()
{
    unsigned int i;
//    triList.clear();


//    for(i=0; i < instList.size();i++)
//    {
//        delete instList[i];
//    }


//    for( i = 0; i < normDispLists.size(); i++)
//    {
//        glDeleteLists(normDispLists[i],1);
//    }

//    normDispLists.clear();

    for(i=0; i < instList.size();i++)
    {
        delete instList[i];
    }

    for( i = 0; i < normDispLists.size(); i++)
    {
        glDeleteLists(normDispLists.at(i),1);
    }
//    for( i = 0; i < normDispLists_up.size(); i++)
//    {
//        glDeleteLists(normDispLists_up[i],1);
//    }
    for( i = 0; i < normDispLists_side.size(); i++)
    {
        glDeleteLists(normDispLists_side.at(i),1);
    }

//    while(triList.size()>0){
//        triList.pop_back();
//    }
//    while(normDispLists.size()>0){
//        normDispLists.pop_back();
//    }
//    while(normDispLists_side.size()>0){
//        normDispLists_side.pop_back();
//    }
    triList.clear();

    normDispLists.clear();
    normDispLists_side.clear();

}

QString ModelData::GetFilePath()
{	
	return filepath;
}
QString ModelData::GetFileName()
{
	return filename;
}

//data loading
bool ModelData::LoadIn(QString filepath)
{
    bool loaderReady;
    bool abort;

    STLTri* pLoadedTri = NULL;
    Triangle3D newtri;

    this->filepath = filepath;

    if(filepath.isEmpty())
        return false;

    //extract filename from path!
    filename = QFileInfo(filepath).fileName();

    B9ModelLoader mLoader(filepath,loaderReady,NULL);

    if(loaderReady == false)//error opening model data
    {
        //display Loader Error
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");
        msgBox.setText(mLoader.GetError());
        msgBox.exec();
        return false;
    }

    //make a progress bar and connect it to
    LoadingBar loadbar(0,100);
    loadbar.useCancelButton(false);
    loadbar.setDescription("Importing: " + filename);//导入
    QObject::connect(&mLoader,SIGNAL(PercentCompletedUpdate(qint64,qint64)),
                     &loadbar,SLOT(setProgress(qint64,qint64)));



    //now we are ready to walk the loader through reading each triangle
    //and copying it into the this model data.
    while(mLoader.LoadNextTri(pLoadedTri,abort))
    {
        if(abort)
        {
            //display Loader abort error
            QMessageBox msgBox;
            msgBox.setWindowTitle("Nepho3D_Studio");
            msgBox.setText(mLoader.GetError());
            msgBox.exec();
            return false;
        }
        else
        {
            //newtri.normal.setX(pLoadedTri->nx);
            //newtri.normal.setY(pLoadedTri->ny);
            //newtri.normal.setZ(pLoadedTri->nz);

            newtri.vertex[0].setX(pLoadedTri->x0);
            newtri.vertex[0].setY(pLoadedTri->y0);
            newtri.vertex[0].setZ(pLoadedTri->z0);
            newtri.vertex[1].setX(pLoadedTri->x1);
            newtri.vertex[1].setY(pLoadedTri->y1);
            newtri.vertex[1].setZ(pLoadedTri->z1);
            newtri.vertex[2].setX(pLoadedTri->x2);
            newtri.vertex[2].setY(pLoadedTri->y2);
            newtri.vertex[2].setZ(pLoadedTri->z2);

            //use right hand rule for importing normals - ignore file normals..
            newtri.UpdateNormalFromGeom();

            delete pLoadedTri;
            newtri.UpdateBounds();

            triList.push_back(newtri);
        }
    }



    qDebug() << "Loaded triangles: " << triList.size();
    //now center it!
    CenterModel();

    //generate a normal display lists.

    int displaySuccess = FormNormalDisplayLists();

    if(displaySuccess)
        return true;
    else
        return false;
}

//instance
B9ModelInstance* ModelData::AddInstance()
{
	loadedcount++;
	B9ModelInstance* pNewInst = new B9ModelInstance(this);
	instList.push_back(pNewInst);
	pNewInst->SetTag(filename + " " + QString().number(loadedcount));
	return pNewInst;
}


//////////////////////////////////////
//Private
//////////////////////////////////////
void ModelData::CenterModel()
{
	//figure out what to current center of the models counds is..
    unsigned int f;
    unsigned int v;
	QVector3D center;


	for(f=0;f<triList.size();f++)
	{
		for(v=0;v<3;v++)
		{
			//update the models bounds.
			//max
            if(triList[f].maxBound.x() > maxbound.x())
			{
                maxbound.setX(triList[f].vertex[v].x());
			}
            if(triList[f].maxBound.y() > maxbound.y())
			{
                maxbound.setY(triList[f].vertex[v].y());
			}
            if(triList[f].maxBound.z() > maxbound.z())
			{
                maxbound.setZ(triList[f].vertex[v].z());
			}
			
			//mins
            if(triList[f].minBound.x() < minbound.x())
			{
                minbound.setX(triList[f].vertex[v].x());
			}
            if(triList[f].minBound.y() < minbound.y())
            {
                minbound.setY(triList[f].vertex[v].y());
			}
            if(triList[f].minBound.z() < minbound.z())
			{
                minbound.setZ(triList[f].vertex[v].z());
			}
		}
	}

	center = (maxbound + minbound)*0.5;

    for(f=0;f<triList.size();f++)
	{
		for(v=0;v<3;v++)
		{
            triList[f].vertex[v] -= center;
		}
        triList[f].UpdateBounds(); // since we are moving every triangle, we need to update their bounds too.
	}
	maxbound -= center;
	minbound -= center;
}

bool intersectionLinePlane(float P[],float P1[],float P2[],float zHeight)
{//求线段P1P2和面z=zHeight的交点P
    if((P2[2]-zHeight)*(P2[2]-zHeight)>=0) return false;//线段与平面无交点
    float P1P2[3]={P2[0]-P1[0],P2[1]-P1[1],P2[2]-P1[2]};
    int i=0;
    float num,den,n;
    num = P1[2] + zHeight;
    den = P1P2[2];
    if(fabs(den)<1e-5)
    {
        //parallel
        return false;
    }
    n=num/den;
    for(i=0;i<3;i++)
        P[i]=P1[i]+n*P1P2[i];

    return true;
}

//rendering
//generate opengl display list, flipx generates with inverted x normals and vertices
bool ModelData::FormNormalDisplayLists() //returns opengl error enunum.
{
    int i;
    unsigned int l;
    unsigned int t;
    const unsigned int listSize = 10000;//each list to be 10000 triangles big.
    unsigned int tSeamCount = 0;

    //first lets free up existing display lists if there are any
    for( l = 0; l < normDispLists.size(); l++)
    {
        glDeleteLists(normDispLists[l],1);
    }

    if(bypassDispLists)
        return true;

    normDispLists.push_back(glGenLists(1));
    if(normDispLists.at(normDispLists.size()-1) == 0)
        return false;//failure to allocate a list index???

    glNewList(normDispLists.at(normDispLists.size()-1),GL_COMPILE);
    glBegin(GL_TRIANGLES);// Drawing Using Triangles
    for(t = 0; t < triList.size(); t = t + 1 + displaySkipping)//for each triangle
    {
        glNormal3f(triList[t].normal.x(),triList[t].normal.y(),triList[t].normal.z());//normals

//        if(triList[t].minBound.z()>0){
//            continue;
//        }
//        else if(triList[t].maxBound.z()>0){
//            for(i = 0;i<3;i++){
//                if(triList[t].vertex[i].z()>0)
//                    glVertex3f( triList[t].vertex[i].x(), triList[t].vertex[i].y(), 0);
//                else
//                    glVertex3f( triList[t].vertex[i].x(), triList[t].vertex[i].y(), triList[t].vertex[i].z());
//            }
//        }
//        else{
            glVertex3f( triList[t].vertex[0].x(), triList[t].vertex[0].y(), triList[t].vertex[0].z());
            glVertex3f( triList[t].vertex[1].x(), triList[t].vertex[1].y(), triList[t].vertex[1].z());
            glVertex3f( triList[t].vertex[2].x(), triList[t].vertex[2].y(), triList[t].vertex[2].z());
//        }

        //make a new seam.
        if(tSeamCount >= listSize)
        {
            glEnd();
            glEndList();
            normDispLists.push_back(glGenLists(1));
            if(normDispLists.at(normDispLists.size()-1) == 0)
                return false;//failure to allocate a list index???

            //when creating a seam check for graphics error
            int err = GetGLError();
            if(err)
            {
                if(err == GL_OUT_OF_MEMORY)
                {
                    displaySkipping += 10;
                    return FormNormalDisplayLists();
                }
                else
                    return false;
            }

            glNewList(normDispLists.at(normDispLists.size()-1),GL_COMPILE);
            glBegin(GL_TRIANGLES);// Drawing Using Triangles
            tSeamCount = 0;
        }

        tSeamCount++;
    }
    for(t = 0; t < 0/*triList.size()*/; t = t + 1 + displaySkipping)//for each triangle
    {
        glNormal3f(-triList[t].normal.x(),-triList[t].normal.y(),-triList[t].normal.z());//normals

        if(triList[t].minBound.z()>0){
            continue;
        }
        else if(triList[t].maxBound.z()>0){
            for(i = 2;i>=0;i--){
                if(triList[t].vertex[i].z()>0)
                    glVertex3f( triList[t].vertex[i].x(), triList[t].vertex[i].y(), 0);
                else
                    glVertex3f( triList[t].vertex[i].x(), triList[t].vertex[i].y(), triList[t].vertex[i].z());
            }
        }
        else{
            glVertex3f( triList[t].vertex[2].x(), triList[t].vertex[2].y(), triList[t].vertex[2].z());
            glVertex3f( triList[t].vertex[1].x(), triList[t].vertex[1].y(), triList[t].vertex[1].z());
            glVertex3f( triList[t].vertex[0].x(), triList[t].vertex[0].y(), triList[t].vertex[0].z());
        }

        //make a new seam.
        if(tSeamCount >= listSize)
        {
            glEnd();
            glEndList();
            normDispLists.push_back(glGenLists(1));
            if(normDispLists.at(normDispLists.size()-1) == 0)
                return false;//failure to allocate a list index???

            //when creating a seam check for graphics error
            int err = GetGLError();
            if(err)
            {
                if(err == GL_OUT_OF_MEMORY)
                {
                    displaySkipping += 10;
                    return FormNormalDisplayLists();
                }
                else
                    return false;
            }

            glNewList(normDispLists.at(normDispLists.size()-1),GL_COMPILE);
            glBegin(GL_TRIANGLES);// Drawing Using Triangles
            tSeamCount = 0;
        }

        tSeamCount++;
    }

    glEnd();
    glEndList();

    int err = GetGLError();
    if(err)
    {
        if(err == GL_OUT_OF_MEMORY)
        {
            displaySkipping += 10;
            return FormNormalDisplayLists();
        }
        else
            return false;
    }



    qDebug() << normDispLists.size() << "Normal Display Lists created for model " << filename;


    return true;
}


bool ModelData::FormSliceDisplayLists(std::map<int,std::vector<QVector2D > >& mapLine,
                                      std::map<int,std::vector<std::vector<QVector2D> > >& mapSlice) //returns opengl error enunum.
{
    int numSlice = mapSlice.size();
    int cnt = 0;
    unsigned int l;
    unsigned int i,j,k;
    const unsigned int listSize = 10000;//each list to be 10000 triangles big.
    unsigned int tSeamCount = 0;
    QVector3D v0,v1,v2,v00,v11,v22,normal,v3;
    std::vector<std::vector<QVector2D> > vecLoop;
    std::vector<QVector2D > vecLine;
    std::vector<QVector2D> vecTriangels;
//    double zPos = 0;//mapSlice.size()*ZLayermm/2;

    //first lets free up existing display lists if there are any
    for( l = 0; l < normDispLists.size(); l++)
    {
        glDeleteLists(normDispLists[l],1);
    }
    for( l = 0; l < normDispLists_up.size(); l++)
    {
        glDeleteLists(normDispLists_up[l],1);
    }
    for( l = 0; l < normDispLists_side.size(); l++)
    {
        glDeleteLists(normDispLists_side[l],1);
    }

//    normDispLists.clear();
//    normDispLists_side01.clear();
//    normDispLists_up.clear();

    normDispLists.push_back(glGenLists(1));
    if(normDispLists.at(normDispLists.size()-1) == 0)
        return false;//failure to allocate a list index???
    glNewList(normDispLists.at(normDispLists.size()-1),GL_COMPILE);
    glNormal3f(0,0,-1);
    glBegin(GL_TRIANGLES);// Drawing Using Triangles
    for(i=0;i<numSlice;i++){
        tSeamCount=0;
        vecLoop = mapSlice[i];
        for(j=0;j<vecLoop.size();j++){
            vecTriangels = vecLoop[j];
            for(k=0;k<vecTriangels.size();){
                v0=QVector3D(vecTriangels[k].x(),vecTriangels[k].y(),i*ZLayermm);//+zPos);//
                v1=QVector3D(vecTriangels[k+1].x(),vecTriangels[k+1].y(),i*ZLayermm);//+zPos);
                v2=QVector3D(vecTriangels[k+2].x(),vecTriangels[k+2].y(),i*ZLayermm);//+zPos);
                v00=QVector3D(vecTriangels[k].x(),vecTriangels[k].y(),(i+1)*ZLayermm);//+zPos);
                v11=QVector3D(vecTriangels[k+1].x(),vecTriangels[k+1].y(),(i+1)*ZLayermm);//+zPos);
                v22=QVector3D(vecTriangels[k+2].x(),vecTriangels[k+2].y(),(i+1)*ZLayermm);//+zPos);
                k+=3;

                //down
//                glNormal3f(0,0,-1);
                glVertex3f( v2.x(), v2.y(), v2.z());
                glVertex3f( v1.x(), v1.y(), v1.z());
                glVertex3f( v0.x(), v0.y(), v0.z());
                glVertex3f( v0.x(), v0.y(), v0.z());
                glVertex3f( v1.x(), v1.y(), v1.z());
                glVertex3f( v2.x(), v2.y(), v2.z());

                cnt++;

                tSeamCount+=2;
                if(/*tSeamCount >= listSize*/0)
                {
//                    break;
                    glEnd();
                    glEndList();
                    normDispLists.push_back(glGenLists(1));
                    if(normDispLists.at(normDispLists.size()-1) == 0)
                        return false;//failure to allocate a list index???

                    //when creating a seam check for graphics error
                    int err = GetGLError();
                    if(err)
                    {
                        if(err == GL_OUT_OF_MEMORY)
                        {
                            displaySkipping += 10;
                            return FormSliceDisplayLists(mapLine,mapSlice);
                        }
                        else
                            return false;
                    }

                    glNewList(normDispLists.at(normDispLists.size()-1),GL_COMPILE);
                    glBegin(GL_TRIANGLES);// Drawing Using Triangles
                    tSeamCount = 0;
                }

            }
        }

        glEnd();
        glEndList();
//        vecIndex_down.push_back(normDispLists.size());
//        if(i == numSlice-1) break;
        normDispLists.push_back(glGenLists(1));
        if(normDispLists.at(normDispLists.size()-1) == 0)
            return false;//failure to allocate a list index???
        glNewList(normDispLists.at(normDispLists.size()-1),GL_COMPILE);
        glNormal3f(0,0,-1);
        glBegin(GL_TRIANGLES);// Drawing Using Triangles
        tSeamCount=0;
    }
    glEnd();
    glEndList();

//    return true;
    normDispLists_up.push_back(glGenLists(1));
    glNewList(normDispLists_up.at(normDispLists_up.size()-1),GL_COMPILE);
    glNormal3f(0,0,1);
    glBegin(GL_TRIANGLES);// Drawing Using Triangles
    for(i=0;i<numSlice;i++){
        tSeamCount=0;
        vecLoop = mapSlice[i];
        for(j=0;j<vecLoop.size();j++){
            vecTriangels = vecLoop[j];
            for(k=0;k<vecTriangels.size();){
                v00=QVector3D(vecTriangels[k].x(),vecTriangels[k].y(),(i+1)*ZLayermm);//+zPos);
                v11=QVector3D(vecTriangels[k+1].x(),vecTriangels[k+1].y(),(i+1)*ZLayermm);//+zPos);
                v22=QVector3D(vecTriangels[k+2].x(),vecTriangels[k+2].y(),(i+1)*ZLayermm);//+zPos);
                k+=3;

                //up
//                glNormal3f(0,0,1);
                glVertex3f( v00.x(), v00.y(), v00.z());
                glVertex3f( v11.x(), v11.y(), v11.z());
                glVertex3f( v22.x(), v22.y(), v22.z());
                glVertex3f( v22.x(), v22.y(), v22.z());
                glVertex3f( v11.x(), v11.y(), v11.z());
                glVertex3f( v00.x(), v00.y(), v00.z());

                tSeamCount+=2;
                if(/*tSeamCount >= listSize*/0)
                {
//                    break;
                    glEnd();
                    glEndList();
                    normDispLists_up.push_back(glGenLists(1));
                    if(normDispLists_up.at(normDispLists_up.size()-1) == 0)
                        return false;//failure to allocate a list index???

                    //when creating a seam check for graphics error
                    int err = GetGLError();
                    if(err)
                    {
                        if(err == GL_OUT_OF_MEMORY)
                        {
                            displaySkipping += 10;
                            return FormSliceDisplayLists(mapLine,mapSlice);
                        }
                        else
                            return false;
                    }

                    glNewList(normDispLists_up.at(normDispLists_up.size()-1),GL_COMPILE);
                    glBegin(GL_TRIANGLES);// Drawing Using Triangles
                    tSeamCount = 0;
                }

            }
        }

        glEnd();
        glEndList();
//        vecIndex_up.push_back(normDispLists_up.size());
//        if(i == numSlice-1) break;
        normDispLists_up.push_back(glGenLists(1));
        if(normDispLists_up.at(normDispLists_up.size()-1) == 0)
            return false;//failure to allocate a list index???
        glNewList(normDispLists_up.at(normDispLists_up.size()-1),GL_COMPILE);
        glNormal3f(0,0,1);
        glBegin(GL_TRIANGLES);// Drawing Using Triangles
    }
    glEnd();
    glEndList();


//    _Line line; GL_POLYGON
    normDispLists_side.push_back(glGenLists(1));
    glNewList(normDispLists_side.at(normDispLists_side.size()-1),GL_COMPILE);
    glBegin(GL_QUADS);//GL_QUADS Drawing Using Triangles
    tSeamCount=0;
    for(i=0;i<numSlice;i++){
//        vecLoop = mapSlice[i];
        vecLine = mapLine[i];
//        if(vecLine.size()>10000)
//            k=0;
        cnt =0;
        for(k=0;k<vecLine.size();){
//            line = vecLine[j];
//            if(!line.isSingle) continue;
            v0=QVector3D(vecLine[k].x(),vecLine[k].y(),i*ZLayermm);
            v1=QVector3D(vecLine[k+1].x(),vecLine[k+1].y(),i*ZLayermm);
            v2=QVector3D(vecLine[k+1].x(),vecLine[k+1].y(),(i+1)*ZLayermm);
            v3=QVector3D(vecLine[k].x(),vecLine[k].y(),(i+1)*ZLayermm);
            k+=2;

            normal = QVector3D::crossProduct(v0 - v1, v2 - v1);
            glNormal3f(normal.x(),normal.y(),normal.z());
                glVertex3f( v1.x(), v1.y(), v1.z());
                glVertex3f( v0.x(), v0.y(), v0.z());
                glVertex3f( v3.x(), v3.y(), v3.z());
//                glVertex3f( v1.x(), v1.y(), v1.z());
//                glVertex3f( v3.x(), v3.y(), v3.z());
                glVertex3f( v2.x(), v2.y(), v2.z());


                if(0/*tSeamCount >= listSize*/)
                {
//                    break;
                    glEnd();
                    glEndList();
                    normDispLists_side.push_back(glGenLists(1));
                    if(normDispLists_side.at(normDispLists_side.size()-1) == 0)
                        return false;//failure to allocate a list index???

                    //when creating a seam check for graphics error
                    int err = GetGLError();
                    if(err)
                    {
                        if(err == GL_OUT_OF_MEMORY)
                        {
                            displaySkipping += 10;
                            return FormSliceDisplayLists(mapLine,mapSlice);
                        }
                        else
                            return false;
                    }

                    glNewList(normDispLists_side.at(normDispLists_side.size()-1),GL_COMPILE);
                    glBegin(GL_QUADS);// Drawing Using Triangles
                    tSeamCount = 0;
                }

                tSeamCount++;
//                cnt++;

//                if(cnt>=1000)
//                    break;
        }

        glEnd();
        glEndList();
//        vecIndex_side.push_back(normDispLists_side01.size());
//        if(i==500)
//            break;
//        if(i == numSlice-1)
//            break;
        normDispLists_side.push_back(glGenLists(1));
        if(normDispLists_side.at(normDispLists_side.size()-1) == 0)
            return false;//failure to allocate a list index???
        glNewList(normDispLists_side.at(normDispLists_side.size()-1),GL_COMPILE);
        glBegin(GL_QUADS);//GL_QUADS Drawing Using Triangles
        tSeamCount=0;

    }
    glEnd();
    glEndList();

    int err = GetGLError();
    if(err)
    {
        if(err == GL_OUT_OF_MEMORY)
        {
            displaySkipping += 10;
            return FormSliceDisplayLists(mapLine,mapSlice);
        }
        else
            return false;
    }

    qDebug() << normDispLists.size() << "Normal Display Lists created for model " << filename;

    triList.clear();
    return true;
}

bool ModelData::FormSliceDisplayLists2(std::map<int,std::vector<std::vector<QVector2D> > >& mapSlice) //returns opengl error enunum.
{
    int cnt = 0;
    int numSlice = mapSlice.size();
    unsigned int l;
    unsigned int t;
    unsigned int i,j,k;
    const unsigned int listSize = 10000;//each list to be 10000 triangles big.
    unsigned int tSeamCount = 0;
    QVector3D v0,v1,v2,v00,v11,v22,normal,v3;
    std::vector<std::vector<QVector2D> > vecLoop;
    std::vector<QVector2D > vecLine;
    std::vector<QVector2D> vecTriangels;

    //first lets free up existing display lists if there are any
    for( l = 0; l < normDispLists.size(); l++)
    {
        glDeleteLists(normDispLists[l],1);
    }

    if(bypassDispLists)
        return true;

    normDispLists.push_back(glGenLists(1));
    if(normDispLists.at(normDispLists.size()-1) == 0)
        return false;//failure to allocate a list index???

    glNewList(normDispLists.at(normDispLists.size()-1),GL_COMPILE);
//    glNormal3f(0,0,-1);
    glBegin(GL_TRIANGLES);// Drawing Using Triangles
    for(i=0;i<numSlice;i++){//
        tSeamCount=0;
        vecLoop = mapSlice[i];
        for(j=0;j<vecLoop.size();j++){
            vecTriangels = vecLoop[j];
            for(k=0;k<vecTriangels.size();){
                v0=QVector3D(vecTriangels[k].x(),vecTriangels[k].y(),i*ZLayermm);//+zPos);//
                v1=QVector3D(vecTriangels[k+1].x(),vecTriangels[k+1].y(),i*ZLayermm);//+zPos);
                v2=QVector3D(vecTriangels[k+2].x(),vecTriangels[k+2].y(),i*ZLayermm);//+zPos);

                k+=3;

                //down
                glNormal3f(0,0,-1);
                glVertex3f( v2.x(), v2.y(), v2.z());
                glVertex3f( v1.x(), v1.y(), v1.z());
                glVertex3f( v0.x(), v0.y(), v0.z());
                glVertex3f( v0.x(), v0.y(), v0.z());
                glVertex3f( v1.x(), v1.y(), v1.z());
                glVertex3f( v2.x(), v2.y(), v2.z());

                cnt++;

                tSeamCount+=2;
                if(tSeamCount >= listSize)
                {
//                    break;
                    glEnd();
                    glEndList();
                    normDispLists.push_back(glGenLists(1));
                    if(normDispLists.at(normDispLists.size()-1) == 0)
                        return false;//failure to allocate a list index???

                    //when creating a seam check for graphics error
                    int err = GetGLError();
                    if(err)
                    {
//                        if(err == GL_OUT_OF_MEMORY)
//                        {
//                            displaySkipping += 10;
//                            return FormSliceDisplayLists2(mapSlice);
//                        }
//                        else
                            return false;
                    }

//                    if(normDispLists.size() == 130)
//                        return true;
                    glNewList(normDispLists.at(normDispLists.size()-1),GL_COMPILE);
                    glBegin(GL_TRIANGLES);// Drawing Using Triangles
                    tSeamCount = 0;
                }

            }
        }

//        glEnd();
//        glEndList();
////        vecIndex_down.push_back(normDispLists.size());
////        if(i == numSlice-1) break;
//        normDispLists.push_back(glGenLists(1));
//        if(normDispLists.at(normDispLists.size()-1) == 0)
//            return false;//failure to allocate a list index???
//        glNewList(normDispLists.at(normDispLists.size()-1),GL_COMPILE);
//        glNormal3f(0,0,-1);
//        glBegin(GL_TRIANGLES);// Drawing Using Triangles
//        tSeamCount=0;
    }
    glEnd();
    glEndList();

    int err = GetGLError();
    if(err)
    {
        if(err == GL_OUT_OF_MEMORY)
        {
            displaySkipping += 10;
            return FormNormalDisplayLists();
        }
        else
            return false;
    }



    qDebug() << normDispLists.size() << "Normal Display Lists created for model " << filename;


    return true;
}


int ModelData::GetGLError()
{
    int displayerror = glGetError();

    if(displayerror)
    {
        //display Assimp Error
        qDebug() << "Display List Error: " << displayerror; //write to log as well.
        QMessageBox msgBox;
        msgBox.setWindowTitle("Nepho3D_Studio");

        switch(displayerror)
        {
        case GL_OUT_OF_MEMORY:
            msgBox.setToolTip("OpenGL错误：GL_OUT_OF_MEMORY \ Model太大，无法在您的显卡上渲染。尝试绘制稀疏三角形");
            msgBox.setText("OpenGL Error:  GL_OUT_OF_MEMORY\nModel is too large to render on your graphics card.\nAttemping To Draw Sparse Triangles.");
            break;
        case GL_INVALID_ENUM:
            msgBox.setToolTip("OpenGL错误：GL_OUT_OF_MEMORY \ Model太大，无法在您的显卡上渲染。尝试绘制稀疏三角形");
            msgBox.setText("OpenGL Error:  GL_INVALID_ENUM");
            break;
        case GL_INVALID_VALUE:
            msgBox.setToolTip("OpenGL错误：GL_INVALID_VALUE");
            msgBox.setText("OpenGL Error:  GL_INVALID_VALUE");
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            msgBox.setToolTip("OpenGL错误：GL_INVALID_FRAMEBUFFER_OPERATION");
            msgBox.setText("OpenGL Error:  GL_INVALID_FRAMEBUFFER_OPERATION");
            break;
        case GL_STACK_UNDERFLOW:
            msgBox.setToolTip("OpenGL错误：GL_STACK_UNDERFLOW");
            msgBox.setText("OpenGL Error:  GL_STACK_UNDERFLOW");
            break;
        case GL_STACK_OVERFLOW:
            msgBox.setToolTip("OpenGL错误：GL_STACK_OVERFLOW");
            msgBox.setText("OpenGL Error:  GL_STACK_OVERFLOW");
            break;
        default:
            msgBox.setToolTip("OpenGL错误：未知");
            msgBox.setText("OpenGL Error:  UNKNOWN");
            break;
        }

        msgBox.exec();
        return displayerror;
   }
   else
        return 0;

}
