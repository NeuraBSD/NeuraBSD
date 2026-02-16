/* $NeuraBSD: CoreSeed/src/pages/DiagnosticPage.hpp, v 1.1 2026/02/16 CodeAkrobat Exp $ */
#include "pages/DiagnosticPage.hpp"
#include <QVBoxLayout>
#include <QLabel>

DiagnosticPage::DiagnosticPage(QWidget *parent) : InstallerPage(parent) {
	setPageTitle(tr("System-Diagnose"));
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(new QLabel(tr("Hardware-Check wird vorbereitet..."), this));
}
