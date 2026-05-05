/* $NeuraBSD: ./src/pages/SliceView.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/**
* @file SliceView.cpp
* @brief DE: Implementierung der grafischen Slice-Vorschau.
* @brief EN: Implementation of the graphical slice preview.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#include "pages/SliceView.hpp"
#include <QLabel>

SliceView::SliceView(QWidget *parent) : QWizardPage(parent) {
	setTitle(tr("Partition Layout"));
	setSubTitle(tr("DE: Geplante Aufteilung der Festplatte.\nEN: Planned disk partitioning."));

	m_mainLayout = new QVBoxLayout(this);
	refreshLayout(128); // Standard-Vorschau für 128GB
}

/**
* @details DE: Berechnet das Layout via AutoSlicer und erstellt Labels für die UI.
* @details EN: Calculates layout via AutoSlicer and creates labels for the UI.
*/
void SliceView::refreshLayout(long totalGB) {
	// Bestehendes Layout leeren
	QLayoutItem *item;
	while ((item = m_mainLayout->takeAt(0)) != nullptr) {
		delete item->widget();
		delete item;
	}

	// Unsere neue Logik nutzen
	AutoSlicer slicer(totalGB * 1024);
	slicer.calculateLayout();
	QList<SliceInfo> slices = slicer.getLayout();

	for (const auto& slice : slices) {
		QString text = QString("%1: %2 MB - %3")
		.arg(slice.mountPoint)
		.arg(slice.sizeMB)
		.arg(slice.description);
		m_mainLayout->addWidget(new QLabel(text));
	}
}
