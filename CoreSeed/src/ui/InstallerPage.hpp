/* $NeuraBSD: CoreSeed/src/ui/InstallerPage.hpp, v 1.2 2026/02/14 CodeAkrobat Exp $ */
#ifndef INSTALLERPAGE_HPP
#define INSTALLERPAGE_HPP

#include <QWizardPage>

/**
 * @class InstallerPage
 * @brief DE: Basisklasse für alle Seiten des CoreSeed Installers.
 * @brief EN: Base class for all pages of the CoreSeed installer.
 */
class InstallerPage : public QWizardPage {
Q_OBJECT
public:
explicit InstallerPage(QWidget *parent = nullptr);
};

#endif
