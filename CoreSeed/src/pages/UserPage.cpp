/* $NeuraBSD: ./src/pages/UserPage.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Implementierung der Benutzer-Konfiguration.
 * EN: Implementation of the user configuration.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "UserPage.hpp"
#include <QFormLayout>

/**
 * @file UserPage.cpp
 * @de Erfasst die administrativen Zugangsdaten für das NeuraBSD System.
 */

UserPage::UserPage(QWidget *parent)
: QWidget(parent)
{
setupUi();
setupStyling();
}

void UserPage::setupUi()
{
QVBoxLayout *mainLayout = new QVBoxLayout(this);
mainLayout->setContentsMargins(40, 40, 40, 40);
mainLayout->setSpacing(15);

QLabel *title = new QLabel("Systemidentität & Benutzer", this);
title->setObjectName("pageTitle");
mainLayout->addWidget(title);

QFormLayout *form = new QFormLayout();
form->setLabelAlignment(Qt::AlignLeft);
form->setFormAlignment(Qt::AlignLeft);
form->setSpacing(10);

// Hostname
m_hostnameEdit = new QLineEdit("neurabsd", this);
form->addRow("Hostname:", m_hostnameEdit);

// Root Sektion
form->addRow(new QLabel("--- Administrator (root) ---", this));
m_rootPass = new QLineEdit(this);
m_rootPass->setEchoMode(QLineEdit::Password);
m_rootPassConfirm = new QLineEdit(this);
m_rootPassConfirm->setEchoMode(QLineEdit::Password);
form->addRow("Root Passwort:", m_rootPass);
form->addRow("Wiederholen:", m_rootPassConfirm);

// User Sektion
form->addRow(new QLabel("--- Primärer Benutzer ---", this));
m_userName = new QLineEdit(this);
m_userPass = new QLineEdit(this);
m_userPass->setEchoMode(QLineEdit::Password);
form->addRow("Benutzername:", m_userName);
form->addRow("Passwort:", m_userPass);

mainLayout->addLayout(form);

// Optionen
m_sshEnable = new QCheckBox("SSH-Dienst (sshd) beim Start aktivieren", this);
m_sshEnable->setChecked(true);
mainLayout->addWidget(m_sshEnable);

mainLayout->addStretch();
}

bool UserPage::validateInputs()
{
/* * DE: Einfache Prüfung der Passwort-Übereinstimmung.
 * EN: Simple check for password matching.
 */
if (m_rootPass->text() != m_rootPassConfirm->text()) return false;
if (m_userName->text().isEmpty()) return false;
return true;
}

void UserPage::setupStyling()
{
this->setStyleSheet(
"QWidget { color: #b0b0b0; font-family: 'Courier New'; font-size: 14px; }"
"#pageTitle { font-size: 24px; color: #3498db; font-weight: bold; margin-bottom: 10px; }"
"QLineEdit { background-color: #121212; border: 1px solid #3498db; color: #3498db; padding: 5px; min-width: 250px; }"
"QCheckBox::indicator { border: 1px solid #3498db; background: #0a0d10; width: 15px; height: 15px; }"
"QCheckBox::indicator:checked { background-color: #3498db; }"
"QLabel[text^='---'] { color: #555; font-weight: bold; margin-top: 10px; }"
);
}
