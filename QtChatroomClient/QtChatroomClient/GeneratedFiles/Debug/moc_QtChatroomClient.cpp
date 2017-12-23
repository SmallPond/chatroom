/****************************************************************************
** Meta object code from reading C++ file 'QtChatroomClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtChatroomClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtChatroomClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NetworkThread_t {
    QByteArrayData data[8];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetworkThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetworkThread_t qt_meta_stringdata_NetworkThread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "NetworkThread"
QT_MOC_LITERAL(1, 14, 10), // "chatsignal"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "char*"
QT_MOC_LITERAL(4, 32, 10), // "listsignal"
QT_MOC_LITERAL(5, 43, 10), // "joinsignal"
QT_MOC_LITERAL(6, 54, 11), // "const char*"
QT_MOC_LITERAL(7, 66, 10) // "quitsignal"

    },
    "NetworkThread\0chatsignal\0\0char*\0"
    "listsignal\0joinsignal\0const char*\0"
    "quitsignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    1,   40,    2, 0x06 /* Public */,
       7,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void NetworkThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetworkThread *_t = static_cast<NetworkThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->chatsignal((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 1: _t->listsignal((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 2: _t->joinsignal((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 3: _t->quitsignal((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetworkThread::*_t)(char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkThread::chatsignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NetworkThread::*_t)(char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkThread::listsignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NetworkThread::*_t)(const char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkThread::joinsignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (NetworkThread::*_t)(const char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkThread::quitsignal)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject NetworkThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_NetworkThread.data,
      qt_meta_data_NetworkThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NetworkThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkThread.stringdata0))
        return static_cast<void*>(const_cast< NetworkThread*>(this));
    return QThread::qt_metacast(_clname);
}

int NetworkThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void NetworkThread::chatsignal(char * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetworkThread::listsignal(char * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetworkThread::joinsignal(const char * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NetworkThread::quitsignal(const char * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_QtChatroomClient_t {
    QByteArrayData data[11];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtChatroomClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtChatroomClient_t qt_meta_stringdata_QtChatroomClient = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QtChatroomClient"
QT_MOC_LITERAL(1, 17, 9), // "showlogin"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "receiveshowchatroom"
QT_MOC_LITERAL(4, 48, 10), // "SendButton"
QT_MOC_LITERAL(5, 59, 6), // "OnChat"
QT_MOC_LITERAL(6, 66, 5), // "char*"
QT_MOC_LITERAL(7, 72, 6), // "OnList"
QT_MOC_LITERAL(8, 79, 6), // "OnJoin"
QT_MOC_LITERAL(9, 86, 11), // "const char*"
QT_MOC_LITERAL(10, 98, 6) // "OnQuit"

    },
    "QtChatroomClient\0showlogin\0\0"
    "receiveshowchatroom\0SendButton\0OnChat\0"
    "char*\0OnList\0OnJoin\0const char*\0OnQuit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtChatroomClient[] = {

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
       3,    1,   50,    2, 0x08 /* Private */,
       4,    0,   53,    2, 0x08 /* Private */,
       5,    1,   54,    2, 0x08 /* Private */,
       7,    1,   57,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
      10,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 9,    2,

       0        // eod
};

void QtChatroomClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtChatroomClient *_t = static_cast<QtChatroomClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showlogin(); break;
        case 1: _t->receiveshowchatroom((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->SendButton(); break;
        case 3: _t->OnChat((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 4: _t->OnList((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 5: _t->OnJoin((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 6: _t->OnQuit((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtChatroomClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtChatroomClient::showlogin)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QtChatroomClient::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QtChatroomClient.data,
      qt_meta_data_QtChatroomClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtChatroomClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtChatroomClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtChatroomClient.stringdata0))
        return static_cast<void*>(const_cast< QtChatroomClient*>(this));
    return QDialog::qt_metacast(_clname);
}

int QtChatroomClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QtChatroomClient::showlogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
