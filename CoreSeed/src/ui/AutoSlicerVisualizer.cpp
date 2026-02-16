/* $NeuraBSD: CoreSeed/src/ui/AutoSlicerVisualizer.cpp, v 1.3 2026/02/16 CodeAkrobat Exp $ */
/*
 * DE: Grafische Darstellung der Festplatten-Slices.
 * EN: Graphical representation of disk slices.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "ui/AutoSlicerVisualizer.hpp"
#include <QPainter>

AutoSlicerVisualizer::AutoSlicerVisualizer(QWidget *parent)
	: QWidget(parent)
{
	setMinimumHeight(100);
}

void AutoSlicerVisualizer::setSlices(const QVector<SliceInfo> &slices)
{
	m_slices = slices;
	update(); // Löst paintEvent aus
}

void AutoSlicerVisualizer::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	int w = width();
	int h = height();

	if (m_slices.isEmpty()) {
		painter.setPen(Qt::gray);
		painter.drawText(rect(), Qt::AlignCenter, tr("Keine Daten zur Visualisierung"));
		return;
	}

	double totalSize = 0;
	for (const auto &slice : m_slices) {
		totalSize += slice.sizeGB;
	}

	int currentX = 0;
	for (const auto &slice : m_slices) {
		int sliceWidth = static_cast<int>((slice.sizeGB / totalSize) * w);
		QRect sliceRect(currentX, 0, sliceWidth, h - 20);

		// Slice zeichnen
		painter.setBrush(slice.color);
		painter.setPen(Qt::black);
		painter.drawRect(sliceRect);

		// Beschriftung (Mountpoint und Größe)
		painter.setPen(Qt::white);
		QString label = QString("%1 (%2G)").arg(slice.mountPoint).arg(slice.sizeGB, 0, 'f', 1);
		painter.drawText(QRect(currentX, h - 18, sliceWidth, 18), Qt::AlignCenter, label);

		currentX += sliceWidth;
	}
}
