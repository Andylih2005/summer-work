/****************************************************************************
** Meta object code from reading C++ file 'checkbook.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../checkbook.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'checkbook.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASScheckbookENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASScheckbookENDCLASS = QtMocHelpers::stringData(
    "checkbook",
    "on_PersonalMode_Button_clicked",
    "",
    "on_FindBookMode_Button_clicked",
    "on_reduce_button_clicked",
    "on_raise_button_clicked",
    "on_pages_textChanged",
    "on_pushButton_4_clicked",
    "on_search_button_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASScheckbookENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[10];
    char stringdata1[31];
    char stringdata2[1];
    char stringdata3[31];
    char stringdata4[25];
    char stringdata5[24];
    char stringdata6[21];
    char stringdata7[24];
    char stringdata8[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASScheckbookENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASScheckbookENDCLASS_t qt_meta_stringdata_CLASScheckbookENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "checkbook"
        QT_MOC_LITERAL(10, 30),  // "on_PersonalMode_Button_clicked"
        QT_MOC_LITERAL(41, 0),  // ""
        QT_MOC_LITERAL(42, 30),  // "on_FindBookMode_Button_clicked"
        QT_MOC_LITERAL(73, 24),  // "on_reduce_button_clicked"
        QT_MOC_LITERAL(98, 23),  // "on_raise_button_clicked"
        QT_MOC_LITERAL(122, 20),  // "on_pages_textChanged"
        QT_MOC_LITERAL(143, 23),  // "on_pushButton_4_clicked"
        QT_MOC_LITERAL(167, 24)   // "on_search_button_clicked"
    },
    "checkbook",
    "on_PersonalMode_Button_clicked",
    "",
    "on_FindBookMode_Button_clicked",
    "on_reduce_button_clicked",
    "on_raise_button_clicked",
    "on_pages_textChanged",
    "on_pushButton_4_clicked",
    "on_search_button_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASScheckbookENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject checkbook::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASScheckbookENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASScheckbookENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASScheckbookENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<checkbook, std::true_type>,
        // method 'on_PersonalMode_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_FindBookMode_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_reduce_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_raise_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pages_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_search_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void checkbook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<checkbook *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_PersonalMode_Button_clicked(); break;
        case 1: _t->on_FindBookMode_Button_clicked(); break;
        case 2: _t->on_reduce_button_clicked(); break;
        case 3: _t->on_raise_button_clicked(); break;
        case 4: _t->on_pages_textChanged(); break;
        case 5: _t->on_pushButton_4_clicked(); break;
        case 6: _t->on_search_button_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *checkbook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *checkbook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASScheckbookENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int checkbook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
