/* $NeuraBSD: CoreSeed/src/core/HardwareScanner.cpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/**
* @file HardwareScanner.cpp
* @brief DE: Implementierung der Hardware-Erkennung.
* @brief EN: Implementation of hardware detection.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#include "core/HardwareScanner.hpp"
#include <QSysInfo>

HardwareScanner::HardwareScanner(QObject *parent) : QObject(parent) {}

/**
* @details DE: Nutzt QSysInfo und simulierte sysctl-Abfragen.
* @details EN: Uses QSysInfo and simulated sysctl queries.
*/
QStringList HardwareScanner::getAvailableDisks() {
	QStringList disks;
	// In der finalen Version binden wir hier die sysctl hw.disknames ein
	disks << "sd0 (256 GB)" << "sd1 (1024 GB)" << "wd0 (512 GB)";
	return disks;
}

QString HardwareScanner::getCpuInfo() {
	return QSysInfo::currentCpuArchitecture();
}

long long HardwareScanner::getTotalMemoryMB() {
	// Dummy-Rückgabe für die Simulation
	return 16384;
}
