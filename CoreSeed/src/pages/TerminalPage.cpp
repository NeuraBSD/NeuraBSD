/* $NeuraBSD: CoreSeed/src/pages/TerminalPage.cpp, v 1.2 2026/02/14 CodeAkrobat Exp $ */
#include "TerminalPage.hpp"
#include <QVBoxLayout>
#include <QTextEdit>

/**
 * @brief DE: TerminalPage für die Spiegelung der Installation (Mode B).
 * @brief EN: TerminalPage for mirroring the installation (Mode B).
 */
TerminalPage::TerminalPage(QWidget *parent) : InstallerPage(parent) {
setTitle("System Console");
setSubTitle("DE: Live-Ausgabe des Kernels.\nEN: Live kernel output.");

QVBoxLayout *layout = new QVBoxLayout(this);
QTextEdit *terminal = new QTextEdit(this);
terminal->setReadOnly(true);
terminal->setStyleSheet("background-color: #000000; color: #d32f2f; font-family: 'Courier New';");

terminal->append("NeuraBSD 2026 CoreSeed initialized...");
layout->addWidget(terminal);
}
