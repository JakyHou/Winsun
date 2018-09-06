/****************************************************************************
** Meta object code from reading C++ file 'layoutprojectdata.h'
**
** Created: Wed Sep 5 16:46:59 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../layout/layoutprojectdata.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'layoutprojectdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_B9LayoutProjectData[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   21,   20,   20, 0x05,
      44,   20,   20,   20, 0x05,
      62,   60,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_B9LayoutProjectData[] = {
    "B9LayoutProjectData\0\0dirt\0DirtChanged(bool)\0"
    "ProjectLoaded()\0,\0"
    "PercentCompletedUpdate(qint64,qint64)\0"
};

void B9LayoutProjectData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        B9LayoutProjectData *_t = static_cast<B9LayoutProjectData *>(_o);
        switch (_id) {
        case 0: _t->DirtChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ProjectLoaded(); break;
        case 2: _t->PercentCompletedUpdate((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData B9LayoutProjectData::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject B9LayoutProjectData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_B9LayoutProjectData,
      qt_meta_data_B9LayoutProjectData, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &B9LayoutProjectData::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *B9LayoutProjectData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *B9LayoutProjectData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_B9LayoutProjectData))
        return static_cast<void*>(const_cast< B9LayoutProjectData*>(this));
    return QObject::qt_metacast(_clname);
}

int B9LayoutProjectData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void B9LayoutProjectData::DirtChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void B9LayoutProjectData::ProjectLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void B9LayoutProjectData::PercentCompletedUpdate(qint64 _t1, qint64 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
