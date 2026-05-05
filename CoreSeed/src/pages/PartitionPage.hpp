/* $NeuraBSD: ./src/pages/PartitionPage.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Definition der Partitionsseite mit Deployment-Anbindung.
 * EN: Definition of the partition page with deployment integration.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef PARTITIONPAGE_HPP
#define PARTITIONPAGE_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QComboBox>
#include "../core/AutoSlicer.hpp"
#include "../core/AutoSlicerVisualizer.hpp"
#include "../core/HardwareScanner.hpp"
#include "../core/DeploymentController.hpp"

/**
 * @class PartitionPage
 * @de Kontrolliert den Übergang von der Planung zur physischen Installation.
 * @en Controls the transition from planning to physical installation.
 */
class PartitionPage : public QWidget
{
Q_OBJECT

public:
explicit PartitionPage(QWidget *parent = nullptr);

private slots:
void toggleExpertMode();
void refreshLayout();
void onDiskSelected(int index);
/** @de Startet den Deployment-Prozess nach Sicherheitsabfrage. */
void handleInstallRequest();
/** @de Verarbeitet Statusmeldungen vom Controller. */
void updateStatus(int percent, const QString &status);

private:
HardwareScanner *m_hwScanner;
AutoSlicer *m_slicer;
AutoSlicerVisualizer *m_visualizer;
DeploymentController *m_deployer;

QComboBox *m_diskSelector;
QVBoxLayout *m_mainLayout;
QFrame *m_expertPanel;
bool m_isExpert;

void setupStyling();
};

#endif // PARTITIONPAGE_HPP
