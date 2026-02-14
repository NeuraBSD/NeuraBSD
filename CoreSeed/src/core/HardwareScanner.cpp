/* $NeuraBSD: CoreSeed/src/core/HardwareScanner.cpp, v 1.4 2026/02/14 CodeAkrobat Exp $ */
#include "HardwareScanner.hpp"
#include <QProcess>
#include <QRegularExpression>

/*
* DE: Implementierung der Hardware-Abfrage für NeuraBSD.
* EN: Implementation of hardware queries for NeuraBSD.
*/

HardwareScanner::HardwareScanner(QObject *parent) : QObject(parent) {}

QStringList HardwareScanner::getAvailableDisks() {
	QStringList disks;
	QProcess process;
	process.start("sysctl", QStringList() << "-n" << "hw.disknames");

	if (process.waitForFinished()) {
		QString output = QString::fromLocal8Bit(process.readAllStandardOutput()).trimmed();
		for (const QString &entry : output.split(",")) {
			// DE: Extrahiere den Namen vor dem Doppelpunkt (z.B. sd0:abc -> sd0)
			QString name = entry.split(":").first();
			if (!name.isEmpty()) disks << name;
		}
	}
	return disks;
}

QString HardwareScanner::getDiskSize(const QString &diskName) {
	QProcess process;
	process.start("disklabel", QStringList() << diskName);

	if (process.waitForFinished()) {
		QString output = QString::fromLocal8Bit(process.readAllStandardOutput());
		QRegularExpression re("total sectors: (\\d+)");
		auto match = re.match(output);

		if (match.hasMatch()) {
			long long sectors = match.captured(1).toLongLong();
			// DE: Umrechnung Sektoren (512 Byte) in Gigabyte
			double gb = (sectors * 512.0) / (1024.0 * 1024.0 * 1024.0);
			return QString::number(gb, 'f', 1) + " GB";
		}
	}
	return "0 GB";
}

QStringList HardwareScanner::getSlices(const QString &diskName) {
	QStringList slices;
	QProcess process;
	// DE: Ruft das Disklabel ab, um die Slice-Tabelle (a-p) zu lesen
	process.start("disklabel", QStringList() << diskName);

	if (process.waitForFinished()) {
		QString output = QString::fromLocal8Bit(process.readAllStandardOutput());

		// DE: Regex sucht Zeilen wie "  a: 20971520 ..." am Zeilenanfang
		// EN: Regex searches for lines like "  a: 20971520 ..." at the start
		QRegularExpression re("^\\s+([a-p]):\\s+(\\d+)");
		re.setPatternOptions(QRegularExpression::MultilineOption);

		auto it = re.globalMatch(output);
		while (it.hasNext()) {
			auto match = it.next();
			// DE: Fügt Slice-Buchstaben an den Disk-Namen an (z.B. sd0a)
			slices << diskName + match.captured(1);
		}
	}
	return slices;
}
