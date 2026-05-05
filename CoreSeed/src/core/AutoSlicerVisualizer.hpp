/* $NeuraBSD: ./src/core/AutoSlicerVisualizer.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Komponente zur grafischen Darstellung der Partitionsslices.
 * EN: Component for graphical representation of partition slices.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef AUTOSLICERVISUALIZER_HPP
#define AUTOSLICERVISUALIZER_HPP

#include <QWidget>
#include <QVector>
#include "AutoSlicer.hpp"

/**
 * @class AutoSlicerVisualizer
 * @de Zeichnet die Partitionen als farbige Balken mit Neura-Styling.
 * @en Renders partitions as colored bars with Neura styling.
 */
class AutoSlicerVisualizer : public QWidget
{
Q_OBJECT

public:
explicit AutoSlicerVisualizer(QWidget *parent = nullptr);

/** @de Setzt die anzuzeigenden Slices und löst ein Neuzeichnen aus. */
void setSlices(const QVector<PartitionSlice> &slices);

protected:
/** @de Die eigentliche Zeichenlogik (Qt Paint Engine). */
void paintEvent(QPaintEvent *event) override;

private:
QVector<PartitionSlice> m_slices;

/** @de Hilfsfunktion für die Farbwahl basierend auf dem Mountpoint. */
QColor getColorForMount(const QString &mount);
};

#endif // AUTOSLICERVISUALIZER_HPP
