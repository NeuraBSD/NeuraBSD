/* $NeuraBSD: CoreSeed/src/core/HardwareScanner.cpp, v 1.1 2026/02/08 CodeAkrobat Exp $ */
/*
 * DE: Implementierung der Hardware-Abfrage via OpenBSD-Systembefehlen.
 * EN: Implementation of hardware queries via OpenBSD system commands.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "HardwareScanner.hpp"
#include <QProcess>
#include <QDebug>

HardwareScanner::HardwareScanner() {
    // Initialisierung falls benötigt / Initialization if needed
}

/**
 * WAS: CPU-Modell auslesen.
 * WIE: Aufruf von 'sysctl -n hw.model'.
 * WARUM: Um dem Benutzer anzuzeigen, auf welcher Hardware er installiert.
 */
QString HardwareScanner::getCPUModel() {
    QProcess process;
    process.start("sysctl", QStringList() << "-n" << "hw.model");
    if (!process.waitForFinished()) {
        return "Unknown CPU";
    }
    return QString(process.readAllStandardOutput()).trimmed();
}

/**
 * WAS: Festplattennamen ermitteln.
 * WIE: Abfrage von 'sysctl -n hw.disknames'.
 * WARUM: Identifikation der Zielmedien für die Installation.
 */
QStringList HardwareScanner::getDisks() {
    QProcess process;
    process.start("sysctl", QStringList() << "-n" << "hw.disknames");
    if (!process.waitForFinished()) {
        return QStringList() << "No disks found";
    }
    
    QString output = QString(process.readAllStandardOutput()).trimmed();
    // OpenBSD liefert z.B. "sd0:xxxx,sd1:yyyy", wir splitten das:
    QStringList rawList = output.split(",");
    QStringList cleanList;
    
    for (const QString &entry : rawList) {
        // Wir nehmen nur den Teil vor dem Doppelpunkt (z.B. sd0)
        cleanList << entry.split(":").first();
    }
    
    return cleanList;
}
