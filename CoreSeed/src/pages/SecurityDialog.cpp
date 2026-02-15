/* $NeuraBSD: CoreSeed/src/pages/SecurityDialog.cpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/**
* @file SecurityDialog.cpp
* @brief DE: Implementierung des Sicherheitsdialogs (Warnung vor Datenverlust).
* @brief EN: Implementation of the security dialog (data loss warning).
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#include "pages/SecurityDialog.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

/**
* @details DE: Erstellt ein düsteres Design (Blue/Black) passend zum "Point of No Return".
* @details EN: Creates a dark design (Blue/Black) fitting the "Point of No Return".
*/
SecurityDialog::SecurityDialog(QWidget *parent) : QDialog(parent) {
	setWindowTitle(tr("FINAL WARNING"));
	setMinimumSize(400, 200);

	QVBoxLayout *layout = new QVBoxLayout(this);

	QLabel *warnTitle = new QLabel(tr("POINT OF NO RETURN"));
	warnTitle->setStyleSheet("color: #d32f2f; font-weight: bold; font-size: 18px;");
	layout->addWidget(warnTitle);

	QLabel *warnDesc = new QLabel(tr("DE: Alle Daten auf der gewählten Festplatte werden gelöscht!\n"
	"EN: All data on the selected disk will be erased!"));
	warnDesc->setWordWrap(true);
	layout->addWidget(warnDesc);

	QHBoxLayout *btnLayout = new QHBoxLayout();
	QPushButton *btnCancel = new QPushButton(tr("ABORT"));
	QPushButton *btnConfirm = new QPushButton(tr("I UNDERSTAND"));

	btnCancel->setStyleSheet("background-color: #333333; color: white; border: 1px solid #555555; padding: 5px;");
	btnConfirm->setStyleSheet("background-color: #7f1d1d; color: white; border: 1px solid #d32f2f; padding: 5px;");

	btnLayout->addWidget(btnCancel);
	btnLayout->addWidget(btnConfirm);
	layout->addLayout(btnLayout);

	connect(btnConfirm, &QPushButton::clicked, this, &QDialog::accept);
	connect(btnCancel, &QPushButton::clicked, this, &QDialog::reject);
}
