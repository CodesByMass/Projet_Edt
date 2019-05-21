#-------------------------------------------------
#
# Project created by QtCreator 2019-05-19T21:40:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ScheduleCreator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    classes/les_cc/Cours.cc \
    classes/les_cc/EDT.cc \
    classes/les_cc/Enseignant.cc \
    classes/les_cc/Filiere.cc \
    classes/les_cc/Groupe.cc \
    classes/les_cc/Matiere.cc \
    classes/les_cc/Ressource.cc \
    classes/les_cc/Salle.cc \
    classes/les_cc/Universite.cc \
    GenerateurEDT/GenerateurEDT.cc \
    IG/Fenetres_ressources/fenetre_enseignant.cpp \
    IG/Fenetres_ressources/fenetre_groupe.cpp \
    IG/Fenetres_ressources/fenetre_matiere.cpp \
    IG/Fenetres_ressources/fenetre_salle.cpp \
    IG/fen_accueil.cpp \
    IG/fen_creation.cpp \
    IG/fen_modificationedt.cpp \
    IG/fen_visualisation.cpp \
    SGF/SGF.cc \
    IG/Fenetres_ressources/fenetre_cours.cpp

HEADERS += \
        mainwindow.h \
    classes/les_h/Cours.h \
    classes/les_h/Data.h \
    classes/les_h/EDT.h \
    classes/les_h/Enseignant.h \
    classes/les_h/Filiere.h \
    classes/les_h/Groupe.h \
    classes/les_h/Matiere.h \
    classes/les_h/Ressource.h \
    classes/les_h/Salle.h \
    classes/les_h/Type.h \
    classes/les_h/Universite.h \
    GenerateurEDT/GenerateurEDT.h \
    IG/Fenetres_ressources/fenetre_enseignant.h \
    IG/Fenetres_ressources/fenetre_groupe.h \
    IG/Fenetres_ressources/fenetre_matiere.h \
    IG/Fenetres_ressources/fenetre_salle.h \
    IG/fen_accueil.h \
    IG/fen_creation.h \
    IG/fen_modificationedt.h \
    IG/fen_visualisation.h \
    SGF/SGF.h \
    IG/Fenetres_ressources/fenetre_cours.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
