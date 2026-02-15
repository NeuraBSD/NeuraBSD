/* $NeuraBSD: CoreSeed/src/pages/PartitionPage.cpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Implementierung der Partitionierungsseite.
* EN: Implementation of the partitioning page.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#include "pages/PartitionPage.hpp"
#include <QLabel>
#include <QVBoxLayout>

PartitionPage::PartitionPage(QWidget *parent) : InstallerPage(parent) {
	setPageTitle("Partitionierung");
	QVBoxLayout *layout = new QVBoxLayout(this);

	layout->addWidget(new QLabel("Wählen Sie die Zielfestplatte für NeuraBSD:"));
}
