#include "SpriteSheet/SpriteSheet.h"
#include "Libraries/json.hpp"


using json = nlohmann::json;

namespace fw {
    SpriteSheet::SpriteSheet(const char* filename)
    {
        std::ifstream file(filename);
        json data = json::parse(file);

        // Load spritesheet size

        fw::vec2 sheetSize = { data["size"][0], data["size"][1] };


        // Loop over sprites
        for (const json& sprite : data["sprites"])
        {
            std::string spriteName = sprite["name"];
            fw::vec2 spritePos = { sprite["pos"][0], sprite["pos"][1] };
            fw::vec2 spriteSize = { sprite["size"][0], sprite["size"][1] };

            fw::vec2 uvScale = spriteSize / sheetSize;
            fw::vec2 uvOffset = spritePos / sheetSize;

            m_SpriteTransforms[spriteName] = { uvScale, uvOffset };
        }
    }

    uvTransform SpriteSheet::GetUVTransform(const std::string& spriteName) const
    {
        auto it = m_SpriteTransforms.find(spriteName);
        if (it != m_SpriteTransforms.end())
        {
            return it->second;
        }
        
        // Entire spritesheet
        return uvTransform{ vec2(1.0f, 1.0f), vec2(0.0f, 0.0f) };
    }
}