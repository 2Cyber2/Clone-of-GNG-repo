#include "Game.h"
#include "Player.h"

Player::Player(Game* pGame, fw::vec2 pos, fw::vec2 scale, float rotation, fw::Mesh* m, fw::ShaderProgram* s, fw::Texture* t, fw::vec2 res, fw::AnimationCollection* collection, float speed) :
    AnimatedObject(pGame, pos, scale, rotation, s, t, m, res, collection),
    m_Speed(speed)
{
    SetAnimation("Player Idle");
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
    AnimatedObject::Update(deltaTime);

    fw::vec2 direction = { 0, 0 };
    if (m_pGame->IsKeyDown('W'))
    {

        SetAnimation("Player Up");
        direction.y += 1;
    }
    else if (m_pGame->IsKeyDown('A'))
    {

        SetAnimation("Player Left");
        direction.x -= 1;
    }
    else if (m_pGame->IsKeyDown('D'))
    {

        SetAnimation("Player Right");
        direction.x += 1;
    }
    else if (m_pGame->IsKeyDown('S'))
    {

        SetAnimation("Player Down");
        direction.y -= 1;
    }
    else
    {
        SetAnimation("Player Idle");
    }

    m_Position += direction * m_Speed * deltaTime;

    //fw::vec2 direction = { 0, 0 };
    //
    ////TODO: Implement "IsKeyDown()" function
    ////if (IsKeyDown('W')) direction.y += 1;
    ////if (IsKeyDown('S')) direction.y -= 1;
    ////if (IsKeyDown('A')) direction.x -= 1;
    ////if (IsKeyDown('A')) direction.x += 1;
    //
    //m_Position += direction * m_Speed * deltaTime;
    //
    ////Animation
    //if (direction.x > 0) SetAnimation("WalkRight");
    //else if (direction.x < 0) SetAnimation("WalkLeft");
    //else if (direction.y > 0) SetAnimation("WalkUp");
    //else if (direction.y < 0) SetAnimation("WalkDown");
}
