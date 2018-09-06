/****************************************************************************
** Meta object code from reading C++ file 'printercomm.h'
**
** Created: Mon Sep 3 14:54:11 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../printercomm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printercomm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_B9FirmwareUpdate[] = {

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

static const char qt_meta_stringdata_B9FirmwareUpdate[] = {
    "B9FirmwareUpdate\0"
};

void B9FirmwareUpdate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData B9FirmwareUpdate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject B9FirmwareUpdate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_B9FirmwareUpdate,
      qt_meta_data_B9FirmwareUpdate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &B9FirmwareUpdate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *B9FirmwareUpdate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *B9FirmwareUpdate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_B9FirmwareUpdate))
        return static_cast<void*>(const_cast< B9FirmwareUpdate*>(this));
    return QObject::qt_metacast(_clname);
}

int B9FirmwareUpdate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_B9PrinterComm[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      21,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   15,   14,   14, 0x05,
      53,   15,   14,   14, 0x05,
      90,   14,   14,   14, 0x05,
     104,   15,   14,   14, 0x05,
     133,  124,   14,   14, 0x05,
     153,   14,   14,   14, 0x05,
     168,   14,   14,   14, 0x05,
     196,   14,   14,   14, 0x05,
     222,  215,   14,   14, 0x05,
     253,  244,   14,   14, 0x05,
     287,  277,   14,   14, 0x05,
     330,  319,   14,   14, 0x05,
     350,   14,   14,   14, 0x05,
     361,   14,   14,   14, 0x05,
     381,   14,   14,   14, 0x05,
     398,   14,   14,   14, 0x05,
     414,   14,   14,   14, 0x05,
     430,   14,   14,   14, 0x05,
     450,   14,   14,   14, 0x05,
     474,   14,   14,   14, 0x05,
     504,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     540,  535,   14,   14, 0x0a,
     566,  557,   14,   14, 0x0a,
     602,  593,   14,   14, 0x0a,
     634,  622,   14,   14, 0x0a,
     652,   14,   14,   14, 0x08,
     668,   14,   14,   14, 0x08,
     691,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_B9PrinterComm[] = {
    "B9PrinterComm\0\0sText\0"
    "updateConnectionStatus(QString)\0"
    "BC_ConnectionStatusDetailed(QString)\0"
    "BC_LostCOMM()\0BC_RawData(QString)\0"
    "sComment\0BC_Comment(QString)\0"
    "BC_HomeFound()\0BC_ProjectorStatusChanged()\0"
    "BC_ProjectorFAIL()\0sModel\0"
    "BC_ModelInfo(QString)\0sVersion\0"
    "BC_FirmVersion(QString)\0isCapable\0"
    "BC_ProjectorRemoteCapable(bool)\0"
    "hasShutter\0BC_HasShutter(bool)\0"
    "BC_PU(int)\0BC_UpperZLimPU(int)\0"
    "BC_HalfLife(int)\0BC_NativeX(int)\0"
    "BC_NativeY(int)\0BC_XYPixelSize(int)\0"
    "BC_CurrentZPosInPU(int)\0"
    "BC_CurrentVatPercentOpen(int)\0"
    "BC_PrintReleaseCycleFinished()\0sCmd\0"
    "SendCmd(QString)\0bPwrFlag\0"
    "setProjectorPowerCmd(bool)\0iDelayMS\0"
    "setWarmUpDelay(int)\0bIsMirrored\0"
    "setMirrored(bool)\0ReadAvailable()\0"
    "RefreshCommPortItems()\0watchDog()\0"
};

void B9PrinterComm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        B9PrinterComm *_t = static_cast<B9PrinterComm *>(_o);
        switch (_id) {
        case 0: _t->updateConnectionStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->BC_ConnectionStatusDetailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->BC_LostCOMM(); break;
        case 3: _t->BC_RawData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->BC_Comment((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->BC_HomeFound(); break;
        case 6: _t->BC_ProjectorStatusChanged(); break;
        case 7: _t->BC_ProjectorFAIL(); break;
        case 8: _t->BC_ModelInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->BC_FirmVersion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->BC_ProjectorRemoteCapable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->BC_HasShutter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->BC_PU((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->BC_UpperZLimPU((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->BC_HalfLife((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->BC_NativeX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->BC_NativeY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->BC_XYPixelSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->BC_CurrentZPosInPU((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->BC_CurrentVatPercentOpen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->BC_PrintReleaseCycleFinished(); break;
        case 21: _t->SendCmd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->setProjectorPowerCmd((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->setWarmUpDelay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->setMirrored((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->ReadAvailable(); break;
        case 26: _t->RefreshCommPortItems(); break;
        case 27: _t->watchDog(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData B9PrinterComm::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject B9PrinterComm::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_B9PrinterComm,
      qt_meta_data_B9PrinterComm, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &B9PrinterComm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *B9PrinterComm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *B9PrinterComm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_B9PrinterComm))
        return static_cast<void*>(const_cast< B9PrinterComm*>(this));
    return QObject::qt_metacast(_clname);
}

int B9PrinterComm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void B9PrinterComm::updateConnectionStatus(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void B9PrinterComm::BC_ConnectionStatusDetailed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void B9PrinterComm::BC_LostCOMM()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void B9PrinterComm::BC_RawData(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void B9PrinterComm::BC_Comment(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void B9PrinterComm::BC_HomeFound()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void B9PrinterComm::BC_ProjectorStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void B9PrinterComm::BC_ProjectorFAIL()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void B9PrinterComm::BC_ModelInfo(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void B9PrinterComm::BC_FirmVersion(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void B9PrinterComm::BC_ProjectorRemoteCapable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void B9PrinterComm::BC_HasShutter(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void B9PrinterComm::BC_PU(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void B9PrinterComm::BC_UpperZLimPU(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void B9PrinterComm::BC_HalfLife(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void B9PrinterComm::BC_NativeX(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void B9PrinterComm::BC_NativeY(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void B9PrinterComm::BC_XYPixelSize(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void B9PrinterComm::BC_CurrentZPosInPU(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void B9PrinterComm::BC_CurrentVatPercentOpen(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void B9PrinterComm::BC_PrintReleaseCycleFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 20, 0);
}
QT_END_MOC_NAMESPACE
