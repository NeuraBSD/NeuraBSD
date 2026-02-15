/* $NeuraBSD: CoreSeed/src/pages/SliceView.hpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Visualisierung der Partitionen (Slices).
* EN: Visualization of partitions (slices).
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#ifndef SLICEVIEW_HPP
#define SLICEVIEW_HPP

#include <QWizardPage>
#include <QVBoxLayout>
#include "core/AutoSlicer.hpp"

/**
* @class SliceView
* @brief DE: Seite zur grafischen Darstellung der berechneten Partitionen.
* @brief EN: Page for graphical representation of calculated partitions.
*/
class SliceView : public QWizardPage {
	Q_OBJECT
	public:
		/**
		* @brief DE: Konstruktor der Slice-Ansicht.
		* @brief EN: Constructor of the slice view.
		*/
		explicit SliceView(QWidget *parent = nullptr);

		/**
		* @brief DE: Aktualisiert die Ansicht basierend auf einer Festplattengröße.
		* @brief EN: Updates the view based on a disk size.
		*/
		void refreshLayout(long totalGB);

		private:
			QVBoxLayout *m_mainLayout;
		};

		#endif // SLICEVIEW_HPP
