/* $NeuraBSD: CoreSeed/src/pages/TerminalPage.hpp, v 1.0 2026/02/08 CodeAkrobat Exp $ */
/*
 * DE: UI-Modul für den Profi-Modus (Mode B). Bindet ein Terminal ein.
 * EN: UI module for professional mode (Mode B). Embeds a terminal.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef TERMINALPAGE_HPP
#define TERMINALPAGE_HPP

#include "ui/InstallerPage.hpp"
#include <QPlainTextEdit>
#include <QProcess>
#include <QVBoxLayout>

/**
 * @class TerminalPage
 * @brief Implementiert den Profi-Modus von CoreSeed.
 * * DE: Führt den originalen OpenBSD /install Script in einem Widget aus.
 * EN: Executes the original OpenBSD /install script inside a widget.
 */
class TerminalPage : public InstallerPage {
    Q_OBJECT
public:
    explicit TerminalPage(QWidget *parent = nullptr);
    void onEnter() override;

private slots:
    void readProcessOutput();

private:
    QPlainTextEdit *terminalOutput; ///< DE: Textfeld für Konsolenausgabe / EN: Text field for console output
    QProcess *installProcess;       ///< DE: Der zugrunde liegende Prozess / EN: The underlying process
};

#endif
