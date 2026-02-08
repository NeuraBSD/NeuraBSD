/* $NeuraBSD: CoreSeed/src/core/HardwareScanner.hpp, v 1.1 2026/02/08 CodeAkrobat Exp $ */
/*
 * DE: Hardware-Erkennungskomponente für das NeuraBSD-System.
 * EN: Hardware detection component for the NeuraBSD system.
 *
 * WAS: Scannt Systemressourcen wie CPU-Modell und Festplattennamen.
 * WIE: Nutzt QProcess zur Abfrage von OpenBSD sysctl-Werten.
 * WARUM: Notwendig für die automatische Konfiguration und Benutzerinformation.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef HARDWARESCANNER_HPP
#define HARDWARESCANNER_HPP

#include <QString>
#include <QStringList>

/**
 * @class HardwareScanner
 * @brief Kapselt den Zugriff auf die OpenBSD Hardware-Abstraktionsschicht.
 */
class HardwareScanner {
public:
    /**
     * @brief Konstruktor für den HardwareScanner.
     */
    HardwareScanner();

    /**
     * @brief Ermittelt das CPU-Modell via sysctl.
     * @return String mit der CPU-Bezeichnung.
     */
    QString getCPUModel();

    /**
     * @brief Listet die im System gefundenen Festplatten auf.
     * @return Liste der Gerätenamen (z.B. sd0, wd0).
     */
    QStringList getDisks();
};

#endif // HARDWARESCANNER_HPP
