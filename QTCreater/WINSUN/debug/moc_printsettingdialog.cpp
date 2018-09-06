/****************************************************************************
** Meta object code from reading C++ file 'printsettingdialog.h'
**
** Created: Wed Sep 5 16:46:57 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../printsettingdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printsettingdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PrintSettingDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      36,   19,   19,   19, 0x05,
      53,   19,   19,   19, 0x05,
      71,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      83,   19,   19,   19, 0x08,
     109,   19,   19,   19, 0x08,
     143,  137,   19,   19, 0x0a,
     184,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PrintSettingDialog[] = {
    "PrintSettingDialog\0\0setPrinter(int)\0"
    "setMaterial(int)\0setThickness(int)\0"
    "setDlg(int)\0on_pushButtonOK_clicked()\0"
    "on_toolButtonMore_clicked()\0index\0"
    "on_printercombo_currentIndexChanged(int)\0"
    "showIt()\0"
};

void PrintSettingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PrintSettingDialog *_t = static_cast<PrintSettingDialog *>(_o);
        switch (_id) {
        case 0: _t->setPrinter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setMaterial((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setThickness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setDlg((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pushButtonOK_clicked(); break;
        case 5: _t->on_toolButtonMore_clicked(); break;
        case 6: _t->on_printercombo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->showIt(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PrintSettingDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PrintSettingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PrintSettingDialog,
      qt_meta_data_PrintSettingDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PrintSettingDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PrintSettingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PrintSettingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrintSettingDialog))
        return static_cast<void*>(const_cast< PrintSettingDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PrintSettingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void PrintSettingDialog::setPrinter(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PrintSettingDialog::setMaterial(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PrintSettingDialog::setThickness(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PrintSettingDialog::setDlg(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
