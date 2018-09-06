/****************************************************************************
** Meta object code from reading C++ file 'showslices.h'
**
** Created: Wed Sep 5 16:46:28 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../showslices.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showslices.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ShowSlices[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      28,   26,   11,   11, 0x05,
      56,   26,   11,   11, 0x05,
      76,   26,   11,   11, 0x05,
      93,   26,   11,   11, 0x05,
     117,   26,   11,   11, 0x05,
     137,   26,   11,   11, 0x05,
     156,   26,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     183,   11,   11,   11, 0x0a,
     218,  206,   11,   11, 0x0a,
     233,   11,   11,   11, 0x0a,
     270,  257,   11,   11, 0x0a,
     296,  291,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ShowSlices[] = {
    "ShowSlices\0\0eventHiding()\0s\0"
    "selectedDirChanged(QString)\0"
    "setVersion(QString)\0setName(QString)\0"
    "setDescription(QString)\0setXYPixel(QString)\0"
    "setZLayer(QString)\0setSliceIndicator(QString)\0"
    "setCurNumOfLayers(int)\0slicenumber\0"
    "GoToSlice(int)\0DeCompressIntoContext()\0"
    "alreadywhite\0RefreshContext(bool)\0"
    "arg1\0on_spinBoxCurNumOfLayers_valueChanged(int)\0"
};

void ShowSlices::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ShowSlices *_t = static_cast<ShowSlices *>(_o);
        switch (_id) {
        case 0: _t->eventHiding(); break;
        case 1: _t->selectedDirChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setVersion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setDescription((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setXYPixel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setZLayer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setSliceIndicator((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setCurNumOfLayers((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->GoToSlice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->DeCompressIntoContext(); break;
        case 11: _t->RefreshContext((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_spinBoxCurNumOfLayers_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ShowSlices::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ShowSlices::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ShowSlices,
      qt_meta_data_ShowSlices, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ShowSlices::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ShowSlices::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ShowSlices::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ShowSlices))
        return static_cast<void*>(const_cast< ShowSlices*>(this));
    return QWidget::qt_metacast(_clname);
}

int ShowSlices::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ShowSlices::eventHiding()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ShowSlices::selectedDirChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ShowSlices::setVersion(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ShowSlices::setName(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ShowSlices::setDescription(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ShowSlices::setXYPixel(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ShowSlices::setZLayer(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ShowSlices::setSliceIndicator(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
