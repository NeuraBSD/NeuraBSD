/* $NeuraBSD: CoreSeed/src/CoreSeed.hpp, v 1.0 2026/02/07 codeakrobat Exp $ */
/* * DE: Header-Datei fuer die Installer-Logik inkl. GUI-Komponenten.
 * EN: Header file for the installer logic incl. GUI components.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause 
 */

#ifndef CORESEED_HPP
#define CORESEED_HPP

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class CoreSeed : public QObject {
	Q_OBJECT

public:
	explicit CoreSeed(QObject *parent = nullptr);
	virtual ~CoreSeed();

	void startInstallation();

private:
	void initHardwareScan();
	void setupUI();

	/* DE: UI Komponenten */
	/* EN: UI components */
	QWidget *m_mainWindow;
	QLabel  *m_statusLabel;
};

#endif /* !CORESEED_HPP */
