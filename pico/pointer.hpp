#pragma once

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

