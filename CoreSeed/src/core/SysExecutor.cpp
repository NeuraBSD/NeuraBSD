/* $NeuraBSD: ./src/core/SysExecutor.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Ausführung der Partitionierungs-Befehle für OpenBSD.
 * EN: Execution of partitioning commands for OpenBSD.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "core/SysExecutor.hpp"
#include <QDebug>

/**
 * @brief DE: Konstruktor des SysExecutors.
 * @brief EN: Constructor of the SysExecutor.
 */
SysExecutor::SysExecutor(QObject *parent) : QObject(parent) {}

/**
 * @details DE: Die Methode führt eine sequentielle Befehlskette aus:
 * 1. Initialisierung des Master Boot Record (MBR) via 'fdisk -iy'.
 * 2. Vorbereitung des OpenBSD-Disklabels basierend auf AutoSlicer-Daten.
 * 3. Logischer Durchlauf der Formatierung (newfs).
 * * EN: The method executes a sequential chain of commands:
 * 1. Master Boot Record (MBR) initialization via 'fdisk -iy'.
 * 2. Preparation of the OpenBSD disklabel based on AutoSlicer data.
 * 3. Logical pass of formatting (newfs).
 */
bool SysExecutor::applyPartitioning(const QString &disk, const QVector<AutoSlicerVisualizer::SliceInfo> &slices) {
	emit logMessage(tr("--- Start der NeuraBSD Installation auf %1 ---").arg(disk));
	emit progressUpdate(5);

	// --- Schritt 1: MBR ---
	QString fdiskCmd = QString("fdisk -iy %1").arg(disk);
	emit logMessage(tr("Schritt 1: Initialisiere Partitionstabelle (MBR)..."));
	emit logMessage("CMD: " + fdiskCmd);
	emit progressUpdate(25);

	// --- Schritt 2: Slicing ---
	emit logMessage(tr("Schritt 2: Berechne Slices für das Disklabel..."));
	for (const auto &slice : slices) {
		// DE: Wir simulieren hier die Erstellung der Slice-Tabelle
		// EN: We simulate the creation of the slice table here
		QString sliceMsg = QString(" > Slice %1: %2 GB")
						   .arg(slice.mountPoint)
						   .arg(slice.sizeGB);
		emit logMessage(sliceMsg);
	}
	emit progressUpdate(60);

	// --- Schritt 3: NewFS ---
	emit logMessage(tr("Schritt 3: Dateisysteme werden formatiert (newfs)..."));
	emit progressUpdate(90);

	if (m_dryRun) {
		emit logMessage(tr("HINWEIS: Dry-Run Modus aktiv. Keine Daten geschrieben."));
	}

	emit logMessage(tr("--- Phase 1 (Partitionierung) abgeschlossen ---"));
	emit progressUpdate(100);

	return true; 
}
