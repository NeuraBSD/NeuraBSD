/* $NeuraBSD: ./src/pages/UserPage.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Definition der Benutzer- und Hostname-Konfigurationsseite.
 * EN: Definition of the user and hostname configuration page.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef USERPAGE_HPP
#define USERPAGE_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>

/**
 * @class UserPage
 * @de Konfiguriert den Hostnamen, das Root-Passwort und den Primärbenutzer.
 * @en Configures the hostname, root password, and primary user.
 */
class UserPage : public QWidget
{
Q_OBJECT

public:
/**
 * @de Konstruktor für die Benutzer-Seite.
 * @en Constructor for the user page.
 * @param parent Zeiger auf das übergeordnete Widget.
 */
explicit UserPage(QWidget *parent = nullptr);

/** @de Validiert die Eingaben (z.B. Passwort-Übereinstimmung). */
bool validateInputs();

private:
QLineEdit *m_hostnameEdit;/**< @de System-Hostname. @en System hostname. */
QLineEdit *m_rootPass;/**< @de Root-Passwort. @en Root password. */
QLineEdit *m_rootPassConfirm;/**< @de Root-Passwort Bestätigung. @en Root password confirmation. */
QLineEdit *m_userName;/**< @de Benutzer-Login. @en User login name. */
QLineEdit *m_userPass;/**< @de Benutzer-Passwort. @en User password. */
QCheckBox *m_sshEnable;/**< @de SSH-Dienst aktivieren. @en Enable SSH service. */

void setupUi();
void setupStyling();
};

#endif // USERPAGE_HPP
