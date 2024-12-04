#pragma once

#include "Core/CoreHeaders.h"

namespace fw {

    struct uvTransform
    {
        vec2 uvScale;
        vec2 uvOffset;
    };

    class SpriteSheet
    {
    public:
        SpriteSheet(const char* filename);

        uvTransform GetUVTransform(const std::string& spriteName) const;
    private:
        std::map<std::string, uvTransform> m_SpriteTransforms;


    };
}