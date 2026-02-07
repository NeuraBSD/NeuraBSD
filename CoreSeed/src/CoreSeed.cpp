/* $NeuraBSD: CoreSeed/src/CoreSeed.cpp, v 1.0 2026/02/07 codeakrobat Exp $ */
/* * DE: Implementierung der grafischen CoreSeed-Oberflaeche.
 * EN: Implementation of the graphical CoreSeed interface.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause 
 */

#include "CoreSeed.hpp"
#include <QDebug>

CoreSeed::CoreSeed(QObject *parent)
	: QObject(parent), m_mainWindow(nullptr)
{
}

CoreSeed::~CoreSeed()
{
	if (m_mainWindow) delete m_mainWindow;
}

void
CoreSeed::setupUI()
{
	m_mainWindow = new QWidget();
	m_mainWindow->setWindowTitle("NeuraBSD CoreSeed - Installation");
	m_mainWindow->setMinimumSize(800, 500);

	QVBoxLayout *layout = new QVBoxLayout(m_mainWindow);
	
	m_statusLabel = new QLabel("Welcome to NeuraBSD\nCoreSeed is ready.");
	m_statusLabel->setAlignment(Qt::AlignCenter);
	
	/* DE: Styling via AxonSurface Definitionen */
	m_statusLabel->setStyleSheet("font-size: 18px; color: #bc13fe;"); // Purple

	layout->addWidget(m_statusLabel);
	m_mainWindow->show();
}

void
CoreSeed::initHardwareScan()
{
	qDebug() << "NeuraBSD: Scanning hardware...";
	if (m_statusLabel) {
		m_statusLabel->setText("Scanning hardware components...");
	}
}

void
CoreSeed::startInstallation()
{
	qDebug() << "NeuraBSD: CoreSeed Installation started.";
	setupUI();
	initHardwareScan();
}
