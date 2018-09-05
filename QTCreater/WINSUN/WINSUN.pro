#-------------------------------------------------
#
# Project created by QtCreator 2012-10-29T17:44:17
#
#-------------------------------------------------

#************************************************************************************
#
#  LICENSE INFORMATION
#
#  BCreator(tm)
#  Software for the control of the 3D Printer, "Creator"(tm)
#
#  Copyright 2011-2012 Creations, LLC
#  Creations(tm) and Creator(tm) are trademarks of Creations, LLC
#
#  This file is part of Creator
#
#    Creator is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    Creator is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with Creator .  If not, see <http://www.gnu.org/licenses/>.
#
#  The above copyright notice and this permission notice shall be
#    included in all copies or substantial portions of the Software.
#
#    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
#    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
#    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
#    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#*************************************************************************************

QT       += core gui
QT       += svg
QT       += opengl
QT       += network

TEMPLATE = app

INCLUDEPATH += slice
INCLUDEPATH += edit
INCLUDEPATH += create

SOURCES += main.cpp\
            dlpc350_common.cpp \
            dlpc350_usb.cpp \
            dlpc350_api.cpp \
            dlpc350_BMPParser.cpp \
            dlpc350_firmware.cpp \
        mainwindow.cpp \
    logfilemanager.cpp \
    loadingbar.cpp \
    crushbitmap.cpp \
    edit/floodfill.cpp \
    edit/DrawingContext.cpp \
    helpsystem.cpp \
    layout/worldview.cpp \
    layout/triangle3d.cpp \
    layout/sliceset.cpp \
    layout/slicecontext.cpp \
    layout/SlcExporter.cpp \
    layout/segment.cpp \
    layout/modeldata.cpp \
    layout/loop.cpp \
    layout/slice.cpp \
    OS_Wrapper_Functions.cpp \
    screensaverwaker.cpp \
    layout/geometricfunctions.cpp \
    terminal.cpp \
    showslices.cpp \
    printwindow.cpp \
    print.cpp \
    materialscatalog.cpp \
    cycleprintsetting.cpp \
    buildspace.cpp \
    supportsetting.cpp \
    modellist.cpp \
    supportparameter.cpp \
    myballon.cpp \
    sizewidget.cpp \
    positionwidget.cpp \
    orientationwidget.cpp \
    viewwidget.cpp \
    statuswidget.cpp \
    sliceslider.cpp \
    uart.cpp \
    Queue.cpp \
    Delay.cpp \
    CRC32.cpp \
    CRC16.cpp \
    Command.cpp \
    printsettingdialog.cpp \
    layout/layoutprojectdata.cpp \
    layout/verticaltricontainer.cpp \
    layout/tesselator.cpp \
    layout/modelinstance.cpp \
    matcat.cpp \
    material.cpp \
    updatemanager.cpp \
    supportstructure.cpp \
    projector.cpp \
    printermodelmanager.cpp \
    printermodeldata.cpp \
    printercomm.cpp \
    nativeapp.cpp \
    modelwriter.cpp \
    modelloader.cpp \
    slicedialog.cpp

HEADERS  += mainwindow.h \
            dlpc350_usb.h \
            dlpc350_api.h \
            dlpc350_BMPParser.h \
            dlpc350_firmware.h \
            dlpc350_version.h \
            dlpc350_common.h \
            dlpc350_flashDevice.h \
            Helper.h \
            dlpc350_error.h \
    logfilemanager.h \
    loadingbar.h \
    crushbitmap.h \
    edit/SliceEditView.h \
    edit/floodfill.h \
    edit/DrawingContext.h \
    helpsystem.h \
    layout/worldview.h \
    layout/triangle3d.h \
    layout/sliceset.h \
    layout/slicecontext.h \
    layout/SlcExporter.h \
    layout/segment.h \
    layout/modeldata.h \
    layout/loop.h \
    layout/slice.h \
    OS_GL_Wrapper.h \
    OS_Wrapper_Functions.h \
    screensaverwaker.h \
    layout/geometricfunctions.h \
    terminal.h \
    showslices.h \
    printwindow.h \
    print.h \
    materialscatalog.h \
    cycleprintsetting.h \
    buildspace.h \
    supportsetting.h \
    modellist.h \
    supportparameter.h \
    WindowsResources/version.h \
    myballon.h \
    sizewidget.h \
    positionwidget.h \
    orientationwidget.h \
    viewwidget.h \
    statuswidget.h \
    sliceslider.h \
    uart.h \
    resource.h \
    Queue.h \
    Delay.h \
    Command.h \
    cnComm.h \
    printsettingdialog.h \
    layout/layoutprojectdata.h \
    layout/modelinstance.h \
    layout/verticaltricontainer.h \
    layout/tesselator.h \
    matcat.h \
    updatemanager.h \
    updateentry.h \
    supportstructure.h \
    projector.h \
    printermodelmanager.h \
    printermodeldata.h \
    printercomm.h \
    nativeapp.h \
    modelwriter.h \
    modelloader.h \
    material.h \
    slicedialog.h

