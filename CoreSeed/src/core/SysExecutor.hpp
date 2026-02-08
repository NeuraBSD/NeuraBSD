/* $NeuraBSD: CoreSeed/src/core/SysExecutor.hpp, v 1.0 2026/02/08 CodeAkrobat Exp $ */
/*
 * DE: Kapselung von Systembefehlen via doas.
 * EN: Encapsulation of system commands via doas.
 *
 * WAS: Führt privilegierte Befehle auf OpenBSD aus.
 * WIE: Nutzt QProcess zur Interaktion mit /usr/bin/doas.
 * WARUM: Sicherheit durch gezielte Rechteeskalation.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef SYSEXECUTOR_HPP
#define SYSEXECUTOR_HPP

#include <QString>
#include <QStringList>
#include <QProcess>

/**
 * @class SysExecutor
 * @brief Führt Befehle mit Root-Rechten aus.
 */
class SysExecutor {
public:
    /**
     * @brief Führt einen Befehl via doas aus.
     * @param cmd Der Befehl (z.B. "disklabel")
     * @param args Die Argumente
     * @return true wenn erfolgreich.
     */
    static bool executeAsRoot(const QString &cmd, const QStringList &args);
};

#endif
