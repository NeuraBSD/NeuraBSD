/* $NeuraBSD: CoreSeed/src/pages/DiagnosticPage.hpp, v 1.2 2026/02/14 CodeAkrobat Exp $ */
/*
* DE: Seite für die Hardware-Diagnose vor der Installation.
* EN: Page for hardware diagnostics before installation.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#ifndef DIAGNOSTICPAGE_HPP
#define DIAGNOSTICPAGE_HPP

#include "InstallerPage.hpp"

class DiagnosticPage : public InstallerPage {
	Q_OBJECT
	public:
		explicit DiagnosticPage(QWidget *parent = nullptr);
	};

	#endif
