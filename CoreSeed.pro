# $NeuraBSD: CoreSeed.pro, v 1.2 2026/02/14 CodeAkrobat Exp $
# DE: Projektdatei für den CoreSeed Installer.
# EN: Project file for the CoreSeed installer.

QT += core gui widgets

TARGET = CoreSeed
TEMPLATE = app

# DE: Verzeichnisse für Header und Build-Artefakte
# EN: Directories for headers and build artifacts
INCLUDEPATH += include
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

# DE: Header Dateien
# EN: Header files
HEADERS += include/HardwareScanner.h

# DE: Source Dateien
# EN: Source files
SOURCES += src/main.cpp \
src/HardwareScanner.cpp

# DE: Installationspfad (Standard für OpenBSD /usr/local/bin)
# EN: Installation path (Default for OpenBSD /usr/local/bin)
target.path = /usr/local/bin
INSTALLS += target
