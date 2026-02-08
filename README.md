# 🌀 NeuraBSD | Architecture & Developer Status

This document defines the official repository structure and technical hierarchy of the **NeuraBSD** project. NeuraBSD is an independent, security-focused operating system based on **OpenBSD**, featuring a native desktop environment and specialized system tools.

## 🌌 The NeuraBSD Chain
Everything in this system follows a strict logical flow: 
**CoreSeed** (Install) → **DaemonPath** (Boot) → **Base-System** (Kernel/Config) → **AxonSurface** (UI)

---

## 🏗️ Repository Structure

### 1. CoreSeed
The modular graphical system installer. Designed for a seamless transition from live media to disk with three deployment modes:
* **Mode A (Standard):** The "Blue-Flow" – Full graphical Qt interface.
* **Mode B (Profi/Mirror):** Bound QProcess terminal for original OpenBSD `/install` power.
* **Mode C (Live/Utility):** System Dashboard for hardware diagnostics and live usage.

**Structure:**
* `src/ui/` – Main application framework and global styling (Qt6).
* `src/pages/` – Wizard-driven logic (Diagnostic, Partitioning, Terminal).
* `src/core/` – System interaction (HardwareScanner, SysExecutor).
* `documentation/` – Doxygen-generated technical docs (DE/EN).

### 2. DaemonPath
The custom NeuraBSD boot manager. Handles the transition from firmware to kernel.
* `bios/` – Legacy BIOS bootloader stages.
* `uefi/` – Modern UEFI Boot Services and EFI applications.
* `common/` – Shared boot logic and kernel handover.

### 3. Base-System
The core foundation based on OpenBSD.
* `sys/` – Kernel source tree (Focus: Independent GPU driver support).
* `etc/` – NeuraBSD-specific configuration and daemons.

### 4. AxonSurface
The native high-performance Desktop Environment (DE).
* `vm/` – Custom Window Manager core logic.
* `panel/` – Status bar and system monitors.
* `assets/` – System themes using **Neura-Blue (#0055ff)**.

---

## 🛠️ Development Status Matrix

| Component | Status | Primary Technology |
| :--- | :--- | :--- |
| **CoreSeed** | Architectural Phase | C++ / Qt6 |
| **DaemonPath** | Architectural Phase | C / ASM |
| **Base-System** | Active Research | C / OpenBSD Kernel |
| **AxonSurface** | Architectural Phase | C++ / Qt6 |
| **Neura-Tools** | Active | C++ / Shell |

---

## 🎨 Branding & Identity
* **Primary Color:** Neura-Blue (#0055ff)
* **Surface Tone:** Deep Black (#0a0a0a)
* **Accent:** Purple (Replacing Beastie Red)
* **Lead Developer:** Daniel Hilbert (**CodeAkrobat**)
* **Contact:** lead@neurabsd.org

Copyright (c) 2026 NeuraBSD Project. Licensed under the BSD 3-Clause License.
