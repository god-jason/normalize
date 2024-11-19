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

#include <string>
typedef std::string string;

#define var auto
