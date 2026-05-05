/* $NeuraBSD: ./src/core/ConfigManager.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */

/*
 * DE: Implementierung des Konfigurations-Managers.
 * EN: Implementation of the configuration manager.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "ConfigManager.hpp"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>

/**
 * @brief DE: Konstruktor des ConfigManagers.
 */
ConfigManager::ConfigManager(QObject *parent) 
	: QObject(parent), m_configPath(".CoreSeed.audit") {
}

/**
 * @brief DE: Sichert die Partitionierung in einer Audit-Datei.
 * WAS: Erstellt eine menschenlesbare und maschinenverarbeitbare Log-Datei.
 * WARUM: Nachvollziehbarkeit des Hardware-Deployments (Neura-Audit).
 * WIE: Nutzt QFile und QTextStream zur persistenten Speicherung.
 */
bool ConfigManager::savePartitionConfig(const QVector<AutoSlicerVisualizer::SliceInfo> &slices) {
	QFile file(m_configPath);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
		qCritical() << "[ConfigManager] Fehler: Audit-Datei konnte nicht geöffnet werden!";
		return false;
	}

	QTextStream out(&file);
	out << "--- NeuraBSD Audit Snapshot: " << QDateTime::currentDateTime().toString() << " ---\n";
	
	for (const auto& slice : slices) {
		out << "ACTION: CREATE_PARTITION | MOUNT: " << slice.mountPoint 
			<< " | SIZE: " << slice.sizeGB << "GB | COLOR: " << slice.color.name() << "\n";
	}
	
	out << "--- End of Audit Entry ---\n\n";
	file.close();

	qDebug() << "[ConfigManager] Audit-Log geschrieben nach:" << m_configPath;
	return true;
}
