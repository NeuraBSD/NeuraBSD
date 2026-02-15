/* $NeuraBSD: CoreSeed/src/core/HardwareScanner.cpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
 * DE: Implementierung der Hardware-Abfrage.
 * EN: Implementation of hardware queries.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "core/HardwareScanner.hpp"
#include <QProcess>

HardwareScanner::HardwareScanner(QObject *parent) : QObject(parent) {}

QStringList HardwareScanner::getAvailableDrives() {
QStringList drives;
QProcess process;
process.start("sysctl", QStringList() << "-n" << "hw.disknames");
if (process.waitForFinished()) {
QString output = process.readAllStandardOutput().trimmed();
QStringList entries = output.split(",");
for (const QString &entry : entries) {
drives << entry.split(":").first();
}
}
return drives;
}

QString HardwareScanner::getCpuArchitecture() {
QProcess process;
process.start("sysctl", QStringList() << "-n" << "hw.machine");
if (process.waitForFinished()) {
return process.readAllStandardOutput().trimmed();
}
return "unknown";
}
