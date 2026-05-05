/* $NeuraBSD: ./src/core/AutoSlicerVisualizer.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Grafische Darstellung der Partitions-Slices im Neura-Design.
 * EN: Graphical representation of partition slices in Neura design.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "AutoSlicerVisualizer.hpp"
#include <QPainter>
#include <QToolTip>
#include <QMouseEvent>

/**
 * @file AutoSlicerVisualizer.cpp
 * @de Implementierung der Visualisierungs-Logik für CoreSeed Slices.
 * @en Implementation of the visualization logic for CoreSeed slices.
 */

AutoSlicerVisualizer::AutoSlicerVisualizer(QWidget *parent)
: QWidget(parent)
{
setMinimumHeight(100);
setMouseTracking(true);
}

/**
 * @de Aktualisiert die internen Daten und triggert das Repaint.
 * @en Updates internal data and triggers a repaint.
 */
void AutoSlicerVisualizer::setSlices(const QVector<PartitionSlice> &slices)
{
m_slices = slices;
update();
}

/**
 * @de Zeichnet die Slices proportional mit den definierten Neura-Farben.
 * @en Draws the slices proportionally using the defined Neura colors.
 */
void AutoSlicerVisualizer::paintEvent(QPaintEvent *event)
{
Q_UNUSED(event);
QPainter painter(this);
painter.setRenderHint(QPainter::Antialiasing);

if (m_slices.isEmpty()) {
painter.setPen(QColor("#3498db"));
painter.drawText(rect(), Qt::AlignCenter, "Warte auf Festplatten-Daten...");
return;
}

double totalSize = 0;
for (const auto &s : m_slices) totalSize += s.sizeGB;

int xOffset = 0;
int w = width();
int h = height();

for (const auto &slice : m_slices) {
int sliceWidth = (slice.sizeGB / totalSize) * w;

// Rechteck für die Slice (abzüglich Rand für die Optik)
QRect rect(xOffset, 10, sliceWidth - 4, h - 40);

// Hintergrundfarbe basierend auf Mountpoint
QColor baseColor = getColorForMount(slice.mountPoint);
painter.setBrush(baseColor);
painter.setPen(QPen(QColor("#3498db"), 1)); // Rahmen im Neura-Blau

painter.drawRoundedRect(rect, 2, 2);

// Beschriftung (Mountpoint & Größe)
painter.setPen(QColor("#b0b0b0"));
QString label = QString("%1\n%2 GB").arg(slice.mountPoint).arg(slice.sizeGB, 0, 'f', 1);
painter.drawText(rect.adjusted(5, 5, -5, 25), Qt::AlignBottom | Qt::AlignHCenter, label);

xOffset += sliceWidth;
}
}

/**
 * @de Mapping der Mountpoints auf die NeuraBSD Farbpalette.
 * @en Mapping of mount points to the NeuraBSD color palette.
 */
QColor AutoSlicerVisualizer::getColorForMount(const QString &mount)
{
// Sidebar-Navy (10273f) für Root
if (mount == "/")       return QColor(16, 39, 63); 
// Neura-Blau (3498db) für Home
if (mount == "/home")    return QColor(52, 152, 219); 
// Header/Footer-Navy (0a1a2f) für Swap
if (mount == "swap")     return QColor(10, 26, 47); 
// Deep Blue für Var
if (mount == "/var")     return QColor(26, 58, 95); 
// Content-Dark (0a0d10) für Tmp
if (mount == "/tmp")     return QColor(10, 13, 16); 

return QColor(42, 42, 42); // Fallback
}
