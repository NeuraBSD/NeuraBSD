/* $NeuraBSD: ./src/core/DeploymentController.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Definition des Deployment-Controllers zur Ausführung der Installation.
 * EN: Definition of the deployment controller for executing the installation.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef DEPLOYMENTCONTROLLER_HPP
#define DEPLOYMENTCONTROLLER_HPP

#include <QObject>
#include <QVector>
#include "AutoSlicer.hpp"

/**
 * @class DeploymentController
 * @de Übersetzt die Slicing-Logik in reale Systembefehle.
 * @en Translates slicing logic into real system commands.
 */
class DeploymentController : public QObject
{
Q_OBJECT

public:
explicit DeploymentController(QObject *parent = nullptr);

/**
 * @de Startet den Installationsprozess auf dem Zielgerät.
 * @en Starts the installation process on the target device.
 * @param disk Der Gerätename (z.B. "sd0").
 * @param slices Die zu schreibenden Partitionen.
 */
void startDeployment(const QString &disk, const QVector<PartitionSlice> &slices);

signals:
/** @de Signalisiert den Fortschritt (0-100%). */
void progressUpdate(int percent, const QString &status);
/** @de Signalisiert den Abschluss der Operation. */
void finished(bool success, const QString &message);

private:
/** @de Führt die eigentlichen Low-Level Befehle aus. */
void runFormatSequence(const QString &disk, const QVector<PartitionSlice> &slices);
};

#endif // DEPLOYMENTCONTROLLER_HPP
