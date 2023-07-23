/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[34];
    char stringdata0[510];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "newPointCloud"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "PointCloudConstPtr"
QT_MOC_LITERAL(4, 45, 10), // "pointCloud"
QT_MOC_LITERAL(5, 56, 10), // "logMessage"
QT_MOC_LITERAL(6, 67, 3), // "msg"
QT_MOC_LITERAL(7, 71, 13), // "onActionStart"
QT_MOC_LITERAL(8, 85, 12), // "onActionStop"
QT_MOC_LITERAL(9, 98, 20), // "onScanWorkerFinished"
QT_MOC_LITERAL(10, 119, 19), // "onActionCalibration"
QT_MOC_LITERAL(11, 139, 23), // "onActionLoadCalibration"
QT_MOC_LITERAL(12, 163, 19), // "onActionPreferences"
QT_MOC_LITERAL(13, 183, 25), // "onActionExportCalibration"
QT_MOC_LITERAL(14, 209, 17), // "updateDisplayRate"
QT_MOC_LITERAL(15, 227, 20), // "receiveNewPointCloud"
QT_MOC_LITERAL(16, 248, 6), // "imshow"
QT_MOC_LITERAL(17, 255, 11), // "const char*"
QT_MOC_LITERAL(18, 267, 10), // "windowName"
QT_MOC_LITERAL(19, 278, 7), // "cv::Mat"
QT_MOC_LITERAL(20, 286, 2), // "im"
QT_MOC_LITERAL(21, 289, 1), // "x"
QT_MOC_LITERAL(22, 291, 1), // "y"
QT_MOC_LITERAL(23, 293, 4), // "hist"
QT_MOC_LITERAL(24, 298, 15), // "onShowHistogram"
QT_MOC_LITERAL(25, 314, 13), // "onShowShading"
QT_MOC_LITERAL(26, 328, 18), // "onShowCameraFrames"
QT_MOC_LITERAL(27, 347, 20), // "std::vector<cv::Mat>"
QT_MOC_LITERAL(28, 368, 8), // "frameSeq"
QT_MOC_LITERAL(29, 377, 15), // "onShowDecoderUp"
QT_MOC_LITERAL(30, 393, 15), // "onShowDecoderVp"
QT_MOC_LITERAL(31, 409, 13), // "onActionAbout"
QT_MOC_LITERAL(32, 423, 39), // "on_actionUpload_Scan_Patterns..."
QT_MOC_LITERAL(33, 463, 46) // "on_actionUpload_Calibration_P..."

    },
    "MainWindow\0newPointCloud\0\0PointCloudConstPtr\0"
    "pointCloud\0logMessage\0msg\0onActionStart\0"
    "onActionStop\0onScanWorkerFinished\0"
    "onActionCalibration\0onActionLoadCalibration\0"
    "onActionPreferences\0onActionExportCalibration\0"
    "updateDisplayRate\0receiveNewPointCloud\0"
    "imshow\0const char*\0windowName\0cv::Mat\0"
    "im\0x\0y\0hist\0onShowHistogram\0onShowShading\0"
    "onShowCameraFrames\0std::vector<cv::Mat>\0"
    "frameSeq\0onShowDecoderUp\0onShowDecoderVp\0"
    "onActionAbout\0on_actionUpload_Scan_Patterns_triggered\0"
    "on_actionUpload_Calibration_Patterns_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       5,    1,  122,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  125,    2, 0x08 /* Private */,
       8,    0,  126,    2, 0x08 /* Private */,
       9,    0,  127,    2, 0x08 /* Private */,
      10,    0,  128,    2, 0x08 /* Private */,
      11,    0,  129,    2, 0x08 /* Private */,
      12,    0,  130,    2, 0x08 /* Private */,
      13,    0,  131,    2, 0x08 /* Private */,
      14,    0,  132,    2, 0x08 /* Private */,
      15,    1,  133,    2, 0x08 /* Private */,
      16,    4,  136,    2, 0x08 /* Private */,
      23,    4,  145,    2, 0x08 /* Private */,
      24,    1,  154,    2, 0x08 /* Private */,
      25,    1,  157,    2, 0x08 /* Private */,
      26,    1,  160,    2, 0x08 /* Private */,
      29,    1,  163,    2, 0x08 /* Private */,
      30,    1,  166,    2, 0x08 /* Private */,
      31,    0,  169,    2, 0x08 /* Private */,
      32,    0,  170,    2, 0x08 /* Private */,
      33,    0,  171,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 19, QMetaType::UInt, QMetaType::UInt,   18,   20,   21,   22,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 19, QMetaType::UInt, QMetaType::UInt,   18,   20,   21,   22,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newPointCloud((*reinterpret_cast< PointCloudConstPtr(*)>(_a[1]))); break;
        case 1: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onActionStart(); break;
        case 3: _t->onActionStop(); break;
        case 4: _t->onScanWorkerFinished(); break;
        case 5: _t->onActionCalibration(); break;
        case 6: _t->onActionLoadCalibration(); break;
        case 7: _t->onActionPreferences(); break;
        case 8: _t->onActionExportCalibration(); break;
        case 9: _t->updateDisplayRate(); break;
        case 10: _t->receiveNewPointCloud((*reinterpret_cast< PointCloudConstPtr(*)>(_a[1]))); break;
        case 11: _t->imshow((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 12: _t->hist((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 13: _t->onShowHistogram((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 14: _t->onShowShading((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 15: _t->onShowCameraFrames((*reinterpret_cast< std::vector<cv::Mat>(*)>(_a[1]))); break;
        case 16: _t->onShowDecoderUp((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 17: _t->onShowDecoderVp((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 18: _t->onActionAbout(); break;
        case 19: _t->on_actionUpload_Scan_Patterns_triggered(); break;
        case 20: _t->on_actionUpload_Calibration_Patterns_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(PointCloudConstPtr );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::newPointCloud)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::logMessage)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::newPointCloud(PointCloudConstPtr _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
