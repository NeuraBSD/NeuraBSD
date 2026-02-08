/* $NeuraBSD: CoreSeed/src/ui/CoreSeed.cpp, v 1.2 2026/02/08 CodeAkrobat Exp $ */
#include "CoreSeed.hpp"

/**
 * DE: Initialisiert den Wizard und setzt das visuelle Design.
 * EN: Initializes the wizard and sets the visual design.
 */
CoreSeed::CoreSeed(QWidget *parent) : QWizard(parent) {
    // NeuraBSD Design-Elemente
    setWizardStyle(QWizard::ModernStyle);
    
    // CSS für das Blue-Flow Design
    setStyleSheet(
        "QWizard { background-color: #0a0a0a; color: #b0b0b0; }"
        "QLabel { color: #b0b0b0; }"
        "QPushButton { background-color: #121212; color: #4a90e2; border: 1px solid #4a90e2; padding: 5px; }"
        "QPushButton:hover { background-color: #4a90e2; color: #0a0a0a; }"
    );
    
    setOption(QWizard::NoBackButtonOnStartPage);
}
