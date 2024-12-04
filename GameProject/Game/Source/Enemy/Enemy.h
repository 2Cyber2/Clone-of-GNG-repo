#include "AnimatedObject/AnimatedObject.h"

class Texture;
class Shader;
class Mesh;
class Enemy : public AnimatedObject
{
public:
    Enemy(Game* pGame, fw::vec2 pos, fw::vec2 scale, float rotation, fw::Mesh* m, fw::ShaderProgram* s, fw::Texture* t, fw::vec2 res, fw::AnimationCollection* collection, float speed);
    ~Enemy();

    void Update(float deltaTime) override;
    void Draw(fw::Camera* cam) override;
private:
    std::vector<fw::vec2> m_WayPoints;
    int m_CurrentWayPoint;
    float m_Speed;
};