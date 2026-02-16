/* $NeuraBSD: CoreSeed/src/pages/PartitionPage.cpp, v 1.7 2026/02/16 CodeAkrobat Exp $ */
/*
 * DE: Implementierung der Partitionswahl-Seite.
 * EN: Implementation of the partition selection page.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "pages/PartitionPage.hpp"
#include "core/HardwareScanner.hpp"
#include <QVBoxLayout>

/**
 * @brief DE: Konstruktor. Initialisiert UI und Hardware-Scanner.
 * EN: Constructor. Initializes UI and hardware scanner.
 */
PartitionPage::PartitionPage(QWidget *parent)
	: InstallerPage(parent)
{
	setPageTitle(tr("Festplatten-Konfiguration"));

	m_layout = new QVBoxLayout(this);
	m_slicer = new AutoSlicer(this);

	m_instructionLabel = new QLabel(tr("Wählen Sie das Zielmedium für NeuraBSD:"), this);
	m_instructionLabel->setStyleSheet("font-weight: bold; color: white;");

	m_diskSelector = new QComboBox(this);

	HardwareScanner scanner;
	QStringList disks = scanner.availableDisks();
	for (const QString &disk : disks) {
		m_diskSelector->addItem(disk, 128.0); // 128GB als Platzhalter-Größe
	}

	m_visualizer = new AutoSlicerVisualizer(this);

	m_layout->addWidget(m_instructionLabel);
	m_layout->addWidget(m_diskSelector);
	m_layout->addSpacing(20);
	m_layout->addWidget(m_visualizer);
	m_layout->addStretch();

	connect(m_diskSelector, QOverload<int>::of(&QComboBox::currentIndexChanged),
		this, &PartitionPage::updateDiskPreview);

	if (m_diskSelector->count() > 0) {
		updateDiskPreview(0);
	}
}

/**
 * @brief DE: Gibt den Namen der aktuell gewählten Festplatte zurück.
 * EN: Returns the name of the currently selected disk.
 */
QString PartitionPage::selectedDisk() const
{
	return m_diskSelector->currentText();
}

/**
 * @brief DE: Gibt die aktuell berechneten Slices zurück.
 * EN: Returns the currently calculated slices.
 */
QVector<AutoSlicerVisualizer::SliceInfo> PartitionPage::calculatedSlices() const
{
	double size = m_diskSelector->currentData().toDouble();
	return m_slicer->calculateSlices(size);
}

/**
 * @brief DE: Aktualisiert die grafische Vorschau bei Auswahländerung.
 * EN: Updates the graphical preview on selection change.
 */
void PartitionPage::updateDiskPreview(int index)
{
	double size = m_diskSelector->itemData(index).toDouble();
	m_visualizer->setSlices(m_slicer->calculateSlices(size));
}
