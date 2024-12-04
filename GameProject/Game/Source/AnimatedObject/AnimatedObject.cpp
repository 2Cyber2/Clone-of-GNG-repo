#include "AnimatedObject/AnimatedObject.h"
#include "Texture/Texture.h"
#include "Shaders/ShaderProgram.h"
#include "SpriteSheet/SpriteSheet.h"
#include "Mesh/Mesh.h"

AnimatedObject::AnimatedObject(Game* pGame, fw::vec2 pos, fw::vec2 sc, float rot, fw::ShaderProgram* s, fw::Texture* t, fw::Mesh* m, fw::vec2 res, fw::AnimationCollection* collection) :
    GameObject(s, t, m, pos, sc, res, rot),
    m_AnimationCollection(collection),
    m_pGame(pGame)
{
}

AnimatedObject::~AnimatedObject()
{
}

void AnimatedObject::Update(float deltaTime)
{
    m_AnimationPlayer.Update(deltaTime);
    fw::uvTransform uv = m_AnimationPlayer.GetCurrentFrameUV();

    
    //SetUVScale(uv.uvScale);
    
    //SetUVOffset(uv.uvOffset);


    std::vector<fw::VertexFormat> attribs =
    {
        { fw::vec2(-0.5f, -0.5f), fw::vec2(uv.uvOffset.x, uv.uvOffset.y),   0, 0, 255, 255 }, // Bottom-left
        { fw::vec2(0.5f, -0.5f), fw::vec2(uv.uvOffset.x + uv.uvScale.x, uv.uvOffset.y),   0, 255, 0, 255 }, // Bottom-right
        { fw::vec2(-0.5f,  0.5f), fw::vec2(uv.uvOffset.x, uv.uvOffset.y + uv.uvScale.y), 255, 0, 0, 255 }, // Top-left
        { fw::vec2(0.5f,  0.5f), fw::vec2(uv.uvOffset.x + uv.uvScale.x, uv.uvOffset.y + uv.uvScale.y), 255, 255, 255, 255 } // Top-right
    };
    m_pMesh->updateMesh(attribs, GL_TRIANGLE_STRIP);

}

void AnimatedObject::SetAnimation(const std::string& name)
{
    fw::Animation* animation = m_AnimationCollection->GetAnimation(name);

    if (animation)
    {
        m_AnimationPlayer.Play(animation);
    }
}