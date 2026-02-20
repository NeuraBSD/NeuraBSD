QT       += core gui widgets

TARGET = coreseed
CONFIG += c++17
TEMPLATE = app

# Suchpfade
INCLUDEPATH += . src src/core src/ui src/pages

# Source-Dateien
SOURCES += src/main.cpp \
    src/core/AutoSlicer.cpp \
    src/core/HardwareScanner.cpp \
    src/core/SysExecutor.cpp \
    src/core/ConfigManager.cpp \
    src/ui/CoreSeed.cpp \
    src/ui/AutoSlicerVisualizer.cpp \
    src/ui/InstallerPage.cpp \
    src/pages/DiagnosticPage.cpp \
    src/pages/PartitionPage.cpp \
    src/pages/TerminalPage.cpp

# Header-Dateien
HEADERS += src/core/AutoSlicer.hpp \
    src/core/HardwareScanner.hpp \
    src/core/SysExecutor.hpp \
    src/core/ConfigManager.hpp \
    src/ui/CoreSeed.hpp \
    src/ui/AutoSlicerVisualizer.hpp \
    src/ui/InstallerPage.hpp \
    src/pages/DiagnosticPage.hpp \
    src/pages/PartitionPage.hpp \
    src/pages/TerminalPage.hpp

# Ressourcen
RESOURCES += resources.qrc

# OpenBSD spezifische Pfade
INCLUDEPATH += /usr/local/include/X11/qt6
LIBS += -L/usr/local/lib
