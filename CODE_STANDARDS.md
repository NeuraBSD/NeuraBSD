# NeuraBSD 🌀 | Code Standards & Guidelines

This document outlines the coding standards for the NeuraBSD project. To ensure seamless compatibility and maintainability with our upstream base, we strictly follow the **OpenBSD Style Guidelines**.

---

## 1. The Golden Rule: OpenBSD style(9)
For all C code (Kernel, Base-System, and System Tools), NeuraBSD adopts the official **OpenBSD KNF (Kernel Normal Form)**.

* **Reference:** [OpenBSD style(9) manual page](https://man.openbsd.org/style.9)
* **Indentation:** Hard tabs (8 characters wide).
* **Braces:** Following the KNF convention (as defined in `style(9)`).
* **Naming:** Use `snake_case` for all C-level functions and variables.

## 2. Language-Specific Rules

### C & Assembly (base-system, DaemonPath)
* **Standard:** C99 / K&R style as per OpenBSD standards.
* **Security:** Use secure functions (`strlcpy`, `strlcat`, `snprintf`) instead of unsafe alternatives. Use `pledge(2)` and `unveil(2)` where possible to enhance security.
* **Commits:** Follow the OpenBSD habit of concise, meaningful commit messages.

### C++ & Qt6 (CoreSeed, AxonSurface, Neura-Apps)
While the base system is pure C, our UI layer uses modern C++.
* **Standard:** C++17 or higher.
* **Naming:** * Classes: `CamelCase`
    * Methods: `camelCase`
    * Member variables: `m_camelCase`
* **UI Integration:** Adhere to the **Neura-Blue (#0055ff)** and **Purple Glow (#bc13fe)** color palette defined in the branding assets.

### Shell Scripts (neura-tools)
* **Interpreter:** `/bin/sh` (POSIX) or `/bin/ksh`. 
* **Guidelines:** Follow the scripting style found in OpenBSD's `/etc/rc` scripts.

---

## 3. Visual & UI Consistency
All graphical components must reflect the NeuraBSD identity:
* **Font:** Monospace / Fixed-width for all technical readouts.
* **Colors:** High contrast dark backgrounds (`#0a0a0a`) with blue accents.
* **Logic:** Every UI element should be lightweight and non-blocking (asynchronous).

## 4. Documentation
* **Header:** Every file must start with the BSD 3-Clause license header.
* **Manpages:** New system tools should ideally come with a corresponding `mdoc(7)` formatted manual page.

---
*"Clean code is the foundation of a secure system. We stand on the shoulders of giants by following the OpenBSD style."*