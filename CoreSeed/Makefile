# $NeuraBSD: CoreSeed/Makefile, v 1.19 2026/02/15 CodeAkrobat Exp $

CXX = clang++
MOC = /usr/local/lib/qt6/libexec/moc
CUR_DIR != pwd

QT_INC = -I/usr/local/include/X11/qt6 -I/usr/local/include/X11/qt6/QtWidgets -I/usr/local/include/X11/qt6/QtCore -I/usr/local/include/X11/qt6/QtGui -I${CUR_DIR}/src
QT_LIB = -L/usr/local/lib/X11 -L/usr/local/lib -lQt6Widgets -lQt6Gui -lQt6Core

CXXFLAGS = -std=c++17 -Wall -fPIC ${QT_INC}
LDFLAGS = ${QT_LIB}

SRCS != find src -name '*.cpp' | grep -v '.moc.cpp'
OBJS = ${SRCS:.cpp=.o}

MOC_HEADERS != grep -l "Q_OBJECT" src/pages/*.hpp src/ui/*.hpp src/core/*.hpp 2>/dev/null || true
MOC_SRCS = ${MOC_HEADERS:.hpp=.moc.cpp}
MOC_OBJS = ${MOC_SRCS:.cpp=.o}

all: CoreSeed.bin

CoreSeed.bin: ${OBJS} ${MOC_OBJS}
	${CXX} ${OBJS} ${MOC_OBJS} -o CoreSeed.bin ${LDFLAGS}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

# MOC-Regeln (Explizit ohne $< für BSD-make Kompatibilität)
src/core/HardwareScanner.moc.cpp: src/core/HardwareScanner.hpp
	${MOC} ${QT_INC} src/core/HardwareScanner.hpp -o $@
src/core/SysExecutor.moc.cpp: src/core/SysExecutor.hpp
	${MOC} ${QT_INC} src/core/SysExecutor.hpp -o $@
src/pages/DiagnosticPage.moc.cpp: src/pages/DiagnosticPage.hpp
	${MOC} ${QT_INC} src/pages/DiagnosticPage.hpp -o $@
src/pages/PartitionPage.moc.cpp: src/pages/PartitionPage.hpp
	${MOC} ${QT_INC} src/pages/PartitionPage.hpp -o $@
src/pages/TerminalPage.moc.cpp: src/pages/TerminalPage.hpp
	${MOC} ${QT_INC} src/pages/TerminalPage.hpp -o $@
src/pages/SliceView.moc.cpp: src/pages/SliceView.hpp
	${MOC} ${QT_INC} src/pages/SliceView.hpp -o $@
src/pages/NavigationEngine.moc.cpp: src/pages/NavigationEngine.hpp
	${MOC} ${QT_INC} src/pages/NavigationEngine.hpp -o $@
src/pages/SecurityDialog.moc.cpp: src/pages/SecurityDialog.hpp
	${MOC} ${QT_INC} src/pages/SecurityDialog.hpp -o $@
src/ui/InstallerPage.moc.cpp: src/ui/InstallerPage.hpp
	${MOC} ${QT_INC} src/ui/InstallerPage.hpp -o $@
src/ui/CoreSeed.moc.cpp: src/ui/CoreSeed.hpp
	${MOC} ${QT_INC} src/ui/CoreSeed.hpp -o $@

.SUFFIXES: .moc.cpp .moc.o
.moc.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS} ${MOC_OBJS} src/pages/*.moc.cpp src/ui/*.moc.cpp src/core/*.moc.cpp CoreSeed.bin

.PHONY: all clean
