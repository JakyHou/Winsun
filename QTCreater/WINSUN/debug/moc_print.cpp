/****************************************************************************
** Meta object code from reading C++ file 'print.h'
**
** Created: Wed Sep 5 16:46:33 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../print.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'print.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Print[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      21,    6,    6,    6, 0x05,
      52,    6,    6,    6, 0x05,
      84,    6,    6,    6, 0x05,
     115,    6,    6,    6, 0x05,
     165,    6,    6,    6, 0x05,
     191,    6,    6,    6, 0x05,
     219,    6,    6,    6, 0x05,
     232,    6,    6,    6, 0x05,
     255,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     284,  278,    6,    6, 0x0a,
     316,    6,  308,    6, 0x0a,
     330,    6,    6,    6, 0x08,
     341,  278,    6,    6, 0x08,
     376,  278,    6,    6, 0x08,
     410,  278,    6,    6, 0x08,
     452,  444,    6,    6, 0x08,
     505,    6,    6,    6, 0x08,
     527,    6,    6,    6, 0x08,
     546,    6,    6,    6, 0x08,
     571,    6,    6,    6, 0x08,
     604,    6,    6,    6, 0x08,
     636,    6,    6,    6, 0x08,
     682,  671,    6,    6, 0x08,
     718,    6,    6,    6, 0x28,

       0        // eod
};

static const char qt_meta_stringdata_Print[] = {
    "Print\0\0eventHiding()\0"
    "updateProjectorStatus(QString)\0"
    "updateConnectionStatus(QString)\0"
    "updateProjectorOutput(QString)\0"
    "updateProjector(B9PrinterStatus::ProjectorStatus)\0"
    "signalAbortPrint(QString)\0"
    "PrintReleaseCycleFinished()\0pausePrint()\0"
    "sendStatusMsg(QString)\0setProjectorPowerOff()\0"
    "sText\0setProjMessage(QString)\0QString\0"
    "updateTimes()\0showHelp()\0"
    "on_updateConnectionStatus(QString)\0"
    "on_updateProjectorOutput(QString)\0"
    "on_updateProjectorStatus(QString)\0"
    "eStatus\0on_updateProjector(B9PrinterStatus::ProjectorStatus)\0"
    "on_signalAbortPrint()\0exposeTBaseLayer()\0"
    "startExposeTOverLayers()\0"
    "exposureOfCurTintLayerFinished()\0"
    "exposureOfTOverLayersFinished()\0"
    "on_pushButtonPauseResume_clicked()\0"
    "sAbortText\0on_pushButtonAbort_clicked(QString)\0"
    "on_pushButtonAbort_clicked()\0"
};

void Print::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Print *_t = static_cast<Print *>(_o);
        switch (_id) {
        case 0: _t->eventHiding(); break;
        case 1: _t->updateProjectorStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateConnectionStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->updateProjectorOutput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->updateProjector((*reinterpret_cast< B9PrinterStatus::ProjectorStatus(*)>(_a[1]))); break;
        case 5: _t->signalAbortPrint((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->PrintReleaseCycleFinished(); break;
        case 7: _t->pausePrint(); break;
        case 8: _t->sendStatusMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setProjectorPowerOff(); break;
        case 10: _t->setProjMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: { QString _r = _t->updateTimes();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 12: _t->showHelp(); break;
        case 13: _t->on_updateConnectionStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->on_updateProjectorOutput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->on_updateProjectorStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->on_updateProjector((*reinterpret_cast< B9PrinterStatus::ProjectorStatus(*)>(_a[1]))); break;
        case 17: _t->on_signalAbortPrint(); break;
        case 18: _t->exposeTBaseLayer(); break;
        case 19: _t->startExposeTOverLayers(); break;
        case 20: _t->exposureOfCurTintLayerFinished(); break;
        case 21: _t->exposureOfTOverLayersFinished(); break;
        case 22: _t->on_pushButtonPauseResume_clicked(); break;
        case 23: _t->on_pushButtonAbort_clicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->on_pushButtonAbort_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Print::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Print::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Print,
      qt_meta_data_Print, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Print::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Print::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Print::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Print))
        return static_cast<void*>(const_cast< Print*>(this));
    return QDialog::qt_metacast(_clname);
}

int Print::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void Print::eventHiding()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Print::updateProjectorStatus(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Print::updateConnectionStatus(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Print::updateProjectorOutput(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Print::updateProjector(B9PrinterStatus::ProjectorStatus _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Print::signalAbortPrint(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Print::PrintReleaseCycleFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Print::pausePrint()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Print::sendStatusMsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Print::setProjectorPowerOff()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}
QT_END_MOC_NAMESPACE
