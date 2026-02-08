/* $NeuraBSD: CoreSeed/src/pages/PartitionPage.cpp, v 1.0 2026/02/08 CodeAkrobat Exp $ */
#include "PartitionPage.hpp"
#include "core/HardwareScanner.hpp"

/**
 * DE: Initialisiert das Layout für die Festplattenauswahl.
 * EN: Initializes the layout for disk selection.
 */
PartitionPage::PartitionPage(QWidget *parent) : InstallerPage(parent) {
    setTitle("Ziel wählen / Select Target");
    setSubTitle("Bitte wählen Sie die Festplatte für NeuraBSD.");

    QVBoxLayout *layout = new QVBoxLayout(this);
    
    diskList = new QListWidget(this);
    diskList->setStyleSheet("background-color: #121212; color: #4a90e2; font-size: 14px;");
    
    statusLabel = new QLabel("Wähle ein Laufwerk aus...");
    
    layout->addWidget(diskList);
    layout->addWidget(statusLabel);

    connect(diskList, &QListWidget::itemSelectionChanged, [this]() {
        emit completeChanged(); // Benachrichtigt den Wizard, dass "Weiter" aktiv werden kann
    });
}

/**
 * DE: Holt die aktuelle Disk-Liste beim Betreten der Seite.
 * EN: Fetches current disk list when entering the page.
 */
void PartitionPage::onEnter() {
    diskList->clear();
    HardwareScanner scanner;
    QStringList disks = scanner.getDisks();
    
    for (const QString &disk : disks) {
        diskList->addItem(disk + " (OpenBSD Drive)");
    }
}

bool PartitionPage::isComplete() const {
    return diskList->selectedItems().count() > 0;
}
