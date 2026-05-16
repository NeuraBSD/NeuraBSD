/* $NeuraBSD: base_system/NeuraCore/hw/scan.cppm, v 1.0 2026/05/16 codeakrobat Exp $ */
/*
 * EN: Stateless hardware scanner abstraction layer leveraging OpenBSD sysctl.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include <sys/types.h>
#include <sys/sysctl.h>

/**
 * @file scan.cppm
 * @brief Hardware scanning and topology discovery module.
 * @details Abstracts low-level OpenBSD kernel sysctl calls into clean, 
 * safe C++20 module interfaces for upper-layer telemetry consumption.
 */

export module neurabsd.hw.scan;

export namespace neurabsd::hw {

/**
 * @class Scanner
 * @brief Stateless utility class to fetch core machine topology.
 */
class Scanner {
public:
	Scanner() = delete; /* Enforce static stateless utility pattern */

	/**
	 * @brief Retrieves the exact number of active CPU cores from the kernel.
	 * @return int Number of detected logical processors, or -1 on error.
	 */
	static int
	get_cpu_count() noexcept
	{
		int mib[2];
		int ncpu;
		size_t len;

		mib[0] = CTL_HW;
		mib[1] = HW_NCPUONLY; /* Fetch actual physical/logical active cores */
		len = sizeof(ncpu);

		if (sysctl(mib, 2, &ncpu, &len, nullptr, 0) == -1) {
			return -1;
		}

		return ncpu;
	}

	/**
	 * @brief Retrieves the total system memory capacity (RAM).
	 * @return uint64_t Total physical memory in bytes, or 0 on error.
	 */
	static uint64_t
	get_total_memory() noexcept
	{
		int mib[2];
		uint64_t physmem;
		size_t len;

		mib[0] = CTL_HW;
		mib[1] = HW_PHYSMEM64; /* 64-bit safe physical memory query */
		len = sizeof(physmem);

		if (sysctl(mib, 2, &physmem, &len, nullptr, 0) == -1) {
			return 0;
		}

		return physmem;
	}

	/**
	 * @brief Fetches the official hardware architecture string.
	 * @param buffer Pointer to a character array where the architecture name will be written.
	 * @param buffer_size The maximum size of the destination buffer.
	 * @return true if successful, false otherwise.
	 */
	static bool
	get_architecture(char *buffer, size_t buffer_size) noexcept
	{
		int mib[2];

		if (buffer == nullptr || buffer_size == 0) {
			return false;
		}

		mib[0] = CTL_HW;
		mib[1] = HW_MACHINE; /* e.g., "amd64", "arm64" */

		if (sysctl(mib, 2, buffer, &buffer_size, nullptr, 0) == -1) {
			return false;
		}

		return true;
	}
};

} // namespace neurabsd::hw