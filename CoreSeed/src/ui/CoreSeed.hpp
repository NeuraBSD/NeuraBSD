/* $NeuraBSD: CoreSeed/src/ui/CoreSeed.hpp, v 1.5 2026/02/16 CodeAkrobat Exp $ */
/*
 * DE: Header für die Hauptsteuerung des CoreSeed Installers.
 * EN: Header for the main controller of the CoreSeed installer.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef CORESEED_HPP
#define CORESEED_HPP

#include <QMainWindow>
#include "core/SysExecutor.hpp"
#include "pages/TerminalPage.hpp"
#include "pages/PartitionPage.hpp"

/**
 * @class CoreSeed
 * @brief DE: Hauptfenster-Klasse des NeuraBSD-Installers.
 * EN: Main window class of the NeuraBSD installer.
 */
class CoreSeed : public QMainWindow {
	Q_OBJECT

public:
	explicit CoreSeed(QWidget *parent = nullptr);
	void startInstallation();

private:
	void setupConnections();

	SysExecutor	*m_sysExecutor;
	TerminalPage	*m_terminalPage;
	PartitionPage	*m_partitionPage;
};

#endif // CORESEED_HPP
