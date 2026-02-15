/* $NeuraBSD: CoreSeed/src/core/SysExecutor.hpp, v 1.2 2026/02/15 CodeAkrobat Exp $ */
/*
 * DE: Wrapper für Systembefehle (QProcess).
 * EN: Wrapper for system commands (QProcess).
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#ifndef SYSEXECUTOR_HPP
#define SYSEXECUTOR_HPP

#include <QObject>
#include <QStringList>

class SysExecutor : public QObject {
Q_OBJECT

public:
explicit SysExecutor(QObject *parent = nullptr);
virtual ~SysExecutor() = default;

bool execute(const QString &cmd, const QStringList &args);
QString lastOutput() const { return m_lastOutput; }
QString lastError() const { return m_lastError; }

private:
QString m_lastOutput;
QString m_lastError;
};

#endif // SYSEXECUTOR_HPP
