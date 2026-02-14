/* $NeuraBSD: CoreSeed/src/core/SysExecutor.hpp, v 1.0 2026/02/14 CodeAkrobat Exp $ */
#ifndef SYSEXECUTOR_HPP
#define SYSEXECUTOR_HPP
#include <QObject>
class SysExecutor : public QObject {
Q_OBJECT
public:
explicit SysExecutor(QObject *parent = nullptr);
};
#endif
