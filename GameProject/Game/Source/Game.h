#pragma once

#include "Framework.h"
#include "imgui.h"
#include <UI/ImGuiManager.h>

//#include <Shaders/ShaderProgram.h>
class Player;
class Enemy;
class Camera;
class SpriteSheet;
class AnimationPlayer;
class Tilemap;
class TrackingCamera;
class Game : public fw::GameCore
{
    
public:
    Game(fw::FWCore& framework);
    virtual ~Game();
   
    virtual void update(float deltaTime) override;
    virtual void draw() override;
    virtual void OnLeftMousePressed(int* x, int* y) override;
    virtual void OnReset() override;

    Player* GetPlayer();

    bool IsKeyDown(int key);
private:
    ImGuiManager* m_gui;
    fw::Texture* m_Texture;
    fw::Mesh* m_mesh;
    fw::vec2 m_pos;
    float m_angle = 0.0f;
    float m_time = 0.0f;

    float m_x = 0, m_y = 0;

    std::vector<fw::vec2> m_triPositions;



    Player* m_player;
    Enemy* m_enemy;


public:

    
    fw::vec2 m_resolution;
    fw::Camera* m_pCamera;
    TrackingCamera* m_pTrackingCamera;
    fw::ShaderProgram* m_shader;
    fw::Mesh* m_pMesh;
    Tilemap* m_pTilemap;
    fw::Texture* m_pTextures[3];
};