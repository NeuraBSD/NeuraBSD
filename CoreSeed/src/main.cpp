/* $NeuraBSD: CoreSeed/src/main.cpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Hauptinstanz des grafischen Installers.
* EN: Main instance of the graphical installer.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#include <QApplication>
#include "ui/CoreSeed.hpp"

/**
* @brief DE: Einstiegspunkt der Anwendung. Initialisiert die Qt6-Umgebung.
* @brief EN: Application entry point. Initializes the Qt6 environment.
*/
int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	app.setApplicationName("CoreSeed");
	app.setOrganizationName("NeuraBSD");

	CoreSeed installer;
	installer.show();

	return app.exec();
}
