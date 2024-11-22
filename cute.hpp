#pragma once


// ======== 重定义基础类型 ========

typedef bool boolean;
typedef float float32;
typedef double float64;

#include <cstdint>
typedef std::uint8_t byte;
typedef std::int8_t int8;
typedef std::uint8_t uint8;
typedef std::int16_t int16;
typedef std::uint16_t uint16;
typedef std::int32_t int32;
typedef std::uint32_t uint32;
typedef std::int64_t int64;
typedef std::uint64_t uint64;
typedef unsigned int uint;

#include <string>
typedef std::string string;

#define var auto


#define nil NULL


#include <memory>
#define Pointer std::shared_ptr
#define SharedPointer std::shared_ptr
#define UniquePointer std::unique_ptr
#define WeakPointer std::weak_ptr

#define MakePointer std::make_shared
#define MakeSharedPointer std::make_shared
#define MakeUniquePointer std::make_unique
#define MakeWeakPointer std::make_weak


/* 标准容器 */

#include <map>
#define Map std::map

#include <set>
#define Set std::set

#include <vector>
#define Array std::vector

#include <list>
#define List std::list

#include <stack>
#define Stack std::stack

#include <queue>
#define Queue std::queue


#ifdef WIN32
#define export __declspec(dllexport) extern "C"
#else
#define export extern "C"
#endif


#include <functional>
#define Function std::function

#include <exception>
#define Exception std::exception


/* 锁 */

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

#include<atomic>
#define Atomic std::atomic

#include <thread>

typedef std::thread Thread;


// template<typename func>
// Thread Go(func, void*... arg)
// {
//     var t = std::thread(func, arg...);
//     t.detach(); //解绑
//     return t;
// }


#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>


//TODO 应该改成微秒值
typedef std::time_t Time;

inline Time Now()
{
    const auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(now);
}

//与Windows.h中重复
inline void Sleep(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}


inline string FormatTime(const Time& t, const std::string& fmt)
{
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&t), fmt.c_str());
    //oss.flush();
    return oss.str();
}

inline Time ParseTime(const std::string& str, const std::string& fmt)
{
    std::tm tm{};
    std::istringstream iss(str);
    iss >> std::get_time(&tm, fmt.c_str());
    return std::mktime(&tm);
}

#define LOCALE_TIME "%Y-%m-%d %H:%M:%S"

//using Seconds = std::chrono::duration<double>;
//using Milliseconds = std::chrono::duration<double, std::milli>;
//using Microseconds = std::chrono::duration<double, std::micro>;
