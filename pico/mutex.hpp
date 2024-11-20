#pragma once

#include <mutex>

// 锁
typedef std::mutex Mutex;

// 递归锁
typedef std::recursive_mutex RecursiveMutex;

#include <shared_mutex>

// 共享锁
typedef std::shared_mutex SharedMutex;

// 读锁
typedef std::shared_lock<SharedMutex> RDLock;

// 写锁
typedef std::unique_lock<SharedMutex> WRLock;



