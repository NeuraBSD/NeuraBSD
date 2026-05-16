/* $NeuraBSD: CoreSeed/ui_config.cppm, v 1.0 2026/05/16 codeakrobat Exp $ */
/*
 * EN: Frontend state buffer allowing non-linear configuration switching before commit.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include <sys/types.h>

/**
 * @file ui_config.cppm
 * @brief Volatile installation configuration registry.
 * @details Buffers layout parameters, regional matrices, and targets inside transient
 * memory, enabling back-and-forth UI step switching before physical disk alteration.
 */

export module neurabsd.coreseed.config;

export namespace neurabsd::coreseed {

/**
 * @enum InstallationTargetMode
 * @brief Identifies which branch the user selected at the boot environment.
 */
enum class InstallationTargetMode : uint32_t {
	MODE_LIVE_CD   = 0x01, /* FreeSBIE pattern: Run entirely from volatile memory */
	MODE_GUI       = 0x02, /* Guided graphical multi-step engine */
	MODE_TUI       = 0x03, /* Industrial-look pseudo window framework */
	MODE_CLI       = 0x04  /* Expert traditional command-line stream */
};

/**
 * @struct UserDeploymentManifest
 * @brief Volatile buffer holding chosen parameters in Industrial Silver specification.
 */
struct UserDeploymentManifest {
	InstallationTargetMode selected_mode;
	char keyboard_layout[8];    /* e.g., "de", "us" */
	char timezone[64];           /* e.g., "Europe/Berlin" */
	char target_disk_path[32];   /* e.g., "/dev/rwd0c" */
	bool user_confirmed_wipe;    /* Safety gate variable */
};

/**
 * @class ConfigRegistry
 * @brief Stateful data capsule holding the user's choices during UI iteration.
 */
class ConfigRegistry {
public:
	ConfigRegistry() noexcept = default;

	/**
	 * @brief Resets the structural layout configuration to safe defaults.
	 */
	void
	set_defaults() noexcept
	{
		manifest_.selected_mode = InstallationTargetMode::MODE_LIVE_CD;
		manifest_.user_confirmed_wipe = false;
		
		/* Direct industrial string safe clamping */
		manifest_.keyboard_layout[0] = 'u';
		manifest_.keyboard_layout[1] = 's';
		manifest_.keyboard_layout[2] = '\0';

		manifest_.timezone[0] = 'U';
		manifest_.timezone[1] = 'T';
		manifest_.timezone[2] = 'C';
		manifest_.timezone[3] = '\0';

		manifest_.target_disk_path[0] = '\0';
	}

	/* Accessor methodologies for the active UI frontends */
	UserDeploymentManifest& get_manifest() noexcept { return manifest_; }

private:
	UserDeploymentManifest manifest_{};
};

} // namespace neurabsd::coreseed