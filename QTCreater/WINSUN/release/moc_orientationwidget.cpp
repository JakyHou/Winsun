/****************************************************************************
** Meta object code from reading C++ file 'orientationwidget.h'
**
** Created: Wed Sep 5 10:48:40 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../orientationwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orientationwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OrientationWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      38,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OrientationWidget[] = {
    "OrientationWidget\0\0PushTranslations()\0"
    "on_pushButtonDrop_To_Floor_clicked()\0"
};

void OrientationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OrientationWidget *_t = static_cast<OrientationWidget *>(_o);
        switch (_id) {
        case 0: _t->PushTranslations(); break;
        case 1: _t->on_pushButtonDrop_To_Floor_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OrientationWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OrientationWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OrientationWidget,
      qt_meta_data_OrientationWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OrientationWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OrientationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OrientationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OrientationWidget))
        return static_cast<void*>(const_cast< OrientationWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int OrientationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
