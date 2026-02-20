/* $NeuraBSD: ./src/ui/InstallerPage.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */
#ifndef INSTALLERPAGE_HPP
#define INSTALLERPAGE_HPP

#include <QWidget>
#include <QString>

class InstallerPage : public QWidget {
	Q_OBJECT
public:
	explicit InstallerPage(QWidget *parent = nullptr) : QWidget(parent) {}
	void setPageTitle(const QString &title) { m_pageTitle = title; }
	QString pageTitle() const { return m_pageTitle; }

private:
	QString m_pageTitle;
};

#endif // INSTALLERPAGE_HPP
