/* $NeuraBSD: CoreSeed/src/main.cpp, v 1.6 2026/02/14 CodeAkrobat Exp $ */
#include <QApplication>
#include "CoreSeed.hpp"
int main(int argc, char *argv[]) {
QApplication a(argc, argv);
CoreSeed wizard;
wizard.show();
return a.exec();
}
