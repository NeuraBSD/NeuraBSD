/* $NeuraBSD: CoreSeed/src/pages/DiagnosticPage.hpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Seite für die Systemdiagnose und Hardware-Prüfung.
* EN: Page for system diagnostics and hardware verification.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#ifndef DIAGNOSTICPAGE_HPP
#define DIAGNOSTICPAGE_HPP

#include "ui/InstallerPage.hpp"

/**
* @class DiagnosticPage
* @brief DE: Zeigt Hardware-Informationen vor der Installation an.
* @brief EN: Displays hardware information prior to installation.
*/
class DiagnosticPage : public InstallerPage {
	Q_OBJECT

	public:
		explicit DiagnosticPage(QWidget *parent = nullptr);
	};

	#endif // DIAGNOSTICPAGE_HPP
