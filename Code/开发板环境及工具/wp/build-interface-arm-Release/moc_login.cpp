/****************************************************************************
** Meta object code from reading C++ file 'login.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface/login.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Login_t {
    QByteArrayData data[10];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Login_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Login_t qt_meta_stringdata_Login = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Login"
QT_MOC_LITERAL(1, 6, 10), // "sendsignal"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 20), // "on_btn_login_clicked"
QT_MOC_LITERAL(4, 39, 21), // "on_btn_cancel_clicked"
QT_MOC_LITERAL(5, 61, 11), // "replyfinish"
QT_MOC_LITERAL(6, 73, 14), // "QNetworkReply*"
QT_MOC_LITERAL(7, 88, 22), // "on_username_textEdited"
QT_MOC_LITERAL(8, 111, 4), // "arg1"
QT_MOC_LITERAL(9, 116, 22) // "on_password_textEdited"

    },
    "Login\0sendsignal\0\0on_btn_login_clicked\0"
    "on_btn_cancel_clicked\0replyfinish\0"
    "QNetworkReply*\0on_username_textEdited\0"
    "arg1\0on_password_textEdited"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Login[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
       9,    1,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void Login::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Login *_t = static_cast<Login *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendsignal(); break;
        case 1: _t->on_btn_login_clicked(); break;
        case 2: _t->on_btn_cancel_clicked(); break;
        case 3: _t->replyfinish((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->on_username_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_password_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Login::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Login::sendsignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Login::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Login.data,
      qt_meta_data_Login,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Login::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Login::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Login.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Login::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Login::sendsignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
