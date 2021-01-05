/****************************************************************************
** Meta object code from reading C++ file 'localmode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PCLogo-demo/localmode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'localmode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LocalMode_t {
    QByteArrayData data[17];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LocalMode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LocalMode_t qt_meta_stringdata_LocalMode = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LocalMode"
QT_MOC_LITERAL(1, 10, 16), // "parseCurrentLine"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "parseLine"
QT_MOC_LITERAL(4, 38, 4), // "line"
QT_MOC_LITERAL(5, 43, 8), // "parseAll"
QT_MOC_LITERAL(6, 52, 11), // "speechStart"
QT_MOC_LITERAL(7, 64, 9), // "speechEnd"
QT_MOC_LITERAL(8, 74, 8), // "openFile"
QT_MOC_LITERAL(9, 83, 6), // "newTab"
QT_MOC_LITERAL(10, 90, 9), // "removeTab"
QT_MOC_LITERAL(11, 100, 1), // "n"
QT_MOC_LITERAL(12, 102, 8), // "saveFile"
QT_MOC_LITERAL(13, 111, 10), // "saveFileAs"
QT_MOC_LITERAL(14, 122, 14), // "receiveNewLine"
QT_MOC_LITERAL(15, 137, 7), // "newLine"
QT_MOC_LITERAL(16, 145, 11) // "closeWindow"

    },
    "LocalMode\0parseCurrentLine\0\0parseLine\0"
    "line\0parseAll\0speechStart\0speechEnd\0"
    "openFile\0newTab\0removeTab\0n\0saveFile\0"
    "saveFileAs\0receiveNewLine\0newLine\0"
    "closeWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LocalMode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    1,   75,    2, 0x08 /* Private */,
       5,    0,   78,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    1,   83,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    1,   88,    2, 0x0a /* Public */,
      16,    0,   91,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,

       0        // eod
};

void LocalMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LocalMode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->parseCurrentLine(); break;
        case 1: _t->parseLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->parseAll(); break;
        case 3: _t->speechStart(); break;
        case 4: _t->speechEnd(); break;
        case 5: _t->openFile(); break;
        case 6: _t->newTab(); break;
        case 7: _t->removeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->saveFile(); break;
        case 9: _t->saveFileAs(); break;
        case 10: _t->receiveNewLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->closeWindow(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LocalMode::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_LocalMode.data,
    qt_meta_data_LocalMode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LocalMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LocalMode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LocalMode.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int LocalMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
