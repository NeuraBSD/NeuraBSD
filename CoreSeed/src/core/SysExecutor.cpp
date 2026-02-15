/* $NeuraBSD: CoreSeed/src/core/SysExecutor.cpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
 * DE: Implementierung des System-Wrappers.
 * EN: Implementation of the system wrapper.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include "core/SysExecutor.hpp"
#include <QProcess>

SysExecutor::SysExecutor(QObject *parent) : QObject(parent) {}

bool SysExecutor::execute(const QString &cmd, const QStringList &args) {
QProcess process;
process.start(cmd, args);

if (!process.waitForFinished()) {
m_lastError = process.errorString();
return false;
}

m_lastOutput = process.readAllStandardOutput().trimmed();
m_lastError = process.readAllStandardError().trimmed();

return (process.exitCode() == 0);
}
