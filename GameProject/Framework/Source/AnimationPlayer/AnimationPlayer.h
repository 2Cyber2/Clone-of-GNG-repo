#pragma once

#include "Core/CoreHeaders.h"

namespace fw {
    class Animation;
    struct uvTransform;
    class AnimationPlayer 
    {
    public:
        AnimationPlayer();
        ~AnimationPlayer();

        //General Functions/Methods
        void Play(Animation* animation);
        void Update(float deltaTime);

        //Getters
        uvTransform GetCurrentFrameUV() const;
        int GetCurrentFrame() const;
    private:
        Animation* m_CurrentAnimation;
        int m_CurrentFrame;
        float m_TimeInCurrentFrame;
    };
}