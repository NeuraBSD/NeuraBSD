/* $NeuraBSD: ./src/MainWindow.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Implementierung der zentralen Steuerung und des Blue-Flow Übergangs.
 * EN: Implementation of the central control and Blue-Flow transition.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "MainWindow.hpp"
#include "pages/KeyboardPage.hpp"
#include "pages/TimezonePage.hpp"
#include "pages/UserPage.hpp"
#include "pages/PartitionPage.hpp"
#include "pages/ExtractionPage.hpp"
#include <QHBoxLayout>

/**
 * @file MainWindow.cpp
 * @de Orchestriert den gesamten Installationsprozess von der Eingabe bis zur Extraktion.
 */

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
setupUi();
setupStyling();

setWindowTitle("NeuraBSD CoreSeed - Blue Flow Installation");
resize(1280, 850);
}

/**
 * @de Erstellt das Layout und verknüpft die Module mit der automatischen Ablauflogik.
 * @en Creates the layout and links the modules with the automated workflow logic.
 */
void MainWindow::setupUi()
{
QWidget *centralWidget = new QWidget(this);
QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
mainLayout->setContentsMargins(0, 0, 0, 0);
mainLayout->setSpacing(0);

// --- Sidebar für die Navigation ---
m_sidebar = new QListWidget(this);
m_sidebar->setObjectName("navSidebar");
m_sidebar->setFixedWidth(240);

m_sidebar->addItem("1. Tastatur");
m_sidebar->addItem("2. Zeitzone");
m_sidebar->addItem("3. Benutzer");
m_sidebar->addItem("4. Partitionierung");
m_sidebar->addItem("5. Installation");

mainLayout->addWidget(m_sidebar);

// --- Content Stack für die Modulseiten ---
m_contentStack = new QStackedWidget(this);

KeyboardPage *kbPage = new KeyboardPage(this);
TimezonePage *tzPage = new TimezonePage(this);
UserPage *uPage = new UserPage(this);
PartitionPage *pPage = new PartitionPage(this);
ExtractionPage *ePage = new ExtractionPage(this);

m_contentStack->addWidget(kbPage);
m_contentStack->addWidget(tzPage);
m_contentStack->addWidget(uPage);
m_contentStack->addWidget(pPage);
m_contentStack->addWidget(ePage);

mainLayout->addWidget(m_contentStack);
setCentralWidget(centralWidget);

// --- Logik-Verknüpfungen ---

// Sidebar gesteuerte Navigation
connect(m_sidebar, &QListWidget::currentRowChanged, this, &MainWindow::changePage);

/* * DE: Automatischer Übergang zum Deployment-Status.
 * EN: Automatic transition to deployment state.
 */
connect(pPage, &PartitionPage::deploymentStarted, this, [=](){
lockNavigation(true);
m_sidebar->setCurrentRow(4); // Wechselt visuell zu Schritt 5
ePage->startInstallation(); // Triggert den Entpack-Prozess
});

// Standardstartseite
m_sidebar->setCurrentRow(0);
}

/**
 * @de Schaltet die Sidebar stumm, um inkonsistente Zustände während des Schreibens zu verhindern.
 * @en Disables the sidebar to prevent inconsistent states during write operations.
 */
void MainWindow::lockNavigation(bool locked)
{
m_sidebar->setEnabled(!locked);
}

/**
 * @de Führt den Seitenwechsel im Stack aus.
 * @en Executes the page switch in the stack.
 */
void MainWindow::changePage(int index)
{
m_contentStack->setCurrentIndex(index);
}

/**
 * @de Setzt das visuelle Thema des Installers.
 * @en Sets the visual theme of the installer.
 */
void MainWindow::setupStyling()
{
this->setStyleSheet(
"QMainWindow { background-color: #0a0a0a; }"
"#navSidebar { "
"background-color: #10273f; "
"color: #b0b0b0; "
"border: none; "
"font-family: 'Courier New'; "
"outline: none; "
"}"
"#navSidebar::item { "
"padding: 25px 20px; "
"border-bottom: 1px solid #0a1a2f; "
"}"
"#navSidebar::item:selected { "
"background-color: rgba(52, 152, 219, 0.15); "
"color: #3498db; "
"border-left: 5px solid #3498db; "
"font-weight: bold; "
"}"
"#navSidebar:disabled { "
"background-color: #050505; "
"color: #444; "
"}"
);
}
