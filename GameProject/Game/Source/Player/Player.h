#include "AnimatedObject/AnimatedObject.h"

class Player : public AnimatedObject
{
public:
    Player(Game* pGame, fw::vec2 pos, fw::vec2 scale, float rotation, fw::Mesh* m, fw::ShaderProgram* s, fw::Texture* t, fw::vec2 res, fw::AnimationCollection* collection, float speed);
    ~Player();

    void Update(float deltaTime) override;
private:
    float m_Speed;
    Texture* m_Texture;
    fw::AnimationCollection* m_Collection;
    fw::ShaderProgram* m_ShaderProgram;
    fw::AnimationPlayer* m_AnimationPlayer;

};