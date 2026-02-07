/*	$NeuraBSD: main.cpp, v 1.2 2026/02/07 16:15:00 codeakrobat Exp $	*/

/*
 * Copyright (c) 2026 Daniel Hilbert <lead@neurabsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * @file main.cpp
 * @brief Main entry point for the CoreSeed graphical installer.
 * @brief Haupteinstiegspunkt für den grafischen Installer CoreSeed.
 *
 * This application initializes the first stage of the NeuraBSD 
 * installation process using Qt6.
 * Diese Anwendung initialisiert die erste Phase des NeuraBSD-
 * Installationsprozesses unter Verwendung von Qt6.
 *
 * @author CodeAkrobat (Daniel Hilbert)
 */

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>

/**
 * @brief Main function initializing the Qt6 environment.
 * @brief Hauptfunktion zur Initialisierung der Qt6-Umgebung.
 *
 * @param argc Argument count / Anzahl der Argumente.
 * @param argv Argument vector / Argument-Vektor.
 * @return int Exit status / Rückgabestatus.
 */
int
main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	/**
	 * @section UI-Initialization
	 * Setting up the main window with NeuraBSD branding.
	 * Einrichten des Hauptfensters mit NeuraBSD-Branding.
	 */
	QWidget window;
	window.setWindowTitle("NeuraBSD CoreSeed - System Setup");
	window.resize(1024, 768);

	/* Apply global styles / Globale Stile anwenden */
	window.setStyleSheet(
	t"background-color: #0a0d10;" // Deep Neura Blue
	t"color: #b0b0b0;"ttt  // Text Grey
	);

	QVBoxLayout *layout = new QVBoxLayout(&window);
	layout->setContentsMargins(50, 50, 50, 50);

	/* * Title Setup 
	 * Titles use white for high contrast on dark background.
	 * Titel verwenden Weiß für hohen Kontrast auf dunklem Grund.
	 */
	QLabel *title = new QLabel("Willkommen bei NeuraBSD");
	QFont titleFont("Courier New", 28, QFont::Bold);
	title->setFont(titleFont);
	title->setStyleSheet("color: #ffffff;");
	title->setAlignment(Qt::AlignCenter);

	QLabel *subtitle = new QLabel(
	t"Alles beginnt mit der grafischen Installation.\n"
	t"Everything starts with the graphical installation.");
	subtitle->setFont(QFont("Courier New", 14));
	subtitle->setAlignment(Qt::AlignCenter);

	/*
	 * Main Action Button
	 * Stylized with the Beastie Red/Purple accent border.
	 * Gestaltet mit dem Beastie-Red/Purple Akzentrand.
	 */
	QPushButton *startButton = new QPushButton(
	t"Installation starten / Start Installation");
	startButton->setFixedSize(350, 60);
	startButton->setStyleSheet(
	t"QPushButton {"
	t"  background-color: #121212;"
	t"  color: #b0b0b0;"
	t"  border: 2px solid #d32f2f;"
	t"  border-radius: 8px;"
	t"  font-weight: bold;"
	t"  font-family: 'Courier New';"
	t"}"
	t"QPushButton:hover {"
	t"  background-color: #d32f2f;"
	t"  color: white;"
	t"}"
	);

	/* Add components to layout / Komponenten zum Layout hinzufügen */
	layout->addWidget(title);
	layout->addWidget(subtitle);
	layout->addStretch();
	layout->addWidget(startButton, 0, Qt::AlignCenter);

	window.show();

	return (app.exec());
}
