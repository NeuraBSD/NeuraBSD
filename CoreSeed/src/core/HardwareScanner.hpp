/* $NeuraBSD: CoreSeed/src/core/HardwareScanner.hpp, v 1.4 2026/02/14 CodeAkrobat Exp $ */
/*
* DE: Definition der Hardware-Erkennung und Slice-Analyse.
* EN: Definition of hardware detection and slice analysis.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#ifndef HARDWARESCANNER_HPP
#define HARDWARESCANNER_HPP

#include <QObject>
#include <QStringList>

/**
* @class HardwareScanner
* @brief DE: Scannt Festplatten und analysiert OpenBSD-Slices.
* @brief EN: Scans disks and analyzes OpenBSD slices.
*/
class HardwareScanner : public QObject {
	Q_OBJECT
	public:
		explicit HardwareScanner(QObject *parent = nullptr);

		/**
		* @brief DE: Gibt eine Liste aller erkannten Festplatten zurück (z.B. sd0, wd0).
		*/
		QStringList getAvailableDisks();

		/**
		* @brief DE: Ermittelt die Gesamtgröße einer Festplatte.
		*/
		QString getDiskSize(const QString &diskName);

		/**
		* @brief DE: Liest die Slices (a, b, d...) einer Disk aus dem disklabel.
		* @brief EN: Reads the slices (a, b, d...) of a disk from disklabel.
		*/
		QStringList getSlices(const QString &diskName);
	};

	#endif
