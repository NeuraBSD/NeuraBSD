/* $NeuraBSD: base_system/NeuraCore/sys/slicer.cppm, v 1.0 2026/05/16 codeakrobat Exp $ */
/*
 * EN: Intelligent Industrial Slicer calculating non-proportional layouts with audit mapping.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include <sys/types.h>

/**
 * @file slicer.cppm
 * @brief Dynamic partitioning and slice allocation engine.
 * @details Calculates highly secure, capped partition boundaries based on 
 * available hardware metrics, ensuring fixed limits for volatile spaces and 
 * dedicated audit rollbacks.
 */

export module neurabsd.sys.slicer;

import neurabsd.hw.scan;

export namespace neurabsd::sys {

/**
 * @struct PartitionLayout
 * @brief Representation of the calculated layout tailored for the Industrial Look standard.
 */
struct PartitionLayout {
	uint64_t root_size_bytes;   /* Primary system layout */
	uint64_t swap_size_bytes;   /* Hard-capped volatile swap space */
	uint64_t audit_size_bytes;  /* Dedicated panic/crash log & rollback state snapshot */
	uint64_t user_size_bytes;   /* Remaining persistent capacity */
	bool allocation_successful;
};

/**
 * @class AutoSlicer
 * @brief Smart layout engine preventing oversized swap and enforcing safety zones.
 */
class AutoSlicer {
public:
	AutoSlicer() = delete;

	/**
	 * @brief Computes a deterministic partition schema based on drive size and system RAM.
	 * @param total_disk_bytes The total capacity of the target drive in bytes.
	 * @return PartitionLayout The calculated absolute block schema vectors.
	 */
	static PartitionLayout
	calculate_layout(uint64_t total_disk_bytes) noexcept
	{
		PartitionLayout layout{};
		uint64_t system_ram = neurabsd::hw::Scanner::get_total_memory();
		
		/* Fallback to 8GB if RAM detection failed via sysctl */
		if (system_ram == 0) {
			system_ram = 8ULL * 1024 * 1024 * 1024;
		}

		/* 1. Calculate Swap Space: Smart Capping Rule */
		/* Rule: 1.5x RAM, but strictly capped at a maximum of 16 Gigabytes */
		uint64_t target_swap = system_ram * 3 / 2;
		uint64_t max_swap_cap = 16ULL * 1024 * 1024 * 1024;
		
		if (target_swap > max_swap_cap) {
			layout.swap_size_bytes = max_swap_cap;
		} else {
			layout.swap_size_bytes = target_swap;
		}

		/* 2. Allocate Dedicated Fixed Audit Partition */
		/* Enforce a static 32 Gigabyte boundary for rollback snapshots and crash cores */
		layout.audit_size_bytes = 32ULL * 1024 * 1024 * 1024;

		/* 3. Base System Root Allocation (Fixed 50 GB for OS binaries and kernels) */
		layout.root_size_bytes = 50ULL * 1024 * 1024 * 1024;

		/* Minimum requirement check: Ensure the drive is large enough to host the core layout */
		uint64_t dynamic_overhead = layout.root_size_bytes + layout.swap_size_bytes + layout.audit_size_bytes;
		
		if (total_disk_bytes <= dynamic_overhead + (10ULL * 1024 * 1024 * 1024)) {
			/* Disk too small for secure industrial deployment profile */
			layout.allocation_successful = false;
			return layout;
		}

		/* 4. User Space gets the entire remaining dynamic storage slice */
		layout.user_size_bytes = total_disk_bytes - dynamic_overhead;
		layout.allocation_successful = true;

		return layout;
	}
};

} // namespace neurabsd::sys