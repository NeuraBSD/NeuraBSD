/* $NeuraBSD: ./src/pages/KeyboardPage.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Definition der Tastatur-Konfigurationsseite.
 * EN: Definition of the keyboard configuration page.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef KEYBOARDPAGE_HPP
#define KEYBOARDPAGE_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>

/**
 * @class KeyboardPage
 * @de Ermöglicht die Auswahl des Tastaturlayouts mit Echtzeit-Testfeld.
 * @en Allows selection of keyboard layout with a real-time test area.
 * * @de Dieses Modul kommuniziert direkt mit wsconsctl unter OpenBSD.
 * @en This module communicates directly with wsconsctl on OpenBSD.
 */
class KeyboardPage : public QWidget
{
Q_OBJECT

public:
/**
 * @de Konstruktor für die Keyboard-Einstellungsseite.
 * @en Constructor for the keyboard settings page.
 * @param parent Zeiger auf das übergeordnete Widget.
 */
explicit KeyboardPage(QWidget *parent = nullptr);

private slots:
/**
 * @de Wendet das gewählte Layout systemweit (für die Session) an.
 * @en Applies the selected layout system-wide (for the session).
 * @param index Der Index des gewählten Layouts in der ComboBox.
 */
void applyLayout(int index);

private:
QComboBox *m_layoutSelector;/**< @de Auswahl des Layouts. @en Layout selection. */
QLineEdit *m_testArea;/**< @de Eingabefeld zum Testen. @en Input field for testing. */

/** @de Initialisiert die grafische Oberfläche. @en Initializes the UI components. */
void setupUi();
/** @de Definiert das NeuraBSD-spezifische Design. @en Defines the NeuraBSD-specific design. */
void setupStyling();
};

#endif // KEYBOARDPAGE_HPP
