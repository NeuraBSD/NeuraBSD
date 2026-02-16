/* $NeuraBSD: CoreSeed/src/core/HardwareScanner.cpp, v 1.2 2026/02/16 CodeAkrobat Exp $ */
/*
 * DE: Implementierung der Hardware-Erkennung via sysctl/dev.
 * EN: Implementation of hardware detection via sysctl/dev.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "core/HardwareScanner.hpp"

HardwareScanner::HardwareScanner(QObject *parent) : QObject(parent) {}

QStringList HardwareScanner::availableDisks() {
	// DE: Dummy-Liste für den Moment, wird später durch sysctl/hw.disknames ersetzt.
	// EN: Dummy list for now, will be replaced by sysctl/hw.disknames later.
	return QStringList() << "sd0 (Virtual Disk)" << "sd1 (Installation Media)";
}

QString HardwareScanner::getCpuInfo() {
	return "Generic x86_64";
}

long long HardwareScanner::getTotalMemoryMB() {
	return 4096;
}
