/* $NeuraBSD: ./src/pages/KeyboardPage.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Implementierung der Tastatur-Konfigurationsseite.
 * EN: Implementation of the keyboard configuration page.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "KeyboardPage.hpp"
#include <QProcess>
#include <QLabel>

/**
 * @file KeyboardPage.cpp
 * @de Setzt das Tastaturlayout und bietet eine Validierungsmöglichkeit im Blue-Flow.
 * @en Sets the keyboard layout and provides a validation option within the Blue-Flow.
 */

KeyboardPage::KeyboardPage(QWidget *parent)
: QWidget(parent)
{
setupUi();
setupStyling();
}

/**
 * @de Baut das Layout auf und verbindet den Selektor mit dem System-Befehl.
 * @en Builds the layout and connects the selector with the system command.
 */
void KeyboardPage::setupUi()
{
QVBoxLayout *layout = new QVBoxLayout(this);
layout->setContentsMargins(40, 40, 40, 40);
layout->setSpacing(20);

QLabel *title = new QLabel("Tastatur-Layout wählen", this);
title->setObjectName("pageTitle");
layout->addWidget(title);

QLabel *desc = new QLabel("Wähle dein Layout aus. Die Änderung wird sofort für diese Installation übernommen.", this);
desc->setWordWrap(true);
layout->addWidget(desc);

// Layout Selektor
m_layoutSelector = new QComboBox(this);
// Typische OpenBSD Layout-Kürzel
m_layoutSelector->addItems({"de", "us", "uk", "fr", "ch", "es", "it"});
m_layoutSelector->setFixedWidth(300);
layout->addWidget(m_layoutSelector);

layout->addSpacing(20);

QLabel *testLabel = new QLabel("Testfeld (tippe hier, um Umlaute/Sonderzeichen zu prüfen):", this);
layout->addWidget(testLabel);

m_testArea = new QLineEdit(this);
m_testArea->setPlaceholderText("z.B. @, €, ß, y/z ...");
m_testArea->setFixedHeight(50);
layout->addWidget(m_testArea);

layout->addStretch();

// Signal-Slot Verbindung für sofortiges Feedback
connect(m_layoutSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), 
this, &KeyboardPage::applyLayout);

// Initialer Lauf um Standard (de) zu setzen
applyLayout(0);
}

/**
 * @de Führt 'wsconsctl' aus, um das Hardware-Encoding der Tastatur zu ändern.
 * @en Executes 'wsconsctl' to change the hardware keyboard encoding.
 */
void KeyboardPage::applyLayout(int index)
{
QString layout = m_layoutSelector->itemText(index);

/* * DE: Nutzung von QProcess zur direkten Systeminteraktion. 
 * EN: Utilizing QProcess for direct system interaction.
 */
QProcess::execute("doas", {"wsconsctl", "keyboard.encoding=" + layout});

m_testArea->clear();
m_testArea->setFocus();
}

/**
 * @de Wendet das Neura-Blue CSS an.
 * @en Applies the Neura-Blue CSS.
 */
void KeyboardPage::setupStyling()
{
this->setStyleSheet(
"QWidget { color: #b0b0b0; font-family: 'Courier New'; }"
"#pageTitle { font-size: 24px; color: #3498db; font-weight: bold; }"
"QComboBox { background-color: #0a1a2f; border: 1px solid #3498db; color: #3498db; padding: 8px; }"
"QLineEdit { background-color: #121212; border: 1px solid #3498db; color: #3498db; padding-left: 10px; font-size: 16px; }"
"QLabel { color: #b0b0b0; }"
);
}
