# $NeuraBSD: CODE_STANDARDS.md, v 1.1 2026/02/07 codeakrobat Exp $

# NeuraBSD | Code Standards & Guidelines

This document defines the coding standards for the NeuraBSD project. To ensure seamless compatibility with our upstream base while maintaining a distinct identity, we combine **OpenBSD KNF** with the **NeuraBSD Hybrid Style**.

---

## 1. The Golden Rule: OpenBSD style(9)
For all C code (Kernel, Base System, and core utilities like **DaemonPath**), NeuraBSD strictly adopts the official **OpenBSD KNF (Kernel Normal Form)**.

* **Reference:** [OpenBSD style(9) manual page](https://man.openbsd.org/style.9)
* **Indentation:** Hard Tabs (8 characters wide).
* **Braces:** KNF convention (Braces on the same line for `if`, `for`, `while`).
* **Naming:** `snake_case` for all C functions and variables.

## 2. NeuraBSD Python Style (Hybrid)
To maintain visual consistency within the **MASTER-REPO**, Python scripts (e.g., `neura-tools`) follow a modified PEP 8 standard.

* **Indentation:** **Hard Tabs** (8 characters wide) – Mandatory to match C-level visual rhythm.
* **Naming:** * Variables & Functions: `snake_case`.
    * Classes: `PascalCase`.
* **Line Length:** Maximum 80 characters.
* **Documentation:** Concise docstrings in `mdoc(7)` style.

## 3. C++ & Qt6 (CoreSeed, AxonSurface)
The graphical layer focuses on performance and the unique NeuraBSD aesthetic.

* **Standard:** C++17 or higher.
* **Naming:** * Classes: `PascalCase`.
    * Methods: `camelCase`.
    * Member Variables: `m_camelCase`.
* **UI Integration:** Statically enforced CSS root sequence for **AxonSurface**:
    * `--bg-black: #0a0a0a;`
    * `--surface-black: #121212;`
    * `--beastie-purple: #bc13fe;` (Signature Neura-Purple).
    * `--neura-blue: #0055ff;`

## 4. Security & Architecture
* **Sandboxing:** Usage of `pledge(2)` and `unveil(2)` is mandatory for all new NeuraBSD utilities.
* **Boot Sequence:** The lifecycle begins with the **CoreSeed** graphical installer, followed by the **DaemonPath** boot manager, and terminates in the **AxonSurface** DE.
* **Memory Safety:** Always prefer `strlcpy`, `strlcat`, and `snprintf` over unsafe alternatives.

## 5. Documentation & Headers
* **File Header:** Every source file must start with the NeuraBSD version string and the BSD 3-Clause license:
    `$NeuraBSD: path/to/file, v 1.x Year/Month/Day Author Exp $`
* **Bilingualism:** Source code comments must be provided in both **German** and **English**.
* **Manual Pages:** All system-level tools must be accompanied by an `mdoc(7)` formatted manpage.

---

*"Unified code is the foundation of system stability. From the first line of CoreSeed to the final boot with DaemonPath: One rhythm, one system."*

**Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat) <lead@neurabsd.org>**
**License: BSD 3-Clause**
