/* $NeuraBSD: ./src/pages/TerminalPage.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */

/*
 * DE: Implementierung der Terminal-Emulation (Mode B - Profi/Mirror).
 * EN: Implementation of the terminal emulation (Mode B - Pro/Mirror).
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "TerminalPage.hpp"
#include <QVBoxLayout>
#include <QTextEdit>

/**
 * @brief DE: Konstruktor der TerminalPage.
 * WAS: Erzeugt eine Ansicht für die Interaktion mit dem OpenBSD-Installationsskript.
 * WARUM: Erlaubt erfahrenen Nutzern volle Kontrolle innerhalb des NeuraBSD-Designs.
 * WIE: Bindet ein QTextEdit oder QProcess-Widget in das Layout ein.
 * * @brief EN: Constructor of the TerminalPage.
 * WHAT: Creates a view for interacting with the OpenBSD installation script.
 * WHY: Allows experienced users full control within the NeuraBSD design.
 * HOW: Integrates a QTextEdit or QProcess widget into the layout.
 *
 * @param parent DE: Eltern-Widget. EN: Parent widget.
 */
TerminalPage::TerminalPage(QWidget *parent) : QWidget(parent) {
QVBoxLayout *layout = new QVBoxLayout(this);
QTextEdit *terminal = new QTextEdit(this);
terminal->setReadOnly(true);
terminal->setStyleSheet("background-color: #0a0a0a; color: #b0b0b0; font-family: 'Courier New';");
layout->addWidget(terminal);
}
