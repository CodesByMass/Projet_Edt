/****************************************************************************
** Meta object code from reading C++ file 'fen_modificationedt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ScheduleCreator/IG/fen_modificationedt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fen_modificationedt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Fen_ModificationEDT_t {
    QByteArrayData data[22];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Fen_ModificationEDT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Fen_ModificationEDT_t qt_meta_stringdata_Fen_ModificationEDT = {
    {
QT_MOC_LITERAL(0, 0, 19), // "Fen_ModificationEDT"
QT_MOC_LITERAL(1, 20, 16), // "actualise_groupe"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 20), // "actualise_enseignant"
QT_MOC_LITERAL(4, 59, 11), // "Enseignant*"
QT_MOC_LITERAL(5, 71, 1), // "e"
QT_MOC_LITERAL(6, 73, 15), // "actualise_cours"
QT_MOC_LITERAL(7, 89, 6), // "Cours*"
QT_MOC_LITERAL(8, 96, 1), // "c"
QT_MOC_LITERAL(9, 98, 15), // "actualise_salle"
QT_MOC_LITERAL(10, 114, 21), // "ressourceSelectionnee"
QT_MOC_LITERAL(11, 136, 11), // "sauvegarder"
QT_MOC_LITERAL(12, 148, 21), // "cree_fen_ajout_groupe"
QT_MOC_LITERAL(13, 170, 25), // "cree_fen_ajout_enseignant"
QT_MOC_LITERAL(14, 196, 20), // "cree_fen_ajout_salle"
QT_MOC_LITERAL(15, 217, 20), // "cree_fen_ajout_cours"
QT_MOC_LITERAL(16, 238, 19), // "celluleSelectionnee"
QT_MOC_LITERAL(17, 258, 4), // "nRow"
QT_MOC_LITERAL(18, 263, 4), // "nCol"
QT_MOC_LITERAL(19, 268, 13), // "changefiliere"
QT_MOC_LITERAL(20, 282, 18), // "exec_generationEDT"
QT_MOC_LITERAL(21, 301, 4) // "conv"

    },
    "Fen_ModificationEDT\0actualise_groupe\0"
    "\0actualise_enseignant\0Enseignant*\0e\0"
    "actualise_cours\0Cours*\0c\0actualise_salle\0"
    "ressourceSelectionnee\0sauvegarder\0"
    "cree_fen_ajout_groupe\0cree_fen_ajout_enseignant\0"
    "cree_fen_ajout_salle\0cree_fen_ajout_cours\0"
    "celluleSelectionnee\0nRow\0nCol\0"
    "changefiliere\0exec_generationEDT\0conv"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Fen_ModificationEDT[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    1,   85,    2, 0x0a /* Public */,
       6,    1,   88,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,
      16,    2,   98,    2, 0x08 /* Private */,
      19,    0,  103,    2, 0x08 /* Private */,
      20,    0,  104,    2, 0x08 /* Private */,
      21,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Fen_ModificationEDT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Fen_ModificationEDT *_t = static_cast<Fen_ModificationEDT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actualise_groupe(); break;
        case 1: _t->actualise_enseignant((*reinterpret_cast< Enseignant*(*)>(_a[1]))); break;
        case 2: _t->actualise_cours((*reinterpret_cast< Cours*(*)>(_a[1]))); break;
        case 3: _t->actualise_salle(); break;
        case 4: _t->ressourceSelectionnee(); break;
        case 5: _t->sauvegarder(); break;
        case 6: _t->cree_fen_ajout_groupe(); break;
        case 7: _t->cree_fen_ajout_enseignant(); break;
        case 8: _t->cree_fen_ajout_salle(); break;
        case 9: _t->cree_fen_ajout_cours(); break;
        case 10: _t->celluleSelectionnee((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->changefiliere(); break;
        case 12: _t->exec_generationEDT(); break;
        case 13: _t->conv(); break;
        default: ;
        }
    }
}

const QMetaObject Fen_ModificationEDT::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Fen_ModificationEDT.data,
      qt_meta_data_Fen_ModificationEDT,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Fen_ModificationEDT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Fen_ModificationEDT::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Fen_ModificationEDT.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Fen_ModificationEDT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
