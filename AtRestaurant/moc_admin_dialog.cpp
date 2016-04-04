/****************************************************************************
** Meta object code from reading C++ file 'admin_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "admin_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admin_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_admin_dialog_t {
    QByteArrayData data[14];
    char stringdata[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_admin_dialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_admin_dialog_t qt_meta_stringdata_admin_dialog = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 13),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 12),
QT_MOC_LITERAL(4, 41, 13),
QT_MOC_LITERAL(5, 55, 7),
QT_MOC_LITERAL(6, 63, 8),
QT_MOC_LITERAL(7, 72, 5),
QT_MOC_LITERAL(8, 78, 5),
QT_MOC_LITERAL(9, 84, 16),
QT_MOC_LITERAL(10, 101, 17),
QT_MOC_LITERAL(11, 119, 14),
QT_MOC_LITERAL(12, 134, 14),
QT_MOC_LITERAL(13, 149, 20)
    },
    "admin_dialog\0aggiungi_menu\0\0elimina_menu\0"
    "aggiorna_menu\0bevande\0contorni\0pizze\0"
    "dolci\0aggiunta_bevanda\0aggiunta_contorno\0"
    "aggiunta_pizza\0aggiunta_dolce\0"
    "conferma_inserimento\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_admin_dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a,
       3,    0,   75,    2, 0x0a,
       4,    0,   76,    2, 0x0a,
       5,    0,   77,    2, 0x0a,
       6,    0,   78,    2, 0x0a,
       7,    0,   79,    2, 0x0a,
       8,    0,   80,    2, 0x0a,
       9,    0,   81,    2, 0x0a,
      10,    0,   82,    2, 0x0a,
      11,    0,   83,    2, 0x0a,
      12,    0,   84,    2, 0x0a,
      13,    0,   85,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void admin_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        admin_dialog *_t = static_cast<admin_dialog *>(_o);
        switch (_id) {
        case 0: _t->aggiungi_menu(); break;
        case 1: _t->elimina_menu(); break;
        case 2: _t->aggiorna_menu(); break;
        case 3: _t->bevande(); break;
        case 4: _t->contorni(); break;
        case 5: _t->pizze(); break;
        case 6: _t->dolci(); break;
        case 7: _t->aggiunta_bevanda(); break;
        case 8: _t->aggiunta_contorno(); break;
        case 9: _t->aggiunta_pizza(); break;
        case 10: _t->aggiunta_dolce(); break;
        case 11: _t->conferma_inserimento(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject admin_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_admin_dialog.data,
      qt_meta_data_admin_dialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *admin_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *admin_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_admin_dialog.stringdata))
        return static_cast<void*>(const_cast< admin_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int admin_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
