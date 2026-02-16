/* $NeuraBSD: CoreSeed/src/main.cpp, v 1.3 2026/02/16 CodeAkrobat Exp $ */
/*
 * DE: Hardware-Audit mit Kapazitaetsberechnung.
 * EN: Hardware audit with capacity calculation.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <iostream>
#include <cmath>

/**
 * @brief DE: Ermittelt die Groesse eines Laufwerks via disklabel.
 * @brief EN: Determines the size of a drive via disklabel.
 */
double getDiskSizeGB(const QString& diskName) {
QProcess disklabel;
// Wir fragen nur die Geometrie ab (-g)
disklabel.start("disklabel", QStringList() << diskName);
if (!disklabel.waitForFinished()) return 0.0;

QString output = QString::fromLocal8Bit(disklabel.readAllStandardOutput());
// Wir suchen die Zeile mit 'total sectors:'
QStringList lines = output.split('\n');
long long sectors = 0;

for (const QString& line : lines) {
if (line.contains("total sectors:")) {
sectors = line.section(':', 1).trimmed().toLongLong();
break;
}
}

/* Berechnung: Sektoren * 512 Bytes / 1024^3 */
return std::round((sectors * 512.0) / (1024.0 * 1024.0 * 1024.0));
}

void performHardwareAudit() {
std::cout << "\n[CoreSeed] Starte erweitertes Hardware-Audit..." << std::endl;

QProcess sysctl;
sysctl.start("sysctl", QStringList() << "hw.disknames");
sysctl.waitForFinished();

QString output = QString::fromLocal8Bit(sysctl.readAllStandardOutput()).trimmed();
QStringList devices = output.section('=', 1).split(',', Qt::SkipEmptyParts);

for (const QString& device : devices) {
QString diskName = device.section(':', 0, 0).trimmed();
double size = getDiskSizeGB(diskName);
std::cout << " -> " << diskName.toStdString() << " [" << size << " GB] [BEREIT]" << std::endl;
}
std::cout << "[CoreSeed] Audit abgeschlossen.\n" << std::endl;
}

int main(int argc, char *argv[]) {
qputenv("QT_QPA_PLATFORM", "offscreen");
QCoreApplication app(argc, argv);
performHardwareAudit();
return 0;
}
