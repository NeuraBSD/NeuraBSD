/* $NeuraBSD: base_system/NeuraCore/core/mutex.cppm, v 1.0 2026/05/16 codeakrobat Exp $ */
/*
 * EN: Thread-safe RAII Mutex wrapper implementing OpenBSD mtx primitives.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

#include <sys/param.h>
#include <sys/mutex.h>

/**
 * @file mutex.cppm
 * @brief Core synchronization module for NeuraCore.
 * @details Provides C++20 module interfaces for traditional OpenBSD kernel mutexes,
 * enforcing strict RAII compliance, compile-time move/copy restrictions, and
 * full thread-safety patterns.
 */

export module neurabsd.core.mutex;

export namespace neurabsd::core {

/**
 * @class Mutex
 * @brief RAII wrapper for the native OpenBSD kernel mtx structure.
 */
class Mutex {
public:
	/**
	 * @brief Initializes a new kernel mutex primitive.
	 * @param ipl The Interrupt Priority Level (IPL) for the mutex.
	 */
	Mutex(int ipl) noexcept
	{
		mtx_init(&mtx, ipl, "nb_core_mutex", nullptr);
	}

	~Mutex() noexcept
	{
		/* OpenBSD mtx primitives do not require explicit destruction */
	}

	/* Strict prevention of copy and move operations to enforce thread safety */
	Mutex(const Mutex&) = delete;
	Mutex& operator=(const Mutex&) = delete;
	Mutex(Mutex&&) = delete;
	Mutex& operator=(Mutex&&) = delete;

	/**
	 * @brief Locks the mutex. Blocks the current thread if already acquired.
	 */
	void
	lock() noexcept
	{
		mtx_enter(&mtx);
	}

	/**
	 * @brief Unlocks the mutex and wakes up waiting threads.
	 */
	void
	unlock() noexcept
	{
		mtx_leave(&mtx);
	}

	/**
	 * @brief Tries to acquire the lock without blocking the execution path.
	 * @return true if the lock was successfully acquired, false otherwise.
	 */
	bool
	try_lock() noexcept
	{
		return (mtx_enter_try(&mtx) != 0);
	}

private:
	struct mutex mtx;
};

/**
 * @class LockGuard
 * @brief Scoped RAII lock guard to automate acquisition and release cycles.
 * @tparam T The mutex type complying with basic lock/unlock signatures.
 */
template <typename T>
class LockGuard {
public:
	/**
	 * @brief Locks the provided mutex reference for the entire object lifespan.
	 * @param mtx_ref Reference to the active Mutex instance.
	 */
	explicit LockGuard(T& mtx_ref) noexcept : mutex_(mtx_ref)
	{
		mutex_.lock();
	}

	/**
	 * @brief Automatically releases the locked mutex upon leaving the scope.
	 */
	~LockGuard() noexcept
	{
		mutex_.unlock();
	}

	LockGuard(const LockGuard&) = delete;
	LockGuard& operator=(const LockGuard&) = delete;

private:
	T& mutex_;
};

} // namespace neurabsd::core