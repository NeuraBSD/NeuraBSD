/* $NeuraBSD: CoreSeed/src/pages/PartitionPage.hpp, v 1.2 2026/02/14 CodeAkrobat Exp $ */
#ifndef PARTITIONPAGE_HPP
#define PARTITIONPAGE_HPP

#include "InstallerPage.hpp"

class PartitionPage : public InstallerPage {
	Q_OBJECT
	public:
		explicit PartitionPage(QWidget *parent = nullptr);
	};

	#endif
