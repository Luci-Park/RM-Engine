/**
 * @file Material.h
 * @author dream
 * @brief // TODO: Add a brief description of this header
 * @version 0.1
 * @date 1/8/2026 12:51:50 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include <glad/glad.h>

#include "Engine/Math/Vec4.h"

namespace rm {

    struct Material {
        GLuint program = 0;
        GLuint texture0 = 0;  // one texture for now
        math::Vec4 tint{1, 1, 1, 1};
    };

} // rm namespace