/* $NeuraBSD: CoreSeed/src/core/HardwareScanner.hpp, v 1.2 2026/02/14 CodeAkrobat Exp $ */
/*
 * DE: Definition der Hardware-Erkennungs-Logik.
 * EN: Definition of the hardware detection logic.
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
 * @brief DE: Scannt das System nach Hardware via sysctl/disklabel.
 */
class HardwareScanner : public QObject {
Q_OBJECT
public:
explicit HardwareScanner(QObject *parent = nullptr);
QStringList getAvailableDisks();
QString getDiskSize(const QString &diskName);
};

#endif
