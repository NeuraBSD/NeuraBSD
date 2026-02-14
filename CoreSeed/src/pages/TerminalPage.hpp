/* $NeuraBSD: CoreSeed/src/pages/TerminalPage.hpp, v 1.2 2026/02/14 CodeAkrobat Exp $ */
#ifndef TERMINALPAGE_HPP
#define TERMINALPAGE_HPP

#include "InstallerPage.hpp"

class TerminalPage : public InstallerPage {
	Q_OBJECT
	public:
		explicit TerminalPage(QWidget *parent = nullptr);
	};

	#endif
