/****************************************************************************
** Meta object code from reading C++ file 'updatemanager.h'
**
** Created: Mon Sep 3 14:54:09 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../updatemanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'updatemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_B9UpdateManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   16,   16,   16, 0x0a,
      70,   62,   16,   16, 0x08,
     110,  104,   16,   16, 0x08,
     147,   16,  142,   16, 0x08,
     164,   16,   16,   16, 0x08,
     181,   16,   16,   16, 0x08,
     201,   16,   16,   16, 0x08,
     219,   16,   16,   16, 0x08,
     241,   16,   16,   16, 0x08,
     262,   16,   16,   16, 0x08,
     287,   16,  142,   16, 0x08,
     302,   16,  142,   16, 0x08,
     348,  331,  142,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_B9UpdateManager[] = {
    "B9UpdateManager\0\0NotifyUpdateFinished()\0"
    "AutoCheckForUpdates()\0request\0"
    "StartNewDownload(QNetworkRequest)\0"
    "reply\0OnRecievedReply(QNetworkReply*)\0"
    "bool\0OnDownloadDone()\0OnCancelUpdate()\0"
    "OnDownloadTimeout()\0ResetEverything()\0"
    "CopyInRemoteEntries()\0CopyInLocalEntries()\0"
    "CalculateUpdateEntries()\0CopyFromTemp()\0"
    "UpdateLocalFileVersionList()\0"
    "candidate,remote\0"
    "NeedsUpdated(B9UpdateEntry&,B9UpdateEntry&)\0"
};

void B9UpdateManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        B9UpdateManager *_t = static_cast<B9UpdateManager *>(_o);
        switch (_id) {
        case 0: _t->NotifyUpdateFinished(); break;
        case 1: _t->AutoCheckForUpdates(); break;
        case 2: _t->StartNewDownload((*reinterpret_cast< QNetworkRequest(*)>(_a[1]))); break;
        case 3: _t->OnRecievedReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: { bool _r = _t->OnDownloadDone();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->OnCancelUpdate(); break;
        case 6: _t->OnDownloadTimeout(); break;
        case 7: _t->ResetEverything(); break;
        case 8: _t->CopyInRemoteEntries(); break;
        case 9: _t->CopyInLocalEntries(); break;
        case 10: _t->CalculateUpdateEntries(); break;
        case 11: { bool _r = _t->CopyFromTemp();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->UpdateLocalFileVersionList();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->NeedsUpdated((*reinterpret_cast< B9UpdateEntry(*)>(_a[1])),(*reinterpret_cast< B9UpdateEntry(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData B9UpdateManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject B9UpdateManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_B9UpdateManager,
      qt_meta_data_B9UpdateManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &B9UpdateManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *B9UpdateManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *B9UpdateManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_B9UpdateManager))
        return static_cast<void*>(const_cast< B9UpdateManager*>(this));
    return QObject::qt_metacast(_clname);
}

int B9UpdateManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void B9UpdateManager::NotifyUpdateFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
