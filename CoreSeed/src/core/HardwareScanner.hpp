/* $NeuraBSD: CoreSeed/src/core/HardwareScanner.hpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Erkennung der Hardware-Ressourcen (CPU, RAM, Disks).
* EN: Detection of hardware resources (CPU, RAM, Disks).
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
* @brief DE: Klasse zur Hardware-Erkennung unter OpenBSD/NeuraBSD.
* @brief EN: Class for hardware detection under OpenBSD/NeuraBSD.
*/
class HardwareScanner : public QObject {
	Q_OBJECT
	public:
		/**
		* @brief DE: Standard-Konstruktor.
		* @brief EN: Standard constructor.
		* @param parent DE: Qt-Elternobjekt. EN: Qt parent object.
		*/
		explicit HardwareScanner(QObject *parent = nullptr);

		/**
		* @brief DE: Listet alle verfügbaren Festplatten auf.
		* @brief EN: Lists all available hard drives.
		* @return QStringList
		*/
		QStringList getAvailableDisks();

		/**
		* @brief DE: Gibt Informationen zur CPU-Architektur zurück.
		* @brief EN: Returns information about the CPU architecture.
		* @return QString
		*/
		QString getCpuInfo();

		/**
		* @brief DE: Ermittelt den gesamten Arbeitsspeicher in MB.
		* @brief EN: Determines the total system memory in MB.
		* @return long long
		*/
		long long getTotalMemoryMB();
	};

	#endif // HARDWARESCANNER_HPP
