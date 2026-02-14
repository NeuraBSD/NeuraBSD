/* $NeuraBSD: CoreSeed/src/core/HardwareScanner.cpp, v 1.2 2026/02/14 CodeAkrobat Exp $ */
#include "HardwareScanner.hpp"
#include <QProcess>
#include <QRegularExpression>

HardwareScanner::HardwareScanner(QObject *parent) : QObject(parent) {}

QStringList HardwareScanner::getAvailableDisks() {
QStringList disks;
QProcess process;
process.start("sysctl", QStringList() << "-n" << "hw.disknames");
if (process.waitForFinished()) {
QString output = QString::fromLocal8Bit(process.readAllStandardOutput()).trimmed();
for (const QString &entry : output.split(",")) {
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
return QString::number((sectors * 512.0) / (1024.0 * 1024.0 * 1024.0), 'f', 1) + " GB";
}
}
return "0 GB";
}
