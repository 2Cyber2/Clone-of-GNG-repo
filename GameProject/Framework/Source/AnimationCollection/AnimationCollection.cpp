#include "AnimationCollection/AnimationCollection.h"
#include "Animation/Animation.h"


namespace fw {
    void AnimationCollection::AddAnimation(const std::string& name, Animation* animation)
    {
        m_mapAnimations[name] = animation;
    }

    Animation* AnimationCollection::GetAnimation(const std::string& name)
    {
        return m_mapAnimations.count(name) ? m_mapAnimations[name] : nullptr;
    }
}
