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

#include <QtGui>
#include <QtOpenGL>
#include <QTime>
#include <QMessageBox>
#include <map>
#include <windows.h>

#include "OS_GL_Wrapper.h"
#include "math.h"
#include "worldview.h"
#include "layoutprojectdata.h"
#include "modelinstance.h"
#include "supportstructure.h"
#include "geometricfunctions.h"
#include "sliceset.h"
#include "slice.h"

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif
//208, 219, 230 245, 247,250
QColor bkgcolor( 233, 233 ,233);//240, 240, 240

WorldView::WorldView(QWidget *parent, MainWindow* main) : QGLWidget(parent)
{
//    bkgcolor.setRgb(232, 221, 203,0);
    pMain = main;

    xRot = 315.0;
    yRot = 0.0;
    zRot = 45.0;

    xRotTarget = 315.0;
    yRotTarget = 0.0;
    zRotTarget = 45.0;

    currViewAngle = "FREE";

    camdist = 350;
    camdistTarget = 350;

    deltaTime = 0.0;//milliseconds per frame.
    lastFrameTime = QTime::currentTime().msec();

    pan = QVector3D(0,0,0);//set pan to center of build area.
    panTarget = QVector3D(0,0,0);

    revolvePoint = QVector3D(0,0,0);

    cursorPos3D = QVector3D(0,0,0);
    cursorNormal3D = QVector3D(0,0,0);
    cursorPreDragPos3D = QVector3D(0,0,0);
    cursorPostDragPos3D = QVector3D(0,0,0);

    perspective = false;//true
    hideNonActiveSupports = false;

    //tools/keys
    currtool = "move";
    shiftdown = false;
    controldown = false;
    dragdown = false;
    pandown = 0;

    //cyp Ĭ��
    buildsizex = /*51.2;//*/pMain->ProjectData()->GetBuildSpace().x();
    buildsizey = /*80;//38.4;//*/pMain->ProjectData()->GetBuildSpace().y();
    buildsizez = pMain->ProjectData()->GetBuildSpace().z();


    //visual fence
    fencesOn[0] = false;
    fencesOn[1] = false;
    fencesOn[2] = false;
    fencesOn[3] = false;
    fencesOn[4] = false;
    fencesOn[5] = false;

    pVisSlice = NULL;

    pDrawTimer = new QTimer();
    connect(pDrawTimer, SIGNAL(timeout()), this, SLOT(UpdateTick()));
    pDrawTimer->start(16.66);//aim for 60fps.
//    UpdateTick();

    setFocusPolicy(Qt::ClickFocus);
    setMouseTracking(true);

    m_thread = new ComputeNormalThread(this);

    progress = new QProgressBar(this)/*(this)*/;
    progress->setMaximum(0);
    progress->setMinimum(0);
    progress->setTextVisible(false);
    progress->setGeometry(500,500,300,30);
    progress->hide();
    connect(this,SIGNAL(finished()),this,SLOT(OnFinished()));
//    connect(this,SIGNAL(finished()),progress,SLOT(hide()));

    m_autoSupport = new AutoSupportThread(this);
    connect(m_thread,SIGNAL(ComputeVertexNormal()),this,SLOT(ComputeVertexNormal()));

    //view
//    QIcon iconScale;
//    iconScale.addFile(QString::fromUtf8(":/B9Edit/icons/scale3.png"), QSize(), QIcon::Normal, QIcon::Off);//
//    pButtonTop = new QPushButton(this);
//    pButtonTop->setIcon(iconScale);
//    pButtonTop->setIconSize(QSize(50, 50));
//    pButtonTop->setFlat(true);
////    pButtonTop->setGeometry(10,30,50,50);//230,350,100,100 border-image: url(:/B9Edit/icons/scale3.png);
//    pButtonTop->setStyleSheet("background-color: rgba(240,240,240, 100%);");
//    pButtonTop->setToolTip("Top");
//    connect(pButtonTop,SIGNAL(clicked()),this,SLOT(TopView()));

}

WorldView::~WorldView()
{
    delete pDrawTimer;
    delete m_thread;
    delete m_autoSupport;
}

static void qNormalizeAngle(float &angle)
{
    while (angle < 0)
        angle += 360;
    while (angle >= 360 )
        angle -= 360;
}


///////////////////////////////////////
//Public Slots
///////////////////////////////////////
void WorldView::setXRotation(float angle)
{
    qNormalizeAngle(angle);

    if(angle < 180)
    {
        return;
    }

    if (angle != xRotTarget)
    {

        xRotTarget = angle;
        emit xRotationChanged(angle);
    }
}
void WorldView::setYRotation(float angle)
{
    //qNormalizeAngle(angle);
    if (angle != yRotTarget) {
        yRotTarget = angle;
        emit yRotationChanged(angle);

    }
}
void WorldView::setZRotation(float angle)
{
    //qNormalizeAngle(angle);
    if (angle != zRotTarget) {
        zRotTarget = angle;
        emit zRotationChanged(angle);
    }
}
void WorldView::CenterView()
{
    panTarget = QVector3D(0,pMain->ProjectData()->GetBuildSpace().z()/2.0,0);//set pan to center of build area.
    camdistTarget = 250;

}

void WorldView::TopView()
{
    CenterView();
    qNormalizeAngle(xRotTarget);
    qNormalizeAngle(xRot);
    qNormalizeAngle(zRot);
    xRotTarget = 360;
    zRotTarget = 0.1f;
    currViewAngle = "TOP";
}
void WorldView::RightView()
{
    CenterView();
    qNormalizeAngle(xRotTarget);
    qNormalizeAngle(xRot);
    qNormalizeAngle(zRot);
    xRotTarget = 180.0 + 90;
    zRotTarget = 180 + 90.0;
    currViewAngle = "RIGHT";
}
void WorldView::FrontView()
{
    CenterView();
    qNormalizeAngle(xRotTarget);
    qNormalizeAngle(xRot);
    qNormalizeAngle(zRot);
    xRotTarget = 180+90;
    zRotTarget = 0.1f;
    currViewAngle = "FRONT";
}
void WorldView::BackView()
{
    CenterView();
    qNormalizeAngle(xRotTarget);
    qNormalizeAngle(xRot);
    qNormalizeAngle(zRot);
    xRotTarget = 180+90;
    zRotTarget = 180.0f;
    currViewAngle = "BACK";
}
void WorldView::LeftView()
{
    CenterView();
    qNormalizeAngle(xRotTarget);
    qNormalizeAngle(xRot);
    qNormalizeAngle(zRot);
    xRotTarget = 180+90;
    zRotTarget = 180.0 - 90;
    currViewAngle = "LEFT";
}
void WorldView::BottomView()
{
    CenterView();
    qNormalizeAngle(xRotTarget);
    qNormalizeAngle(xRot);
    qNormalizeAngle(zRot);
    xRotTarget = 180;
    zRotTarget = 0.1f;
    currViewAngle = "BOTTOM";
}

void WorldView::SetRevolvePoint(QVector3D point)
{
    revolvePointTarget = point;
}
void WorldView::SetPan(QVector3D pan)
{
    panTarget = pan;
}
void WorldView::SetZoom(double zoom)
{
    camdistTarget = zoom;
}

//called by timer - draws the world and updates cool visual transitions
//no serious updating should happen here
void WorldView::UpdateTick()
{
    float dt = QTime::currentTime().msec() - lastFrameTime;
    bool anyFenceOn;

    if(dt > 0) deltaTime = dt;

    lastFrameTime = QTime::currentTime().msec();
    //float timeScaleFactor = deltaTime/33.333;


    buildsizex += ((pMain->ProjectData()->GetBuildSpace().x() - buildsizex)/2);
    buildsizey += ((pMain->ProjectData()->GetBuildSpace().y() - buildsizey)/2);
    buildsizez += ((pMain->ProjectData()->GetBuildSpace().z() - buildsizez)/2);

    anyFenceOn = (fencesOn[0] || fencesOn[1] || fencesOn[2] || fencesOn[3] || fencesOn[5]);
    if(anyFenceOn)
        fenceAlpha += 0.01f;
    else
        fenceAlpha = 0;

    if(fenceAlpha >= 0.3)
        fenceAlpha = 0.3f;

    if(xRot < 200 && xRot >= 180)
    {
        supportAlpha = ((xRot-180)/20.0);
        if(supportAlpha < 0.1)
            supportAlpha = 0.1f;
    }
    else
        supportAlpha = 1.0;

    UpdatePlasmaFence();


    //always normalize all angles to 0-360
    //qNormalizeAngle(xRotTarget);
    qNormalizeAngle(yRotTarget);
    qNormalizeAngle(zRotTarget);
    qNormalizeAngle(xRot);
    qNormalizeAngle(yRot);
    qNormalizeAngle(zRot);


    if((zRotTarget - zRot) < -180)
        zRotTarget = zRotTarget + 360;

    if((zRot - zRotTarget) < -180)
        zRot = zRot + 360;

    xRot = xRot + ((xRotTarget - xRot)/5.0);
    yRot = yRot + ((yRotTarget - yRot)/5.0);
    zRot = zRot + ((zRotTarget - zRot)/5.0);


    camdist = camdist + (camdistTarget - camdist)/5.0;

    pan = pan + (panTarget - pan)/2.0;

    revolvePoint = revolvePoint + (revolvePointTarget - revolvePoint)/2.0;


    //update visiual slice
    QTimer::singleShot(0,this,SLOT(UpdateVisSlice()));





    glDraw();//actual draw (and flip buffers internally)
}
void WorldView::SetTool(QString tool)
{
    currtool = tool;
}
QString WorldView::GetTool()
{
     return currtool;
}

