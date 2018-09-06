/****************************************************************************
** Meta object code from reading C++ file 'printwindow.h'
**
** Created: Wed Sep 5 16:46:30 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../printwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ComboBoxMaterialItemDelegate[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_ComboBoxMaterialItemDelegate[] = {
    "ComboBoxMaterialItemDelegate\0"
};

void ComboBoxMaterialItemDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ComboBoxMaterialItemDelegate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ComboBoxMaterialItemDelegate::staticMetaObject = {
    { &QStyledItemDelegate::staticMetaObject, qt_meta_stringdata_ComboBoxMaterialItemDelegate,
      qt_meta_data_ComboBoxMaterialItemDelegate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ComboBoxMaterialItemDelegate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ComboBoxMaterialItemDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ComboBoxMaterialItemDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ComboBoxMaterialItemDelegate))
        return static_cast<void*>(const_cast< ComboBoxMaterialItemDelegate*>(this));
    return QStyledItemDelegate::qt_metacast(_clname);
}

int ComboBoxMaterialItemDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_PrintWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      24,   12,   12,   12, 0x0a,
      41,   12,   12,   12, 0x0a,
      71,   66,   12,   12, 0x0a,
      96,   66,   12,   12, 0x0a,
     127,  121,   12,   12, 0x0a,
     150,  144,   12,   12, 0x08,
     189,   12,   12,   12, 0x08,
     228,   12,   12,   12, 0x08,
     262,   12,   12,   12, 0x08,
     291,   12,   12,   12, 0x08,
     325,   12,   12,   12, 0x08,
     363,  358,   12,   12, 0x08,
     405,  358,   12,   12, 0x08,
     452,  358,   12,   12, 0x08,
     490,  358,   12,   12, 0x08,
     535,  358,   12,   12, 0x08,
     580,  358,   12,   12, 0x08,
     629,   12,   12,   12, 0x08,
     661,   12,   12,   12, 0x08,
     694,   12,   12,   12, 0x08,
     724,   12,   12,   12, 0x08,
     763,  358,   12,   12, 0x08,
     801,  358,   12,   12, 0x08,
     839,  358,   12,   12, 0x08,
     886,  358,   12,   12, 0x08,
     932,   12,   12,   12, 0x08,
     964,  358,   12,   12, 0x08,
    1009,   12,   12,   12, 0x08,
    1047,   12,   12,   12, 0x08,
    1077,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PrintWindow[] = {
    "PrintWindow\0\0accepted()\0setPrintEnable()\0"
    "OnSetProjectorPowerOff()\0text\0"
    "onSetCommStatus(QString)\0"
    "onSetProjStatus(QString)\0index\0"
    "setMaterial(int)\0sText\0"
    "onBC_ConnectionStatusDetailed(QString)\0"
    "on_pushButtonMaterialCatalog_clicked()\0"
    "on_pushButtonCycSetting_clicked()\0"
    "on_pushButtonPrint_clicked()\0"
    "on_lineEditTgtPos_returnPressed()\0"
    "on_pushButtonSelectAll_clicked()\0arg1\0"
    "on_spinBoxLayersToPrint_valueChanged(int)\0"
    "on_doubleSpinBoxTattachMS_valueChanged(double)\0"
    "on_spinBoxNumAttach_valueChanged(int)\0"
    "on_doubleSpinBoxTbaseMS_valueChanged(double)\0"
    "on_doubleSpinBoxToverMS_valueChanged(double)\0"
    "on_comboBoxMaterial_currentIndexChanged(QString)\0"
    "on_pushButtonCmdReset_clicked()\0"
    "on_pushButtonShowSlice_clicked()\0"
    "on_pushButtonBrowse_clicked()\0"
    "on_pushButtonRestoreDefaults_clicked()\0"
    "on_spinBoxRaiseSpd1_valueChanged(int)\0"
    "on_spinBoxLowerSpd1_valueChanged(int)\0"
    "on_doubleSpinBoxOverlift1_valueChanged(double)\0"
    "on_doubleSpinBoxBreathe1_valueChanged(double)\0"
    "on_pushButtonTerminal_clicked()\0"
    "on_spinBox_BlueLEDExposure_valueChanged(int)\0"
    "on_pushButton_MaterialsEdit_clicked()\0"
    "onBC_UpdateMaterialsCatalog()\0"
    "on_toolButtonAdvanced_clicked()\0"
};

void PrintWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PrintWindow *_t = static_cast<PrintWindow *>(_o);
        switch (_id) {
        case 0: _t->accepted(); break;
        case 1: _t->setPrintEnable(); break;
        case 2: _t->OnSetProjectorPowerOff(); break;
        case 3: _t->onSetCommStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onSetProjStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setMaterial((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onBC_ConnectionStatusDetailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_pushButtonMaterialCatalog_clicked(); break;
        case 8: _t->on_pushButtonCycSetting_clicked(); break;
        case 9: _t->on_pushButtonPrint_clicked(); break;
        case 10: _t->on_lineEditTgtPos_returnPressed(); break;
        case 11: _t->on_pushButtonSelectAll_clicked(); break;
        case 12: _t->on_spinBoxLayersToPrint_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_doubleSpinBoxTattachMS_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->on_spinBoxNumAttach_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_doubleSpinBoxTbaseMS_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->on_doubleSpinBoxToverMS_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->on_comboBoxMaterial_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->on_pushButtonCmdReset_clicked(); break;
        case 19: _t->on_pushButtonShowSlice_clicked(); break;
        case 20: _t->on_pushButtonBrowse_clicked(); break;
        case 21: _t->on_pushButtonRestoreDefaults_clicked(); break;
        case 22: _t->on_spinBoxRaiseSpd1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_spinBoxLowerSpd1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_doubleSpinBoxOverlift1_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->on_doubleSpinBoxBreathe1_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: _t->on_pushButtonTerminal_clicked(); break;
        case 27: _t->on_spinBox_BlueLEDExposure_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_pushButton_MaterialsEdit_clicked(); break;
        case 29: _t->onBC_UpdateMaterialsCatalog(); break;
        case 30: _t->on_toolButtonAdvanced_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PrintWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PrintWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PrintWindow,
      qt_meta_data_PrintWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PrintWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PrintWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PrintWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrintWindow))
        return static_cast<void*>(const_cast< PrintWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int PrintWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void PrintWindow::accepted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
