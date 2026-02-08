/* $NeuraBSD: CoreSeed/src/main.cpp, v 2.6 2026/02/08 CodeAkrobat Exp $ */
/*
 * DE: Hauptinstanz des grafischen Installers.
 * EN: Main instance of the graphical installer.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include <QApplication>
#include "ui/CoreSeed.hpp"
#include "pages/DiagnosticPage.hpp"
#include "pages/PartitionPage.hpp"
#include "pages/TerminalPage.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    CoreSeed wizard;
    wizard.setWindowTitle("NeuraBSD CoreSeed - Installation");

    // Seiten-Reihenfolge (Modularer Aufbau)
    wizard.addPage(new DiagnosticPage(&wizard)); // Schritt 1: HW-Check
    wizard.addPage(new PartitionPage(&wizard));  // Schritt 2: Partitionierung
    wizard.addPage(new TerminalPage(&wizard));   // Schritt 3: Profi-Konsole

    wizard.show();
    return app.exec();
}