void WorldView::ExitToolAction()
{
    dragdown = false;
    shiftdown = false;
    controldown = false;
}


////////////////////////////////////////////////////////
//Public Gets
//////////////////////////////////////////////////////////////


QVector3D WorldView::GetPan()
{
    return panTarget;
}

float WorldView::GetZoom()
{
    return camdistTarget;
}
QVector3D WorldView::GetRotation()
{
    return QVector3D(xRotTarget,yRotTarget,zRotTarget);
}




//Private
void WorldView::initializeGL()
{

    qglClearColor(bkgcolor);//cyp QColor (208, 219, 230) 70,130,180
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_NORMALIZE);
    glLineWidth(0.5);
    glEnable(GL_LINE_SMOOTH);

    glEnable ( GL_COLOR_MATERIAL );
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


    glDisable(GL_MULTISAMPLE);
    glBlendFunc(GL_DST_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    static GLfloat lightPosition0[4] = { 0.0, 0.0, 100.0, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0);


}

void WorldView::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_ACCUM_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    ResetCamera(false);


//    if(pMain->XRayEnabled())
//    {
//        DrawBuildArea();
//        ResetCamera(true);
//    }

    DrawMisc();

    DrawInstances();

    //draw slices
    DrawVisualSlice();

//    if(!pMain->XRayEnabled())
        DrawBuildArea();
}

void WorldView::resizeGL(int width, int height)
{
     glViewport(0,0,width,height);
//     pButtonTop->setGeometry(width-60,0,50,50);
//     emit getGLSize(width,height);
}


