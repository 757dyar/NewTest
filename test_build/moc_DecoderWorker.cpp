/****************************************************************************
** Meta object code from reading C++ file 'DecoderWorker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/DecoderWorker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DecoderWorker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DecoderWorker_t {
    QByteArrayData data[23];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DecoderWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DecoderWorker_t qt_meta_stringdata_DecoderWorker = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DecoderWorker"
QT_MOC_LITERAL(1, 14, 6), // "imshow"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "const char*"
QT_MOC_LITERAL(4, 34, 10), // "windowName"
QT_MOC_LITERAL(5, 45, 7), // "cv::Mat"
QT_MOC_LITERAL(6, 53, 3), // "mat"
QT_MOC_LITERAL(7, 57, 1), // "x"
QT_MOC_LITERAL(8, 59, 1), // "y"
QT_MOC_LITERAL(9, 61, 11), // "showShading"
QT_MOC_LITERAL(10, 73, 13), // "showDecoderUp"
QT_MOC_LITERAL(11, 87, 13), // "showDecoderVp"
QT_MOC_LITERAL(12, 101, 7), // "newUpVp"
QT_MOC_LITERAL(13, 109, 2), // "up"
QT_MOC_LITERAL(14, 112, 2), // "vp"
QT_MOC_LITERAL(15, 115, 4), // "mask"
QT_MOC_LITERAL(16, 120, 7), // "shading"
QT_MOC_LITERAL(17, 128, 10), // "logMessage"
QT_MOC_LITERAL(18, 139, 3), // "msg"
QT_MOC_LITERAL(19, 143, 5), // "setup"
QT_MOC_LITERAL(20, 149, 14), // "decodeSequence"
QT_MOC_LITERAL(21, 164, 20), // "std::vector<cv::Mat>"
QT_MOC_LITERAL(22, 185, 8) // "frameSeq"

    },
    "DecoderWorker\0imshow\0\0const char*\0"
    "windowName\0cv::Mat\0mat\0x\0y\0showShading\0"
    "showDecoderUp\0showDecoderVp\0newUpVp\0"
    "up\0vp\0mask\0shading\0logMessage\0msg\0"
    "setup\0decodeSequence\0std::vector<cv::Mat>\0"
    "frameSeq"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DecoderWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   54,    2, 0x06 /* Public */,
       9,    1,   63,    2, 0x06 /* Public */,
      10,    1,   66,    2, 0x06 /* Public */,
      11,    1,   69,    2, 0x06 /* Public */,
      12,    4,   72,    2, 0x06 /* Public */,
      17,    1,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,   84,    2, 0x0a /* Public */,
      20,    1,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::UInt, QMetaType::UInt,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5,   13,   14,   15,   16,
    QMetaType::Void, QMetaType::QString,   18,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,

       0        // eod
};

void DecoderWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DecoderWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->imshow((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 1: _t->showShading((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 2: _t->showDecoderUp((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 3: _t->showDecoderVp((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 4: _t->newUpVp((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3])),(*reinterpret_cast< cv::Mat(*)>(_a[4]))); break;
        case 5: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->setup(); break;
        case 7: _t->decodeSequence((*reinterpret_cast< std::vector<cv::Mat>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DecoderWorker::*)(const char * , cv::Mat , unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DecoderWorker::imshow)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DecoderWorker::*)(cv::Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DecoderWorker::showShading)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DecoderWorker::*)(cv::Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DecoderWorker::showDecoderUp)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DecoderWorker::*)(cv::Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DecoderWorker::showDecoderVp)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DecoderWorker::*)(cv::Mat , cv::Mat , cv::Mat , cv::Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DecoderWorker::newUpVp)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DecoderWorker::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DecoderWorker::logMessage)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DecoderWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DecoderWorker.data,
    qt_meta_data_DecoderWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DecoderWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DecoderWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DecoderWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DecoderWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DecoderWorker::imshow(const char * _t1, cv::Mat _t2, unsigned int _t3, unsigned int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DecoderWorker::showShading(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DecoderWorker::showDecoderUp(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DecoderWorker::showDecoderVp(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DecoderWorker::newUpVp(cv::Mat _t1, cv::Mat _t2, cv::Mat _t3, cv::Mat _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DecoderWorker::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
