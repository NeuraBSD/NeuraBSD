/* $NeuraBSD: CoreSeed/src/core/AutoSlicer.cpp, v 1.3 2026/02/15 CodeAkrobat Exp $ */
/**
* @file AutoSlicer.cpp
* @brief DE: Implementierung der dynamischen Slicer-Logik mit Obergrenzen (Caps).
* @brief EN: Implementation of dynamic slicer logic with upper limits (caps).
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#include "core/AutoSlicer.hpp"
#include <QtGlobal>

AutoSlicer::AutoSlicer(long long totalDiskSizeMB) : m_totalSize(totalDiskSizeMB) {}

/**
* @details DE: Berechnet Partitionen mit fixen Werten für / und /altroot sowie
* prozentualen Werten mit Caps für Systemverzeichnisse.
* @details EN: Calculates partitions with fixed values for / and /altroot and
* percentage values with caps for system directories.
*/
void AutoSlicer::calculateLayout() {
	m_layout.clear();
	long long remaining = m_totalSize;

	// 1. Root (/) - Fix 3 GB
	long long rootSize = 3072;
	m_layout.append({"/", rootSize, "Active System Root"});
	remaining -= rootSize;

	// 2. Alt-Root (/altroot) - Fix 3 GB (Forensisches Backup)
	long long altSize = 3072;
	m_layout.append({"/altroot", altSize, "Forensic Rollback Mirror"});
	remaining -= altSize;

	// 3. Swap - 4GB bis 8GB Cap
	long long swapSize = qMax(4096LL, qMin((long long)(m_totalSize * 0.05), 8192LL));
	m_layout.append({"swap", swapSize, "Virtual Memory"});
	remaining -= swapSize;

	// 4. /tmp - 5%, capped bei 20 GB
	long long tmpSize = qMin((long long)(m_totalSize * 0.05), 20480LL);
	m_layout.append({"/tmp", tmpSize, "Temporary Files"});
	remaining -= tmpSize;

	// 5. /var - 10%, capped bei 50 GB (Logs & Audit)
	long long varSize = qMin((long long)(m_totalSize * 0.10), 51200LL);
	m_layout.append({"/var", varSize, "Logs & Audit Data"});
	remaining -= varSize;

	// 6. /crash - 5%, capped bei 40 GB (Forensik/AI Dumps)
	long long crashSize = qMin((long long)(m_totalSize * 0.05), 40960LL);
	m_layout.append({"/crash", crashSize, "Forensic Core Dumps"});
	remaining -= crashSize;

	// 7. /usr - 30%, capped bei 120 GB (System-Apps)
	long long usrSize = qMin((long long)(m_totalSize * 0.30), 122880LL);
	m_layout.append({"/usr", usrSize, "System Apps & UI"});
	remaining -= usrSize;

	// 8. /home - Nimmt den gesamten Rest auf (Business Logic)
	if (remaining > 0) {
		m_layout.append({"/home", remaining, "User Home & Business Logic"});
	}
}

QList<SliceInfo> AutoSlicer::getLayout() const {
	return m_layout;
}
