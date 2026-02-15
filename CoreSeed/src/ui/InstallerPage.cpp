/* $NeuraBSD: CoreSeed/src/ui/InstallerPage.cpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Implementierung der Basisklasse für Installer-Seiten.
* EN: Implementation of the base class for installer pages.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#include "ui/InstallerPage.hpp"
#include <QVBoxLayout>

InstallerPage::InstallerPage(QWidget *parent) : QWizardPage(parent) {}

void InstallerPage::setPageTitle(const QString &title) {
	setTitle(title);
}
