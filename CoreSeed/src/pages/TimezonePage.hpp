/* $NeuraBSD: ./src/pages/TimezonePage.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Definition der Zeitzonen-Konfigurationsseite.
 * EN: Definition of the timezone configuration page.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef TIMEZONEPAGE_HPP
#define TIMEZONEPAGE_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QDateTime>
#include <QTimer>

/**
 * @class TimezonePage
 * @de Ermöglicht die Auswahl der Weltregion und der spezifischen Zeitzone.
 * @en Allows selection of the world region and the specific timezone.
 */
class TimezonePage : public QWidget
{
Q_OBJECT

public:
/**
 * @de Konstruktor für die Zeitzonen-Seite.
 * @en Constructor for the timezone page.
 * @param parent Zeiger auf das übergeordnete Widget.
 */
explicit TimezonePage(QWidget *parent = nullptr);

private slots:
/** @de Aktualisiert die Liste der Städte basierend auf der Region. */
void updateCities(int index);
/** @de Wendet die Zeitzone an und aktualisiert die lokale Uhranzeige. */
void applyTimezone();
/** @de Aktualisiert die Live-Uhr im UI. */
void updateLiveClock();

private:
QComboBox *m_regionSelector;/**< @de Kontinent/Region. @en Continent/Region. */
QComboBox *m_citySelector;/**< @de Stadt/Zone. @en City/Zone. */
QLabel *m_timeDisplay;/**< @de Live-Uhranzeige. @en Live clock display. */
QTimer *m_clockTimer;/**< @de Timer für die Uhrzeit. @en Timer for the time. */

void setupUi();
void setupStyling();
void loadRegions();
};

#endif // TIMEZONEPAGE_HPP