INCLUDEPATH += "hidapi-master\\hidapi"

FORMS    += mainwindow.ui \
    terminal.ui \
    showslices.ui \
    printwindow.ui \
    print.ui \
    materialscatalog.ui \
    cycleprintsetting.ui \
    buildspace.ui \
    supportsetting.ui \
    modellist.ui \
    supportparameter.ui \
    sizewidget.ui \
    positionwidget.ui \
    orientationwidget.ui \
    viewwidget.ui \
    statuswidget.ui \
    sliceslider.ui \
    printsettingdialog.ui \
    slicedialog.ui

RESOURCES += \
    edit/sliceeditview.qrc \
    edit/edit.qrc

# Icons
#macx{
#ICON = icons/LCr4500.icns
#}

win32{
#RC_FILE = icons\LCr4500.rc
#Recource File For Windows
#Includes information for app icon
RC_FILE = WindowsResources/b9c_win_resources.rc

#In windows this application needs elevated privileges to do self updates.
#QMAKE_LFLAGS += /MANIFESTUAC:\"level=\'requireAdministrator\' uiAccess=\'false\'\"

TARGET = Nepho3d_Studio
}

win32:CONFIG(release, debug|release): LIBS += -L../WINSUN/hidapi-master/windows/release/ -lhidapi
else:win32:CONFIG(debug, debug|release): LIBS += -L../WINSUN/hidapi-master/windows/debug/ -lhidapi
##macx: SOURCES += ../GUI/hidapi-master/mac/hid.c
##unix: !macx: SOURCES += ../GUI/hidapi-master/linux/hid.c

#macx: LIBS += -framework CoreFoundation -framework IOkit
#win32: LIBS += -lSetupAPI
#unix: !macx: LIBS += -lusb-1.0 -ludev

INCLUDEPATH += ../WINSUN/hidapi-master/hidapi
DEPENDPATH += ../WINSUN/hidapi-master/hidapi

include(qextserialport-1.2beta2/src/qextserialport.pri)

OTHER_FILES += \
                icons\LCr4500.rc \
                icons\LCr4500.ico \
    documentation/wildcardmatching.html \
    documentation/creator.qhp \
    documentation/creator.qhcp \
    documentation/creator.qhc \
    documentation/creator.qch \
    documentation/openfile.html \
    documentation/intro.html \
    documentation/index.html \
    documentation/findfile.html \
    documentation/filedialog.html \
    documentation/browse.html \
    documentation/about.txt \
    documentation/images/wildcard.png \
    documentation/images/open.png \
    documentation/images/mainwindow.png \
    documentation/images/icon.png \
    documentation/images/handbook.png \
    documentation/images/filedialog.png \
    documentation/images/fadedfilemenu.png \
    documentation/images/browse.png \
    WindowsResources/logo1.ico \
    WindowsResources/b9c_win_resources.rc \
    Creator.pro.user \
    WindowsResources/logo.png \
    WindowsResources/ReadMe.txt \
    WindowsResources/logo5.ico \
    WindowsResources/logo1.ico \
    WindowsResources/logo.png \
    WindowsResources/b9c_win_resources.rc \
    WindowsResources/b9c_icon.ico \
    trans/zh.ts \
    trans/zh.qm \
    trans/en.ts \
    trans/en.qm

TRANSLATIONS += trans/zh.ts \
                trans/en.ts


