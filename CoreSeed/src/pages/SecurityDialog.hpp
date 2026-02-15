/* $NeuraBSD: CoreSeed/src/pages/SecurityDialog.hpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Sicherheitsdialog vor der finalen Partitionierung.
* EN: Security dialog before final partitioning.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#ifndef SECURITYDIALOG_HPP
#define SECURITYDIALOG_HPP

#include <QDialog>

/**
* @class SecurityDialog
* @brief DE: Bestätigungsdialog für kritische Operationen.
* @brief EN: Confirmation dialog for critical operations.
*/
class SecurityDialog : public QDialog {
	Q_OBJECT
	public:
		/**
		* @brief DE: Konstruktor für den Sicherheitsdialog.
		* @brief EN: Constructor for the security dialog.
		*/
		explicit SecurityDialog(QWidget *parent = nullptr);
	};

	#endif // SECURITYDIALOG_HPP
