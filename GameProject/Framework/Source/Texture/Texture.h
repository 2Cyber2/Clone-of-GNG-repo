#pragma once

#include "Core/CoreHeaders.h"

namespace fw
{
    class Texture 
    {
    public:
        Texture();
        Texture(const char* filename);
        ~Texture();
        GLuint GetTextureID();
    private:
        GLuint m_TextureID;
    protected:
    };
}