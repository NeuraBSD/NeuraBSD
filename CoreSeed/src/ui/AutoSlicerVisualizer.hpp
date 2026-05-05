/* $NeuraBSD: ./src/ui/AutoSlicerVisualizer.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Definition der Slice-Struktur und des Visualisierungs-Widgets.
 * EN: Definition of the slice structure and visualization widget.
 */

#ifndef AUTOSLICERVISUALIZER_HPP
#define AUTOSLICERVISUALIZER_HPP

#include <QWidget>
#include <QVector>
#include <QColor>

class AutoSlicerVisualizer : public QWidget {
	Q_OBJECT

public:
	/**
	 * @struct SliceInfo
	 * @brief DE: Datenstruktur für eine einzelne OpenBSD-Partition.
	 * EN: Data structure for a single OpenBSD partition.
	 */
	struct SliceInfo {
		QString mountPoint;     ///< DE: Einhängepunkt (z.B. / oder /home)
		double sizeGB;    ///< DE: Größe in Gigabyte (Großschreibung angepasst)
		QColor color;      ///< DE: Farbe für die GUI
	};

	explicit AutoSlicerVisualizer(QWidget *parent = nullptr);
	void setSlices(const QVector<SliceInfo> &slices);

protected:
	void paintEvent(QPaintEvent *event) override;

private:
	QVector<SliceInfo> m_slices;
};

#endif // AUTOSLICERVISUALIZER_HPP
