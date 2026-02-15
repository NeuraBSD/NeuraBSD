/* $NeuraBSD: CoreSeed/src/pages/TerminalPage.cpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
 * DE: Implementierung der Terminal-Anzeigeseite.
 * EN: Implementation of the terminal display page.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "pages/TerminalPage.hpp"
#include <QLabel>
#include <QVBoxLayout>

TerminalPage::TerminalPage(QWidget *parent) : InstallerPage(parent) {
setPageTitle("Installation");
QVBoxLayout *layout = new QVBoxLayout(this);

layout->addWidget(new QLabel("System wird installiert - bitte warten..."));
}
