/* $NeuraBSD: CoreSeed/src/ui/InstallerPage.hpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Basisklasse für alle Installer-Seiten.
* EN: Base class for all installer pages.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#ifndef INSTALLERPAGE_HPP
#define INSTALLERPAGE_HPP

#include <QWizardPage>

/**
* @class InstallerPage
* @brief DE: Abstrakte Basisklasse für ein einheitliches Layout der Seiten.
* @brief EN: Abstract base class for a consistent page layout.
*/
class InstallerPage : public QWizardPage {
	Q_OBJECT

	public:
		explicit InstallerPage(QWidget *parent = nullptr);
		virtual ~InstallerPage() = default;

		protected:
		void setPageTitle(const QString &title);
	};

	#endif // INSTALLERPAGE_HPP
