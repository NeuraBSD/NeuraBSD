/* $NeuraBSD: CoreSeed/src/ui/InstallerPage.hpp, v 1.1 2026/02/08 CodeAkrobat Exp $ */
/*
 * DE: Basis-Interface für NeuraBSD Installer-Seiten.
 * EN: Base interface for NeuraBSD installer pages.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef INSTALLERPAGE_HPP
#define INSTALLERPAGE_HPP

#include <QWizardPage>

/**
 * @class InstallerPage
 * @brief Basisklasse für alle Seiten des CoreSeed Wizards.
 * * DE: Erbt von QWizardPage, um die Integration in den Wizard zu ermöglichen.
 * EN: Inherits from QWizardPage to allow integration into the wizard.
 */
class InstallerPage : public QWizardPage {
    Q_OBJECT
public:
    explicit InstallerPage(QWidget *parent = nullptr) : QWizardPage(parent) {}
    
    /**
     * @brief Virtuelle Methode, die aufgerufen wird, wenn die Seite aktiv wird.
     */
    virtual void onEnter() {}

protected:
    /**
     * @brief Überschreibt die Qt-interne Methode, um onEnter zu triggern.
     */
    void initializePage() override {
        onEnter();
    }
};

#endif
