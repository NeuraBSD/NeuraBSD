/* $NeuraBSD: CoreSeed/src/pages/PartitionPage.hpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Seite für die Festplattenauswahl und Partitionierung.
* EN: Page for disk selection and partitioning.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#ifndef PARTITIONPAGE_HPP
#define PARTITIONPAGE_HPP

#include "ui/InstallerPage.hpp"

/**
* @class PartitionPage
* @brief DE: Interface für die Auswahl der Ziel-Festplatte.
* @brief EN: Interface for selecting the target hard drive.
*/
class PartitionPage : public InstallerPage {
	Q_OBJECT

	public:
		explicit PartitionPage(QWidget *parent = nullptr);
	};

	#endif // PARTITIONPAGE_HPP
