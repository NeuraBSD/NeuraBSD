/* $NeuraBSD: CoreSeed/src/ui/CoreSeed.cpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Implementierung der Wizard-Steuerung und Seitenregistrierung.
* EN: Implementation of wizard control and page registration.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#include "ui/CoreSeed.hpp"
#include "pages/DiagnosticPage.hpp"
#include "pages/PartitionPage.hpp"
#include "pages/TerminalPage.hpp"
#include <QVBoxLayout>

CoreSeed::CoreSeed(QWidget *parent) : QWizard(parent) {
	setupUi();

	addPage(new DiagnosticPage(this));
	addPage(new PartitionPage(this));
	addPage(new TerminalPage(this));

	setWindowTitle("NeuraBSD CoreSeed Installer");
	setWizardStyle(QWizard::ModernStyle);
}

void CoreSeed::setupUi() {
	resize(800, 600);
}
