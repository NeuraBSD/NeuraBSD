/* $NeuraBSD: ./src/pages/NavigationEngine.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
* DE: Implementierung der Navigation mit sicherem Type-Casting.
* EN: Implementation of navigation with safe type casting.
*/

#include "pages/NavigationEngine.hpp"
#include <qobjectdefs.h>

NavigationEngine::NavigationEngine(QStackedWidget *stack, QWidget *sidebar, QWidget *parent)
: QWizardPage(parent), m_stack(stack) {

	// DE: Sicherer Cast von QWidget zu QListWidget
	m_sidebar = qobject_cast<QListWidget*>(sidebar);

	QHBoxLayout *layout = new QHBoxLayout(this);
	backButton = new QPushButton("< Back");
	nextButton = new QPushButton("Next >");

	backButton->setEnabled(false);
	layout->addWidget(backButton);
	layout->addStretch();
	layout->addWidget(nextButton);

	connect(nextButton, &QPushButton::clicked, this, &NavigationEngine::nextStep);
	connect(backButton, &QPushButton::clicked, this, &NavigationEngine::prevStep);
}

void NavigationEngine::addStep(const QString &label, QWidget *page) {
	m_stack->addWidget(page);
	if (m_sidebar) {
		m_sidebar->addItem(label);
	}
}

void NavigationEngine::nextStep() {
	int nextIdx = m_stack->currentIndex() + 1;
	if (nextIdx < m_stack->count()) {
		m_stack->setCurrentIndex(nextIdx);
		if (m_sidebar) m_sidebar->setCurrentRow(nextIdx);
		backButton->setEnabled(true);
	}
}

void NavigationEngine::prevStep() {
	int prevIdx = m_stack->currentIndex() - 1;
	if (prevIdx >= 0) {
		m_stack->setCurrentIndex(prevIdx);
		if (m_sidebar) m_sidebar->setCurrentRow(prevIdx);
	}
	if (prevIdx == 0) backButton->setEnabled(false);
}

void NavigationEngine::lockNavigation() {
	backButton->setEnabled(false);
	nextButton->setEnabled(false);
}
