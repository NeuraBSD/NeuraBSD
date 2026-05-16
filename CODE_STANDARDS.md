# NeuraBSD Development & Code Standards

All contributions to the NeuraBSD repository must strictly adhere to these architectural and stylistic rules. Code that violates these terms will be automatically rejected by the CI pipeline.

## 1. Technical Framework
* **Standard**: Explicitly C++20 or higher.
* **Modularity**: Strict usage of C++20 native modules (`export module`, `import`). Traditional header chaining (`.hpp`/`.cpp` inclusion) is prohibited in the core subsystems unless required by external framework generation (e.g., Qt MOC).

## 2. Code Formatting (OpenBSD KNF / style(9))
We follow the OpenBSD Kernel Normal Form (KNF) with exact compliance:
* **Indentation**: Real hard-tabs only, configured to **8 characters**. Absolutely no spaces for block indentation.
* **Brace Style**: 
  * For function definitions, the opening brace MUST be placed on a new line.
  * For control structures (`if`, `while`, `for`, `switch`), the opening brace MUST be placed on the same line as the conditional statement.
* **Variables**: Local variables must be declared block-wise, sorted cleanly by type, and grouped at the very beginning of the function scope.

## 3. Architecture & Safety
* **Thread-Safety**: All module interfaces must guarantee absolute thread-safety.
* **Statelessness**: Subsystems should prefer stateless logic patterns where architecturally feasible.
* **Documentation**: Full Doxygen compliance using explicit English markers (`@file`, `@brief`, `@param`, `@return`).