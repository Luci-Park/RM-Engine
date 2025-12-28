/**
 * @file Buffer.h
 * @author sumin.park
 * @brief  Data to communicate to GPU
 * @version 0.1
 * @date 12/27/2025 10:13:19 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once

#include "RenderCommon.h"

namespace rm
{
    class Buffer
    {
    public:
        virtual ~Buffer() = default;
    };

} // rm namespace