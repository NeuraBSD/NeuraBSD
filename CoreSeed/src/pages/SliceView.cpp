/* $NeuraBSD: CoreSeed/src/pages/SliceView.cpp, v 1.1 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Implementierung der Partitions-Vorschau.
* EN: Implementation of the partition preview.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#include "pages/SliceView.hpp"
#include <QVBoxLayout>
#include <QLabel>

/**
* DE: Konstruktor der Slice-Vorschau.
* EN: Constructor of the slice preview.
*/
SliceView::SliceView(QWidget *parent) : QWizardPage(parent) {
	QVBoxLayout *layout = new QVBoxLayout(this);

	QLabel *title = new QLabel("Partition Layout (Mode A)");
	title->setStyleSheet("font-size: 18px; color: #00bfff; font-weight: bold;");
	layout->addWidget(title);

	slicer = new AutoSlicer();
	refreshLayout(20); // Dummy: 20GB Initialisierung
}

/**
* DE: Aktualisiert die Anzeige basierend auf der berechneten Logik.
* EN: Updates the display based on calculated logic.
*/
void SliceView::refreshLayout(long totalGB) {
	QList<SliceInfo> slices = slicer->calculateDefaultSlices(totalGB * 1024);

	for (const auto &slice : slices) {
		QLabel *lbl = new QLabel(QString("%1: %2 MB (%3)")
		.arg(slice.mountPoint)
		.arg(slice.sizeMB)
		.arg(slice.type));
		lbl->setStyleSheet("color: #b0b0b0; font-family: 'Courier New';");
		this->layout()->addWidget(lbl);
	}
}
