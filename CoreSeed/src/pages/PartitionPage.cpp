/* $NeuraBSD: CoreSeed/src/pages/PartitionPage.cpp, v 1.5 2026/02/14 CodeAkrobat Exp $ */
#include "PartitionPage.hpp"
#include "HardwareScanner.hpp"
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QFont>

/*
* DE: Seite zur Auswahl der Festplatte und Anzeige der OpenBSD Slices.
* EN: Page for disk selection and display of OpenBSD slices.
*/

PartitionPage::PartitionPage(QWidget *parent) : InstallerPage(parent) {
	setTitle("Disk Partitioning");
	setSubTitle("DE: Wählen Sie das Zielmedium für NeuraBSD.\nEN: Select the target medium for NeuraBSD.");

	QVBoxLayout *layout = new QVBoxLayout(this);

	QLabel *headerLabel = new QLabel("Detected Storage Layout:", this);
	headerLabel->setStyleSheet("font-weight: bold; color: #d32f2f;");
	layout->addWidget(headerLabel);

	QListWidget *diskList = new QListWidget(this);
	diskList->setStyleSheet(
	"QListWidget { background-color: #121212; color: #b0b0b0; border: 1px solid #333; padding: 5px; }"
	"QListWidget::item { padding: 3px; }"
	);

	QFont monoFont("Courier New", 10);
	diskList->setFont(monoFont);

	HardwareScanner scanner;
	QStringList disks = scanner.getAvailableDisks();

	for (const QString &disk : disks) {
		QString diskSize = scanner.getDiskSize(disk);
		QListWidgetItem *diskItem = new QListWidgetItem(QString("DISK: %1 [%2]").arg(disk.toUpper(), diskSize), diskList);
		diskItem->setForeground(QColor("#d32f2f"));

		QStringList slices = scanner.getSlices(disk);
		for (const QString &slice : slices) {
			new QListWidgetItem(QString("  +-- Slice: %1").arg(slice), diskList);
		}
	}

	layout->addWidget(diskList);

	QLabel *footerLabel = new QLabel("Note: 'a' is usually the boot/root slice.", this);
	footerLabel->setStyleSheet("font-size: 10px; font-style: italic;");
	layout->addWidget(footerLabel);

	layout->addStretch();
}
