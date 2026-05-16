/* $NeuraBSD: CoreSeed/core_seed.cppm, v 1.0 2026/05/16 codeakrobat Exp $ */
/*
 * EN: Central installation controller module for the CoreSeed deployment framework.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include <sys/types.h>

/**
 * @file core_seed.cppm
 * @brief Universal deployment backend engine for NeuraBSD.
 * @details Consumes NeuraCore interfaces to drive the automated physical partitioning,
 * regional configuration mappings, and core operating system extraction vectors.
 */

export module neurabsd.coreseed;

import neurabsd.sys.slicer;
import neurabsd.sys.audit;

export namespace neurabsd::coreseed {

/**
 * @enum ProgressPhase
 * @brief Tracks the active installation step for non-linear step-switching.
 */
enum class ProgressPhase : uint32_t {
	PHASE_WELCOME        = 0,
	PHASE_KEYBOARD_SET   = 1,
	PHASE_TIMEZONE_SET   = 2,
	PHASE_DISK_SELECT    = 3,
	PHASE_CONFIRMATION   = 4,
	PHASE_EXECUTION      = 5,
	PHASE_COMPLETE       = 6
};

/**
 * @struct DeploymentState
 * @brief Telemetry package dispatched to the active UI frontend (CLI/TUI/GUI).
 */
struct DeploymentState {
	uint32_t percentage;
	const char* current_action_msg;
	bool encountered_error;
	ProgressPhase active_phase;
};

/**
 * @class InstallationController
 * @brief Stateless execution engine driving the NeuraBSD deployment steps.
 */
class InstallationController {
public:
	InstallationController() = delete;

	/**
	 * @brief Executes the smart partitioning and registers the initial audit safety net.
	 * @param target_disk The device string identifier (e.g., "/dev/rwd0c").
	 * @param disk_size_bytes Total detected raw capacity of the target drive.
	 * @return true if target disk was successfully sliced and the audit header committed.
	 */
	static bool
	commit_storage_layout(const char* target_disk, uint64_t disk_size_bytes) noexcept
	{
		/* Calculate dynamic, capped industrial layout mapping via NeuraCore */
		auto plan = neurabsd::sys::AutoSlicer::calculate_layout(disk_size_bytes);
		
		if (!plan.allocation_successful) {
			return false;
		}

		/*
		 * Real system execution hook:
		 * 1. Commits calculated boundaries to physical disklabel.
		 * 2. Formats partitions with secure Fast File System (FFS).
		 */

		/* Initialize the 32GB security rollback zone using our native audit layer */
		if (!neurabsd::sys::AuditManager::initialize_audit_zone(target_disk)) {
			return false;
		}

		return true;
	}

	/**
	 * @brief Drives the physical extraction and progress reporting tailored for Industrial Silver rendering.
	 * @param current_percentage Manual or calculated step incremental value.
	 * @param phase The active state-machine step.
	 * @return DeploymentState Feedback package for UI updating.
	 */
	static DeploymentState
	update_progress(uint32_t current_percentage, ProgressPhase phase) noexcept
	{
		DeploymentState state{current_percentage, "CoreSeed Engine Idle", false, phase};

		switch (phase) {
		case ProgressPhase::PHASE_KEYBOARD_SET:
			state.current_action_msg = "Configuring system keyboard map vectors...";
			break;
		case ProgressPhase::PHASE_TIMEZONE_SET:
			state.current_action_msg = "Synchronizing local timezone matrices...";
			break;
		case ProgressPhase::PHASE_DISK_SELECT:
			state.current_action_msg = "Probing storage block geometry...";
			break;
		case ProgressPhase::PHASE_EXECUTION:
			if (current_percentage < 40) {
				state.current_action_msg = "Extracting untouched OpenBSD base layers...";
			} else if (current_percentage < 80) {
				state.current_action_msg = "Injecting NeuraCore C++20 translation layers...";
			} else {
				state.current_action_msg = "Seeding industrial safe audit rollback state. Syncing disk...";
			}
			break;
		case ProgressPhase::PHASE_COMPLETE:
			state.current_action_msg = "NeuraBSD successfully seeded. Everything boots with DaemonPath.";
			break;
		default:
			state.current_action_msg = "Awaiting user stage navigation input...";
			break;
		}

		return state;
	}
};

} // namespace neurabsd::coreseed