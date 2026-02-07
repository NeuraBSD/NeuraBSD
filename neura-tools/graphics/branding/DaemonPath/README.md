# DaemonPath Branding Assets

This directory contains all visual identity components specifically tailored for the **DaemonPath Boot Manager**. 

## Design Specifications
Due to the early system initialization phase, these assets follow stricter constraints than the AxonSurface DE to ensure compatibility with various framebuffers:

* **Mandatory Background Color:** `#0a0d10` (Deep Blue-Black)
* **Accent Colors:** * Neura-Blue: `#00d4ff`
    * Neura-Purple: `#9d50bb`
* **Target Resolution:** 800x600 Pixels (VGA/VESA Standard)
* **Format:** PNG-24 (Flattened, no Alpha channel recommended for legacy BIOS/UEFI compatibility)

## Component Overview
1.  `boot_splash_800x600.png`: The primary splash screen featuring the NeuraBSD Trident logo and the "Powered by DaemonPath" footer.
2.  `loading_bar_assets.png`: Individual segments and masks for the animated progress bar.
3.  `dp_logo_mini.png`: A compact version of the DaemonPath logo for status indicators.

## Implementation Notes
These assets are referenced during the build process of `src/boot/daemonpath/`. To avoid dependencies on filesystem drivers during the early boot stage, it is recommended to convert these images into C header files (.h) or binary blobs embedded directly into the bootloader executable.

---
*Part of the NeuraBSD Master-Repo*
*Maintained by: Daniel Hilbert & CodeAkrobat*