/* $NeuraBSD: CoreSeed/src/core/SysExecutor.cpp, v 1.0 2026/02/08 CodeAkrobat Exp $ */
#include "SysExecutor.hpp"

bool SysExecutor::executeAsRoot(const QString &cmd, const QStringList &args) {
    QStringList doasArgs;
    doasArgs << "-n" << cmd << args; // -n für non-interactive (erfordert passende doas.conf)

    int exitCode = QProcess::execute("/usr/bin/doas", doasArgs);
    return (exitCode == 0);
}
