/* $NeuraBSD: CoreSeed/src/core/AutoSlicer.hpp, v 1.5 2026/02/16 CodeAkrobat Exp $ */
#ifndef AUTOSLICER_HPP
#define AUTOSLICER_HPP

#include <QObject>
#include <QVector>
#include <QString>
#include "ui/AutoSlicerVisualizer.hpp"

class AutoSlicer : public QObject {
	Q_OBJECT
public:
	explicit AutoSlicer(QObject *parent = nullptr);
	
	/**
	 * @brief DE: Berechnet das Partitionslayout basierend auf GB.
	 * EN: Calculates the partition layout based on GB.
	 */
	QVector<AutoSlicerVisualizer::SliceInfo> calculateSlices(double totalSizeGB);

private:
	double m_totalSizeGB;
};

#endif // AUTOSLICER_HPP
