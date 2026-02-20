/* $NeuraBSD: CoreSeed/src/ui/NeuraPulse.qml, v 1.0 2026/02/19 CodeAkrobat Exp $ */

/*
 * DE:
 * WAS: Konvergenz-Ladebalken-Komponente für die AxonSurface.
 * WARUM: Um die Verschmelzung von Hardware (Base) und Software (Neura-UX) visuell darzustellen. 
 * Die Bewegung von außen nach innen symbolisiert den Fokus auf den Kern des Systems.
 * WIE: Zwei symmetrische Rechtecke wachsen proportional zum 'progress'-Wert zur Mitte hin. 
 * Ein Easing-Behavior sorgt für organische, nicht-lineare Bewegungsabläufe.
 *
 * EN:
 * WHAT: Convergence progress bar component for AxonSurface.
 * WHY: To visually represent the fusion of hardware (base) and software (Neura-UX). 
 * The movement from outside to center symbolizes the focus on the system's core.
 * HOW: Two symmetrical rectangles grow towards the center proportional to the 'progress' value. 
 * An easing behavior ensures organic, non-linear motion.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

import QtQuick

Item {
	id: root
	width: 600
	height: 20
	
	// Fortschrittswert (0.0 bis 1.0), der von der C++ Logik (AutoSlicer) gesteuert wird.
	property real progress: 0.0 

	Rectangle {
		id: background
		anchors.fill: parent
		color: "#121212" // --surface-black
		radius: 10
		border.color: "#333"

		// Linker Impuls (Neura-Blue): Repräsentiert die Hardware/Basis.
		Rectangle {
			id: pulseLeft
			height: parent.height
			width: (parent.width / 2) * root.progress
			anchors.left: parent.left
			color: "#00aaff"
			radius: parent.radius
			
			Behavior on width { NumberAnimation { duration: 300; easing.type: Easing.OutCubic } }
		}

		// Rechter Impuls (Neura-Purple): Repräsentiert die AxonSurface/User-Experience.
		Rectangle {
			id: pulseRight
			height: parent.height
			width: (parent.width / 2) * root.progress
			anchors.right: parent.right
			color: "#9b59b6"
			radius: parent.radius

			Behavior on width { NumberAnimation { duration: 300; easing.type: Easing.OutCubic } }
		}
	}
}
