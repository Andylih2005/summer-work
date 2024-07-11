/****************************************************************************
** Meta object code from reading C++ file 'changebook.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../changebook.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changebook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSchangebookENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSchangebookENDCLASS = QtMocHelpers::stringData(
    "changebook",
    "on_back_button_clicked",
    "",
    "on_change_button_clicked",
    "on_None_button_clicked",
    "on_PersonalMode_Button_clicked",
    "on_FindBookMode_Button_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSchangebookENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[11];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[23];
    char stringdata5[31];
    char stringdata6[31];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSchangebookENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSchangebookENDCLASS_t qt_meta_stringdata_CLASSchangebookENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "changebook"
        QT_MOC_LITERAL(11, 22),  // "on_back_button_clicked"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 24),  // "on_change_button_clicked"
        QT_MOC_LITERAL(60, 22),  // "on_None_button_clicked"
        QT_MOC_LITERAL(83, 30),  // "on_PersonalMode_Button_clicked"
        QT_MOC_LITERAL(114, 30)   // "on_FindBookMode_Button_clicked"
    },
    "changebook",
    "on_back_button_clicked",
    "",
    "on_change_button_clicked",
    "on_None_button_clicked",
    "on_PersonalMode_Button_clicked",
    "on_FindBookMode_Button_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSchangebookENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject changebook::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSchangebookENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSchangebookENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSchangebookENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<changebook, std::true_type>,
        // method 'on_back_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_change_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_None_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PersonalMode_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_FindBookMode_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void changebook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<changebook *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_back_button_clicked(); break;
        case 1: _t->on_change_button_clicked(); break;
        case 2: _t->on_None_button_clicked(); break;
        case 3: _t->on_PersonalMode_Button_clicked(); break;
        case 4: _t->on_FindBookMode_Button_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *changebook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *changebook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSchangebookENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int changebook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
