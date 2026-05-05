/* $NeuraBSD: ./src/MainWindow.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Definition der zentralen Steuerinstanz für den CoreSeed Installer.
 * EN: Definition of the central control instance for the CoreSeed installer.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>
#include <QListWidget>

/**
 * @class MainWindow
 * @de Das Hauptfenster verwaltet den Blue-Flow und die Modul-Navigation.
 * @en The main window manages the Blue-Flow and module navigation.
 */
class MainWindow : public QMainWindow
{
Q_OBJECT

public:
/**
 * @de Konstruktor des Hauptfensters.
 * @en Constructor of the main window.
 * @param parent Zeiger auf das übergeordnete Widget.
 */
explicit MainWindow(QWidget *parent = nullptr);

public slots:
/**
 * @de Sperrt oder entsperrt die Sidebar-Navigation.
 * @en Locks or unlocks the sidebar navigation.
 * @param locked True zum Sperren, False zum Entsperren.
 */
void lockNavigation(bool locked);

private slots:
/**
 * @de Wechselt die Anzeige im StackedWidget.
 * @en Switches the display in the StackedWidget.
 * @param index Index der Zielseite.
 */
void changePage(int index);

private:
QStackedWidget *m_contentStack;/**< @de Container für die Module. @en Container for the modules. */
QListWidget *m_sidebar;/**< @de Navigationsleiste. @en Navigation bar. */

/** @de Initialisiert die UI-Komponenten. @en Initializes the UI components. */
void setupUi();
/** @de Wendet das globale NeuraBSD-Styling an. @en Applies the global NeuraBSD styling. */
void setupStyling();
};

#endif // MAINWINDOW_HPP
