/* $NeuraBSD: CoreSeed/src/main.cpp, v 1.5 2026/02/14 CodeAkrobat Exp $ */
#include <QCoreApplication>
#include <QDebug>
#include "HardwareScanner.hpp"

int main(int argc, char *argv[]) {
QCoreApplication a(argc, argv);
qDebug() << "--- NeuraBSD Hardware Reality-Check ---";

HardwareScanner scanner;
for (const QString &disk : scanner.getAvailableDisks()) {
qDebug() << "Disk:" << disk << "Size:" << scanner.getDiskSize(disk);
}

return 0;
}
