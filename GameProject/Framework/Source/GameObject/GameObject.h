#pragma once

#include "Core/CoreHeaders.h"

namespace fw {
    class ShaderProgram;
    class Mesh;
    class Texture;
    class Camera;
    class GameObject
    {
    public:
        GameObject(ShaderProgram* shader, Texture* texture, Mesh* mesh = nullptr, vec2 pos = {0.0f,0.0f}, vec2 scale = {1.0f,1.0f}, vec2 resolution = {1920, 1080}, float rotation = 0.0f);
        ~GameObject();

        //Setters
        void SetPosition(const vec2& position);
        void SetScale(const vec2& scale);
        void SetRotation(float rotation);

        void SetUVOffset(vec2 offset);
        void SetUVScale(vec2 scale);


        //Getters
        const vec2& GetPosition() const;
        const vec2& GetScale() const;
        float GetRotation();


        virtual void Draw(Camera* pcamera);
        virtual void Update(float deltaTime) {};
    protected:
        Texture* m_pTexture;
        ShaderProgram* m_pShader;
        Mesh* m_pMesh;
        vec2 m_Position;
        vec2 m_Scale;
        vec2 m_Resolution;
        vec2 m_uvOffset;
        vec2 m_uvScale;
        float m_Rotation;

    };

}