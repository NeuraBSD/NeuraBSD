# NeuraBSD 🌀 | Architecture & Developer Status

This document defines the official repository structure and technical hierarchy of the **NeuraBSD** project. NeuraBSD is an independent, security-focused operating system based on **OpenBSD 7.8**, featuring a native desktop environment and specialized system tools.

## 🌌 The NeuraBSD Chain
Everything in this system follows a strict logical flow:
**CoreSeed** (Install) → **DaemonPath** (Boot) → **Base-System** (Kernel/Config) → **AxonSurface** (UI)

---

## 🏗️ Repository Structure

### 1. [CoreSeed](./CoreSeed/)
The graphical system installer. Designed for a seamless transition from live media to disk.
* `ui/` – Qt6 Designer interface files (.ui).
* `assets/` – Branding and icons specific to the installation process.
* `include/` – Header files for partitioning and deployment logic.
* `src/` – C++/Qt source code.
* `legacy/` – Fallback shell scripts and OpenBSD base-install compatibility layers.

### 2. [DaemonPath](./DaemonPath/)
The custom NeuraBSD boot manager. Handles the transition from firmware to kernel.
* `bios/` – Legacy BIOS bootloader stages (x86 Real Mode).
* `uefi/` – Modern UEFI Boot Services and EFI application source.
* `common/` – Shared boot logic, UI routines, and kernel handover protocols.
* `config/` – Configuration templates for boot menus and kernel flags.

### 3. [Base-System](./base-system/)
The core operating system foundation based on OpenBSD 7.8.
* `sys/` – Kernel source tree.
    * `dev/` – **Development Focus:** Independent GPU driver support (NVIDIA).
* `etc/` – Default system configuration templates and NeuraBSD-specific daemons.

### 4. [AxonSurface](./AxonSurface/)
The native high-performance Desktop Environment (DE).
* `vm/` – Custom Window Manager core logic and tiling engine.
* `panel/` – Status bar, system monitors, and application menu.
* `lib/` – Shared C++ libraries for DE components.
* `assets/` – System themes, icons, and wallpapers in **Neura-Blue (#0055ff)**.

### 5. [Neura-Tools](./neura-tools/)
A suite of essential utilities and background services.
* `graphics/` – Central branding assets (`branding/`, `icons/`, `wallpapers/`).
* `scripts/` – System management (`neura-info/`, `neura-update/`).
* `tray-services/` – Backend monitors for `battery/`, `volume/`, and `network/`.
* `neura-apps/` – Native applications (`n_calc/`, `n_edit/`, `n_info/`).

---

## 🛠️ Development Status Matrix

| Component | Status | Primary Technology |
| :--- | :--- | :--- |
| **CoreSeed** | Architectural Phase | C++ / Qt6 |
| **DaemonPath** | Architectural Phase | C / ASM |
| **Base-System** | Active Research | C / OpenBSD Kernel |
| **AxonSurface** | Architectural Phase | C++ / Axon-Engine |
| **Neura-Tools** | Active | C++ / Shell |

## 🎨 Branding Guidelines
The visual identity of NeuraBSD is strictly defined by **Neura-Blue (#0055ff)**. All UI components across CoreSeed, DaemonPath, and AxonSurface must adhere to the design specifications found in `neura-tools/graphics/branding/`.

---
*Copyright (c) 2026 NeuraBSD Project. Licensed under the BSD 3-Clause License.*