/**
 * @file Assert.h
 * @author sumin.park
 * @brief The RM_ASSERT macro definition file.
 * @version 0.1
 * @date 12/16/2025 8:54:04 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "Log.h"

#ifndef NDEBUG
#define RM_ASSERT(expr, fmt, ...) \
        do { \
            if(!(expr)) { \
                ::rm::Log::FailFast(#expr, ::rm::Format((fmt) __VA_OPT__(,) __VA_ARGS__), std::source_location::current()); \
                RM_DEBUGBREAK(); \
            } \
        } while(0)
#else
#define RM_ASSERT(...) ((void)0)
#endif

// Optional: always-on verify (shipping assert)
#define RM_VERIFY(expr, fmt, ...) \
    do { \
        if(!(expr)) { \
            ::rm::Log::FailFast(#expr, ::rm::Format((fmt) __VA_OPT__(,) __VA_ARGS__), std::source_location::current()); \
        } \
    } while(0)