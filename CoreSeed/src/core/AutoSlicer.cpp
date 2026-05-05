/* $NeuraBSD: ./src/core/AutoSlicer.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Dynamische Berechnung der Slices unter Berücksichtigung von Experten-Flags.
 * EN: Dynamic calculation of slices considering expert flags.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "AutoSlicer.hpp"
#include <algorithm>

/**
 * @file AutoSlicer.cpp
 * @de Logik zur Partitionierung mit Berücksichtigung von Isolation und Performance.
 */

AutoSlicer::AutoSlicer(QObject *parent)
: QObject(parent)
{
}

/**
 * @de Berechnet das Layout. Falls /var deaktiviert ist, wird der Platz / zugeschlagen.
 * @en Calculates the layout. If /var is disabled, the space is added to /.
 */
void AutoSlicer::calculateLayout(double totalCapacityGB)
{
m_slices.clear();

double swapSize = (totalCapacityGB > 64.0) ? 8.0 : 4.0;
double rootBase = 2.0;
double tmpSize = 1.0;
double varSize = 0.0;

// /var Logik
if (m_useVar) {
varSize = std::max(4.0, totalCapacityGB * 0.1);
if (varSize > 40.0) varSize = 40.0;
} else {
rootBase += 4.0; // Vergrößere Root, wenn /var integriert ist
}

double usedSpace = swapSize + rootBase + varSize + tmpSize;
double homeSize = std::max(1.0, totalCapacityGB - usedSpace);

// Aufbau der Slice-Liste
m_slices.append({"/", rootBase, "FFS2"});
m_slices.append({"swap", swapSize, "SWAP"});

if (m_useVar) {
m_slices.append({"/var", varSize, "FFS2"});
}

m_slices.append({"/tmp", tmpSize, m_useMfs ? "MFS" : "FFS2"});
m_slices.append({"/home", homeSize, "FFS2"});

emit layoutChanged();
}

QVector<PartitionSlice> AutoSlicer::getSlices() const
{
return m_slices;
}
