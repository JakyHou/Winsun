/****************************************************************************
** Meta object code from reading C++ file 'supportparameter.h'
**
** Created: Wed Sep 5 16:46:42 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../supportparameter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'supportparameter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SupportParameter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   40,   17,   17, 0x08,
      80,   40,   17,   17, 0x08,
     115,   17,   17,   17, 0x08,
     147,   17,   17,   17, 0x08,
     192,  186,   17,   17, 0x08,
     254,  186,   17,   17, 0x08,
     316,  186,   17,   17, 0x08,
     381,  186,   17,   17, 0x08,
     446,   40,   17,   17, 0x08,
     476,   17,   17,   17, 0x08,
     511,   17,   17,   17, 0x08,
     543,   17,   17,   17, 0x08,
     571,  186,   17,   17, 0x08,
     631,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SupportParameter[] = {
    "SupportParameter\0\0setSupportWidget(int)\0"
    "checked\0on_radioButtonAdd_toggled(bool)\0"
    "on_radioButtonDelete_toggled(bool)\0"
    "on_pushButtonCleanAll_clicked()\0"
    "on_pushButtonRestoreDefaults_clicked()\0"
    "value\0"
    "on_Support_Top_Penetration_horizontalSlider_valueChanged(int)\0"
    "on_Support_Top_AngleFactor_horizontalSlider_valueChanged(int)\0"
    "on_Support_Bottom_Penetration_horizontalSlider_valueChanged(int)\0"
    "on_Support_Bottom_AngleFactor_horizontalSlider_valueChanged(int)\0"
    "on_checkBoxBase_toggled(bool)\0"
    "on_pushButtonAutoSupport_clicked()\0"
    "on_toolButtonAdvanced_clicked()\0"
    "on_pushButtonSave_clicked()\0"
    "on_Support_Base_Coverage_horizontalSlider_valueChanged(int)\0"
    "on_doubleSpinBoxDensity_editingFinished()\0"
};

void SupportParameter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SupportParameter *_t = static_cast<SupportParameter *>(_o);
        switch (_id) {
        case 0: _t->setSupportWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_radioButtonAdd_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_radioButtonDelete_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_pushButtonCleanAll_clicked(); break;
        case 4: _t->on_pushButtonRestoreDefaults_clicked(); break;
        case 5: _t->on_Support_Top_Penetration_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_Support_Top_AngleFactor_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_Support_Bottom_Penetration_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_Support_Bottom_AngleFactor_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_checkBoxBase_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_pushButtonAutoSupport_clicked(); break;
        case 11: _t->on_toolButtonAdvanced_clicked(); break;
        case 12: _t->on_pushButtonSave_clicked(); break;
        case 13: _t->on_Support_Base_Coverage_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_doubleSpinBoxDensity_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SupportParameter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SupportParameter::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SupportParameter,
      qt_meta_data_SupportParameter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SupportParameter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SupportParameter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SupportParameter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SupportParameter))
        return static_cast<void*>(const_cast< SupportParameter*>(this));
    return QWidget::qt_metacast(_clname);
}

int SupportParameter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void SupportParameter::setSupportWidget(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
