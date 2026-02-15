/* $NeuraBSD: CoreSeed/src/pages/SecurityDialog.cpp, v 1.0 2026/02/15 CodeAkrobat Exp $ */
/**
* @file SecurityDialog.cpp
* @brief DE: Implementierung der Sicherheitsabfrage vor der Systeminstallation.
* EN: Implementation of the security prompt before system installation.
*
* @details DE: Dieses modale Fenster erzwingt eine Bestätigung, bevor irreversible
* Änderungen an der Partitionstabelle vorgenommen werden.
* EN: This modal window forces a confirmation before irreversible changes
* are made to the partition table.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#include "SecurityDialog.hpp"

/**
* @brief DE: Konstruktor für den Sicherheitsdialog.
* EN: Constructor for the security dialog.
* @param parent Zeiger auf das Eltern-Widget.
*/
SecurityDialog::SecurityDialog(QWidget *parent) : QDialog(parent) {
	// DE: Fenster-Eigenschaften (Modaler Dialog)
	// EN: Window properties (Modal dialog)
	setWindowTitle("CRITICAL WARNING");
	setFixedSize(400, 250);
	setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);

	// DE: Styling passend zum Neura-Design (Dunkel mit Warn-Rot)
	// EN: Styling matching Neura design (Dark with warning red)
	setStyleSheet(
	"QDialog { background-color: #0a0a0a; border: 2px solid #d32f2f; }"
	"QLabel { color: #b0b0b0; font-family: 'Courier New'; font-size: 13px; }"
	"QPushButton { background-color: #7f1d1d; color: #ffffff; border: 1px solid #d32f2f; padding: 10px; font-weight: bold; }"
	"QPushButton:hover { background-color: #d32f2f; }"
	);

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->setContentsMargins(30, 30, 30, 30);
	layout->setSpacing(20);

	// DE: Warntext
	// EN: Warning text
	QLabel *warnTitle = new QLabel("POINT OF NO RETURN");
	warnTitle->setStyleSheet("color: #d32f2f; font-size: 18px; font-weight: bold;");
	warnTitle->setAlignment(Qt::AlignCenter);

	QLabel *warnDesc = new QLabel(
	"DE: Alle Daten auf dem ausgewählten Laufwerk werden gelöscht.\n"
	"EN: All data on the selected drive will be destroyed.\n\n"
	"Proceed with installation?"
	);
	warnDesc->setWordWrap(true);
	warnDesc->setAlignment(Qt::AlignCenter);

	// DE: Aktions-Buttons
	// EN: Action buttons
	QHBoxLayout *btnLayout = new QHBoxLayout();
	QPushButton *btnCancel = new QPushButton("ABORT");
	QPushButton *btnConfirm = new QPushButton("I UNDERSTAND");

	btnCancel->setStyleSheet("background-color: #333333; border: 1px solid #555555;");

	btnLayout->addWidget(btnCancel);
	btnLayout->addWidget(btnConfirm);

	layout->addWidget(warnTitle);
	layout->addWidget(warnDesc);
	layout->addLayout(btnLayout);

	// DE: Signal-Verknüpfung
	// EN: Signal mapping
	connect(btnConfirm, &QPushButton::clicked, this, &QDialog::accept);
	connect(btnCancel, &QPushButton::clicked, this, &QDialog::reject);
}
