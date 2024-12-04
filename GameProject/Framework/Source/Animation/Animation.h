#pragma once

#include "Core/CoreHeaders.h"
#include "SpriteSheet/SpriteSheet.h"


class SpriteSheet;
struct uvTransform;
namespace fw {
    class Animation
    {
    public:
        Animation(fw::SpriteSheet* spriteSheet, const std::vector<std::string>& frameNames, float frameTime, bool l);
        ~Animation();

        //Getters
        fw::uvTransform GetFrameUV(int frameIndex) const;

        int GetTotalFrames() const { return m_FrameNames.size(); }
        float GetFrameTime() const { return m_FrameTime; }
        bool DoesLoop() const { return m_Loop; }

    private:
        fw::SpriteSheet* m_SpriteSheet;
        std::vector<std::string> m_FrameNames;
        float m_FrameTime;
        bool m_Loop;
        
    };
}