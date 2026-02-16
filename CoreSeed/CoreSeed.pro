# $NeuraBSD: CoreSeed/CoreSeed.pro, v 1.6 2026/02/16 CodeAkrobat Exp $
#
# DE: Projektkonfiguration für den CoreSeed Installer (Qt6/OpenBSD).
# EN: Project configuration for the CoreSeed installer (Qt6/OpenBSD).
#
# DE: Hard-Tabs (8 Zeichen) für OpenBSD-Konformität.
# EN: Hard tabs (8 chars) for OpenBSD conformity.

QT	+= core gui widgets

CONFIG	+= c++17

TARGET	= coreseed
TEMPLATE	= app

# DE: Suchpfade
INCLUDEPATH	+= src

# DE: Quelldateien
SOURCES	+= \
	src/main.cpp \
	src/core/AutoSlicer.cpp \
	src/core/HardwareScanner.cpp \
	src/core/SysExecutor.cpp \
	src/ui/CoreSeed.cpp \
	src/ui/AutoSlicerVisualizer.cpp \
	src/ui/InstallerPage.cpp \
	src/pages/DiagnosticPage.cpp \
	src/pages/PartitionPage.cpp \
	src/pages/TerminalPage.cpp

# DE: Header-Dateien
HEADERS	+= \
	src/core/AutoSlicer.hpp \
	src/core/HardwareScanner.hpp \
	src/core/SysExecutor.hpp \
	src/ui/CoreSeed.hpp \
	src/ui/AutoSlicerVisualizer.hpp \
	src/ui/InstallerPage.hpp \
	src/pages/DiagnosticPage.hpp \
	src/pages/PartitionPage.hpp \
	src/pages/TerminalPage.hpp

RESOURCES	+= resources.qrc

# DE: Installationsziel
target.path	= /usr/local/bin
INSTALLS	+= target

CONFIG	+= warn_on
