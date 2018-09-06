/****************************************************************************
** Meta object code from reading C++ file 'worldview.h'
**
** Created: Fri Aug 31 18:07:35 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../layout/worldview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worldview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WorldView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x05,
      39,   11,   10,   10, 0x05,
      61,   11,   10,   10, 0x05,
      83,   10,   10,   10, 0x05,
     105,   10,   10,   10, 0x05,
     129,  116,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     148,   10,   10,   10, 0x0a,
     161,   10,   10,   10, 0x0a,
     171,   10,   10,   10, 0x0a,
     183,   10,   10,   10, 0x0a,
     195,   10,   10,   10, 0x0a,
     206,   10,   10,   10, 0x0a,
     217,   10,   10,   10, 0x0a,
     236,  230,   10,   10, 0x0a,
     262,  256,   10,   10, 0x0a,
     293,  289,   10,   10, 0x0a,
     316,  311,   10,   10, 0x0a,
     332,   11,   10,   10, 0x0a,
     352,   11,   10,   10, 0x0a,
     372,   11,   10,   10, 0x0a,
     392,   10,   10,   10, 0x0a,
     412,   10,   10,   10, 0x0a,
     429,   10,   10,   10, 0x0a,
     447,  442,   10,   10, 0x0a,
     472,   10,  464,   10, 0x0a,
     482,   10,   10,   10, 0x0a,
     499,   10,   10,   10, 0x0a,
     521,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WorldView[] = {
    "WorldView\0\0angle\0xRotationChanged(int)\0"
    "yRotationChanged(int)\0zRotationChanged(int)\0"
    "ComputeComplete(bool)\0finished()\0"
    "width,height\0getGLSize(int,int)\0"
    "CenterView()\0TopView()\0RightView()\0"
    "FrontView()\0BackView()\0LeftView()\0"
    "BottomView()\0persp\0SetPerpective(bool)\0"
    "point\0SetRevolvePoint(QVector3D)\0pan\0"
    "SetPan(QVector3D)\0zoom\0SetZoom(double)\0"
    "setXRotation(float)\0setYRotation(float)\0"
    "setZRotation(float)\0UpdatePlasmaFence()\0"
    "UpdateVisSlice()\0UpdateTick()\0tool\0"
    "SetTool(QString)\0QString\0GetTool()\0"
    "ExitToolAction()\0ComputeVertexNormal()\0"
    "OnFinished()\0"
};

void WorldView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WorldView *_t = static_cast<WorldView *>(_o);
        switch (_id) {
        case 0: _t->xRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->yRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->zRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ComputeComplete((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->finished(); break;
        case 5: _t->getGLSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->CenterView(); break;
        case 7: _t->TopView(); break;
        case 8: _t->RightView(); break;
        case 9: _t->FrontView(); break;
        case 10: _t->BackView(); break;
        case 11: _t->LeftView(); break;
        case 12: _t->BottomView(); break;
        case 13: _t->SetPerpective((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->SetRevolvePoint((*reinterpret_cast< QVector3D(*)>(_a[1]))); break;
        case 15: _t->SetPan((*reinterpret_cast< QVector3D(*)>(_a[1]))); break;
        case 16: _t->SetZoom((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->setXRotation((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 18: _t->setYRotation((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 19: _t->setZRotation((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 20: _t->UpdatePlasmaFence(); break;
        case 21: _t->UpdateVisSlice(); break;
        case 22: _t->UpdateTick(); break;
        case 23: _t->SetTool((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: { QString _r = _t->GetTool();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 25: _t->ExitToolAction(); break;
        case 26: _t->ComputeVertexNormal(); break;
        case 27: _t->OnFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WorldView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WorldView::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_WorldView,
      qt_meta_data_WorldView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WorldView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WorldView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WorldView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WorldView))
        return static_cast<void*>(const_cast< WorldView*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int WorldView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void WorldView::xRotationChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WorldView::yRotationChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WorldView::zRotationChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WorldView::ComputeComplete(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WorldView::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void WorldView::getGLSize(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
static const uint qt_meta_data_ComputeNormalThread[] = {

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

static const char qt_meta_stringdata_ComputeNormalThread[] = {
    "ComputeNormalThread\0"
};

void ComputeNormalThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ComputeNormalThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ComputeNormalThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ComputeNormalThread,
      qt_meta_data_ComputeNormalThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ComputeNormalThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ComputeNormalThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ComputeNormalThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ComputeNormalThread))
        return static_cast<void*>(const_cast< ComputeNormalThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ComputeNormalThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_AutoSupportThread[] = {

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

static const char qt_meta_stringdata_AutoSupportThread[] = {
    "AutoSupportThread\0"
};

void AutoSupportThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData AutoSupportThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AutoSupportThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_AutoSupportThread,
      qt_meta_data_AutoSupportThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AutoSupportThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AutoSupportThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AutoSupportThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AutoSupportThread))
        return static_cast<void*>(const_cast< AutoSupportThread*>(this));
    return QThread::qt_metacast(_clname);
}

int AutoSupportThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
