/****************************************************************************
** Meta object code from reading C++ file 'statuswidget.h'
**
** Created: Wed Sep 5 16:46:54 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../statuswidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statuswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_statusWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   14,   13,   13, 0x0a,
      36,   14,   13,   13, 0x0a,
      56,   54,   13,   13, 0x0a,
      86,   13,   78,   13, 0x0a,
     106,   13,   99,   13, 0x0a,
     121,   14,   13,   13, 0x08,
     164,   14,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_statusWidget[] = {
    "statusWidget\0\0index\0setPrinter(int)\0"
    "setThickness(int)\0s\0setThickness(QString)\0"
    "QString\0getPrinter()\0double\0getThickness()\0"
    "on_thicknesscombo_currentIndexChanged(int)\0"
    "on_printercombo_currentIndexChanged(int)\0"
};

void statusWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        statusWidget *_t = static_cast<statusWidget *>(_o);
        switch (_id) {
        case 0: _t->setPrinter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setThickness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setThickness((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: { QString _r = _t->getPrinter();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: { double _r = _t->getThickness();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 5: _t->on_thicknesscombo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_printercombo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData statusWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject statusWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_statusWidget,
      qt_meta_data_statusWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &statusWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *statusWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *statusWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_statusWidget))
        return static_cast<void*>(const_cast< statusWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int statusWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
