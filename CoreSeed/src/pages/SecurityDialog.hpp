/* $NeuraBSD: CoreSeed/src/pages/SecurityDialog.hpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Dialog für Sicherheitsabfragen und Passwörter.
* EN: Dialog for security prompts and passwords.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#ifndef SECURITYDIALOG_HPP
#define SECURITYDIALOG_HPP

#include <QDialog>

class SecurityDialog : public QDialog {
	Q_OBJECT

	public:
		explicit SecurityDialog(QWidget *parent = nullptr);
	};

	#endif // SECURITYDIALOG_HPP
