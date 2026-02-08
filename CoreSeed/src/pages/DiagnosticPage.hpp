/* $NeuraBSD: CoreSeed/src/pages/DiagnosticPage.hpp, v 1.3 2026/02/08 CodeAkrobat Exp $ */
/*
 * DE: UI-Modul für die Hardware-Diagnose.
 * EN: UI module for hardware diagnostics.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef DIAGNOSTICPAGE_HPP
#define DIAGNOSTICPAGE_HPP

#include "ui/InstallerPage.hpp"
#include <QLabel>
#include <QVBoxLayout>

/**
 * @class DiagnosticPage
 * @brief Seite zur Anzeige der Systemressourcen.
 * * DE: Diese Klasse liest via HardwareScanner die Systemdaten aus und zeigt sie an.
 * EN: This class reads system data via HardwareScanner and displays it.
 */
class DiagnosticPage : public InstallerPage {
    Q_OBJECT
public:
    /**
     * @brief Konstruktor der Diagnoseseite.
     * @param parent Das Eltern-Widget.
     */
    explicit DiagnosticPage(QWidget *parent = nullptr);

    /**
     * @brief Aktualisiert die Hardware-Infos beim Betreten der Seite.
     * DE: Implementiert die Logik zum Refresh der CPU- und Disk-Label.
     * EN: Implements the logic to refresh CPU and disk labels.
     */
    void onEnter() override;

private:
    QLabel *cpuInfo;  ///< DE: Label für CPU Modell / EN: Label for CPU model
    QLabel *diskInfo; ///< DE: Label für Festplatten / EN: Label for disks
};

#endif
