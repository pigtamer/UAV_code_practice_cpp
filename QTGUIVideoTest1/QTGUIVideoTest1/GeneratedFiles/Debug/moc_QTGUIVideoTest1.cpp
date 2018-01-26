/****************************************************************************
** Meta object code from reading C++ file 'QTGUIVideoTest1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTGUIVideoTest1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTGUIVideoTest1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QTGUIVideoTest1_t {
    QByteArrayData data[8];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTGUIVideoTest1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTGUIVideoTest1_t qt_meta_stringdata_QTGUIVideoTest1 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QTGUIVideoTest1"
QT_MOC_LITERAL(1, 16, 11), // "ModelSelect"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "VideoSelect"
QT_MOC_LITERAL(4, 41, 12), // "CameraSelect"
QT_MOC_LITERAL(5, 54, 10), // "pixmapshow"
QT_MOC_LITERAL(6, 65, 7), // "cv::Mat"
QT_MOC_LITERAL(7, 73, 5) // "frame"

    },
    "QTGUIVideoTest1\0ModelSelect\0\0VideoSelect\0"
    "CameraSelect\0pixmapshow\0cv::Mat\0frame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTGUIVideoTest1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void QTGUIVideoTest1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QTGUIVideoTest1 *_t = static_cast<QTGUIVideoTest1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->ModelSelect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->VideoSelect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->CameraSelect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: _t->pixmapshow((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QTGUIVideoTest1::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QTGUIVideoTest1.data,
      qt_meta_data_QTGUIVideoTest1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QTGUIVideoTest1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTGUIVideoTest1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QTGUIVideoTest1.stringdata0))
        return static_cast<void*>(const_cast< QTGUIVideoTest1*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QTGUIVideoTest1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
