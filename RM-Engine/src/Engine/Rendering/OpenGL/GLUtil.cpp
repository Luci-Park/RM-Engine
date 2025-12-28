/**
 * @file GLUtil.cpp
 * @author sumin.park
 * @brief  GL util functions
 * @version 0.1
 * @date 12/28/2025 12:43:31 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "GLUtil.h"
#include <glad/glad.h>

namespace rm
{
    uint32_t CompileShader(uint32_t stage, std::string_view src)
    {
        GLuint s = glCreateShader(stage);
        const char* c = src.data();
        GLint len = (GLint)src.size();
        glShaderSource(s, 1, &c, &len);
        glCompileShader(s);

        GLint ok = 0;
        glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
        if (!ok)
        {
            char log[2048];
            glGetShaderInfoLog(s, (GLsizei)sizeof(log), nullptr, log);
            LOG_CRITICAL("[GL] Shader compile failed:\n%s\n", log);
        }
        return (uint32_t)s;
    }

    uint32_t LinkProgram(uint32_t vs, uint32_t fs)
    {
        GLuint p = glCreateProgram();
        glAttachShader(p, vs);
        glAttachShader(p, fs);
        glLinkProgram(p);

        GLint ok = 0;
        glGetProgramiv(p, GL_LINK_STATUS, &ok);
        if (!ok)
        {
            char log[2048];
            glGetProgramInfoLog(p, (GLsizei)sizeof(log), nullptr, log);
            LOG_CRITICAL("[GL] Program link failed:\n%s\n", log);
        }

        glDetachShader(p, vs);
        glDetachShader(p, fs);
        glDeleteShader(vs);
        glDeleteShader(fs);

        return (uint32_t)p;
    }
} // rm namespace