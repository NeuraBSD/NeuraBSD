/* $NeuraBSD: ./src/core/DeploymentController.cpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Erweiterung des Controllers um die Set-Extraktion und AxonSurface-Installation.
 * EN: Extension of the controller for set extraction and AxonSurface installation.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "DeploymentController.hpp"
#include <QProcess>
#include <QDir>

/**
 * @file DeploymentController.cpp
 * @de Automatisiert das Entpacken der BSD-Sets und die Integration von AxonSurface.
 */

void DeploymentController::extractSystemSets(const QString &sourcePath)
{
/* * DE: Liste der obligatorischen Sets für ein vollständiges NeuraBSD-Erlebnis.
 * EN: List of mandatory sets for a complete NeuraBSD experience.
 */
QStringList sets = {
"base7x.tgz", "comp7x.tgz", "game7x.tgz", "man7x.tgz",
"xbase7x.tgz", "xfont7x.tgz", "xserv7x.tgz", "xshare7x.tgz"
};

int totalSets = sets.size() + 2; // +1 für Firmware, +1 für AxonSurface
int currentStep = 0;

for (const QString &set : sets) {
currentStep++;
int progress = (currentStep * 80) / totalSets; // Die ersten 80% für Basis-Sets
emit progressUpdate(progress, "Extrahiere " + set + "...");

QProcess tar;
// -C /mnt: Entpacken direkt in das gemountete Zielsystem
tar.start("doas", {"tar", "-C", "/mnt", "-xzphf", sourcePath + "/" + set});
tar.waitForFinished(-1); // Warten bis fertig
}

// Schritt: Firmware & Microcode
emit progressUpdate(85, "Aktualisiere System-Firmware...");
QProcess::execute("doas", {"chroot", "/mnt", "fw_update", "-i"});

// Schritt: AxonSurface DE & Branding
emit progressUpdate(95, "Installiere AxonSurface Desktop Environment...");
installAxonSurface();

emit progressUpdate(100, "System erfolgreich eingerichtet!");
emit finished(true, "NeuraBSD ist nun bereit für den ersten Start.");
}

void DeploymentController::installAxonSurface()
{
/* * DE: Hier werden die AxonSurface-spezifischen Konfigurationen gesetzt.
 * EN: Setting up AxonSurface specific configurations here.
 */
QProcess::execute("doas", {"cp", "-R", "/usr/local/share/axonsurface", "/mnt/usr/local/share/"});

// Boot-Manager DaemonPath als Standard setzen
QProcess::execute("doas", {"chroot", "/mnt", "rcctl", "enable", "apmd"}); // Beispielhafter Dienst
}
