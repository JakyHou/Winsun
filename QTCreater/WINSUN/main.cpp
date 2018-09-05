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

#include <QtGui/QApplication>
#include <QSplashScreen>
//#include "nativeapp.h"
#include <QDir>
#include <mainwindow.h>
#include <windows.h>
#define VERSIONINFO "Version 1.0.0     Copyright 2018 , Nepho3d_Studio     www.nepho3d.com\n "

int main(int argc, char *argv[])
{
    //Save user settings parameters(eg.supportparameter materialscatalog...)
    QCoreApplication::setOrganizationDomain("Nepho3d.com");//?
    QCoreApplication::setOrganizationName("Nepho3d, LLC");
    QCoreApplication::setApplicationName("Nepho3d");

    //Avoid garbled characters
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
      QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF8"));//
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));

//      QCoreApplication::setOrganizationDomain("winsun.com");

      QApplication a(argc, argv);
//      //Software startup interface
//      QPixmap pixmap("logo.png");//image
//      QSplashScreen splash;
//      splash.setPixmap(pixmap);
//      splash.showMessage(VERSIONINFO,Qt::AlignBottom|Qt::AlignCenter,QColor(130,130,255));

      MainWindow w(GetSystemMetrics(SM_CXFULLSCREEN),GetSystemMetrics(SM_CYFULLSCREEN));//Ö÷½çÃæ

//      splash.show();
//      Sleep(1000);
      w.t->m_cx = GetSystemMetrics(SM_CXFULLSCREEN);
      w.show();

      //Whether to display the printsettingdialog
      QSettings appSettings;
//      appSettings.remove("USERSET");
      appSettings.beginGroup("USERSET");
      if(appSettings.value("AppearDLG","YES") == "YES"){
          w.pPriSetDlg->showIt();
      }
      appSettings.endGroup();

//      splash.hide();
      return a.exec();
}
