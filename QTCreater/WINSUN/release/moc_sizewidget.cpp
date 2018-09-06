/****************************************************************************
** Meta object code from reading C++ file 'sizewidget.h'
**
** Created: Wed Sep 5 10:48:36 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sizewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sizewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_sizeWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      36,   31,   11,   11, 0x08,
      80,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_sizeWidget[] = {
    "sizeWidget\0\0PushTranslations()\0arg1\0"
    "on_doubleSpinBox_scale_valueChanged(double)\0"
    "on_pushButtonDrop_To_Floor_clicked()\0"
    "on_doubleSpinBox_scale_editingFinished()\0"
};

void sizeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        sizeWidget *_t = static_cast<sizeWidget *>(_o);
        switch (_id) {
        case 0: _t->PushTranslations(); break;
        case 1: _t->on_doubleSpinBox_scale_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_pushButtonDrop_To_Floor_clicked(); break;
        case 3: _t->on_doubleSpinBox_scale_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData sizeWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject sizeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_sizeWidget,
      qt_meta_data_sizeWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &sizeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *sizeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *sizeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_sizeWidget))
        return static_cast<void*>(const_cast< sizeWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int sizeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
