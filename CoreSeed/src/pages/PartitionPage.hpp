/* $NeuraBSD: CoreSeed/src/pages/PartitionPage.hpp, v 1.3 2026/02/16 CodeAkrobat Exp $ */
#ifndef PARTITIONPAGE_HPP
#define PARTITIONPAGE_HPP

#include "ui/InstallerPage.hpp"
#include "ui/AutoSlicerVisualizer.hpp"
#include "core/AutoSlicer.hpp"
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>

class PartitionPage : public InstallerPage {
	Q_OBJECT

public:
	explicit PartitionPage(QWidget *parent = nullptr);
	QString selectedDisk() const;
	QVector<AutoSlicerVisualizer::SliceInfo> calculatedSlices() const;

private slots:
	void updateDiskPreview(int index);

private:
	QVBoxLayout	*m_layout;
	QComboBox		*m_diskSelector;
	QLabel		*m_instructionLabel;
	AutoSlicerVisualizer	*m_visualizer;
	AutoSlicer		*m_slicer;
};

#endif // PARTITIONPAGE_HPP
