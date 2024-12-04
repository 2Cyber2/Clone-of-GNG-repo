#include "AnimationCollection/AnimationCollection.h"
#include "Animation/Animation.h"
#include "AnimationPlayer.h"
#include "SpriteSheet/SpriteSheet.h"


namespace fw {
    fw::AnimationPlayer::AnimationPlayer() :
        m_CurrentAnimation(nullptr),
        m_CurrentFrame(0),
        m_TimeInCurrentFrame(0.0f)
    {
    }
    AnimationPlayer::~AnimationPlayer()
    {
    }
    void AnimationPlayer::Play(Animation* animation)
    {
        if ((m_CurrentAnimation != animation) || (m_CurrentAnimation == nullptr))
        {
            m_CurrentAnimation = animation;
            m_CurrentFrame = 0;
            m_TimeInCurrentFrame = 0.0f;


            assert(m_CurrentAnimation != nullptr && "Current animation is still nullptr");
        }
    }
    void AnimationPlayer::Update(float deltaTime)
    {
        //Get out of the update if there isn't any current animation
        if (m_CurrentAnimation == nullptr)
            return;

        //Add delta time to the time spent in the frame
        m_TimeInCurrentFrame += deltaTime;

        //Check if the frame is greater or equal to the frame duration
        if (m_TimeInCurrentFrame >= m_CurrentAnimation->GetFrameTime())
        {
            //Subtract the frame duration frime the time in the current frame
            m_TimeInCurrentFrame -= m_CurrentAnimation->GetFrameTime();
            m_CurrentFrame++; // go to the next frame


            //Check if it loops then loop it, otherwise set it to the last frame in the animation
            if (m_CurrentFrame >= m_CurrentAnimation->GetTotalFrames())
            {
                m_CurrentFrame = m_CurrentAnimation->DoesLoop() ? 0 : (int)m_CurrentAnimation->GetTotalFrames() - 1;
            }
        }
    }
    uvTransform AnimationPlayer::GetCurrentFrameUV() const
    {
        if (m_CurrentAnimation == nullptr) return { vec2(1.0f, 1.0f), vec2(0.0f, 0.0f) };
        return m_CurrentAnimation->GetFrameUV(m_CurrentFrame);
    }
    int AnimationPlayer::GetCurrentFrame() const
    {
        return m_CurrentFrame;
    }
}