void WorldView::ResetCamera(bool xrayon)
{
    double nearClip;
    //perpective/ortho/xray stuff!
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();//restores default matrix.
    if(perspective)
    {
//        //cyp
//        if(pMain->XRayEnabled() && pMain->SupportModeInst() && xrayon)
//        {
//            nearClip = camdist -
//            (pMain->SupportModeInst()->GetMaxBound() - pMain->SupportModeInst()->GetMinBound()).length()*(1/*-pMain->XRayPercentage()*/)
//            +(pMain->SupportModeInst()->GetMaxBound() - pMain->SupportModeInst()->GetMinBound()).length()*0.5;
//        }
//        else
            nearClip = 1;

        gluPerspective(30,double(width())/height(),nearClip,5500);
    }
    else
    {
        float aspRatio = float(this->width())/this->height();
//        //cyp
//        if(pMain->XRayEnabled() && pMain->SupportModeInst() && xrayon)
//        {
//            nearClip = 200-
//            (pMain->SupportModeInst()->GetMaxBound() - pMain->SupportModeInst()->GetMinBound()).length()*(1/*-pMain->XRayPercentage()*/)
//            +(pMain->SupportModeInst()->GetMaxBound() - pMain->SupportModeInst()->GetMinBound()).length()*0.5;
//        }
//        else
            nearClip = 0.1;

        glOrtho(-(camdist/120.0)*aspRatio*102.4/2,
                (camdist/120.0)*aspRatio*102.4/2,
                -(camdist/120.0)*102.4/2,
                (camdist/120.0)*102.4/2,
                nearClip,
                5500);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if(perspective)
        glTranslatef(0.0, 0.0, -camdist);//step back amount
    else
        glTranslatef(0.0, 0.0, -200.0);//step back amount

    glTranslatef(pan.x(),-pan.y(),0);

    glRotatef(xRot, 1.0, 0.0, 0.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glRotatef(zRot, 0.0, 0.0, 1.0);
    glTranslatef(-revolvePoint.x(),-revolvePoint.y(),-revolvePoint.z());


}

void WorldView::DrawMisc()
{
    //show the cursor position
    if(currtool == "SUPPORTADD")
    {
        glDisable(GL_LIGHTING);
        glPushMatrix();
        if(cursorNormal3D.z() <= 0)
        glColor3f(0.0f,1.0f,0.0f);
        else
        glColor3f(1.0f,0.0f,0.0f);
            glBegin(GL_LINES);
                glVertex3f( cursorPos3D.x(), cursorPos3D.y(), cursorPos3D.z());
                glVertex3f( cursorPos3D.x() + cursorNormal3D.x(), cursorPos3D.y() + cursorNormal3D.y(), cursorPos3D.z() + cursorNormal3D.z());
            glEnd();
        glPopMatrix();
        glEnable(GL_LIGHTING);
    }
}


void WorldView::DrawInstances()
{
    unsigned int i;
    B9ModelInstance* pInst;

    glEnable(GL_DEPTH_TEST);

    //if were in support mode wee want to only render
    //the support mode instance
    if(pMain->SupportModeInst() != NULL)
    {
        glColor3f(0.3f,0.3f,0.3f);
        glDisable(GL_CULL_FACE);
        pMain->SupportModeInst()->RenderGL(true);//
        glEnable(GL_CULL_FACE);


        glEnable(GL_BLEND);
        glPushAttrib(GL_COLOR_BUFFER_BIT);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_CULL_FACE);
        if(hideNonActiveSupports && pMain->HidingSupports()){
            glDisable(GL_LIGHTING);
            glColor3f(0.0f,1.0f,1.0f);//cyp
            pMain->SupportModeInst()->RenderSupportsTipsGL();
            glEnable(GL_LIGHTING);
            pMain->SupportModeInst()->renderSupportGL(pMain->GetSelectedSupports()->at(0),false,1.0,supportAlpha);
        }
        else
            pMain->SupportModeInst()->RenderSupportsGL(false,1.0,supportAlpha);
        glEnable(GL_CULL_FACE);
        glPopAttrib();
        glDisable(GL_BLEND);

    }
    else
    {
        for(i = 0; i < pMain->GetAllInstances().size();i++)
        {
            pInst = pMain->GetAllInstances()[i];
            pInst->RenderGL();
            glColor3f(pInst->visualcolor.redF()*0.5,
                    pInst->visualcolor.greenF()*0.5,
                    pInst->visualcolor.blueF()*0.5);

            pInst->RenderSupportsGL(true,1.0,1.0);

        }
    }
}

void  WorldView::DrawVisualSlice()
{
    if(pVisSlice == NULL)
        return;

    if(supportAlpha < 0.5)
        glDisable(GL_DEPTH_TEST);

    glDisable(GL_LIGHTING);

    glPushMatrix();
    glTranslatef(0.0,0.0,pVisSlice->realAltitude);
    glColor3f(0.5,0.5,0.5);
    pVisSlice->RenderOutlines();


    glPopMatrix();

    if(supportAlpha < 0.5)
        glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
}

void WorldView::DrawBuildArea()
{
//    buildsizex = 51.2;
//    buildsizey = 38.4;
    buildsizez = 130;//cyp
//    if(buildsizez == 0)
//        buildsizez = 150;

//    QPainter painter(pMain->pWorldView);
//    QPolygonF pts;
//    QPainterPath path;
//    pts.push_back(QPointF(0,0));
//    pts.push_back(QPointF(0,3));
//    pts.push_back(QPointF(1,5));
//    pts.push_back(QPointF(3,2));
//    pts.push_back(QPointF(3,0));

//    path.addPolygon(pts);
//    painter.fillPath(path,QBrush(Qt::blue));

//    return ;

    glPushMatrix();
    glColor3f(0.6f,0.6f,0.6f);//�����ı� cyp
    glTranslatef(-buildsizex/2, -buildsizey/2, 0);

    glDisable(GL_LIGHTING);
        //4 vertical lines
        glBegin(GL_LINES);
            glVertex3d( 0, 0, 0);
            glVertex3d( 0, 0, buildsizez);
        glEnd();
        glBegin(GL_LINES);
            glVertex3d( buildsizex, 0,0);
            glVertex3d( buildsizex, 0,buildsizez);
        glEnd();
        glBegin(GL_LINES);
            glVertex3d( 0, buildsizey,0);
            glVertex3d( 0, buildsizey,buildsizez);
        glEnd();
        glBegin(GL_LINES);
            glVertex3d( buildsizex, buildsizey,0);
            glVertex3d( buildsizex, buildsizey,buildsizez);
        glEnd();

        //4 Top lines
        glBegin(GL_LINES);
            glVertex3d( 0, 0, buildsizez);
            glVertex3d( buildsizex, 0, buildsizez);
        glEnd();
        glBegin(GL_LINES);
            glVertex3d( 0, 0, buildsizez);
            glVertex3d( 0, buildsizey, buildsizez);
        glEnd();
        glBegin(GL_LINES);
            glVertex3d( buildsizex, buildsizey, buildsizez);
            glVertex3d( 0, buildsizey, buildsizez);
        glEnd();
        glBegin(GL_LINES);
            glVertex3d( buildsizex, buildsizey, buildsizez);
            glVertex3d( buildsizex, 0, buildsizez);
        glEnd();
        //4 Bottom lines
        glBegin(GL_LINES);
            glVertex3d( 0, 0, 0);
            glVertex3d( buildsizex, 0,0);
        glEnd();
        glBegin(GL_LINES);
            glVertex3d( 0, 0, 0);
            glVertex3d( 0, buildsizey, 0);
        glEnd();
        glBegin(GL_LINES);
            glVertex3d( buildsizex, buildsizey, 0);
            glVertex3d( 0, buildsizey, 0);
        glEnd();
        glBegin(GL_LINES);
            glVertex3d( buildsizex, buildsizey, 0);
            glVertex3d( buildsizex, 0, 0);
        glEnd();
        //��������//cyp
        glColor3f(0.7f,0.7f,0.7f);
        for(int i=5;i<buildsizex;i+=7){
            glBegin(GL_LINES);
                glVertex3d( i, buildsizey, 0);
                glVertex3d( i, 0, 0);
            glEnd();
        }
        for(int i=5;i<buildsizey;i+=7){
            glBegin(GL_LINES);
                glVertex3d( buildsizex, i, 0);
                glVertex3d( 0, i, 0);
            glEnd();
        }

        //draw red cordinate hints //cyp ����ϵ
        glColor3f(1.0f,0.0f,0.0f);
        glBegin(GL_LINES);
                glVertex3d( 0, 0, 0);
                glVertex3d( 0, 0, 10);//buildsizez +
        glEnd();
        glBegin(GL_LINES);
                glVertex3d( 0, 0, 0);
                glVertex3d( 10, 0, 0);//buildsizex +
        glEnd();
        glBegin(GL_LINES);
                glVertex3d( 0, 0, 0);
                glVertex3d( 0, 10, 0);//buildsizey +
        glEnd();
        glColor3f(1.0f,1.0f,1.0f);


        glEnable(GL_LIGHTING);
        glEnable(GL_BLEND);

        //top rectangle
        if(fencesOn[4] && !pMain->SupportModeInst())
            glColor4f(1.0f,0.0f,0.0f,0.5f);
        else
            glColor4f(0.9f,0.9f,0.9f,0.5f);

        glNormal3f(0,0,1);
        glBegin(GL_QUADS);
            glVertex3f( buildsizex, 0, 0);
            glVertex3f( buildsizex, buildsizey, 0);
            glVertex3f( 0, buildsizey, 0);
            glVertex3f( 0, 0, 0);
        glEnd();
//            glBegin(GL_TRIANGLES);
//                glVertex3f( buildsizex, 0, 0);
//                glVertex3f( buildsizex, buildsizey, 0);
//                glVertex3f( 0, buildsizey, 0);
//            glEnd();

//            glBegin(GL_TRIANGLES);
//                glVertex3f( buildsizex, 0, 0);
//                glVertex3f( 0, buildsizey, 0);
//                glVertex3f( 0, 0, 0);
//            glEnd();


        //bottom rectangle

        if(0/*!pMain->SupportModeInst()*/)
        {

            glNormal3f(0,0,-1);
            if(fencesOn[4])
                glColor4f(1.0f,0.0f,0.0f,0.5f);
            else
                glColor4f(1.0f,1.0f,1.0f,1.0f);

//                glBegin(GL_TRIANGLES);//-0.1 is to hide z-fighting
//                    glVertex3f( 0, buildsizey, -0.1f);
//                    glVertex3f( buildsizex, buildsizey, -0.1f);
//                    glVertex3f( buildsizex, 0, -0.1f);
//                glEnd();

//                glBegin(GL_TRIANGLES);
//                    glVertex3f( 0, 0, -0.1f);
//                    glVertex3f( 0, buildsizey, -0.1f);
//                    glVertex3f( buildsizex, 0, -0.1f);
//                glEnd();
                glBegin(GL_QUADS);//˳ʱ��
                    glVertex3f( 0, 0, -0.1f);
                    glVertex3f( 0, buildsizey, -0.1f);
                    glVertex3f( buildsizex, buildsizey, -0.1f);
                    glVertex3f( buildsizex, 0, -0.1f);
                glEnd();
            glColor4f(1.0f,1.0f,1.0f,1.0f);

        }

        //draw plasma fences!
        if(!pMain->SupportModeInst())
        {
            glColor4f(fenceAlpha*2,0.0f,0.0f,fenceAlpha);
            glDisable(GL_CULL_FACE);
            glDisable(GL_LIGHTING);

            //X+ fence
            if(fencesOn[0])
            {
                glNormal3f(1,0,0);
                glBegin(GL_QUADS);
                    glVertex3f( buildsizex, 0, 0);
                    glVertex3f( buildsizex, buildsizey, 0);
                    glVertex3f( buildsizex, buildsizey, buildsizez);
                    glVertex3f( buildsizex, 0, buildsizez);
                glEnd();
            }
            //X- fence
            if(fencesOn[1])
            {
                glNormal3f(1,0,0);
                glBegin(GL_QUADS);
                    glVertex3f( 0, 0, 0);
                    glVertex3f( 0, buildsizey, 0);
                    glVertex3f( 0, buildsizey, buildsizez);
                    glVertex3f( 0, 0, buildsizez);
                glEnd();
            }
            //Y+
            if(fencesOn[2])
            {
                glNormal3f(1,0,0);
                glBegin(GL_QUADS);
                    glVertex3f( 0, buildsizey, 0);
                    glVertex3f( buildsizex, buildsizey, 0);
                    glVertex3f( buildsizex, buildsizey, buildsizez);
                    glVertex3f( 0, buildsizey, buildsizez);
                glEnd();
            }
            //Y-
            if(fencesOn[3])
            {
                glNormal3f(1,0,0);
                glBegin(GL_QUADS);
                    glVertex3f( 0, 0, 0);
                    glVertex3f( buildsizex, 0, 0);
                    glVertex3f( buildsizex, 0, buildsizez);
                    glVertex3f( 0, 0, buildsizez);
                glEnd();
            }
            //Z+
            if(fencesOn[5])
            {
                glNormal3f(1,0,0);
                glBegin(GL_QUADS);
                    glVertex3f( buildsizex, 0, buildsizez);
                    glVertex3f( buildsizex, buildsizey, buildsizez);
                    glVertex3f( 0, buildsizey, buildsizez);
                    glVertex3f( 0, 0, buildsizez);
                glEnd();
            }

            glEnable(GL_LIGHTING);
            glEnable(GL_CULL_FACE);
        }
        glDisable(GL_BLEND);


//        glTranslatef(-buildsizex/2, -buildsizey/2, 0);
    glPopMatrix();

 }


 void WorldView::UpdateSelectedBounds()
 {
     unsigned int i;
     pMain->setCursor(Qt::WaitCursor);

     for(i=0;i<pMain->GetSelectedInstances().size();i++)
     {
         pMain->GetSelectedInstances()[i]->UpdateBounds();
     }
     pMain->setCursor(Qt::ArrowCursor);
 }

 //checks all instances against fences.
 void WorldView::UpdatePlasmaFence()
 {
     unsigned int i;
     B9ModelInstance* inst;

     fencesOn[0] = false;
     fencesOn[1] = false;
     fencesOn[2] = false;
     fencesOn[3] = false;
     fencesOn[4] = false;
     fencesOn[5] = false;

     for(i = 0; i < pMain->GetAllInstances().size(); i++)
     {
         inst = pMain->GetAllInstances()[i];
         if(inst->GetMaxBound().x() > pMain->ProjectData()->GetBuildSpace().x()*0.5)
             fencesOn[0] = true;
         if(inst->GetMinBound().x() < -pMain->ProjectData()->GetBuildSpace().x()*0.5)
             fencesOn[1] = true;
         if(inst->GetMaxBound().y() > pMain->ProjectData()->GetBuildSpace().y()*0.5)
             fencesOn[2] = true;
         if(inst->GetMinBound().y() < -pMain->ProjectData()->GetBuildSpace().y()*0.5)
             fencesOn[3] = true;
         //Below Build Table
         if(inst->GetMinBound().z() < -0.01)
             fencesOn[4] = true;
         if(inst->GetMaxBound().z() > 130.00)
             fencesOn[5] = true;
     }
 }



 //Mouse Interaction
void WorldView::mousePressEvent(QMouseEvent *event)
{
     mouseLastPos = event->pos();
     mouseDownInitialPos = event->pos();

     if(event->button() == Qt::MiddleButton)
     {
        pandown = true;
     }
     if(event->button() == Qt::LeftButton)
     {
         dragdown = true;
         OnToolInitialAction(currtool, event);
     }
}

void WorldView::mouseMoveEvent(QMouseEvent *event)
{
    mouseDeltaPos.setX(event->x() - mouseLastPos.x());
    mouseDeltaPos.setY(event->y() - mouseLastPos.y());
    mouseLastPos = event->pos();

    if((event->buttons() & Qt::RightButton) && !shiftdown) {
        setXRotation(xRotTarget + 0.5 * mouseDeltaPos.y());
        setZRotation(zRotTarget + 0.5 * mouseDeltaPos.x());
        //were rotating the view so switch view mode!
        currViewAngle = "FREE";
    }

    if(pandown || (event->buttons() & Qt::RightButton && shiftdown))
    {
        panTarget += QVector3D(mouseDeltaPos.x()/20.0,mouseDeltaPos.y()/20.0,0);
    }

    if(dragdown && (event->buttons() & Qt::LeftButton))
    {
        OnToolDragAction(currtool,event);
    }

    if(!dragdown && !pandown && !shiftdown
            && !(event->buttons() & Qt::LeftButton) && !(event->buttons() & Qt::RightButton))
        OnToolHoverMove(currtool,event);


}
void WorldView::mouseReleaseEvent(QMouseEvent *event)
{

    if(event->button() == Qt::MiddleButton)
    {
        pandown = false;
    }
    if(event->button() == Qt::LeftButton)
    {
        dragdown = false;
        OnToolReleaseAction(currtool, event);
    }
}


void WorldView::wheelEvent(QWheelEvent *event)
{
    camdistTarget -= event->delta()/8.0;
    //zooming limits
    if(perspective)
    {
        if(camdistTarget <= 10.0)
        {
            camdistTarget = 10.0;
        }
        if(camdistTarget >= 550.00)
            camdistTarget = 550.00;
    }
    else
    {
        if(camdistTarget <= 5.0)
        {
            camdistTarget = 5.0;
        }
        if(camdistTarget >= 550.00)
            camdistTarget = 550.00;


    }
}

 //Keyboard interaction
void WorldView::keyPressEvent( QKeyEvent * event )
{
    QWidget::keyPressEvent(event);
    if(event->key() == Qt::Key_Shift)
    {
        shiftdown = true;
    }
    if(event->key() == Qt::Key_Control)
    {
        controldown = true;
    }
}
void WorldView::keyReleaseEvent( QKeyEvent * event )
{
    if(event->key() == Qt::Key_Shift)
    {
        shiftdown = false;
    }
    if(event->key() == Qt::Key_Control)
    {
        controldown = false;
    }
}

bool WorldView::AddSupport(QVector3D topPos,QVector3D normal,bool isAutor,bool isLowest)
{
    QSettings appSettings;
    Triangle3D* pBottomTri = NULL;
    B9SupportStructure* addedSupport;
    bool hitGround;


    addedSupport = pMain->SupportModeInst()->AddSupport(QVector3D(),QVector3D());

    addedSupport->SetTopPoint(topPos);
    addedSupport->SetTopNormal(normal*-1.0);


    //"drill" down from the toppivot position and see where the vertical ray hits.
    QVector3D basePos = GetDrillingHit(addedSupport->GetTopPivot(),pMain->SupportModeInst(), hitGround, pBottomTri);

    if(hitGround)
    {
        addedSupport->SetIsGrounded(true);
    }
    else
    {
        addedSupport->SetBottomPoint(basePos);
        addedSupport->SetBottomNormal(pBottomTri->normal*-1.0);
        addedSupport->SetIsGrounded(false);
    }

    //now the support is created - but we want to load in the default user settings for
    //things like shape and radius
    //CYP
    appSettings.beginGroup("USERSUPPORTPARAMS");
        addedSupport->SetTopAttachShape(appSettings.value("TopAttachShape",addedSupport->GetTopAttachShape()).toString());
        addedSupport->SetTopLength(appSettings.value("TopLength",addedSupport->GetTopLength()).toDouble());
        addedSupport->SetTopPenetration(appSettings.value("TopPenetration",addedSupport->GetTopPenetration()).toDouble());
        addedSupport->SetTopRadius(appSettings.value("TopRadius",addedSupport->GetTopRadius()).toDouble());
        addedSupport->SetTopAngleFactor(appSettings.value("TopAngleFactor",addedSupport->GetTopAngleFactor()).toDouble());

        addedSupport->SetMidAttachShape(appSettings.value("MidAttachShape",addedSupport->GetMidAttachShape()).toString());
        addedSupport->SetMidRadius(appSettings.value("MidRadius",addedSupport->GetMidRadius()).toDouble());

    if(addedSupport->GetIsGrounded())
    {
            addedSupport->SetBottomAttachShape(appSettings.value("BottomAttachShape",addedSupport->GetTopAttachShape()).toString());
            addedSupport->SetBottomLength(appSettings.value("BottomLength",addedSupport->GetTopLength()).toDouble());
            addedSupport->SetBottomPenetration(appSettings.value("BottomPenetration",addedSupport->GetTopPenetration()).toDouble());
            addedSupport->SetBottomRadius(appSettings.value("BottomRadius",addedSupport->GetTopRadius()).toDouble());//cyp
            addedSupport->SetBottomAngleFactor(appSettings.value("BottomAngleFactor",addedSupport->GetTopAngleFactor()).toDouble());

        addedSupport->SetBottomPoint(addedSupport->GetTopPivot());
    }
    else
    {
            addedSupport->SetBottomAttachShape(addedSupport->GetTopAttachShape());//cyp
            addedSupport->SetBottomLength(addedSupport->GetTopLength());
            addedSupport->SetBottomPenetration(addedSupport->GetTopPenetration());
            addedSupport->SetBottomAngleFactor(addedSupport->GetTopAngleFactor());
            addedSupport->SetBottomRadius(addedSupport->GetTopRadius());
    }
    appSettings.endGroup();

    //�ֶ����֧�ţ���������
    if(!isAutor) return true;

    //==================�Զ�֧�ŵ��ص�֧�ŵ���=============================

    double midRadius = addedSupport->GetMidRadius();
    QVector3D topPivot = addedSupport->GetTopPivot();
    QVector3D bottomPivot;// = addedSupport->GetBottomPivot();
    QVector3D bottomPoint;
    double ZTopPivot = addedSupport->GetTopPivot().z();
    double ZBottomPivot;// = addedSupport->GetBottomPivot().z();
    int nVertex = vertexByZPos.size();
    double ZBottomNormal;
    double d;
    QVector3D v;

    //���ҵ��Զ�֧��:�����ص�֧��
    bool found=true;
    while(isLowest){
        found=true;
        bottomPoint = addedSupport->GetBottomPoint();
        bottomPivot = addedSupport->GetBottomPivot();

        if(!hitGround)
            ZBottomNormal = addedSupport->GetBottomNormal().z();
        else
            ZBottomNormal=-1;
        if(/*addedSupport->GetMidLength()<2topPivot.z()-bottomPivot.z()<1 ||*/ ZBottomNormal>=-0.3
                || bottomPivot.z()<bottomPoint.z() || bottomPivot.z()>topPivot.z()
                || GradientOfLine(topPivot,bottomPivot) < 0.7){//֧���¶�̫С�������
            pMain->SupportModeInst()->supportStructureList.pop_back();
            return false;
        }
        ZBottomPivot = bottomPivot.z();//addedSupport->GetBottomPivot().z();
//        for(int i=0;i<nVertex;i++){
        for(int i=nVertex-1;i>=0;i--){
            v = vertexByZPos[i].pos - pMain->SupportModeInst()->GetPos();
            if(v==bottomPoint)
                continue;
            if(v.z()<ZBottomPivot+0.1)
                break;//continue;
            if(v.z()>ZTopPivot+0.1)
                continue;//break;
            d=Distance3DPointToLine(topPivot,bottomPivot,v);
            if(d <= midRadius + 0.1){//�Ƿ�֧�ţ�֧����ģ�͵Ŀ�϶��С��0.1
//                if(!isLowest){
//                    pMain->SupportModeInst()->supportStructureList.pop_back();//�Ƿ�֧�ŵ���
//                    return false;
//                }
//                found = false;
                addedSupport->SetBottomPoint(v);
                addedSupport->SetBottomNormal(vertexByZPos[i].sumNormal*-1.0);
                addedSupport->SetIsGrounded(false);
                addedSupport->SetBottomAttachShape(addedSupport->GetTopAttachShape());//cyp
                addedSupport->SetBottomLength(addedSupport->GetTopLength());
                addedSupport->SetBottomPenetration(addedSupport->GetTopPenetration());
                addedSupport->SetBottomAngleFactor(addedSupport->GetTopAngleFactor());
                addedSupport->SetBottomRadius(addedSupport->GetTopRadius());
                found = false;
                hitGround = false;
                break;
            }
        }
        if(found){
//            if(ZBottomNormal>=-0.3/* || bottomPivot.z()<bottomPoint.z()*/ || GradientOfLine(topPivot,bottomPivot) < 0.7){//֧���¶�̫С�������
//                pMain->SupportModeInst()->supportStructureList.pop_back();
//                return false;
//            }
            return true;
        }
    }

    //�����ҵ��Զ�֧��:ɾ���ص�֧��
    bottomPoint = addedSupport->GetBottomPoint();
    bottomPivot = addedSupport->GetBottomPivot();
    ZBottomPivot = bottomPivot.z();//addedSupport->GetBottomPivot().z();
    if(!hitGround)
        ZBottomNormal = addedSupport->GetBottomNormal().z();
    else
        ZBottomNormal=-1;
    //֧��̫�̵ģ�����������ҵ��֧�Ż�֧���¶�̫С�������
    if(/*addedSupport->GetMidLength()<2topPivot.z()-bottomPivot.z()<1 ||*/ ZBottomNormal>=-0.3
            || bottomPivot.z()<bottomPoint.z() || bottomPivot.z()>topPivot.z()
            || GradientOfLine(topPivot,bottomPivot) < 0.7){//֧���¶�̫С�������
        pMain->SupportModeInst()->supportStructureList.pop_back();
        return false;
    }
    for(int i=0;i<nVertex;i++){
        v = vertexByZPos[i].pos - pMain->SupportModeInst()->GetPos();
        if(v==bottomPoint)
            continue;
        if(v.z()<ZBottomPivot)
            continue;
        if(v.z()>ZTopPivot)
            return true;
        d=Distance3DPointToLine(topPivot,bottomPivot,v);
        if(d < midRadius + 0.1){//�Ƿ�֧�ţ�֧����ģ�͵Ŀ�϶��С��0.1
            pMain->SupportModeInst()->supportStructureList.pop_back();//�Ƿ�֧�ŵ���
            return false;
        }
    }
    return true;


}

void WorldView::OnToolInitialAction(QString tool, QMouseEvent* event)
{
    B9ModelInstance* clickedInst = NULL;
    Triangle3D* pTopTri = NULL;
//    Triangle3D* pBottomTri = NULL;
//    B9SupportStructure* addedSupport;
    B9SupportStructure* pSup;
//    bool hitGround;



    if(currtool == "MODELSELECT" ||
            currtool == "MODELMOVE" ||
            currtool == "MODELSPIN" ||
            currtool == "MODELSCALE" ||
            currtool == "MODELORIENTATE")
    {
        Update3DCursor(event->pos());

        pMain->DeSelectAll();
        clickedInst = SelectInstanceByScreen(event->pos());
    }

    if(currtool == "SUPPORTADD")//after the user clicked the add support button.
    {

        bool s;
        unsigned int tri;

        if(!pMain->SupportModeInst())
            return;

        tri = GetPickTriangleIndx(pMain->SupportModeInst(),event->pos(),s);

        if(s)
        {

            QVector3D topPos = GetPickOnTriangle(event->pos(),pMain->SupportModeInst(),tri);
            pTopTri = pMain->SupportModeInst()->triList[tri];

            if(pTopTri->normal.z() <= 0)
            {
                AddSupport(topPos,pTopTri->normal);//�ֶ����֧��
            }
        }
    }

    if(currtool == "SUPPORTDELETE")
    {
        pMain->DeSelectAllSupports();

        pSup = GetSupportByScreen(event->pos());
        if(pSup != NULL)
        {
            pMain->DeleteSupport(pSup);
        }
    }

}

bool sortByNormal(const __Vertex &v1,const __Vertex& v2)
{//���򣺸��ݷ�������z��������
    return v1.sumNormal.z()<v2.sumNormal.z();
}

bool sortByZValue(const __Vertex &v1,const __Vertex& v2)
{//���򣺸��ݷ�������z��������
    return v1.pos.z()<v2.pos.z();
}

void WorldView::ComputeVertexNormal()
{//cyp �ж��Ƿ�Ϊ���ҵ����͵㣬����¼���ǵķ����������ɸõ������ƽ��ķ�����֮��
    emit ComputeComplete(false);
    std::vector<__Vertex> vecVertex;
    Triangle3D* pTri = NULL;
    unsigned int i,j;
    int cnt=0;
    int cnt2=0;
    std::map<__Position, int> mapVerID;
    QVector3D topPos;

    vertexByZNormal.clear();
    vertexByZPos.clear();

    if(!pMain->SupportModeInst())
        return;

    int nTriList = pMain->SupportModeInst()->triList.size();
    bool haveLowest;
    __Position _pos;
    __Vertex v;
    int index = 0;
    int count = 0;
    double Zmin;
    for(i=0;i<nTriList;i++){
        haveLowest = true;
        pTri = pMain->SupportModeInst()->triList[i];
        Zmin = 999;
//            pTri->minVertex = QVector3D(9999,9999,9999);
        int indexMin;// = 0;
        for(j=0;j<3;j++){
            topPos = pTri->vertex[j];
            _pos=topPos;
            if(topPos.z() < Zmin/*pTri->minVertex.z()*/){
                indexMin = j;
                haveLowest = true;
                Zmin = topPos.z();
//                    pTri->minVertex = topPos;//pTri->vertex[j];
            }
            else if(topPos.z() == Zmin/*pTri->minVertex.z()*/){
                haveLowest = false;
//                    pTri->minVertex.setX((pTri->vertex[j].x()+pTri->minVertex.x())/2);
//                    pTri->minVertex.setY((pTri->vertex[j].y()+pTri->minVertex.y())/2);
            }
            if(mapVerID[_pos] <= 0){//�µĵ�
                count++;
                v.isHangVer = false;
                v.isLowest = true;
                v.pos = topPos;
                v.sumNormal = pTri->normal;
                vecVertex.push_back(v);
                mapVerID[_pos] = count;
            }
            else{//��λ������
                vecVertex[mapVerID[_pos]-1].sumNormal += pTri->normal;
                vecVertex[mapVerID[_pos]-1].sumNormal /= Distance3D(vecVertex[mapVerID[_pos]-1].sumNormal,QVector3D(0,0,0));
//                    if(vecVertex[mapVerID[_pos]-1].sumNormal.z()>pTri->normal.z())
//                        vecVertex[mapVerID[_pos]-1].sumNormal = pTri->normal;
            }
        }
        for(j=0;j<3;j++){
            topPos = pTri->vertex[j];
            _pos=topPos;
            index = mapVerID[_pos] - 1;//�±�
//                if(haveLowest && j==indexMin){
            if(topPos.z()==Zmin/*pTri->minVertex.z()*/){
                vecVertex[index].isHangVer=true;//���ҵ���
            }
            else if(vecVertex[index].isLowest){
                vecVertex[index].isLowest = false;//��͵���
                cnt2++;
            }
        }
    }
    std::sort(vecVertex.begin(),vecVertex.end(),sortByNormal);//����������zֵ��С��������
    vertexByZNormal = vecVertex;

    std::sort(vecVertex.begin(),vecVertex.end(),sortByZValue);//�������zֵ��С��������
    vertexByZPos = vecVertex;

    emit ComputeComplete(true);
}

void WorldView::OnToolAutoAddSupport()
{
//    disconnect(pDrawTimer, SIGNAL(timeout()), this, SLOT(UpdateTick()));

//    ComputeVertexNormal();

//    emit ComputeComplete(false);
    bool s;
    unsigned int i;
    int cnt=0;
    int cnt2=0;
    QVector3D topPos;
    double len;

    __Vertex v;
    int nVertex = vertexByZNormal.size();

    std::vector<QVector3D> SupportVertex;
    for(i=0;i<nVertex;i++)
    {//��͵�һ��Ҫ��֧��
        v=vertexByZNormal[i];
        if(v.sumNormal.z()>0)
            break;
        if(!v.isLowest)
            continue;
        topPos = v.pos - pMain->SupportModeInst()->GetPos();
        s=true;
        for(int i=0;i<SupportVertex.size();i++){
            double d = sqrt(pow(topPos.x()-SupportVertex[i].x(),2)+pow(topPos.y()-SupportVertex[i].y(),2)/*+pow(topPos.z()-SupportVertex[i].z(),2)*/);
            if(/*topPos == vertex[i] ||*/ d < 1){//2��֧�ž��벻��С��1
                s = false;
                break;
            }

        }
        if(!s) continue;
        cnt++;
        if(AddSupport(topPos,v.sumNormal,true,true)){
            SupportVertex.push_back(topPos);
        }
    }

    QSettings appSettings;
    appSettings.beginGroup("USERSUPPORTPARAMS");
        len = appSettings.value("AutoDistance",2).toDouble();
    appSettings.endGroup();

    for(i=0;i<nVertex;i++)//
    {//���ҵ�֧���ܶ��㷨��ÿ2��֧��ˮƽ���벻��С����ֵ
        v=vertexByZNormal[i];
        if(v.sumNormal.z()>=-0.8)
            break;
        if(v.isLowest)
            continue;
        if(!v.isHangVer)
            continue;
        topPos = v.pos - pMain->SupportModeInst()->GetPos();
        s = true;
        for(int i=0;i<SupportVertex.size();i++){
            double d = sqrt(pow(topPos.x()-SupportVertex[i].x(),2)+pow(topPos.y()-SupportVertex[i].y(),2)/*+pow(topPos.z()-SupportVertex[i].z(),2)*/);
            if(/*topPos == vertex[i] ||*/ d < len){//2��֧�ž��벻��С��2
                s = false;
                break;
            }

        }
        if(s){//���õ㷨������z����С��-0.9ʱ���֧��
            if(AddSupport(topPos,v.sumNormal,true,false)){
                SupportVertex.push_back(topPos);
                cnt2++;
            }
        }
    }

    emit finished();
}

void WorldView::OnFinished()
{
    connect(pDrawTimer, SIGNAL(timeout()), this, SLOT(UpdateTick()));//�ָ���ʱ����
//    pMain->pActionSupport->setEnabled(true);
    pMain->setButtonEnable(true);
}

void WorldView::OnToolDragAction(QString tool, QMouseEvent* event)
{
    unsigned int i;
    B9ModelInstance* pInst;
    B9SupportStructure* pSup;
    QSettings appSettings;


    if(currtool == "MODELMOVE")
    {
        Update3DCursor(event->pos());

        for(i = 0; i < pMain->GetSelectedInstances().size(); i++)
        {
            if(shiftdown)
            {
                pMain->GetSelectedInstances()[i]->Move(QVector3D(0,0,-mouseDeltaPos.y()*0.1));
            }
            else
            {
                if(currViewAngle == "FREE" || currViewAngle == "TOP" || currViewAngle == "BOTTOM")
                {
                    pMain->GetSelectedInstances()[i]->SetX(cursorPos3D.x() - PreDragInstanceOffset.x());
                    pMain->GetSelectedInstances()[i]->SetY(cursorPos3D.y() - PreDragInstanceOffset.y());
                }
                else if(currViewAngle == "FRONT" || currViewAngle == "BACK")
                {
                    pMain->GetSelectedInstances()[i]->SetX(cursorPos3D.x() - PreDragInstanceOffset.x());
                    pMain->GetSelectedInstances()[i]->SetZ(cursorPos3D.z() - PreDragInstanceOffset.z());
                }
                else if(currViewAngle == "RIGHT" || currViewAngle == "LEFT")
                {
                    pMain->GetSelectedInstances()[i]->SetY(cursorPos3D.y() - PreDragInstanceOffset.y());
                    pMain->GetSelectedInstances()[i]->SetZ(cursorPos3D.z() - PreDragInstanceOffset.z());
                }
            }
            pMain->UpdateInterface();
        }

    }
    if(currtool == "MODELSPIN")
    {
        Update3DCursor(event->pos());
            for(unsigned int i = 0; i < pMain->GetSelectedInstances().size(); i++)
            {
                pInst = pMain->GetSelectedInstances()[i];

                if(currViewAngle == "FREE" || currViewAngle == "TOP")
                {
                    float theta = qAtan2((cursorPos3D.y() - pInst->GetPos().y())
                                         ,
                                         (cursorPos3D.x()-pInst->GetPos().x()));
                    theta = theta*(180/M_PI);
                    pInst->SetRot(QVector3D(pInst->GetRot().x(),pInst->GetRot().y(),
                                            PreDragRotationOffsetData.y() + (theta - PreDragRotationOffsetData.x())));
                }
                else
                    pInst->Rotate(QVector3D(0,0,mouseDeltaPos.x()*0.2));
            }
            pMain->UpdateInterface();


    }
    if(currtool == "MODELORIENTATE")
    {

            for(unsigned int i = 0; i < pMain->GetSelectedInstances().size(); i++)
            {
                pInst = pMain->GetSelectedInstances()[i];
                pInst->Rotate(QVector3D(mouseDeltaPos.y()*0.2,mouseDeltaPos.x()*0.2,0));
            }
            pMain->UpdateInterface();


    }
    if(currtool == "MODELSCALE")
    {
        for(unsigned int i = 0; i<pMain->GetSelectedInstances().size(); i++)
        {
            //pMain->GetSelectedInstances()[i]->Scale(QVector3D(dx*0.01,dx*0.01,dx*0.01));
            QVector3D cScale = pMain->GetSelectedInstances()[i]->GetScale();

            pMain->GetSelectedInstances()[i]->SetScale(cScale*(1+mouseDeltaPos.x()/50.0));
        }
        pMain->UpdateInterface();

    }
//    pMain->DropSelectionToFloor();
}

void WorldView::OnToolReleaseAction(QString tool, QMouseEvent* event)
{
    B9SupportStructure* pSup;


    hideNonActiveSupports = false;
    pMain->UpdateInterface();
    if(currtool == "MODELSPIN" || currtool == "MODELORIENTATE" || currtool == "MODELSCALE")
    {
        UpdateSelectedBounds();
        pMain->DropSelectionToFloor();//Drop Selection To Floor after SCALE and ORIENTATE
    }
    if(currtool == "MODELMOVE")
    {

    }
    if(currtool == "SUPPORTMODIFY")
    {
        if(pMain->GetSelectedSupports()->size() == 1)
        {
            pSup = pMain->GetSelectedSupports()->at(0);

            if(!pSup->IsPrintable())//if we've released the support in the wrong spot
            {

               pSup->CopyFrom(&toolSupportMemory);//revert
            }
            else
            {

            }
            pSup->DisableErrorGlow();
        }
    }
}

void WorldView::OnToolHoverMove(QString tool, QMouseEvent* event)
{
    B9ModelInstance* pInst;
    if(tool == "SUPPORTADD" || tool == "SUPPORTMODIFY")
    {
       if(!pMain->SupportModeInst())
            return;
       pInst = pMain->SupportModeInst();
       Update3DCursor(event->pos(),pInst);

    }
}



////////////////////////////////////////////////////////////////////
//Private Functions
////////////////////////////////////////////////////////////////////


B9ModelInstance* WorldView::SelectInstanceByScreen(QPoint pos)
{
   unsigned int i;
   unsigned char pixel[3];
   //clear the screen
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glDisable(GL_LIGHTING);

   for(i = 0; i < pMain->GetAllInstances().size();i++)
   {
       pMain->GetAllInstances()[i]->RenderPickGL();
   }

   glReadPixels(pos.x(), this->height() - pos.y(), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glEnable(GL_LIGHTING);

   //now that we have the color, compare it against every instance
   for(i = 0; i < pMain->GetAllInstances().size();i++)
   {
       B9ModelInstance* inst = pMain->GetAllInstances()[i];

       if((pixel[0] == inst->pickcolor[0]) && (pixel[1] == inst->pickcolor[1]) && (pixel[2] == inst->pickcolor[2]))
       {

           pMain->Select(inst);
           return inst;
       }
   }

   return NULL;
}

B9SupportStructure* WorldView::GetSupportByScreen(QPoint pos)
{
    unsigned int i;
    unsigned char pixel[3];
    B9ModelInstance* pInst;
    B9SupportStructure* pSup;

    pInst = pMain->SupportModeInst();
    if(pInst == NULL)
        return NULL;


    //clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_LIGHTING);

    //we need to render the model too so it can occlude hidden supports
    pInst->RenderGL(true);

    for(i = 0; i < pInst->GetSupports().size(); i++)
    {
        pSup = pInst->GetSupports()[i];
        pSup->RenderPickGL(supportAlpha > 0.99 || !pSup->GetIsGrounded(),true);
    }

    glReadPixels(pos.x(), this->height() - pos.y(), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_LIGHTING);

    //now that we have the color, compare it against every instance
    for(i = 0; i < pInst->GetSupports().size();i++)
    {
        pSup = pInst->GetSupports()[i];

        if((pixel[0] == pSup->pickcolor[0]) && (pixel[1] == pSup->pickcolor[1]) && (pixel[2] == pSup->pickcolor[2]))
        {
            return pSup;
        }
    }
    return NULL;
}

QString WorldView::GetSupportSectionByScreen(QPoint pos, B9SupportStructure* sup)
{
    unsigned char pixel[3];

    //clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_LIGHTING);

    sup->RenderPartPickGL(supportAlpha > 0.99 || !sup->GetIsGrounded(),true);//renders all 3 sections in different colors.

    glReadPixels(pos.x(), this->height() - pos.y(), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_LIGHTING);

    if(pixel[0] > 200)
        return "TOP";

    if(pixel[1] > 200)
        return "MID";

    if(pixel[2] > 200)
        return "BOTTOM";

    //else
    return "";
}


//returns global cordinates of mouse position, the plane is centered around hintPos.
//standoff if how much to nudge the plane towards the viewer.
QVector3D WorldView::Get3DCursorOnScreen(QPoint screenPos, QVector3D hintPos, double standoff)
{

    unsigned char pixel[3];//color picked pixel
    QVector3D firstPassPos;
    QVector3D finalPos;

    //clear the screen and set the background to pure green.
    qglClearColor(QColor(0,255,0));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_LIGHTING);
    glDisable(GL_CULL_FACE);//dont cull so we can track from back side too :)
    glPushMatrix();


    //computer standoff vector
    QVector3D standoffv(0,0,1);
    RotateVector(standoffv,-xRot,QVector3D(1,0,0));
    RotateVector(standoffv,-yRot,QVector3D(0,1,0));
    RotateVector(standoffv,-zRot,QVector3D(0,0,1));

    standoffv = standoffv*standoff;

    hintPos += standoffv;

    glTranslatef(hintPos.x(),hintPos.y(),hintPos.z());

    //rotate to face camera and move to hint position
    glRotatef(-zRot,0.0,0.0,1.0);
    glRotatef(-yRot,0.0,1.0,0.0);
    glRotatef(-xRot,1.0,0.0,0.0);


    //In the first pass we will render a very large quad
    //that is 10 times the size of the build area

    //render colored cordinate table
    //255,0,0-------------255,0,255
    //|                       |
    //|                       |
    //|                       |
    //0,0,0----------------0,0,255
    //
    //y cordinate maps to red channel
    //x cordinate maps to blue channel

    glNormal3f(0,0,1.0f);
    glBegin(GL_QUADS);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f( -buildsizex*5, -buildsizey*5, 0);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f( buildsizex*5, -buildsizey*5, 0);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3f( buildsizex*5, buildsizey*5, 0);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f( -buildsizex*5, buildsizey*5, 0);
    glEnd();

    glReadPixels(screenPos.x(), this->height() - screenPos.y(), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);

    //lets map the colors to the first pass course position
    firstPassPos.setX((float(pixel[2])/255.0)*buildsizex*10 - buildsizex*5);
    firstPassPos.setY((float(pixel[0])/255.0)*buildsizey*10 - buildsizey*5);


    //now we are ready to begin second pass based on first pass position
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f( firstPassPos.x() - buildsizex*2*0.039063*0.5, firstPassPos.y() - buildsizey*2*0.039063*0.5, 0);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f( firstPassPos.x() + buildsizex*2*0.039063*0.5, firstPassPos.y() - buildsizey*2*0.039063*0.5, 0);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3f( firstPassPos.x() + buildsizex*2*0.039063*0.5, firstPassPos.y() + buildsizey*2*0.039063*0.5, 0);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f( firstPassPos.x() - buildsizex*2*0.039063*0.5, firstPassPos.y() + buildsizey*2*0.039063*0.5, 0);
    glEnd();

    //re-read pixels for second pass
    glReadPixels(screenPos.x(), this->height() - screenPos.y(), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
    glPopMatrix();

    //set openGl stuff back the way we found it...
    glEnable(GL_LIGHTING);
    glEnable(GL_CULL_FACE);

    qglClearColor(QColor(70,130,0));//cyp 70 130 180


    //if we hit pure green - we've hit the clear color (and vector is unknowns)
    if(pixel[1] > 200)
        return QVector3D(0,0,0);

    //lets map the colors to the real world
    finalPos.setX((float(pixel[2])/255.0)*buildsizex*2*0.039063 - buildsizex*2*0.039063*0.5 + firstPassPos.x());
    finalPos.setY((float(pixel[0])/255.0)*buildsizey*2*0.039063 - buildsizey*2*0.039063*0.5 + firstPassPos.y());
    finalPos.setZ(0.0);

    //bring to real space.
    RotateVector(finalPos,-xRot,QVector3D(1,0,0));
    RotateVector(finalPos,-yRot,QVector3D(0,1,0));
    RotateVector(finalPos,-zRot,QVector3D(0,0,1));

    finalPos += hintPos;

    return finalPos;
}


//Unseen by the user - does a two pass render on the base of the
// track the mouse against the plane given by current view angle
// if an instance is given - it will track against the whole model AS WELL
void WorldView::Update3DCursor(QPoint pos)
{
    bool b;
    Update3DCursor(pos, NULL, b);
}
void WorldView::Update3DCursor(QPoint pos, B9ModelInstance* trackInst)
{
    bool b;
    Update3DCursor(pos, trackInst, b);
}
void WorldView::Update3DCursor(QPoint pos, B9ModelInstance* trackInst, bool &isAgainstInst)
{
    unsigned char pixel[3];//color picked pixel
    QVector3D firstPassPos;
    bool hitInstSuccess;
    unsigned int hitTri;

    isAgainstInst = false;

    //before starting plane tracking - see if we hit the instance
    if(trackInst != NULL)
    {

        hitTri = GetPickTriangleIndx(trackInst,pos,hitInstSuccess);
        if( hitInstSuccess )
        {
            isAgainstInst = true;
            cursorPos3D = GetPickOnTriangle(pos,trackInst,hitTri) + trackInst->GetPos();
            cursorNormal3D = trackInst->triList[hitTri]->normal;

            return;
        }
    }

    //clear the screen and set the background to pure green.
    qglClearColor(QColor(0,255,0));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_LIGHTING);
    glDisable(GL_CULL_FACE);//dont cull so we can track from back side too :)
    glPushMatrix();
    //Depending on the current view angle - we may want the cursor canvas
    //vertical and/or rotated
    if(currViewAngle == "FREE" || currViewAngle == "TOP" || currViewAngle == "BOTTOM")
        glRotatef(0.0f,0.0f,0.0f,1.0f);//no rotating - put on ground
    else if(currViewAngle == "FRONT" || currViewAngle == "BACK"){
        glRotatef(-90.0f,1.0f,0.0f,0.0f);
    }
    else if(currViewAngle == "RIGHT" || currViewAngle == "LEFT")
    {
        glRotatef(-90.0f,0.0f,0.0f,1.0f);
        glRotatef(-90.0f,1.0f,0.0f,0.0f);
    }

    //In the first pass we will render a very large quad
    //that is 10 times the size of the build area

    //render colored cordinate table
    //255,0,0-------------255,0,255
    //|                       |
    //|                       |
    //|                       |
    //0,0,0----------------0,0,255
    //
    //y cordinate maps to red channel
    //x cordinate maps to blue channel

    glNormal3f(0,0,1.0f);
    glBegin(GL_QUADS);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f( -buildsizex*5, -buildsizey*5, 0);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f( buildsizex*5, -buildsizey*5, 0);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3f( buildsizex*5, buildsizey*5, 0);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f( -buildsizex*5, buildsizey*5, 0);
    glEnd();

    glReadPixels(pos.x(), this->height() - pos.y(), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);

    //lets map the colors to the first pass course position
    firstPassPos.setX((float(pixel[2])/255.0)*buildsizex*10 - buildsizex*5);
    firstPassPos.setY((float(pixel[0])/255.0)*buildsizey*10 - buildsizey*5);


    //now we are ready to begin second pass based on first pass position
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f( firstPassPos.x() - buildsizex*2*0.039063*0.5, firstPassPos.y() - buildsizey*2*0.039063*0.5, 0);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f( firstPassPos.x() + buildsizex*2*0.039063*0.5, firstPassPos.y() - buildsizey*2*0.039063*0.5, 0);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3f( firstPassPos.x() + buildsizex*2*0.039063*0.5, firstPassPos.y() + buildsizey*2*0.039063*0.5, 0);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f( firstPassPos.x() - buildsizex*2*0.039063*0.5, firstPassPos.y() + buildsizey*2*0.039063*0.5, 0);
    glEnd();
    //re-read pixels for second pass
    glReadPixels(pos.x(), this->height() - pos.y(), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
    glPopMatrix();

    //set openGl stuff back the way we found it...
    glEnable(GL_LIGHTING);
    glEnable(GL_CULL_FACE);

    qglClearColor(bkgcolor);//cyp240,240,240


    //if we hit pure green - we've hit the clear color and dont want to make any changes
    if(pixel[1] > 200)
        return;


    //lets map the colors to the real world
    if(currViewAngle == "FREE" || currViewAngle == "TOP" || currViewAngle == "BOTTOM"){
        cursorPos3D.setX((float(pixel[2])/255.0)*buildsizex*2*0.039063 - buildsizex*2*0.039063*0.5 + firstPassPos.x());
        cursorPos3D.setY((float(pixel[0])/255.0)*buildsizey*2*0.039063 - buildsizey*2*0.039063*0.5 + firstPassPos.y());
        cursorPos3D.setZ(0.0);
        cursorNormal3D = QVector3D(0,0,1);
        cursorPosOnTrackCanvas.setX(cursorPos3D.x());
        cursorPosOnTrackCanvas.setY(cursorPos3D.y());
    }
    else if(currViewAngle == "FRONT" || currViewAngle == "BACK"){
        cursorPos3D.setX((float(pixel[2])/256.0)*buildsizex*2*0.039063 - buildsizex*2*0.039063*0.5 + firstPassPos.x());
        cursorPos3D.setY(0.0);
        cursorPos3D.setZ(-((float(pixel[0])/256.0)*buildsizey*2*0.039063 - buildsizey*2*0.039063*0.5 + firstPassPos.y()));
        cursorNormal3D = QVector3D(0,1,0);
        cursorPosOnTrackCanvas.setX(cursorPos3D.x());
        cursorPosOnTrackCanvas.setY(cursorPos3D.z());
    }
    else if(currViewAngle == "RIGHT" || currViewAngle == "LEFT")
    {
        cursorPos3D.setX(0.0);
        cursorPos3D.setY(-((float(pixel[2])/255.0)*buildsizex*2*0.039063 - buildsizex*2*0.039063*0.5 + firstPassPos.x()));
        cursorPos3D.setZ(-((float(pixel[0])/255.0)*buildsizey*2*0.039063 - buildsizey*2*0.039063*0.5 + firstPassPos.y()));
        cursorNormal3D = QVector3D(1,0,0);
        cursorPosOnTrackCanvas.setX(cursorPos3D.y());
        cursorPosOnTrackCanvas.setY(cursorPos3D.z());
    }
}

unsigned int WorldView::GetPickTriangleIndx(B9ModelInstance* inst, QPoint pos, bool &success)
{
    unsigned char pixel[3];

    if(inst == NULL)
    {
        success = false;
        return 0;
    }

    //clear the screen
    qglClearColor(QColor(0,0,0));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_LIGHTING);

    inst->RenderTrianglePickGL();

    glReadPixels(pos.x(), this->height() - pos.y(), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);

    qglClearColor(bkgcolor);//cyp
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_LIGHTING);


    //now that we have the color, we should know what triangle index it is.
    //if the color is 0,0,0, then we missed the model
    unsigned int result = pixel[0]*1 + pixel[1]*256 + pixel[2]*65536;

    if(!result)
    {
        success = false;
        return 0;
    }
    else
    {
        if((result - 1) < inst->triList.size())//make sure the indx is in a valid range!
        {                                //just in case..
            success = true;
            return result - 1;//to get actual index
        }
        else
        {
            success = false;
            return 0;
        }

    }
}
//return position relative to instance center!
QVector3D WorldView::GetPickOnTriangle(QPoint pos, B9ModelInstance* inst, unsigned int triIndx)
{
    unsigned char pixel[3];

    //clear the screen
    qglClearColor(QColor(128,128,128));// so if by chance we miss it will be center bounds
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_LIGHTING);

    inst->RenderSingleTrianglePickGL(triIndx);

    glReadPixels(pos.x(), this->height() - pos.y(), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);

    double xPercent = float(pixel[0])/256.0;
    double yPercent = float(pixel[1])/256.0;
    double zPercent = float(pixel[2])/256.0;
    QVector3D Slew(xPercent,yPercent,zPercent);

    QVector3D minBound = inst->triList[triIndx]->minBound;
    QVector3D maxBound = inst->triList[triIndx]->maxBound;

    QVector3D globalPos = minBound + (maxBound - minBound)*Slew;


    QVector3D localPos = globalPos - inst->GetPos();


    qglClearColor(bkgcolor);//cyp
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_LIGHTING);

    return localPos;

}

