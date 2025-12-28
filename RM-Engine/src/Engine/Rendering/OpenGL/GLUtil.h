/**
 * @file GLUtil.h
 * @author sumin.park
 * @brief  GL util functions
 * @version 0.1
 * @date 12/28/2025 12:43:31 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include <string_view>

namespace rm
{
    uint32_t CompileShader(uint32_t stage, std::string_view src);
    uint32_t LinkProgram(uint32_t vs, uint32_t fs);
} // rm namespace