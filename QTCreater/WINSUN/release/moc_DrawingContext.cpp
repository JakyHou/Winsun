/****************************************************************************
** Meta object code from reading C++ file 'DrawingContext.h'
**
** Created: Wed Sep 5 10:48:15 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../edit/DrawingContext.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DrawingContext.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DrawingContext[] = {

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
      20,   16,   15,   15, 0x0a,
      41,   16,   15,   15, 0x0a,
      62,   15,   15,   15, 0x0a,
      83,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DrawingContext[] = {
    "DrawingContext\0\0img\0SetUpperImg(QImage*)\0"
    "SetLowerImg(QImage*)\0GenerateLogicImage()\0"
    "GenerateGreenImage()\0"
};

void DrawingContext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DrawingContext *_t = static_cast<DrawingContext *>(_o);
        switch (_id) {
        case 0: _t->SetUpperImg((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 1: _t->SetLowerImg((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 2: _t->GenerateLogicImage(); break;
        case 3: _t->GenerateGreenImage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DrawingContext::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DrawingContext::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DrawingContext,
      qt_meta_data_DrawingContext, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DrawingContext::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DrawingContext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DrawingContext::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DrawingContext))
        return static_cast<void*>(const_cast< DrawingContext*>(this));
    return QWidget::qt_metacast(_clname);
}

int DrawingContext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
