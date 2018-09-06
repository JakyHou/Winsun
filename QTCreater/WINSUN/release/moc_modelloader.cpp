/****************************************************************************
** Meta object code from reading C++ file 'modelloader.h'
**
** Created: Mon Sep 3 14:54:12 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../modelloader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modelloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_B9ModelLoader[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   15,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_B9ModelLoader[] = {
    "B9ModelLoader\0\0frac,total\0"
    "PercentCompletedUpdate(qint64,qint64)\0"
};

void B9ModelLoader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        B9ModelLoader *_t = static_cast<B9ModelLoader *>(_o);
        switch (_id) {
        case 0: _t->PercentCompletedUpdate((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData B9ModelLoader::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject B9ModelLoader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_B9ModelLoader,
      qt_meta_data_B9ModelLoader, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &B9ModelLoader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *B9ModelLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *B9ModelLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_B9ModelLoader))
        return static_cast<void*>(const_cast< B9ModelLoader*>(this));
    return QObject::qt_metacast(_clname);
}

int B9ModelLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void B9ModelLoader::PercentCompletedUpdate(qint64 _t1, qint64 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
