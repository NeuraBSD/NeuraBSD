/* $NeuraBSD: ./src/pages/DiagnosticPage.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */

/*
 * DE: Header für die Diagnose-Seite (Hardware-Check).
 * EN: Header for the diagnostic page (hardware check).
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef DIAGNOSTICPAGE_HPP
#define DIAGNOSTICPAGE_HPP

#include <QWidget>

/**
 * @class DiagnosticPage
 * @brief DE: UI-Seite für Systemdiagnosen vor der Installation.
 * EN: UI page for system diagnostics prior to installation.
 */
class DiagnosticPage : public QWidget {
Q_OBJECT
public:
explicit DiagnosticPage(QWidget *parent = nullptr);

/**
 * @brief DE: Führt einen Hardware-Selbsttest aus.
 * EN: Executes a hardware self-test.
 */
void runSelfTest();
};

#endif // DIAGNOSTICPAGE_HPP
