/* $NeuraBSD: CoreSeed/src/core/AutoSlicer.hpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Partitionierungs-Logik für NeuraBSD.
* EN: Partitioning logic for NeuraBSD.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#ifndef AUTOSLICER_HPP
#define AUTOSLICER_HPP

#include <QObject>
#include <QString>

class AutoSlicer : public QObject {
	Q_OBJECT

	public:
		explicit AutoSlicer(QObject *parent = nullptr);
		virtual ~AutoSlicer() = default;

		void calculateDefaultSlices(long totalSizeMB);
	};

	#endif // AUTOSLICER_HPP
