/* $NeuraBSD: CoreSeed/src/pages/DiagnosticPage.cpp, v 1.4 2026/02/14 CodeAkrobat Exp $ */
#include "DiagnosticPage.hpp"
#include "HardwareScanner.hpp"
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>

DiagnosticPage::DiagnosticPage(QWidget *parent) : InstallerPage(parent) {
	setTitle("Hardware Diagnostic");
	setSubTitle("DE: Scan-Ergebnisse der Systemumgebung.\nEN: Scan results of the system environment.");

	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	HardwareScanner scanner;

	QLabel *infoLabel = new QLabel("Detected Storage Devices:", this);
	infoLabel->setStyleSheet("font-weight: bold; color: #d32f2f;");
	mainLayout->addWidget(infoLabel);

	QStringList disks = scanner.getAvailableDisks();
	for (const QString &disk : disks) {
		QLabel *diskLabel = new QLabel(QString(" - %1 (Size: %2)").arg(disk, scanner.getDiskSize(disk)), this);
		mainLayout->addWidget(diskLabel);
	}

	mainLayout->addStretch();
}
