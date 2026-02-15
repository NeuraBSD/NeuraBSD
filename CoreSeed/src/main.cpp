/* $NeuraBSD: CoreSeed/src/main.cpp, v 1.3 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Hauptinstanz des grafischen Installers - Simulation der Partitionierung.
* EN: Main instance of the graphical installer - Partitioning simulation.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "core/AutoSlicer.hpp"

/**
* @brief DE: Simuliert die Partitionierung für eine gegebene Festplattengröße.
* @brief EN: Simulates partitioning for a given disk size.
* @param sizeGB Die Größe der fiktiven Festplatte in Gigabyte.
*/
void simulate(long long sizeGB) {
	qDebug() << "-------------------------------------------------------";
	qDebug() << "NeuraBSD AutoSlicer Simulation für:" << sizeGB << "GB";
	qDebug() << "-------------------------------------------------------";

	AutoSlicer slicer(sizeGB * 1024); // Umrechnung in MB
	slicer.calculateLayout();

	for (const auto& slice : slicer.getLayout()) {
		double sizeInGB = slice.sizeMB / 1024.0;
		QString output = QString("%1: %2 GB \t(%3)")
		.arg(slice.mountPoint, -10)
		.arg(QString::number(sizeInGB, 'f', 2), 8)
		.arg(slice.description);
		qDebug() << output.toUtf8().constData();
	}
	qDebug() << "";
}

/**
* @brief DE: Einstiegspunkt zur Validierung der Slicer-Logik.
* @brief EN: Entry point for slicer logic validation.
*/
int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);
	app.setApplicationName("CoreSeed-Simulator");

	// Testläufe für verschiedene Szenarien
	simulate(128);  // Kleiner Laptop / SSD
	simulate(512);  // Moderne Workstation
	simulate(2048); // High-End Storage / NVMe (2TB)

	qDebug() << "Simulation beendet. Sind die Proportionen korrekt?";

	return 0;
}
