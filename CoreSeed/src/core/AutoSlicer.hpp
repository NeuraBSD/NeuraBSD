/* $NeuraBSD: ./src/core/AutoSlicer.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Definition der Slicer-Logik mit Steuerungs-Flags für Experten-Optionen.
 * EN: Definition of the slicer logic with control flags for expert options.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef AUTOSLICER_HPP
#define AUTOSLICER_HPP

#include <QObject>
#include <QVector>
#include <QString>

/**
 * @struct PartitionSlice
 * @de Repräsentiert einen einzelnen Partitionseintrag.
 * @en Represents a single partition entry.
 */
struct PartitionSlice {
QString mountPoint;
double sizeGB;
QString fsType;
};

/**
 * @class AutoSlicer
 * @de Berechnet dynamisch Partitions-Layouts basierend auf Nutzer-Vorgaben.
 * @en Dynamically calculates partition layouts based on user input.
 */
class AutoSlicer : public QObject
{
Q_OBJECT

public:
explicit AutoSlicer(QObject *parent = nullptr);

/** @de Startet die Berechnung des Layouts. */
void calculateLayout(double totalCapacityGB);

/** @de Gibt die berechneten Slices zurück. */
QVector<PartitionSlice> getSlices() const;

/** @de Steuert die Nutzung einer separaten /var Partition. */
void setUseVar(bool use) { m_useVar = use; }

/** @de Steuert die Nutzung von MFS für /tmp. */
void setUseMfs(bool use) { m_useMfs = use; }

signals:
/** @de Wird emittiert, wenn sich das Layout geändert hat. */
void layoutChanged();

private:
QVector<PartitionSlice> m_slices;
bool m_useVar = true;
bool m_useMfs = true;
};

#endif // AUTOSLICER_HPP
