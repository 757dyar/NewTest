/****************************************************************************
** Meta object code from reading C++ file 'TriangulatorWorker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/TriangulatorWorker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TriangulatorWorker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TriangulatorWorker_t {
    QByteArrayData data[20];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TriangulatorWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TriangulatorWorker_t qt_meta_stringdata_TriangulatorWorker = {
    {
QT_MOC_LITERAL(0, 0, 18), // "TriangulatorWorker"
QT_MOC_LITERAL(1, 19, 6), // "imshow"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "const char*"
QT_MOC_LITERAL(4, 39, 10), // "windowName"
QT_MOC_LITERAL(5, 50, 7), // "cv::Mat"
QT_MOC_LITERAL(6, 58, 3), // "mat"
QT_MOC_LITERAL(7, 62, 1), // "x"
QT_MOC_LITERAL(8, 64, 1), // "y"
QT_MOC_LITERAL(9, 66, 13), // "newPointCloud"
QT_MOC_LITERAL(10, 80, 18), // "PointCloudConstPtr"
QT_MOC_LITERAL(11, 99, 10), // "pointCloud"
QT_MOC_LITERAL(12, 110, 10), // "logMessage"
QT_MOC_LITERAL(13, 121, 3), // "msg"
QT_MOC_LITERAL(14, 125, 5), // "setup"
QT_MOC_LITERAL(15, 131, 21), // "triangulatePointCloud"
QT_MOC_LITERAL(16, 153, 2), // "up"
QT_MOC_LITERAL(17, 156, 2), // "vp"
QT_MOC_LITERAL(18, 159, 4), // "mask"
QT_MOC_LITERAL(19, 164, 7) // "shading"

    },
    "TriangulatorWorker\0imshow\0\0const char*\0"
    "windowName\0cv::Mat\0mat\0x\0y\0newPointCloud\0"
    "PointCloudConstPtr\0pointCloud\0logMessage\0"
    "msg\0setup\0triangulatePointCloud\0up\0"
    "vp\0mask\0shading"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TriangulatorWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,
       9,    1,   48,    2, 0x06 /* Public */,
      12,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   54,    2, 0x0a /* Public */,
      15,    4,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::UInt, QMetaType::UInt,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5,   16,   17,   18,   19,

       0        // eod
};

void TriangulatorWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TriangulatorWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->imshow((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 1: _t->newPointCloud((*reinterpret_cast< PointCloudConstPtr(*)>(_a[1]))); break;
        case 2: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setup(); break;
        case 4: _t->triangulatePointCloud((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3])),(*reinterpret_cast< cv::Mat(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TriangulatorWorker::*)(const char * , cv::Mat , unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TriangulatorWorker::imshow)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TriangulatorWorker::*)(PointCloudConstPtr );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TriangulatorWorker::newPointCloud)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TriangulatorWorker::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TriangulatorWorker::logMessage)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TriangulatorWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TriangulatorWorker.data,
    qt_meta_data_TriangulatorWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TriangulatorWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TriangulatorWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TriangulatorWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TriangulatorWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void TriangulatorWorker::imshow(const char * _t1, cv::Mat _t2, unsigned int _t3, unsigned int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TriangulatorWorker::newPointCloud(PointCloudConstPtr _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TriangulatorWorker::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
