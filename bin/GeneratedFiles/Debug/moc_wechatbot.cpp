/****************************************************************************
** Meta object code from reading C++ file 'wechatbot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../client/qt_c++/wechatbot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wechatbot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WeChatBot_t {
    QByteArrayData data[21];
    char stringdata0[381];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeChatBot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeChatBot_t qt_meta_stringdata_WeChatBot = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WeChatBot"
QT_MOC_LITERAL(1, 10, 23), // "on_close_Button_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 26), // "on_clear_op_Button_clicked"
QT_MOC_LITERAL(4, 62, 27), // "on_clear_log_Button_clicked"
QT_MOC_LITERAL(5, 90, 25), // "on_connect_Button_clicked"
QT_MOC_LITERAL(6, 116, 22), // "ws_client_connected_cb"
QT_MOC_LITERAL(7, 139, 21), // "ws_client_received_cb"
QT_MOC_LITERAL(8, 161, 3), // "msg"
QT_MOC_LITERAL(9, 165, 25), // "ws_client_disconnected_cb"
QT_MOC_LITERAL(10, 191, 29), // "on_edit_friend_Button_clicked"
QT_MOC_LITERAL(11, 221, 31), // "on_edit_chatroom_Button_clicked"
QT_MOC_LITERAL(12, 253, 18), // "update_wxuser_list"
QT_MOC_LITERAL(13, 272, 19), // "std::vector<cJSON*>"
QT_MOC_LITERAL(14, 292, 5), // "items"
QT_MOC_LITERAL(15, 298, 6), // "items2"
QT_MOC_LITERAL(16, 305, 9), // "show_mask"
QT_MOC_LITERAL(17, 315, 9), // "hide_mask"
QT_MOC_LITERAL(18, 325, 15), // "reload_ini_file"
QT_MOC_LITERAL(19, 341, 17), // "reload_f_ini_file"
QT_MOC_LITERAL(20, 359, 21) // "get_wxuser_timer_slot"

    },
    "WeChatBot\0on_close_Button_clicked\0\0"
    "on_clear_op_Button_clicked\0"
    "on_clear_log_Button_clicked\0"
    "on_connect_Button_clicked\0"
    "ws_client_connected_cb\0ws_client_received_cb\0"
    "msg\0ws_client_disconnected_cb\0"
    "on_edit_friend_Button_clicked\0"
    "on_edit_chatroom_Button_clicked\0"
    "update_wxuser_list\0std::vector<cJSON*>\0"
    "items\0items2\0show_mask\0hide_mask\0"
    "reload_ini_file\0reload_f_ini_file\0"
    "get_wxuser_timer_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeChatBot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    1,   94,    2, 0x0a /* Public */,
       9,    0,   97,    2, 0x0a /* Public */,
      10,    0,   98,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x0a /* Public */,
      12,    2,  100,    2, 0x0a /* Public */,
      16,    0,  105,    2, 0x0a /* Public */,
      17,    0,  106,    2, 0x0a /* Public */,
      18,    0,  107,    2, 0x0a /* Public */,
      19,    0,  108,    2, 0x0a /* Public */,
      20,    0,  109,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 13,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WeChatBot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WeChatBot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_close_Button_clicked(); break;
        case 1: _t->on_clear_op_Button_clicked(); break;
        case 2: _t->on_clear_log_Button_clicked(); break;
        case 3: _t->on_connect_Button_clicked(); break;
        case 4: _t->ws_client_connected_cb(); break;
        case 5: _t->ws_client_received_cb((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->ws_client_disconnected_cb(); break;
        case 7: _t->on_edit_friend_Button_clicked(); break;
        case 8: _t->on_edit_chatroom_Button_clicked(); break;
        case 9: _t->update_wxuser_list((*reinterpret_cast< std::vector<cJSON*>(*)>(_a[1])),(*reinterpret_cast< std::vector<cJSON*>(*)>(_a[2]))); break;
        case 10: _t->show_mask(); break;
        case 11: _t->hide_mask(); break;
        case 12: _t->reload_ini_file(); break;
        case 13: _t->reload_f_ini_file(); break;
        case 14: _t->get_wxuser_timer_slot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WeChatBot::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WeChatBot.data,
    qt_meta_data_WeChatBot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WeChatBot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeChatBot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WeChatBot.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WeChatBot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
