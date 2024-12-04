#pragma once

#include "GameObject/GameObject.h"
#include "AnimationCollection/AnimationCollection.h"
#include "AnimationPlayer/AnimationPlayer.h"

class ShaderProgram;
class Texture;
class Mesh;
class Game;
class AnimatedObject : public fw::GameObject
{
protected:
    fw::AnimationCollection* m_AnimationCollection;
    fw::AnimationPlayer m_AnimationPlayer;
    Game* m_pGame;
public:
    AnimatedObject(Game* pGame, fw::vec2 pos, fw::vec2 sc, float rot, fw::ShaderProgram* s, fw::Texture* t, fw::Mesh* m, fw::vec2 res, fw::AnimationCollection* collection);
    ~AnimatedObject();

    void Update(float deltaTime) override;

    // Setters
    void SetAnimation(const std::string& name);
};