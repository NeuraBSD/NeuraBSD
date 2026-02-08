/* $NeuraBSD: CoreSeed/src/pages/TerminalPage.cpp, v 1.0 2026/02/08 CodeAkrobat Exp $ */
#include "TerminalPage.hpp"

/**
 * DE: Erstellt ein Terminal-ähnliches Widget mit Monospace-Schrift.
 * EN: Creates a terminal-like widget with monospace font.
 */
TerminalPage::TerminalPage(QWidget *parent) : InstallerPage(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    
    terminalOutput = new QPlainTextEdit(this);
    terminalOutput->setReadOnly(true);
    terminalOutput->setStyleSheet("background-color: #0a0a0a; color: #b0b0b0; font-family: 'Courier New';");
    
    layout->addWidget(terminalOutput);
    
    installProcess = new QProcess(this);
    connect(installProcess, &QProcess::readyReadStandardOutput, this, &TerminalPage::readProcessOutput);
}

void TerminalPage::onEnter() {
    terminalOutput->appendPlainText("--- Starting NeuraBSD Professional Mode (Mirror) ---");
    // Hier würde später der Aufruf des originalen Installers erfolgen
    // For testing, we just list the current directory
    installProcess->start("ls", QStringList() << "-la");
}

void TerminalPage::readProcessOutput() {
    QByteArray data = installProcess->readAllStandardOutput();
    terminalOutput->appendPlainText(QString::fromUtf8(data));
}
