/* $NeuraBSD: ./src/core/ConfigManager.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */

/*
 * DE: Verwaltung von Konfigurationsdaten und Audit-Logs.
 * EN: Management of configuration data and audit logs.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef CONFIGMANAGER_HPP
#define CONFIGMANAGER_HPP

#include <QObject>
#include <QString>
#include <QVector>
#include "AutoSlicerVisualizer.hpp"

/**
 * @class ConfigManager
 * @brief DE: Modul zur Sicherung der Deployment-Parameter.
 * WAS: Schreibt Audit-Logs und Konfigurationen für den Blue-Flow.
 * WARUM: Sicherheit durch Nachvollziehbarkeit; Basis für Forensic Rollbacks.
 * WIE: Serialisiert Slice-Informationen in persistente Dateien.
 */
class ConfigManager : public QObject {
	Q_OBJECT
public:
	explicit ConfigManager(QObject *parent = nullptr);

	/**
	 * @brief DE: Speichert das Partitionslayout.
	 * @param slices Die zu sichernden Partitionen.
	 * @return bool True bei Erfolg.
	 */
	bool savePartitionConfig(const QVector<AutoSlicerVisualizer::SliceInfo> &slices);

private:
	QString m_configPath;
};

#endif // CONFIGMANAGER_HPP
