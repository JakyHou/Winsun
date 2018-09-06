/****************************************************************************
** Meta object code from reading C++ file 'materialscatalog.h'
**
** Created: Fri Aug 31 18:07:49 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../materialscatalog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'materialscatalog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MaterialsTableItemDelegate[] = {

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

static const char qt_meta_stringdata_MaterialsTableItemDelegate[] = {
    "MaterialsTableItemDelegate\0"
};

void MaterialsTableItemDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MaterialsTableItemDelegate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaterialsTableItemDelegate::staticMetaObject = {
    { &QStyledItemDelegate::staticMetaObject, qt_meta_stringdata_MaterialsTableItemDelegate,
      qt_meta_data_MaterialsTableItemDelegate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaterialsTableItemDelegate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaterialsTableItemDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaterialsTableItemDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaterialsTableItemDelegate))
        return static_cast<void*>(const_cast< MaterialsTableItemDelegate*>(this));
    return QStyledItemDelegate::qt_metacast(_clname);
}

int MaterialsTableItemDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_MaterialsCatalog[] = {

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
      23,   18,   17,   17, 0x08,
      72,   17,   17,   17, 0x08,
      99,   17,   17,   17, 0x08,
     129,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaterialsCatalog[] = {
    "MaterialsCatalog\0\0arg1\0"
    "on_comboBoxMaterial_currentIndexChanged(QString)\0"
    "on_pushButtonAdd_clicked()\0"
    "on_pushButtonDelete_clicked()\0"
    "on_pushButtonSave_clicked()\0"
};

void MaterialsCatalog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaterialsCatalog *_t = static_cast<MaterialsCatalog *>(_o);
        switch (_id) {
        case 0: _t->on_comboBoxMaterial_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonAdd_clicked(); break;
        case 2: _t->on_pushButtonDelete_clicked(); break;
        case 3: _t->on_pushButtonSave_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaterialsCatalog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaterialsCatalog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MaterialsCatalog,
      qt_meta_data_MaterialsCatalog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaterialsCatalog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaterialsCatalog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaterialsCatalog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaterialsCatalog))
        return static_cast<void*>(const_cast< MaterialsCatalog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MaterialsCatalog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