//returns local position on the instance
QVector3D WorldView::GetDrillingHit(QVector3D localBeginPosition, B9ModelInstance *inst, bool &hitground, Triangle3D *&pTri)
{
    unsigned int hitTri;
    const float viewRad = 1.0;
    const float nearPlane = 0.5;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //lets set up a ortho view facing down from the begining position.
    glOrtho((inst->GetPos().x() + localBeginPosition.x()) - viewRad,
            (inst->GetPos().x() + localBeginPosition.x()) + viewRad,
            (inst->GetPos().y() + localBeginPosition.y()) - viewRad,
            (inst->GetPos().y() + localBeginPosition.y()) + viewRad,
            nearPlane,
            (inst->GetMaxBound().z() - inst->GetMinBound().z()));

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //move the "camera" into the right position.
    glTranslatef(0.0f,
                 0.0f,
                 -(inst->GetPos().z() + localBeginPosition.z()));

    bool s;
    hitTri = GetPickTriangleIndx(inst, QPoint(this->width()/2,this->height()/2), s);
    if(!s)
    {
        hitground = true;
        pTri = NULL;
        return QVector3D(0,0,0);
    }

    hitground = false;
    pTri = inst->triList[hitTri];
    return GetPickOnTriangle(QPoint(this->width()/2,this->height()/2),inst,hitTri);
}




void WorldView::UpdateVisSlice()
{

    B9ModelInstance* pInst;
    if((currtool != "SUPPORTADD" && currtool != "SUPPORTMODIFY")/* || !pMain->ContourAidEnabled()*/)
    {
        if(pVisSlice)
            delete pVisSlice;
        pVisSlice = NULL;
        return;
    }
    if(pMain->SupportModeInst() == NULL)
        return;

    pInst = pMain->SupportModeInst();


    if(pVisSlice != NULL)
    {
        delete pVisSlice;
    }

    pVisSlice = new Slice(cursorPos3D.z(),0);
    pVisSlice->GenerateSegments(pInst);



}

