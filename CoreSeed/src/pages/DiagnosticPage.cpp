/* $NeuraBSD: CoreSeed/src/pages/DiagnosticPage.cpp, v 1.2 2026/02/08 CodeAkrobat Exp $ */
/**
 * @file DiagnosticPage.cpp
 * @brief Implementierung der Hardware-Diagnoseseite.
 * * DE: Nutzt den HardwareScanner, um Live-Daten von OpenBSD zu beziehen.
 * EN: Uses HardwareScanner to retrieve live data from OpenBSD.
 * * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "DiagnosticPage.hpp"
#include "core/HardwareScanner.hpp"

/**
 * DE: Erstellt das Layout und die Platzhalter-Labels.
 * EN: Creates the layout and placeholder labels.
 */
DiagnosticPage::DiagnosticPage(QWidget *parent) : InstallerPage(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(40, 40, 40, 40);

    QLabel *header = new QLabel("Systemdiagnose / System Check");
    header->setStyleSheet("font-size: 20px; font-weight: bold; color: #4a90e2;");

    cpuInfo = new QLabel("CPU: Ermittle Daten...");
    diskInfo = new QLabel("Disks: Ermittle Daten...");

    layout->addWidget(header);
    layout->addSpacing(30);
    layout->addWidget(cpuInfo);
    layout->addWidget(diskInfo);
    layout->addStretch();
}

/**
 * DE: Aktualisiert die Anzeige mit echten Systemwerten beim Seitenwechsel.
 * EN: Updates the display with real system values on page change.
 */
void DiagnosticPage::onEnter() {
    HardwareScanner scanner;
    
    // CPU-Daten setzen / Set CPU data
    cpuInfo->setText("Detected CPU: " + scanner.getCPUModel());
    
    // Festplatten-Daten setzen / Set Disk data
    diskInfo->setText("Available Disks: " + scanner.getDisks().join(", "));
}
