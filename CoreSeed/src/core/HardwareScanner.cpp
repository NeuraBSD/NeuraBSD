/* $NeuraBSD: ./src/core/HardwareScanner.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Implementierung der Hardware-Erkennung für CoreSeed.
 * EN: Implementation of hardware detection for CoreSeed.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "HardwareScanner.hpp"
#include <QProcess>
#include <QDebug>

/**
 * @file HardwareScanner.cpp
 * @de Abstraktionsschicht zwischen Systembefehlen und dem grafischen Installer.
 * @en Abstraction layer between system commands and the graphical installer.
 */

/**
 * @de Initialisiert den Scanner. In der aktuellen Phase werden Testgeräte geladen.
 * @en Initializes the scanner. Test devices are loaded in the current phase.
 */
HardwareScanner::HardwareScanner(QObject *parent)
: QObject(parent)
{
/* * TODO: Hier später sysctl hw.disknames oder geom disk list (FreeBSD) implementieren.
 * Aktuell nutzen wir NeuraBSD-Testprofile für die Design-Validierung.
 */
m_diskMap.insert("sd0 (OpenBSD Virtual Disk)", 120.0);
m_diskMap.insert("sd1 (NeuraStorage)", 2048.0);
m_diskMap.insert("nvme0 (System Flash)", 512.0);
}

/**
 * @de Extrahiert die Gerätenamen aus der internen Map für die UI-Auswahl.
 * @en Extracts device names from the internal map for UI selection.
 */
QStringList HardwareScanner::getAvailableDisks()
{
return m_diskMap.keys();
}

/**
 * @de Liefert die Kapazität, die als Basis für den AutoSlicer dient.
 * @en Provides the capacity used as a base for the AutoSlicer.
 */
double HardwareScanner::getDiskCapacity(const QString &diskName)
{
return m_diskMap.value(diskName, 0.0);
}
