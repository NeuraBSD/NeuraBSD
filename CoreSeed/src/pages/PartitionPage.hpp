/* $NeuraBSD: CoreSeed/src/pages/PartitionPage.hpp, v 1.1 2026/02/08 CodeAkrobat Exp $ */
/*
 * DE: UI-Modul für die Festplattenauswahl (Modul III).
 * EN: UI module for disk selection (Module III).
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef PARTITIONPAGE_HPP
#define PARTITIONPAGE_HPP

#include "ui/InstallerPage.hpp"
#include <QListWidget>
#include <QLabel>
#include <QVBoxLayout>

/**
 * @class PartitionPage
 * @brief Seite zur Auswahl des Installationsziels.
 * * DE: Listet alle verfügbaren Festplatten auf.
 * EN: Lists all available disks.
 */
class PartitionPage : public InstallerPage {
    Q_OBJECT
public:
    explicit PartitionPage(QWidget *parent = nullptr);
    void onEnter() override;
    bool isComplete() const override;

private:
    QListWidget *diskList;
    QLabel *statusLabel;
};

#endif
