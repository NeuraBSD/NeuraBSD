/* $NeuraBSD: ./src/pages/ExtractionPage.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Implementierung der Installation mit pulsierendem Neura-Glow-Effekt.
 * EN: Implementation of the installation with pulsating Neura-Glow effect.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "ExtractionPage.hpp"
#include <QProcess>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>

/**
 * @file ExtractionPage.cpp
 * @de Zeigt den Fortschritt und erzeugt beim Abschluss ein pulsierendes Leuchten.
 */

ExtractionPage::ExtractionPage(QWidget *parent)
: QWidget(parent)
{
setupUi();
setupStyling();
}

void ExtractionPage::setupUi()
{
QVBoxLayout *layout = new QVBoxLayout(this);
layout->setContentsMargins(50, 50, 50, 50);
layout->setSpacing(25);

QLabel *title = new QLabel("System-Installation", this);
title->setObjectName("pageTitle");
layout->addWidget(title);

m_statusLabel = new QLabel("Bereit für Deployment...", this);
layout->addWidget(m_statusLabel);

m_overallProgress = new QProgressBar(this);
m_overallProgress->setFixedHeight(35);
m_overallProgress->setValue(0);
layout->addWidget(m_overallProgress);

m_logView = new QListWidget(this);
m_logView->setObjectName("installLog");
layout->addWidget(m_logView);

m_rebootBtn = new QPushButton("Neustart in AxonSurface", this);
m_rebootBtn->setObjectName("rebootButton");
m_rebootBtn->setFixedWidth(300);
m_rebootBtn->setVisible(false);
layout->addWidget(m_rebootBtn, 0, Qt::AlignCenter);

connect(m_rebootBtn, &QPushButton::clicked, this, &ExtractionPage::handleReboot);
}

void ExtractionPage::updateProgress(int percent, const QString &status)
{
m_overallProgress->setValue(percent);
m_statusLabel->setText(status);

if (percent >= 100) {
onInstallationFinished(true, "System erfolgreich zum Leben erweckt.");
}
}

void ExtractionPage::onInstallationFinished(bool success, const QString &msg)
{
if (!success) return;

m_statusLabel->setText("NeuraBSD lebt! AxonSurface ist bereit.");
m_rebootBtn->setVisible(true);

// --- Der Neura-Glow Effekt ---
m_overallProgress->setStyleSheet(
"QProgressBar::chunk { "
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0, "
"stop:0 #3498db, stop:1 #9b59b6); "
"border-radius: 15px; "
"}"
);

// Schatten-Effekt für das Pulsieren
QGraphicsDropShadowEffect *glow = new QGraphicsDropShadowEffect(this);
glow->setBlurRadius(15);
glow->setColor(QColor(155, 89, 182, 200)); // Neura-Purple
glow->setOffset(0);
m_overallProgress->setGraphicsEffect(glow);

// Animation: Den Glow pulsieren lassen
QPropertyAnimation *pulse = new QPropertyAnimation(glow, "blurRadius");
pulse->setDuration(1500);
pulse->setStartValue(10);
pulse->setEndValue(30);
pulse->setEasingCurve(QEasingCurve::InOutSine);
pulse->setLoopCount(-1); // Endlosschleife
pulse->start();
}

void ExtractionPage::handleReboot()
{
QProcess::execute("doas", {"reboot"});
}

void ExtractionPage::setupStyling()
{
this->setStyleSheet(
"QWidget { color: #b0b0b0; font-family: 'Courier New'; }"
"#pageTitle { font-size: 26px; color: #3498db; font-weight: bold; }"
"QProgressBar { border: 2px solid #3498db; background: #0a0d10; border-radius: 17px; text-align: center; color: white; font-weight: bold; }"
"#installLog { background-color: #050505; border: 1px solid #1a1a1a; color: #444; font-size: 11px; }"
"#rebootButton { "
"background-color: #3498db; "
"color: #0a0d10; "
"font-weight: bold; "
"padding: 15px; "
"font-size: 16px; "
"border-radius: 5px; "
"}"
"#rebootButton:hover { background-color: #9b59b6; color: white; }"
);
}

void ExtractionPage::startInstallation() { /* Triggered by Controller */ }
