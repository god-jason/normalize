#pragma once

#define nil NULL

#include <memory>
#define Pointer std::shared_ptr
#define SharedPointer std::shared_ptr
#define UniquePointer std::unique_ptr
#define WeakPointer std::weak_ptr

#define Make std::make_shared
#define MakeShared std::make_shared
#define MakeUnique std::make_unique
#define MakeWeak std::make_weak

