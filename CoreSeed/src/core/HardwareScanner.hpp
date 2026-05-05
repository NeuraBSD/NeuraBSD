/* $NeuraBSD: ./src/core/HardwareScanner.hpp, v 1.0 2026/02/20 codeakrobat Exp $ */
/*
 * DE: Definition des Hardware-Scanners zur Datenträger-Erkennung.
 * EN: Definition of the hardware scanner for disk detection.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef HARDWARESCANNER_HPP
#define HARDWARESCANNER_HPP

#include <QObject>
#include <QStringList>
#include <QMap>

/**
 * @class HardwareScanner
 * @de Schnittstelle zur Abfrage physischer Laufwerke und Systemressourcen.
 * @en Interface for querying physical drives and system resources.
 */
class HardwareScanner : public QObject
{
Q_OBJECT

public:
/**
 * @de Konstruktor des HardwareScanners.
 * @en Constructor of the HardwareScanner.
 * @param parent Zeiger auf das übergeordnete QObject.
 */
explicit HardwareScanner(QObject *parent = nullptr);

/**
 * @de Scannt das System und liefert eine Liste der verfügbaren Festplattenbezeichner.
 * @en Scans the system and returns a list of available disk identifiers.
 * @return QStringList Liste der erkannten Geräte (z.B. sd0, wd0).
 */
QStringList getAvailableDisks();

/**
 * @de Ermittelt die Gesamtkapazität eines Datenträgers für die Partitionierung.
 * @en Determines the total capacity of a drive for partitioning.
 * @param diskName Der Systemname des Geräts.
 * @return double Die Kapazität in Gigabyte (GB).
 */
double getDiskCapacity(const QString &diskName);

private:
/** * @de Interne Datenstruktur zur Speicherung der Hardware-Profile.
 * @en Internal data structure for storing hardware profiles.
 */
QMap<QString, double> m_diskMap;
};

#endif // HARDWARESCANNER_HPP
