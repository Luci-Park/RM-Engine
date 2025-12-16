/**
 * @file pch.h
 * @author rahul
 * @brief Includes frequently used includes in a desirable configuration for all projects.
 * @version 0.1
 * @date 12/16/2025 3:11:45 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once

 // Windows Header Files
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#define NOMINMAX				// Disable the Windows.h versions of min/max
#include <windows.h>

// C RunTime Header Files
#include <algorithm>
#include <cassert>
#include <malloc.h>
#include <memory.h>
#include <sal.h>
#include <cstdlib>
#include <string_view>
#include <tchar.h>
#include <vector>