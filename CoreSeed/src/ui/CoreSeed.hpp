/* $NeuraBSD: CoreSeed/src/ui/CoreSeed.hpp, v 1.1 2026/02/08 codeakrobat Exp $ */
/*
 * DE: Header für das Hauptfenster des Installers. 
 * EN: Header for the main installer window.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include "../pages/DiagnosticPage.hpp"
#include "../pages/PartitionPage.hpp"
#include "../pages/TerminalPage.hpp"

class CoreSeed : public QMainWindow {
    Q_OBJECT

public:
    CoreSeed(QWidget *parent = nullptr);
    ~CoreSeed();

private:
    QStackedWidget *m_pages;
    DiagnosticPage *m_diagPage;
    PartitionPage  *m_partPage;
    TerminalPage   *m_termPage;

    void setupLayout();
};
