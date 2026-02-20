/* $NeuraBSD: ./src/pages/ExtractionPage.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Definition der Extraktionsseite mit Abschluss-Logik (Reboot).
 * EN: Definition of the extraction page with completion logic (reboot).
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef EXTRACTIONPAGE_HPP
#define EXTRACTIONPAGE_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>

/**
 * @class ExtractionPage
 * @de Visualisiert den Installationsfortschritt und bietet den finalen Neustart an.
 * @en Visualizes the installation progress and offers the final reboot.
 */
class ExtractionPage : public QWidget
{
Q_OBJECT

public:
/**
 * @de Konstruktor für die Extraktionsseite.
 * @en Constructor for the extraction page.
 * @param parent Zeiger auf das übergeordnete Widget.
 */
explicit ExtractionPage(QWidget *parent = nullptr);

/** @de Startet den automatisierten Installationsprozess. @en Starts the automated installation. */
void startInstallation();

private slots:
/** @de Aktualisiert Fortschritt und Log. @en Updates progress and log. */
void updateProgress(int percent, const QString &status);
/** @de Wird aufgerufen, wenn die Installation abgeschlossen ist. @en Called when installation finishes. */
void onInstallationFinished(bool success, const QString &msg);
/** @de Führt den System-Reboot aus. @en Executes the system reboot. */
void handleReboot();

private:
QProgressBar *m_overallProgress;
QLabel *m_statusLabel;
QListWidget *m_logView;
QPushButton *m_rebootBtn;/**< @de Button für den Neustart. @en Button for reboot. */

void setupUi();
void setupStyling();
};

#endif // EXTRACTIONPAGE_HPP
