/* $NeuraBSD: ./src/main.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Hauptinstanz des grafischen Installers (CoreSeed).
 * EN: Main instance of the graphical installer (CoreSeed).
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include <QApplication>
#include "MainWindow.hpp"

/**
 * @file main.cpp
 * @de Startpunkt für den NeuraBSD Blue-Flow Installer. 
 * @en Entry point for the NeuraBSD Blue-Flow installer.
 * * @de Initialisiert die Qt-Umgebung und startet das MainWindow.
 * @en Initializes the Qt environment and launches the MainWindow.
 */

/**
 * @de Hauptfunktion des Installers.
 * @en Main function of the installer.
 * @param argc Argument-Zähler.
 * @param argv Argument-Vektor.
 * @return Exit-Code der Anwendung.
 */
int main(int argc, char *argv[])
{
/* * DE: Aktivierung der High-DPI Skalierung für moderne Monitore.
 * EN: Enabling High-DPI scaling for modern displays.
 */
QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

QApplication app(argc, argv);

/* * DE: Setzen der Applikations-Metadaten für konsistente Pfade.
 * EN: Setting application metadata for consistent paths.
 */
app.setApplicationName("CoreSeed");
app.setOrganizationName("NeuraBSD");
app.setOrganizationDomain("neurabsd.org");
app.setApplicationVersion("1.0.0-release");

/* * DE: MainWindow initialisieren. Dieses verwaltet den Blue-Flow Stack.
 * EN: Initialize MainWindow. This manages the Blue-Flow stack.
 */
MainWindow window;

/* * DE: Im Blue-Flow Modus starten wir direkt im Vollbild oder maximiert.
 * EN: In Blue-Flow mode, we start directly in fullscreen or maximized.
 */
window.show();

return app.exec();
}
