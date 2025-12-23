/**
 * @file RHIBuffer.h
 * @author sumin.park
 * @brief  GPU buffers interface
 * @version 0.1
 * @date 12/23/2025 11:38:01 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "RHICommon.h"
namespace rm
{
    class RHIBuffer
    {
    public:
        virtual ~RHIBuffer() = default;

        virtual BufferUsage GetUsage() const = 0;
        virtual size_t GetSizeBytes() const = 0;
        virtual size_t GetStrideBytes() const = 0;
    };

} // rm namespace