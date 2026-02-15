/* $NeuraBSD: CoreSeed/src/pages/SliceView.hpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Widget zur grafischen Darstellung der Slices/Partitionen.
* EN: Widget for graphical representation of slices/partitions.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#ifndef SLICEVIEW_HPP
#define SLICEVIEW_HPP

#include <QWidget>

class SliceView : public QWidget {
	Q_OBJECT

	public:
		explicit SliceView(QWidget *parent = nullptr);
	};

	#endif // SLICEVIEW_HPP
