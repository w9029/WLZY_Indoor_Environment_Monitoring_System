/****************************************************************************
** Meta object code from reading C++ file 'stream.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface/stream.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stream.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Stream_t {
    QByteArrayData data[10];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Stream_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Stream_t qt_meta_stringdata_Stream = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Stream"
QT_MOC_LITERAL(1, 7, 8), // "sesignal"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 20), // "on_btn_start_clicked"
QT_MOC_LITERAL(4, 38, 19), // "on_btn_shot_clicked"
QT_MOC_LITERAL(5, 58, 19), // "on_btn_quit_clicked"
QT_MOC_LITERAL(6, 78, 13), // "replyFinished"
QT_MOC_LITERAL(7, 92, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 107, 8), // "flushPic"
QT_MOC_LITERAL(9, 116, 22) // "on_Streamclose_clicked"

    },
    "Stream\0sesignal\0\0on_btn_start_clicked\0"
    "on_btn_shot_clicked\0on_btn_quit_clicked\0"
    "replyFinished\0QNetworkReply*\0flushPic\0"
    "on_Streamclose_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Stream[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Stream::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Stream *_t = static_cast<Stream *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sesignal(); break;
        case 1: _t->on_btn_start_clicked(); break;
        case 2: _t->on_btn_shot_clicked(); break;
        case 3: _t->on_btn_quit_clicked(); break;
        case 4: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->flushPic(); break;
        case 6: _t->on_Streamclose_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
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
            typedef void (Stream::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Stream::sesignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Stream::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Stream.data,
      qt_meta_data_Stream,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Stream::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Stream::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Stream.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Stream::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Stream::sesignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
