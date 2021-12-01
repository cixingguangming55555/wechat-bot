/****************************************************************************
** Meta object code from reading C++ file 'friendaddreg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../client/qt_c++/friendaddreg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'friendaddreg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FriendAddReg_t {
    QByteArrayData data[7];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FriendAddReg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FriendAddReg_t qt_meta_stringdata_FriendAddReg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FriendAddReg"
QT_MOC_LITERAL(1, 13, 17), // "reload_f_ini_file"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 31), // "on_reply_add_pushButton_clicked"
QT_MOC_LITERAL(4, 64, 31), // "on_reply_del_pushButton_clicked"
QT_MOC_LITERAL(5, 96, 31), // "on_sync_file_pushButton_clicked"
QT_MOC_LITERAL(6, 128, 12) // "load_init_cb"

    },
    "FriendAddReg\0reload_f_ini_file\0\0"
    "on_reply_add_pushButton_clicked\0"
    "on_reply_del_pushButton_clicked\0"
    "on_sync_file_pushButton_clicked\0"
    "load_init_cb"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FriendAddReg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FriendAddReg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FriendAddReg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reload_f_ini_file(); break;
        case 1: _t->on_reply_add_pushButton_clicked(); break;
        case 2: _t->on_reply_del_pushButton_clicked(); break;
        case 3: _t->on_sync_file_pushButton_clicked(); break;
        case 4: _t->load_init_cb(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FriendAddReg::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FriendAddReg::reload_f_ini_file)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FriendAddReg::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FriendAddReg.data,
    qt_meta_data_FriendAddReg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FriendAddReg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FriendAddReg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FriendAddReg.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FriendAddReg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FriendAddReg::reload_f_ini_file()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
