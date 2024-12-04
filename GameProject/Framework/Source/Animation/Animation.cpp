#include "Animation/Animation.h"
#include "SpriteSheet/SpriteSheet.h"
namespace fw
{

    fw::Animation::Animation(fw::SpriteSheet* spriteSheet, const std::vector<std::string>& frameNames, float frameTime, bool l) :
        m_SpriteSheet(spriteSheet),
        m_FrameNames(frameNames),
        m_FrameTime(frameTime),
        m_Loop(l)
    {
    }

    fw::Animation::~Animation()
    {
    }

    uvTransform fw::Animation::GetFrameUV(int frameIndex) const
    {
        if (frameIndex < 0 || frameIndex >= m_FrameNames.size())
        {
            //Return default UV if entry is invalid
            return uvTransform{ vec2(1.0f, 1.0f), vec2(0.0f, 0.0f) };
        }
        return m_SpriteSheet->GetUVTransform(m_FrameNames[frameIndex]);
    }
}
