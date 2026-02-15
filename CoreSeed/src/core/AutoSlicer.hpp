/* $NeuraBSD: CoreSeed/src/core/AutoSlicer.hpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Logik zur automatischen Berechnung der Partitionierung.
* EN: Logic for automatic partitioning calculation.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#ifndef AUTOSLICER_HPP
#define AUTOSLICER_HPP

#include <QString>
#include <QList>

/**
* @struct SliceInfo
* @brief DE: Struktur für Partitionsinformationen.
* @brief EN: Structure for partition information.
*/
struct SliceInfo {
	QString mountPoint;  /**< DE: Einhängepunkt (z.B. /). EN: Mount point. */
	long long sizeMB;    /**< DE: Größe in Megabyte. EN: Size in Megabytes. */
	QString description; /**< DE: Beschreibung der Nutzung. EN: Usage description. */
};

/**
* @class AutoSlicer
* @brief DE: Berechnet dynamisch die Partitionierung basierend auf der Disk-Größe.
* @brief EN: Dynamically calculates partitioning based on disk size.
*/
class AutoSlicer {
	public:
		/**
		* @brief DE: Konstruktor mit Angabe der Gesamtgröße.
		* @brief EN: Constructor with total disk size.
		* @param totalDiskSizeMB DE: Größe der Disk in MB. EN: Disk size in MB.
		*/
		explicit AutoSlicer(long long totalDiskSizeMB);

		/**
		* @brief DE: Startet die Berechnung des Layouts.
		* @brief EN: Starts the layout calculation.
		*/
		void calculateLayout();

		/**
		* @brief DE: Gibt das berechnete Layout zurück.
		* @brief EN: Returns the calculated layout.
		* @return QList<SliceInfo>
		*/
		QList<SliceInfo> getLayout() const;

		private:
			long long m_totalSize;     /**< DE: Gesamte Disk-Größe. EN: Total disk size. */
			QList<SliceInfo> m_layout; /**< DE: Liste der Slices. EN: List of slices. */
		};

		#endif // AUTOSLICER_HPP
