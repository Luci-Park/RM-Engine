/**
 * @file RHIPipeline.h
 * @author sumin.park
 * @brief  Rendering pipeline interface
 * @version 0.1
 * @date 12/23/2025 11:40:57 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "RHICommon.h"

namespace rm
{
    class RHIPipeline
    {
    public:
        virtual ~RHIPipeline() = default;

        virtual PrimitiveTopology GetTopology() const = 0;
    };


} // rm namespace