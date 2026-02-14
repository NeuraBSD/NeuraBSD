/* $NeuraBSD: CoreSeed/src/pages/PartitionPage.cpp, v 1.3 2026/02/14 CodeAkrobat Exp $ */
#include "PartitionPage.hpp"
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>

/**
 * @brief DE: Partitionierungs-Logik für NeuraBSD Slices.
 * @brief EN: Partitioning logic for NeuraBSD slices.
 */
PartitionPage::PartitionPage(QWidget *parent) : InstallerPage(parent) {
setTitle("Disk Partitioning");
setSubTitle("DE: Wählen Sie das Zielmedium für NeuraBSD.\nEN: Select the target medium for NeuraBSD.");

QVBoxLayout *layout = new QVBoxLayout(this);
layout->addWidget(new QLabel("Select Target Disk:"));

QComboBox *diskSelector = new QComboBox(this);
diskSelector->setStyleSheet("background-color: #121212; color: #b0b0b0; border: 1px solid #d32f2f;");
// DE: Logik zum Befüllen kommt im nächsten Schritt.
layout->addWidget(diskSelector);

layout->addStretch();
}
