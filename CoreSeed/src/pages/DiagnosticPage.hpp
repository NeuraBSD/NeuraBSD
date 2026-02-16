/* $NeuraBSD: CoreSeed/src/pages/DiagnosticPage.hpp, v 1.1 2026/02/16 CodeAkrobat Exp $ */
#ifndef DIAGNOSTICPAGE_HPP
#define DIAGNOSTICPAGE_HPP

#include "ui/InstallerPage.hpp"

class DiagnosticPage : public InstallerPage {
	Q_OBJECT
public:
	explicit DiagnosticPage(QWidget *parent = nullptr);
};

#endif // DIAGNOSTICPAGE_HPP
