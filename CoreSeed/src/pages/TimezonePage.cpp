/* $NeuraBSD: ./src/pages/TimezonePage.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Implementierung der Zeitzonen-Auswahl mit Live-Vorschau.
 * EN: Implementation of the timezone selection with live preview.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "TimezonePage.hpp"
#include <QProcess>

/**
 * @file TimezonePage.cpp
 * @de Verwaltet die Zeitkonfiguration für das Zielsystem.
 * @en Manages the time configuration for the target system.
 */

TimezonePage::TimezonePage(QWidget *parent)
: QWidget(parent)
{
setupUi();
setupStyling();

m_clockTimer = new QTimer(this);
connect(m_clockTimer, &QTimer::timeout, this, &TimezonePage::updateLiveClock);
m_clockTimer->start(1000);
}

void TimezonePage::setupUi()
{
QVBoxLayout *layout = new QVBoxLayout(this);
layout->setContentsMargins(40, 40, 40, 40);
layout->setSpacing(20);

QLabel *title = new QLabel("Datum & Zeitzone", this);
title->setObjectName("pageTitle");
layout->addWidget(title);

// Zeit-Vorschau
m_timeDisplay = new QLabel(this);
m_timeDisplay->setObjectName("timeDisplay");
updateLiveClock();
layout->addWidget(m_timeDisplay);

// Regionen
layout->addWidget(new QLabel("Region / Kontinent:", this));
m_regionSelector = new QComboBox(this);
m_regionSelector->addItems({"Europe", "America", "Asia", "Africa", "Atlantic", "Pacific"});
layout->addWidget(m_regionSelector);

// Städte
layout->addWidget(new QLabel("Stadt / Zone:", this));
m_citySelector = new QComboBox(this);
layout->addWidget(m_citySelector);

layout->addStretch();

connect(m_regionSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TimezonePage::updateCities);
connect(m_citySelector, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TimezonePage::applyTimezone);

updateCities(0); // Initialisierung
}

void TimezonePage::updateCities(int index)
{
m_citySelector->clear();
QString region = m_regionSelector->itemText(index);

// Beispielhafte Liste (später dynamisch via ls /usr/share/zoneinfo/REGION)
if (region == "Europe") m_citySelector->addItems({"Berlin", "London", "Paris", "Zurich", "Rome"});
else if (region == "America") m_citySelector->addItems({"New_York", "Los_Angeles", "Chicago", "Toronto"});
else m_citySelector->addItem("Universal");
}

void TimezonePage::applyTimezone()
{
QString zone = m_regionSelector->currentText() + "/" + m_citySelector->currentText();
/* * DE: Setzt den symbolischen Link für die Zone.
 * EN: Sets the symbolic link for the zone.
 */
QProcess::execute("doas", {"ln", "-sf", "/usr/share/zoneinfo/" + zone, "/etc/localtime"});
}

void TimezonePage::updateLiveClock()
{
m_timeDisplay->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy - HH:mm:ss"));
}

void TimezonePage::setupStyling()
{
this->setStyleSheet(
"QWidget { color: #b0b0b0; font-family: 'Courier New'; }"
"#pageTitle { font-size: 24px; color: #3498db; font-weight: bold; }"
"#timeDisplay { font-size: 32px; color: #3498db; margin: 10px 0; }"
"QComboBox { background-color: #0a1a2f; border: 1px solid #3498db; color: #3498db; padding: 8px; }"
);
}
