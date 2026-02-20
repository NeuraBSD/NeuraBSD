/* $NeuraBSD: ./src/pages/PartitionPage.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Implementierung der Partitionierungsseite mit Blue-Flow Signalsteuerung.
 * EN: Implementation of the partition page with Blue-Flow signal control.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "PartitionPage.hpp"
#include <QLabel>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QMessageBox>
#include <QProgressBar>

/**
 * @file PartitionPage.cpp
 * @de Verwaltet die Festplattenauswahl und triggert den globalen Installationsstatus.
 */

PartitionPage::PartitionPage(QWidget *parent)
: QWidget(parent), 
  m_hwScanner(new HardwareScanner(this)),
  m_slicer(new AutoSlicer(this)), 
  m_visualizer(new AutoSlicerVisualizer(this)),
  m_deployer(new DeploymentController(this)),
  m_isExpert(false)
{
m_mainLayout = new QVBoxLayout(this);
m_mainLayout->setContentsMargins(0, 0, 0, 0);
m_mainLayout->setSpacing(0);

setupStyling();

// --- Zentraler Inhaltsbereich ---
QFrame *contentFrame = new QFrame(this);
contentFrame->setObjectName("contentArea");
QVBoxLayout *contentLayout = new QVBoxLayout(contentFrame);
contentLayout->setContentsMargins(40, 30, 40, 30);

QLabel *title = new QLabel("System Deployment", contentFrame);
title->setObjectName("pageTitle");
contentLayout->addWidget(title);

m_diskSelector = new QComboBox(contentFrame);
m_diskSelector->setFixedWidth(350);
m_diskSelector->addItems(m_hwScanner->getAvailableDisks());
contentLayout->addWidget(m_diskSelector);

contentLayout->addSpacing(20);
contentLayout->addWidget(m_visualizer);

// Expert Panel (optional einblendbar)
m_expertPanel = new QFrame(contentFrame);
m_expertPanel->setObjectName("expertPanel");
m_expertPanel->setVisible(false);
QVBoxLayout *expLay = new QVBoxLayout(m_expertPanel);
expLay->addWidget(new QCheckBox("Separate /var Partition (Isolation)", m_expertPanel));
expLay->addWidget(new QCheckBox("MFS for /tmp (Memory Speed)", m_expertPanel));
contentLayout->addWidget(m_expertPanel);

contentLayout->addStretch();

// --- Interaktions-Leiste ---
QHBoxLayout *btnLayout = new QHBoxLayout();
QPushButton *backBtn = new QPushButton("Abbrechen", contentFrame);
QPushButton *expertBtn = new QPushButton("Expert Mode", contentFrame);
QPushButton *installBtn = new QPushButton("Start Installation", contentFrame);
installBtn->setObjectName("installButton");

backBtn->setFixedWidth(180);
expertBtn->setFixedWidth(150);
installBtn->setFixedWidth(220);

btnLayout->addWidget(backBtn);
btnLayout->addWidget(expertBtn);
btnLayout->addStretch();
btnLayout->addWidget(installBtn);
contentLayout->addLayout(btnLayout);

m_mainLayout->addWidget(contentFrame);

// --- Logik Verknüpfung ---

// Abbruch mit Sicherheitsabfrage
connect(backBtn, &QPushButton::clicked, this, [=](){
QMessageBox abortBox(this);
abortBox.setWindowTitle("Konfiguration abbrechen?");
abortBox.setText("Möchtest du wirklich zum Hauptmenü zurückkehren?");
abortBox.setInformativeText("Alle bisher getätigten Einstellungen gehen verloren.");
abortBox.setStandardButtons(QMessageBox::Discard | QMessageBox::Cancel);
abortBox.setButtonText(QMessageBox::Discard, "Ja, alles verwerfen");

if (abortBox.exec() == QMessageBox::Discard) {
// Signal zum MainWindow für Reset (hier später)
}
});

connect(expertBtn, &QPushButton::clicked, this, &PartitionPage::toggleExpertMode);
connect(m_diskSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &PartitionPage::onDiskSelected);
connect(m_slicer, &AutoSlicer::layoutChanged, this, &PartitionPage::refreshLayout);
connect(installBtn, &QPushButton::clicked, this, &PartitionPage::handleInstallRequest);

if (!m_diskSelector->currentText().isEmpty()) onDiskSelected(0);
}

/**
 * @de Prüft die Auswahl und emittiert das Start-Signal für den Blue-Flow.
 * @en Validates selection and emits the start signal for the Blue-Flow.
 */
void PartitionPage::handleInstallRequest()
{
QString disk = m_diskSelector->currentText();

QMessageBox warnBox(this);
warnBox.setIcon(QMessageBox::Critical);
warnBox.setWindowTitle("LETZTE WARNUNG");
warnBox.setText(QString("Bist du sicher, dass du NeuraBSD auf %1 installieren willst?").arg(disk));
warnBox.setInformativeText("ALLE DATEN auf diesem Datenträger werden UNWIDERRUFLICH gelöscht.");
warnBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
warnBox.setDefaultButton(QMessageBox::Cancel);

warnBox.setStyleSheet("QMessageBox { background-color: #0a0d10; color: #b0b0b0; } "
      "QLabel { color: #d32f2f; font-weight: bold; } "
      "QPushButton { color: #3498db; min-width: 80px; }");

if (warnBox.exec() == QMessageBox::Yes) {
/* * DE: Triggert den Übergang zur ExtractionPage im MainWindow.
 * EN: Triggers the transition to ExtractionPage in MainWindow.
 */
emit deploymentStarted();

// Startet den eigentlichen Low-Level Prozess
m_deployer->startDeployment(disk, m_slicer->getSlices());
}
}

void PartitionPage::onDiskSelected(int index) { m_slicer->calculateLayout(m_hwScanner->getDiskCapacity(m_diskSelector->itemText(index))); }
void PartitionPage::refreshLayout() { m_visualizer->setSlices(m_slicer->getSlices()); }
void PartitionPage::toggleExpertMode() { m_isExpert = !m_isExpert; m_expertPanel->setVisible(m_isExpert); }

void PartitionPage::setupStyling()
{
this->setStyleSheet(
"QWidget { color: #b0b0b0; font-family: 'Courier New'; }"
"#contentArea { background-color: #0a0a0a; }"
"#pageTitle { font-size: 24px; color: #3498db; font-weight: bold; }"
"QComboBox { background-color: #0a1a2f; border: 1px solid #3498db; color: #3498db; padding: 5px; }"
"QPushButton { background-color: rgba(10, 26, 47, 0.8); border: 1px solid #3498db; color: #3498db; padding: 10px; }"
"QPushButton#installButton { background-color: #3498db; color: #0a0d10; font-weight: bold; }"
"QCheckBox { spacing: 10px; }"
);
}
