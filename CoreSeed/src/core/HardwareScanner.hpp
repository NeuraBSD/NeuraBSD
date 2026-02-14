/* $NeuraBSD: CoreSeed/src/core/HardwareScanner.hpp, v 1.3 2026/02/14 CodeAkrobat Exp $ */
/*
 * DE: Definition der Hardware-Erkennung für den Installer.
 * EN: Definition of the hardware detection for the installer.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef HARDWARESCANNER_HPP
#define HARDWARESCANNER_HPP

#include <QObject>
#include <QStringList>

/**
 * @class HardwareScanner
 * @brief DE: Scannt Festplatten und Hardware via OpenBSD-Systembefehlen.
 * @brief EN: Scans disks and hardware via OpenBSD system commands.
 */
class HardwareScanner : public QObject {
Q_OBJECT
public:
explicit HardwareScanner(QObject *parent = nullptr);

/**
 * @brief DE: Gibt eine Liste aller erkannten Festplatten zurück.
 * @brief EN: Returns a list of all detected disks.
 */
QStringList getAvailableDisks();

/**
 * @brief DE: Ermittelt die Größe einer Festplatte in GB.
 * @brief EN: Determines the size of a disk in GB.
 * @param diskName Name der Disk (sd0, etc.)
 */
QString getDiskSize(const QString &diskName);
};

#endif
