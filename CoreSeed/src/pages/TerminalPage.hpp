/* $NeuraBSD: CoreSeed/src/pages/TerminalPage.hpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
 * DE: Seite zur Anzeige des Installationsfortschritts (Terminal-Emulation).
 * EN: Page for displaying installation progress (terminal emulation).
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef TERMINALPAGE_HPP
#define TERMINALPAGE_HPP

#include "ui/InstallerPage.hpp"

/**
 * @class TerminalPage
 * @brief DE: Zeigt den Output des Installationsprozesses an.
 * @brief EN: Displays the output of the installation process.
 */
class TerminalPage : public InstallerPage {
Q_OBJECT

public:
explicit TerminalPage(QWidget *parent = nullptr);
};

#endif // TERMINALPAGE_HPP
