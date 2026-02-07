/* $NeuraBSD: CoreSeed/src/main.cpp, v 1.3 2026/02/07 codeakrobat Exp $ */
/*
 * DE: Hauptinstanz des grafischen Installers (CoreSeed).
 * EN: Main instance of the graphical installer (CoreSeed).
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include <QApplication>
#include <QSurfaceFormat>
#include <QStyleFactory>
#include "CoreSeed.hpp"

/**
 * DE: Einstiegspunkt fuer CoreSeed. Initialisiert das AxonSurface-Design.
 * EN: Entry point for CoreSeed. Initializes the AxonSurface design.
 */
int
main(int argc, char *argv[])
{
	/* DE: Qt6-Anwendung initialisieren */
	/* EN: Initialize Qt6 application */
	QApplication app(argc, argv);
	app.setApplicationName("NeuraBSD CoreSeed");
	app.setApplicationVersion("1.0-ALPHA");

	/* DE: AxonSurface Stylesheet (Black/Purple/Blue) */
	/* EN: AxonSurface stylesheet (Black/Purple/Blue) */
	app.setStyleSheet(
		"QWidget { "
		"  background-color: #0a0a0a; "
		"  color: #b0b0b0; "
		"  font-family: 'Courier New', monospace; "
		"} "
		"QPushButton { "
		"  background-color: #121212; "
		"  border: 1px solid #bc13fe; " // Signature Purple
		"  padding: 5px; "
		"} "
		"QPushButton:hover { "
		"  border: 1px solid #0055ff; " // Neura Blue
		"}"
	);

	/* DE: Backend-Logik starten */
	/* EN: Start backend logic */
	CoreSeed installer;
	installer.startInstallation();

	return app.exec();
}
