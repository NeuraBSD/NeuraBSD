/* $NeuraBSD: ./src/core/SysExecutor.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Schnittstelle zur Ausführung von Systembefehlen (fdisk, disklabel).
 * EN: Interface for executing system commands (fdisk, disklabel).
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef SYSEXECUTOR_HPP
#define SYSEXECUTOR_HPP

#include <QObject>
#include <QStringList>
#include <QVector>
#include "ui/AutoSlicerVisualizer.hpp"

/**
 * @class SysExecutor
 * @brief DE: Führt die physische Partitionierung auf dem Zielsystem aus.
 * @brief EN: Executes the physical partitioning on the target system.
 * * @details DE: Diese Klasse ist verantwortlich für die Transformation der grafischen 
 * Partitionswünsche in reale OpenBSD-Systembefehle. Sie steuert den Prozess von der 
 * MBR-Initialisierung (fdisk) über das Slicing (disklabel) bis hin zur 
 * Dateisystem-Erstellung (newfs).
 * * EN: This class is responsible for transforming graphical partitioning requests 
 * into real OpenBSD system commands. It controls the process from MBR initialization 
 * (fdisk) to slicing (disklabel) and filesystem creation (newfs).
 */
class SysExecutor : public QObject {
	Q_OBJECT

public:
	/**
	 * @brief DE: Standard-Konstruktor.
	 * @brief EN: Default constructor.
	 */
	explicit SysExecutor(QObject *parent = nullptr);

	/**
	 * @brief DE: Wendet die Partitionierungs-Logik auf eine Festplatte an.
	 * @brief EN: Applies the partitioning logic to a disk.
	 * * @param disk DE: Gerätename der Zielfestplatte (z.B. "sd0").
	 * EN: Device name of the target disk (e.g., "sd0").
	 * @param slices DE: Vector mit den berechneten Slice-Informationen vom AutoSlicer.
	 * EN: Vector containing calculated slice information from AutoSlicer.
	 * * @return bool DE: True bei Erfolg oder erfolgreichem Dry-Run.
	 * EN: True on success or successful dry-run.
	 */
	bool applyPartitioning(const QString &disk, const QVector<AutoSlicerVisualizer::SliceInfo> &slices);

signals:
	/**
	 * @brief DE: Signal zur Ausgabe von Statusmeldungen an die UI.
	 * @brief EN: Signal for outputting status messages to the UI.
	 * @param msg DE: Die zu protokollierende Nachricht. EN: The message to be logged.
	 */
	void logMessage(const QString &msg);

	/**
	 * @brief DE: Signal zur Aktualisierung des Fortschrittsbalkens (0-100%).
	 * @brief EN: Signal for updating the progress bar (0-100%).
	 */
	void progressUpdate(int percent);

private:
	/**
	 * @brief DE: Sicherheits-Flag. Wenn true, werden Befehle nur simuliert.
	 * @brief EN: Safety flag. If true, commands are only simulated.
	 */
	bool m_dryRun = true; 
};

#endif // SYSEXECUTOR_HPP
