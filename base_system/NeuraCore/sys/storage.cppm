/* $NeuraBSD: base_system/NeuraCore/sys/storage.cppm, v 1.0 2026/05/16 codeakrobat Exp $ */
/*
 * EN: Native C++20 module interface for OpenBSD disk and partition geometry topology.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/dkio.h>
#include <sys/disklabel.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * @file storage.cppm
 * @brief Storage geometry and drive topology discovery.
 * @details Leverages native OpenBSD ioctl descriptors to safely fetch disk capacity
 * and layout telemetry, encapsulating low-level file descriptors into stateless interfaces.
 */

export module neurabsd.sys.storage;

export namespace neurabsd::sys {

/**
 * @struct DiskGeometry
 * @brief High-level storage metrics container in Industrial Silver typography standard.
 */
struct DiskGeometry {
	uint64_t sector_size;
	uint64_t total_sectors;
	uint64_t total_bytes;
};

/**
 * @class StorageManager
 * @brief Stateless interface to probe mass storage devices.
 */
class StorageManager {
public:
	StorageManager() = delete; /* Static utility block restriction */

	/**
	 * @brief Probes a raw disk device to extract its inner geometry parameters.
	 * @param dev_path Absolute string path to the raw block device (e.g., "/dev/rwd0c").
	 * @param out_geom Reference to the DiskGeometry structure where values will be populated.
	 * @return true if the system device was successfully opened and queried, false otherwise.
	 */
	static bool
	get_disk_geometry(const char *dev_path, DiskGeometry& out_geom) noexcept
	{
		struct disklabel lab;
		int fd;

		if (dev_path == nullptr) {
			return false;
		}

		/* Open raw device descriptor with read-only restriction */
		fd = open(dev_path, O_RDONLY);
		if (fd == -1) {
			return false;
		}

		/* Execute native OpenBSD disk subsystem ioctl call */
		if (ioctl(fd, DIOCGPDINFO, &lab) == -1) {
			close(fd);
			return false;
		}

		close(fd);

		/* Map raw struct data safely onto our modern architecture fields */
		out_geom.sector_size = lab.d_secsize;
		out_geom.total_sectors = lab.d_secperunit;
		out_geom.total_bytes = out_geom.sector_size * out_geom.total_sectors;

		return true;
	}
};

} // namespace neurabsd::sys