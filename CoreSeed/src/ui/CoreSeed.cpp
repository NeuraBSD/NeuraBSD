/* $NeuraBSD: CoreSeed/src/ui/CoreSeed.cpp, v 1.1 2026/02/08 codeakrobat Exp $ */
/*
 * DE: Hauptlogik für das UI-Framework und den Seitenwechsel.
 * EN: Main logic for the UI framework and page switching.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "CoreSeed.hpp"
#include <QVBoxLayout>

CoreSeed::CoreSeed(QWidget *parent) : QMainWindow(parent) {
    setupLayout();
    
    // Neura-Blue Branding
    setWindowTitle("NeuraBSD CoreSeed - Deployment Wizard");
    resize(1024, 768); // Etwas größer für bessere Übersicht
}

void CoreSeed::setupLayout() {
    auto *centralWidget = new QWidget(this);
    auto *layout = new QVBoxLayout(centralWidget);

    m_pages = new QStackedWidget(this);

    // Initialisierung der modularen Seiten
    m_diagPage = new DiagnosticPage(this);
    m_partPage = new PartitionPage(this);
    m_termPage = new TerminalPage(this);

    // Die Seiten dem Stapel hinzufügen
    m_pages->addWidget(m_diagPage); // Index 0
    m_pages->addWidget(m_partPage); // Index 1
    m_pages->addWidget(m_termPage); // Index 2

    layout->addWidget(m_pages);
    setCentralWidget(centralWidget);

    // Wir starten immer mit der Hardware-Diagnose (Blue-Flow)
    m_pages->setCurrentIndex(0);
}

CoreSeed::~CoreSeed() {}
