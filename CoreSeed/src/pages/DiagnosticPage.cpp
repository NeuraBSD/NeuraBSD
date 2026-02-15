/* $NeuraBSD: CoreSeed/src/pages/DiagnosticPage.cpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Implementierung der Diagnoseseite.
* EN: Implementation of the diagnostic page.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#include "pages/DiagnosticPage.hpp"
#include <QLabel>
#include <QVBoxLayout>

DiagnosticPage::DiagnosticPage(QWidget *parent) : InstallerPage(parent) {
	setPageTitle("System-Check");
	QVBoxLayout *layout = new QVBoxLayout(this);

	QLabel *info = new QLabel("Scanne Hardware-Komponenten...");
	layout->addWidget(info);
}
