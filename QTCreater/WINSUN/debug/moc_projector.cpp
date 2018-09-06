/****************************************************************************
** Meta object code from reading C++ file 'projector.h'
**
** Created: Fri Aug 31 18:08:20 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../projector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_B9Projector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      38,   12,   12,   12, 0x05,
      52,   12,   12,   12, 0x05,
      73,   68,   12,   12, 0x05,
     112,   90,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     143,  135,   12,   12, 0x0a,
     174,   12,   12,   12, 0x0a,
     193,  187,   12,   12, 0x0a,
     218,  211,   12,   12, 0x0a,
     245,  240,   12,   12, 0x0a,
     282,  275,  270,   12, 0x0a,
     312,  304,   12,   12, 0x0a,
     337,  332,   12,   12, 0x0a,
     355,  350,   12,   12, 0x0a,
     382,  368,   12,   12, 0x0a,
     433,  425,   12,   12, 0x2a,
     474,  469,   12,   12, 0x2a,
     503,   12,   12,   12, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_B9Projector[] = {
    "B9Projector\0\0setProjectorBlueLED(int)\0"
    "eventHiding()\0hideProjector()\0iKey\0"
    "keyReleased(int)\0iScreenNumber,geoRect\0"
    "newGeometry(int,QRect)\0x,y,w,h\0"
    "showProjector(int,int,int,int)\0"
    "hideCursor()\0bShow\0setShowGrid(bool)\0"
    "status\0setStatusMsg(QString)\0pCPJ\0"
    "setCPJ(CrushedPrintJob*)\0bool\0iLevel\0"
    "clearTimedPixels(int)\0iRadius\0"
    "createToverMap(int)\0xOff\0setXoff(int)\0"
    "yOff\0setYoff(int)\0XYPS,dZ,dOhMM\0"
    "createNormalizedMask(double,double,double)\0"
    "XYPS,dZ\0createNormalizedMask(double,double)\0"
    "XYPS\0createNormalizedMask(double)\0"
    "createNormalizedMask()\0"
};

void B9Projector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        B9Projector *_t = static_cast<B9Projector *>(_o);
        switch (_id) {
        case 0: _t->setProjectorBlueLED((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->eventHiding(); break;
        case 2: _t->hideProjector(); break;
        case 3: _t->keyReleased((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->newGeometry((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QRect(*)>(_a[2]))); break;
        case 5: _t->showProjector((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: _t->hideCursor(); break;
        case 7: _t->setShowGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setStatusMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setCPJ((*reinterpret_cast< CrushedPrintJob*(*)>(_a[1]))); break;
        case 10: { bool _r = _t->clearTimedPixels((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: _t->createToverMap((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setXoff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setYoff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->createNormalizedMask((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 15: _t->createNormalizedMask((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 16: _t->createNormalizedMask((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->createNormalizedMask(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData B9Projector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject B9Projector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_B9Projector,
      qt_meta_data_B9Projector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &B9Projector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *B9Projector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *B9Projector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_B9Projector))
        return static_cast<void*>(const_cast< B9Projector*>(this));
    return QWidget::qt_metacast(_clname);
}

int B9Projector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void B9Projector::setProjectorBlueLED(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void B9Projector::eventHiding()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void B9Projector::hideProjector()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void B9Projector::keyReleased(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void B9Projector::newGeometry(int _t1, QRect _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
