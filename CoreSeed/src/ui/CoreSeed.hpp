/* $NeuraBSD: CoreSeed/src/ui/CoreSeed.hpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
 * DE: Header für das Hauptfenster (Wizard-Steuerung).
 * EN: Header for the main window (Wizard control).
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef CORESEED_HPP
#define CORESEED_HPP

#include <QWizard>

/**
 * @class CoreSeed
 * @brief DE: Verwaltet die verschiedenen Installationsseiten und das globale Design.
 * @brief EN: Manages the various installation pages and global design.
 */
class CoreSeed : public QWizard {
Q_OBJECT

public:
explicit CoreSeed(QWidget *parent = nullptr);
~CoreSeed() = default;

private:
void setupUi();
};

#endif // CORESEED_HPP
