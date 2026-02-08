/* $NeuraBSD: CoreSeed/src/ui/CoreSeed.hpp, v 1.2 2026/02/08 CodeAkrobat Exp $ */
/*
 * DE: Host-Fenster für den CoreSeed Installer.
 * EN: Host window for the CoreSeed installer.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef CORESEED_HPP
#define CORESEED_HPP

#include <QWizard>

/**
 * @class CoreSeed
 * @brief Der Haupt-Wizard für die Installation.
 * * DE: Verwaltet die verschiedenen Installer-Seiten (Diagnose, Terminal, etc.).
 * EN: Manages the various installer pages (Diagnostic, Terminal, etc.).
 */
class CoreSeed : public QWizard {
    Q_OBJECT
public:
    explicit CoreSeed(QWidget *parent = nullptr);
};

#endif
