# NeuraBSD

Modern Next-Generation Operating System based on the rock-solid foundation of OpenBSD, featuring a decoupled C++20 core architecture and native module subsystems.

## 🧠 Architectural Vision
NeuraBSD solves the upstream maintainability issue of custom operating system distributions by isolating the original OpenBSD source tree and leveraging a unified C++20 abstraction layer (**NeuraCore**). This architecture decouples the base system from our high-level components.

## 📁 Repository Structure
* **`base_system/`**: The untouched OpenBSD upstream core combined with our custom C++20 interface layer (`NeuraCore`).
* **`DaemonPath/`**: Secure, modular boot manager subsystem.
* **`CoreSeed/`**: Universal deployment and installation framework (supporting CLI, Windowed TUI, and Qt/QML graphical modes).
* **`AxonSurface/`**: High-performance, native C++20 desktop environment.
* **`documentation/`**: Central repository for technical specs, API references, and user guides.
* **`share/`**: Shared architecture-independent system assets and styling configurations.

## ⚖️ License
This project is dedicated to the open-source community and is licensed under the strict **BSD 3-Clause License**. See the `LICENSE` file for the full legal text.