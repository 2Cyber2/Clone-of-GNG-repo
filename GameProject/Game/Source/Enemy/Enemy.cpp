#include "Enemy.h"
#include "Game.h"
#include "Texture/Texture.h"
#include "Shaders/ShaderProgram.h"
#include "Player/Player.h"
Enemy::Enemy(Game* pGame, fw::vec2 pos, fw::vec2 scale, float rotation, fw::Mesh* m, fw::ShaderProgram* s, fw::Texture* t, fw::vec2 res, fw::AnimationCollection* collection, float speed) :
    AnimatedObject(pGame, pos, scale, rotation, s, t, m, res, collection), 
    m_CurrentWayPoint(0), 
    m_Speed(speed)
{
    m_WayPoints.push_back({2, 2});
    m_WayPoints.push_back({-2, -2});
    m_WayPoints.push_back({-4, 4});

   
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime)
{
    AnimatedObject::Update(deltaTime);
    fw::vec2 playerpos = m_pGame->GetPlayer()->GetPosition();

    float mindist = FLT_MAX;
    for (int i = 0; i < m_WayPoints.size(); ++i)
    {
        fw::vec2 wp = m_WayPoints[i];
        float dist = (playerpos - wp).length();
        if (dist < mindist)
        {
            mindist = dist;
            m_CurrentWayPoint = i;
        }
    }

    if (m_CurrentWayPoint < m_WayPoints.size())
    {
        fw::vec2 target = m_WayPoints[m_CurrentWayPoint];
        fw::vec2 direction = target - m_Position;
        if (direction.length() > 0.05f)
        {
            direction.normalize();
            m_Position += (direction * m_Speed * deltaTime);

            if (direction.x > 0) SetAnimation("WalkRight");
            else if (direction.x < 0) SetAnimation("WalkLeft");
            else if (direction.y > 0) SetAnimation("WalkUp");
            else if (direction.y < 0) SetAnimation("WalkDown");

        }
        else SetAnimation("IdleEnemy");
    }
}

void Enemy::Draw(fw::Camera* cam)
{
    fw::vec2 origpos = GetPosition();

    for (int i = 0; i < m_WayPoints.size(); ++i)
    {
        SetPosition(m_WayPoints[i]);
        AnimatedObject::Draw(cam);
    }
    SetPosition(origpos);
    AnimatedObject::Draw(cam);

}
