/* $NeuraBSD: ./src/pages/TerminalPage.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */

/*
 * DE: Header für die Terminal-Emulation (Pro-Modus).
 * EN: Header for the terminal emulation (Pro mode).
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef TERMINALPAGE_HPP
#define TERMINALPAGE_HPP

#include <QWidget>

/**
 * @class TerminalPage
 * @brief DE: Terminal-Ansicht für die Interaktion mit dem OpenBSD-Installer.
 * EN: Terminal view for interaction with the OpenBSD installer.
 */
class TerminalPage : public QWidget {
Q_OBJECT
public:
explicit TerminalPage(QWidget *parent = nullptr);
};

#endif // TERMINALPAGE_HPP
