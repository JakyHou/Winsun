/****************************************************************************
** Meta object code from reading C++ file 'cycleprintsetting.h'
**
** Created: Wed Sep 5 10:48:28 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cycleprintsetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cycleprintsetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CyclePrintSetting[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      58,   18,   18,   18, 0x08,
      81,   18,   18,   18, 0x08,
     107,   18,   18,   18, 0x08,
     131,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CyclePrintSetting[] = {
    "CyclePrintSetting\0\0"
    "on_pushButtonRestoreDefaults_clicked()\0"
    "on_buttonBox_clicked()\0on_pushButtonOK_clicked()\0"
    "on_buttonBox_accepted()\0on_buttonBox_rejected()\0"
};

void CyclePrintSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CyclePrintSetting *_t = static_cast<CyclePrintSetting *>(_o);
        switch (_id) {
        case 0: _t->on_pushButtonRestoreDefaults_clicked(); break;
        case 1: _t->on_buttonBox_clicked(); break;
        case 2: _t->on_pushButtonOK_clicked(); break;
        case 3: _t->on_buttonBox_accepted(); break;
        case 4: _t->on_buttonBox_rejected(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CyclePrintSetting::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CyclePrintSetting::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CyclePrintSetting,
      qt_meta_data_CyclePrintSetting, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CyclePrintSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CyclePrintSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CyclePrintSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CyclePrintSetting))
        return static_cast<void*>(const_cast< CyclePrintSetting*>(this));
    return QDialog::qt_metacast(_clname);
}

int CyclePrintSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
