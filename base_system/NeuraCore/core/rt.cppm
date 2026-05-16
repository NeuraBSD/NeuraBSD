/* $NeuraBSD: base_system/NeuraCore/core/rt.cppm, v 1.0 2026/05/16 codeakrobat Exp $ */
/*
 * EN: Core minimal C++ runtime support for the NeuraBSD interface layer.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include <sys/types.h>
#include <sys/malloc.h>

/**
 * @file rt.cppm
 * @brief NeuraBSD Kernel C++ Runtime Support.
 * @details Implements necessary low-level runtime components required for 
 * C++20 execution within the NeuraCore abstraction layer, providing global 
 * allocation primitives mapped safely onto OpenBSD core subsystems.
 */

export module neurabsd.core.rt;

/*
 * Standard global new and delete operators mapped directly onto 
 * the highly secure OpenBSD kernel malloc(9) subsystem.
 */

void *
operator new(size_t size) noexcept
{
	return malloc(size, M_DEVBUF, M_NOWAIT | M_ZERO);
}

void *
operator new[](size_t size) noexcept
{
	return malloc(size, M_DEVBUF, M_NOWAIT | M_ZERO);
}

void
operator delete(void *ptr) noexcept
{
	if (ptr != nullptr) {
		free(ptr, M_DEVBUF, 0);
	}
}

void
operator delete[](void *ptr) noexcept
{
	if (ptr != nullptr) {
		free(ptr, M_DEVBUF, 0);
	}
}

void
operator delete(void *ptr, size_t size) noexcept
{
	if (ptr != nullptr) {
		free(ptr, M_DEVBUF, size);
	}
}

void
operator delete[](void *ptr, size_t size) noexcept
{
	if (ptr != nullptr) {
		free(ptr, M_DEVBUF, size);
	}
}

export namespace neurabsd::core::rt {

/**
 * @brief Halts the execution context safely on unrecoverable C++ state.
 * @param msg English literal description of the failure reason.
 */
void
panic(const char *msg) noexcept
{
	/* Forward directly to OpenBSD native kernel panic sequence */
	extern void panic(const char *, ...);
	::panic("NeuraBSD Core Runtime Exception: %s", msg);
}

} // namespace neurabsd::core::rt

/* ABI required symbol stubs for pure virtual compliance */
extern "C" void
__cxa_pure_virtual()
{
	neurabsd::core::rt::panic("pure virtual function call context violation");
}