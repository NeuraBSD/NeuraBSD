# $NeuraBSD: CoreSeed/CoreSeed.pro, v 3.0 2026/02/08 CodeAkrobat Exp $
QT       += core gui widgets
CONFIG   += c++2a

TARGET   = CoreSeed
TEMPLATE = app

# Build-Artefakte trennen / Separation of build artifacts
OBJECTS_DIR = build/obj
MOC_DIR     = build/moc
UI_DIR      = build/ui

INCLUDEPATH += src src/ui src/core src/pages
INCLUDEPATH += /usr/local/include/X11/qt6
LIBS        += -L/usr/local/lib

SOURCES += src/main.cpp \
           src/ui/CoreSeed.cpp \
           src/core/SysExecutor.cpp \
           src/core/HardwareScanner.cpp \
           src/pages/DiagnosticPage.cpp \
           src/pages/TerminalPage.cpp \
           src/pages/PartitionPage.cpp

HEADERS += src/ui/CoreSeed.hpp \
           src/ui/InstallerPage.hpp \
           src/core/SysExecutor.hpp \
           src/core/HardwareScanner.hpp \
           src/pages/DiagnosticPage.hpp \
           src/pages/TerminalPage.hpp \
           src/pages/PartitionPage.hpp
