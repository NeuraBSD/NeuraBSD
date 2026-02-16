/* $NeuraBSD: CoreSeed/src/ui/CoreSeed.cpp, v 1.5 2026/02/16 CodeAkrobat Exp $ */
/*
 * DE: Hauptsteuerung des CoreSeed Installers.
 * EN: Main controller of the CoreSeed installer.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "ui/CoreSeed.hpp"
#include <QVBoxLayout>

/**
 * @details DE: Der Konstruktor initialisiert die UI-Seiten und stellt die 
 * Signal-Slot-Verbindungen zwischen Logik und Anzeige her.
 * EN: The constructor initializes the UI pages and establishes the 
 * signal-slot connections between logic and display.
 */
CoreSeed::CoreSeed(QWidget *parent)
	: QMainWindow(parent)
{
	// DE: Initialisierung der Hauptkomponenten
	// EN: Initialization of main components
	m_sysExecutor = new SysExecutor(this);
	m_terminalPage = new TerminalPage(this);
	m_partitionPage = new PartitionPage(this);

	setupConnections();
}

/**
 * @brief DE: Verknüpft die Backend-Signale mit der Terminal-Anzeige.
 * EN: Connects backend signals with the terminal display.
 */
void CoreSeed::setupConnections()
{
	/**
	 * DE: Verbindung vom Executor zur Terminal-Log-Anzeige.
	 * EN: Connection from executor to terminal log display.
	 */
	connect(m_sysExecutor, &SysExecutor::logMessage,
		m_terminalPage, &TerminalPage::appendLog);

	/**
	 * DE: Verbindung für den Fortschrittsbalken.
	 * EN: Connection for the progress bar.
	 */
	connect(m_sysExecutor, &SysExecutor::progressUpdate,
		m_terminalPage, &TerminalPage::setProgress);
}

/**
 * @brief DE: Startet den eigentlichen Installationsvorgang.
 * EN: Starts the actual installation process.
 */
void CoreSeed::startInstallation()
{
	QString targetDisk = m_partitionPage->selectedDisk();
	auto slices = m_partitionPage->calculatedSlices();

	// DE: Übergabe an den Executor
	// EN: Handover to the executor
	m_sysExecutor->applyPartitioning(targetDisk, slices);
}
