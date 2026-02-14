/* $NeuraBSD: CoreSeed/src/core/SysExecutor.hpp, v 1.1 2026/02/14 CodeAkrobat Exp $ */
#ifndef SYSEXECUTOR_HPP
#define SYSEXECUTOR_HPP

#include <QObject>

/**
* @class SysExecutor
* @brief DE: Verwaltung von Systemprozessen (QProcess).
* @brief EN: Management of system processes (QProcess).
*/
class SysExecutor : public QObject {
	Q_OBJECT
	public:
		explicit SysExecutor(QObject *parent = nullptr);
	};

	#endif
