/* $NeuraBSD: CoreSeed/src/pages/TerminalPage.hpp, v 1.1 2026/02/16 CodeAkrobat Exp $ */
/*
 * DE: UI-Komponente zur Anzeige von System-Logs und Fortschritt.
 * EN: UI component for displaying system logs and progress.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef TERMINALPAGE_HPP
#define TERMINALPAGE_HPP

#include "ui/InstallerPage.hpp"
#include <QTextEdit>
#include <QProgressBar>
#include <QTime>

/**
 * @class TerminalPage
 * @brief DE: Konsolen-Ansicht für den Installationsprozess.
 * EN: Console view for the installation process.
 *
 * @details DE: Diese Seite empfängt Signale vom SysExecutor und visualisiert 
 * den Fortschritt sowie die Log-Ausgaben im NeuraBSD-Design.
 * EN: This page receives signals from the SysExecutor and visualizes 
 * progress and log output in NeuraBSD design.
 */
class TerminalPage : public InstallerPage {
	Q_OBJECT

public:
	explicit TerminalPage(QWidget *parent = nullptr);

public slots:
	/**
	 * @brief DE: Schreibt eine Nachricht in das Terminal.
	 * EN: Writes a message to the terminal.
	 */
	void appendLog(const QString &msg);

	/**
	 * @brief DE: Aktualisiert den Fortschrittsbalken.
	 * EN: Updates the progress bar.
	 */
	void setProgress(int value);

private:
	QTextEdit	*m_console;
	QProgressBar	*m_progressBar;
};

#endif // TERMINALPAGE_HPP
