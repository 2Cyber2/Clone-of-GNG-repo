#include "GameObject/GameObject.h"
#include "Mesh/Mesh.h"
#include "Shaders/ShaderProgram.h"
#include "Texture/Texture.h"

namespace fw {
    GameObject::GameObject(ShaderProgram* shader, Texture* texture, Mesh* mesh, vec2 pos, vec2 scale, vec2 resolution, float rotation) :
        m_pShader(shader),
        m_pTexture(texture),
        m_pMesh(mesh),
        m_Position(pos),
        m_Scale(scale),
        m_Rotation(rotation),
        m_Resolution(resolution)
    {
        // TODO: create game object constructor if needed

        m_uvScale = { 1, 1 };
        m_uvOffset = { 0, 0 };
    }
    GameObject::~GameObject()
    {
    }
    void GameObject::SetPosition(const vec2& position) 
    {
        m_Position = position;
    }
    void GameObject::SetScale(const vec2& scale)
    {
        m_Scale = scale;
    }
    void GameObject::SetRotation(float rotation)
    {
        m_Rotation = rotation;
    }
    void GameObject::SetUVOffset(vec2 offset)
    {
        m_uvOffset = offset;
    }
    void GameObject::SetUVScale(vec2 scale)
    {
        m_uvScale = scale;
    }
    const vec2& GameObject::GetPosition() const
    {
        return m_Position;
    }
    const vec2& GameObject::GetScale() const
    {
        return m_Scale;
    }
    float GameObject::GetRotation()
    {
        return m_Rotation;
    }


    void GameObject::Draw(Camera* pcamera)
    {
        // TODO: Create draw statement
        m_pMesh->draw(pcamera, m_pShader, m_pTexture, m_Position, m_Scale, m_Resolution, m_uvOffset, m_uvScale);
    }
}