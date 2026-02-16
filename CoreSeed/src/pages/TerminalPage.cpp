/* $NeuraBSD: CoreSeed/src/pages/TerminalPage.cpp, v 1.1 2026/02/16 CodeAkrobat Exp $ */
/*
 * DE: Implementierung der Terminal-Seite.
 * EN: Implementation of the terminal page.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "pages/TerminalPage.hpp"
#include <QVBoxLayout>

/**
 * @details DE: Baut das Layout mit einem schreibgeschützten QTextEdit auf.
 * Das Stylesheet nutzt das NeuraBSD-Blau auf schwarzem Grund.
 * EN: Sets up the layout with a read-only QTextEdit.
 * The stylesheet uses NeuraBSD blue on black background.
 */
TerminalPage::TerminalPage(QWidget *parent)
	: InstallerPage(parent)
{
	setPageTitle(tr("Deployment Status"));

	QVBoxLayout *layout = new QVBoxLayout(this);

	m_console = new QTextEdit(this);
	m_console->setReadOnly(true);
	m_console->setStyleSheet("background-color: #0a0a0a; color: #00aaff; "
				      "font-family: 'Courier New'; border: 1px solid #1a1a1a;");

	m_progressBar = new QProgressBar(this);
	m_progressBar->setStyleSheet("QProgressBar { border: 1px solid #333; background: #0a0a0a; color: white; text-align: center; } "
				          "QProgressBar::chunk { background-color: #0055ff; }");

	layout->addWidget(m_console);
	layout->addWidget(m_progressBar);
}

void TerminalPage::appendLog(const QString &msg)
{
	QString timestamp = QTime::currentTime().toString("HH:mm:ss");
	m_console->append(QString("[%1] %2").arg(timestamp, msg));
	m_console->ensureCursorVisible();
}

void TerminalPage::setProgress(int value)
{
	m_progressBar->setValue(value);
}
