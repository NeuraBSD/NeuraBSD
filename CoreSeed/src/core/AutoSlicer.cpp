/* $NeuraBSD: CoreSeed/src/core/AutoSlicer.cpp, v 1.5 2026/02/16 CodeAkrobat Exp $ */
#include "core/AutoSlicer.hpp"
#include <QtGlobal>

AutoSlicer::AutoSlicer(QObject *parent) : QObject(parent), m_totalSizeGB(0) {}

QVector<AutoSlicerVisualizer::SliceInfo> AutoSlicer::calculateSlices(double totalSizeGB) {
	m_totalSizeGB = totalSizeGB;
	QVector<AutoSlicerVisualizer::SliceInfo> slices;

	// DE: Hilfsfunktion für Slices / EN: Helper for slices
	auto addSlice = [&](QString mp, double size, QString color) {
		AutoSlicerVisualizer::SliceInfo s;
		s.mountPoint = mp;
		s.sizeGB = size;
		s.color = QColor(color);
		slices.append(s);
	};

	// 1. Root (/) - Active System
	addSlice("/", m_totalSizeGB * 0.10, "#0055ff");

	// 2. Altroot (/altroot) - Forensic Rollback Mirror
	addSlice("/altroot", m_totalSizeGB * 0.10, "#0033aa");

	// 3. Swap - Virtual Memory
	addSlice("swap", 4.0, "#333333");

	// 4. Tmp (/tmp)
	addSlice("/tmp", 2.0, "#555555");

	// 5. Var (/var) - Logs & Audit Data
	addSlice("/var", m_totalSizeGB * 0.15, "#0088ff");

	// 6. Crash (/crash) - Forensic Core Dumps
	addSlice("/crash", 4.0, "#ff5500");

	// 7. Usr (/usr) - System Apps
	addSlice("/usr", m_totalSizeGB * 0.20, "#0044cc");

	// 8. Home (/home) - Business Logic & User Data
	double remaining = m_totalSizeGB * 0.30; 
	addSlice("/home", remaining, "#00aaff");

	return slices;
}
