# NeuraBSD 🌀

NeuraBSD is an independent, security-focused operating system based on **OpenBSD 7.8**. It aims to provide a modern, elegant, and unified desktop experience through its custom environment and specialized tools.

## 🌌 Project Vision
Everything in NeuraBSD starts with a seamless graphical installation via **CoreSeed**, followed by a reliable boot process managed by **DaemonPath**, leading into the high-performance **AxonSurface** Desktop Environment.

## 🏗️ Repository Structure

This repository is organized into four main pillars:

### 1. [CoreSeed](./CoreSeed/)
The graphical installer. Designed for simplicity and reliability. It handles disk partitioning, base system installation, and initial user configuration.

### 2. [DaemonPath](./DaemonPath/)
The custom NeuraBSD boot manager. Focused on a clean handover from the hardware to the OpenBSD kernel with a modern interface.

### 3. [AxonSurface](./AxonSurface/)
The native Desktop Environment (DE). Built with performance and aesthetics in mind.
- **Identity:** Defined by "Neura-Blue" (#0055ff).
- **Core:** Custom Window Manager (WM) and Panel system.

### 4. [Neura-Tools](./neura-tools/)
A suite of essential tools and services:
- **Tray Services:** Network, Battery, and Volume management.
- **User Apps:** Lightweight native applications (Calculator, Editor, etc.).
- **Branding:** Central repository for icons, wallpapers, and CSS variables.

---

## 🛠️ Development Status
The project is currently in the **Architectural Phase**. The directory structure is finalized, and core logic implementation is beginning.

**Target Platform:** OpenBSD 7.8 (AMD64)
**Primary Focus:** Independent GPU driver support (NVIDIA) and a cohesive "Blue" design language.

---
*Everything starts with CoreSeed. Everything runs with AxonSurface.*