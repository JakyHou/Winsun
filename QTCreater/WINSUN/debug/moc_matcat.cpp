/****************************************************************************
** Meta object code from reading C++ file 'matcat.h'
**
** Created: Fri Aug 31 18:08:18 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../matcat.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'matcat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_B9MatCat[] = {

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
      29,   10,    9,    9, 0x0a,
      90,   58,    9,    9, 0x0a,
     121,    9,    9,    9, 0x0a,
     145,  134,  129,    9, 0x0a,
     159,    9,  129,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_B9MatCat[] = {
    "B9MatCat\0\0sName,sDescription\0"
    "addMaterial(QString,QString)\0"
    "sName,sDescription,iOriginIndex\0"
    "addDupMat(QString,QString,int)\0clear()\0"
    "bool\0sModelName\0load(QString)\0save()\0"
};

void B9MatCat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        B9MatCat *_t = static_cast<B9MatCat *>(_o);
        switch (_id) {
        case 0: _t->addMaterial((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->addDupMat((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->clear(); break;
        case 3: { bool _r = _t->load((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData B9MatCat::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject B9MatCat::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_B9MatCat,
      qt_meta_data_B9MatCat, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &B9MatCat::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *B9MatCat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *B9MatCat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_B9MatCat))
        return static_cast<void*>(const_cast< B9MatCat*>(this));
    return QObject::qt_metacast(_clname);
}

int B9MatCat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
