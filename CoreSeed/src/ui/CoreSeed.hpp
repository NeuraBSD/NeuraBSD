/* $NeuraBSD: CoreSeed/src/ui/CoreSeed.hpp, v 1.2 2026/02/14 CodeAkrobat Exp $ */
#ifndef CORESEED_HPP
#define CORESEED_HPP

#include <QWizard>

class CoreSeed : public QWizard {
	Q_OBJECT
	public:
		explicit CoreSeed(QWidget *parent = nullptr);
	};

	#endif
