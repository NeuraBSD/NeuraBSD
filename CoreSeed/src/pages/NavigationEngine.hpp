/* $NeuraBSD: CoreSeed/src/pages/NavigationEngine.hpp, v 1.3 2026/02/15 CodeAkrobat Exp $ */
/*
* DE: Navigationssteuerung mit flexibler Widget-Anbindung.
* EN: Navigation control with flexible widget binding.
*
* Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
* License: BSD 3-Clause
*/

#ifndef NAVIGATIONENGINE_HPP
#define NAVIGATIONENGINE_HPP

#include <QWizardPage>
#include <QPushButton>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QListWidget>

/**
* @class NavigationEngine
* @brief DE: Verwaltung der Navigation. Akzeptiert QWidget für maximale Kompatibilität.
* EN: Navigation management. Accepts QWidget for maximum compatibility.
*/
class NavigationEngine : public QWizardPage {
	Q_OBJECT
	public:
		// DE: Wir nehmen QWidget* für die Sidebar, um Casting-Fehler in der main.cpp zu vermeiden.
		explicit NavigationEngine(QStackedWidget *stack, QWidget *sidebar, QWidget *parent = nullptr);

		void addStep(const QString &label, QWidget *page);
		void lockNavigation();

		private slots:
		void nextStep();
		void prevStep();

		private:
			QStackedWidget *m_stack;
			QListWidget *m_sidebar; // Intern arbeiten wir mit der Liste
			QPushButton *backButton;
			QPushButton *nextButton;
		};

		#endif // NAVIGATIONENGINE_HPP
