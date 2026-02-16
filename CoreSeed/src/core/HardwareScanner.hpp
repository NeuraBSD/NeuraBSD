/* $NeuraBSD: CoreSeed/src/core/HardwareScanner.hpp, v 1.3 2026/02/16 CodeAkrobat Exp $ */
#ifndef HARDWARESCANNER_HPP
#define HARDWARESCANNER_HPP

#include <QObject>
#include <QStringList>

class HardwareScanner : public QObject {
	Q_OBJECT

public:
	explicit HardwareScanner(QObject *parent = nullptr);
	QStringList availableDisks();
	QString getCpuInfo();
	long long getTotalMemoryMB();
};

#endif // HARDWARESCANNER_HPP
