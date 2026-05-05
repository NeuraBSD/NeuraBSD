# $NeuraBSD: CoreSeed.pro, v 1.5 2026/02/14 CodeAkrobat Exp $
# DE: Projektkonfiguration für CoreSeed.
# EN: Project configuration for CoreSeed.

QT += core gui widgets
CONFIG += c++2a

TARGET = CoreSeed
TEMPLATE = app

# DE: Suchpfade für Header
# EN: Search paths for headers
INCLUDEPATH += src/core src/pages src/ui

HEADERS += src/core/HardwareScanner.hpp \
src/core/SysExecutor.hpp \
src/pages/DiagnosticPage.hpp \
src/pages/PartitionPage.hpp \
src/pages/TerminalPage.hpp \
src/ui/CoreSeed.hpp \
src/ui/InstallerPage.hpp

SOURCES += src/main.cpp \
src/core/HardwareScanner.cpp \
src/core/SysExecutor.cpp \
src/pages/DiagnosticPage.cpp \
src/pages/PartitionPage.cpp \
src/pages/TerminalPage.cpp \
src/ui/CoreSeed.cpp \
src/ui/InstallerPage.cpp

MOC_DIR = build/moc
OBJECTS_DIR = build/obj
