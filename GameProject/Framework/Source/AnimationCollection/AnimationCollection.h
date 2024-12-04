#pragma once

#include "Core/CoreHeaders.h"

namespace fw {
    class Animation;
    class AnimationCollection
    {
    public:
        void AddAnimation(const std::string& name, Animation* animation);
        Animation* GetAnimation(const std::string& name); //Returns an existing animation from the map, if it doesn't exist it returns nullptr
    private:
        std::map<std::string, Animation*> m_mapAnimations;
    };
}