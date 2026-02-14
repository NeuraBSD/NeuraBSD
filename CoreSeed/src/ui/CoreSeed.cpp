/* $NeuraBSD: CoreSeed/src/ui/CoreSeed.cpp, v 1.3 2026/02/14 CodeAkrobat Exp $ */
#include "CoreSeed.hpp"
#include "DiagnosticPage.hpp"
#include "PartitionPage.hpp"
#include "TerminalPage.hpp"

CoreSeed::CoreSeed(QWidget *parent) : QWizard(parent) {
setWindowTitle("NeuraBSD CoreSeed - System Deployment");
setWizardStyle(QWizard::ModernStyle);

// DE: Seiten-Indizes für den Wizard.
// EN: Page indices for the wizard.
addPage(new DiagnosticPage(this));
addPage(new PartitionPage(this));
addPage(new TerminalPage(this));

// DE: Das Neura-Blue UI Design.
// EN: The Neura-Blue UI design.
setStyleSheet(
"QWizard { background-color: #0a0a0a; color: #b0b0b0; }"
"QLabel { color: #b0b0b0; font-family: 'Courier New'; }"
"QPushButton { background-color: #121212; color: #b0b0b0; border: 1px solid #d32f2f; }"
);
}
