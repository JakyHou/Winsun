/****************************************************************************
** Meta object code from reading C++ file 'supportsetting.h'
**
** Created: Wed Sep 5 16:46:38 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../supportsetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'supportsetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SupportSetting[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      55,   15,   15,   15, 0x08,
      87,   81,   15,   15, 0x08,
     149,   81,   15,   15, 0x08,
     211,   81,   15,   15, 0x08,
     276,   81,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SupportSetting[] = {
    "SupportSetting\0\0on_pushButtonRestoreDefaults_clicked()\0"
    "on_pushButtonOK_clicked()\0value\0"
    "on_Support_Top_Penetration_horizontalSlider_valueChanged(int)\0"
    "on_Support_Top_AngleFactor_horizontalSlider_valueChanged(int)\0"
    "on_Support_Bottom_Penetration_horizontalSlider_valueChanged(int)\0"
    "on_Support_Bottom_AngleFactor_horizontalSlider_valueChanged(int)\0"
};

void SupportSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SupportSetting *_t = static_cast<SupportSetting *>(_o);
        switch (_id) {
        case 0: _t->on_pushButtonRestoreDefaults_clicked(); break;
        case 1: _t->on_pushButtonOK_clicked(); break;
        case 2: _t->on_Support_Top_Penetration_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_Support_Top_AngleFactor_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_Support_Bottom_Penetration_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_Support_Bottom_AngleFactor_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SupportSetting::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SupportSetting::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SupportSetting,
      qt_meta_data_SupportSetting, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SupportSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SupportSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SupportSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SupportSetting))
        return static_cast<void*>(const_cast< SupportSetting*>(this));
    return QDialog::qt_metacast(_clname);
}

int SupportSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
