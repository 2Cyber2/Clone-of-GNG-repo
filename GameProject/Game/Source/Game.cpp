#include "Game.h"
//#include "Framework.h"
#include "Texture/Texture.h"

#include <string>
#include <fstream>
#include "Utility/Utility.cpp"
#include "SpriteSheet/SpriteSheet.h"
#include "AnimationPlayer/AnimationPlayer.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "TrackingCamera/TrackingCamera.h"
#include "Tilemap/Tilemap.h"



//using json = nlohmann::json;

using fw::vec2;
using fw::ivec2;


struct spriteTransform
{
    fw::vec2 uvScale;
    fw::vec2 uvOffset;
};

Game::Game(fw::FWCore& framework) :
    fw::GameCore(framework)
{


    m_pCamera = new fw::Camera();
    m_shader = new fw::ShaderProgram("Data/Shaders/basic.vert", "Data/Shaders/basic.frag");
    m_resolution = fw::vec2((float)framework.getWindowWidth(), (float)framework.getWindowHeight());
    //m_Texture = new fw::Texture("Game/Source/Images/sword.png");




    //m_gui = new ImGuiManager(&framework);

    //m_pSpriteSheet = new fw::SpriteSheet( Data/Zelda.json");
    //m_pPlayer = new Player(texture, mesh, m_pSpriteSheet, ..);
    /*
    Player::Update()
    {
        m_pSpriteSheet->GetSpriteSheetTransformByName("LinkWalk1");
    */


    m_pos = fw::vec2(m_x, m_y);


    std::vector<fw::VertexFormat> attribs =
    {
        { fw::vec2(-0.5f, -0.5f), fw::vec2(0.f, 0.f),   0, 0, 255, 255 }, // Bottom-left
        { fw::vec2(0.5f, -0.5f), fw::vec2(1.f, 0.f),   0, 255, 0, 255 }, // Bottom-right
        { fw::vec2(-0.5f,  0.5f), fw::vec2(0.f, 1.f), 255, 0, 0, 255 }, // Top-left
        { fw::vec2(0.5f,  0.5f), fw::vec2(1.f, 1.f), 255, 255, 255, 255 } // Top-right
    };


    m_pMesh = new fw::Mesh(attribs, GL_TRIANGLE_STRIP);
    m_pTextures[0] = new fw::Texture("Data/Textures/ground_01.png");
    m_pTextures[1] = new fw::Texture("Data/Textures/ground_05.png");
    m_pTextures[2] = new fw::Texture("Data/Textures/ground_06.png");

    const char* layout =
        ",,,,,,,,,,"
        "XXXXXXXXXX"
        "XXXXXXXXX#"
        "XXXXXXXX#X"
        "XXXXXXX#XX"
        "XXXXXX#XXX"
        "XXXXXXXXXX"
        "XXXXXXXXXX"
        "XXXXXXXXXX"
        "XXXXXXXXXX";

    ivec2 mapSize = { 10, 10 };
    m_pTilemap = new Tilemap(this, layout, mapSize, {2,2 });


    //m_mesh = new fw::Mesh(attribs, GL_TRIANGLE_STRIP);
    //{
    //    fw::vec2 playerPos = { 0.0f, 0.0f };
    //    fw::vec2 playerScale = { 0.2f, 0.2f };
    //    float playerRotation = 0.0f;
    //    fw::Mesh* playerMesh = new fw::Mesh(attribs, GL_TRIANGLE_STRIP); // Your mesh initialization
    //    fw::Texture* playerTexture = new fw::Texture("Data/SpriteToolAndImages/Sokoban.png");



    //    fw::SpriteSheet* m_BombermanSpriteSheet = new fw::SpriteSheet("Data/SpriteToolAndImages/Sokoban.json");



    //    fw::AnimationCollection* playerCollection = new fw::AnimationCollection();


    //    {
    //        std::vector<std::string> PlayerIdle = {
    //            "player_down1"
    //        };
    //        float frametime = 0.2f;
    //        bool loops = true;

    //        fw::Animation* bomberManIdleAnim = new fw::Animation(m_BombermanSpriteSheet, PlayerIdle, frametime, loops);
    //        playerCollection->AddAnimation("Player Idle", bomberManIdleAnim);
    //    }
    //    {



    //        std::vector<std::string> PlayerDown = {
    //            "player_down1",
    //            "player_down2",
    //            "player_down3"
    //        };
    //        float frametime = 0.2f;
    //        bool loops = true;

    //        fw::Animation* bomberManIdleAnim = new fw::Animation(m_BombermanSpriteSheet, PlayerDown, frametime, loops);
    //        playerCollection->AddAnimation("Player Down", bomberManIdleAnim);
    //    }
    //    {
    //        std::vector<std::string> PlayerRight = {
    //            "player_right1",
    //            "player_right2",
    //            "player_right3"
    //        };
    //        float frametime = 0.2f;
    //        bool loops = true;

    //        fw::Animation* bomberManAnim = new fw::Animation(m_BombermanSpriteSheet, PlayerRight, frametime, loops);
    //        playerCollection->AddAnimation("Player Right", bomberManAnim);
    //    }
    //    {
    //        std::vector<std::string> PlayerLeft = {
    //            "player_left1",
    //            "player_left2",
    //            "player_left3"
    //        };
    //        float frametime = 0.2f;
    //        bool loops = true;

    //        fw::Animation* bomberManRightAnim = new fw::Animation(m_BombermanSpriteSheet, PlayerLeft, frametime, loops);
    //        playerCollection->AddAnimation("Player Left", bomberManRightAnim);

    //    }
    //    {
    //        std::vector<std::string> PlayerUp = {
    //            "player_up1",
    //            "player_up2",
    //            "player_up3"
    //        };
    //        float frametime = 0.2f;
    //        bool loops = true;

    //        fw::Animation* bomberManRightAnim = new fw::Animation(m_BombermanSpriteSheet, PlayerUp, frametime, loops);
    //        playerCollection->AddAnimation("Player Up", bomberManRightAnim);
    //    }
    //    float playerSpeed = 5.0f;
    //    m_player = new Player(this, playerPos, playerScale, playerRotation, playerMesh, m_shader, playerTexture, m_resolution, playerCollection, playerSpeed);
    //}
    //{
    //    fw::vec2 enemyPos = { 0.0f, 0.0f };
    //    fw::vec2 enemyScale = { 0.2f, 0.2f };
    //    float enemyRotation = 0.0f;
    //    fw::Mesh* enemyMesh = new fw::Mesh(attribs, GL_TRIANGLE_STRIP); // Your mesh initialization
    //    fw::Texture* enemyTexture = new fw::Texture("Data/SpriteToolAndImages/Bomberman.png");



    //    fw::SpriteSheet* m_BombermanSpriteSheet = new fw::SpriteSheet("Data/SpriteToolAndImages/Bomberman.json");
    //    fw::AnimationCollection* enemyCollection = new fw::AnimationCollection();

    //    {

    //        std::vector<std::string> bomberManIdle = {
    //            "BM_WalkDown1",
    //        };
    //        float frametime = 0.0f;
    //        bool loops = false;

    //        fw::Animation* bomberManIdleAnim = new fw::Animation(m_BombermanSpriteSheet, bomberManIdle, frametime, loops);
    //        enemyCollection->AddAnimation("IdleEnemy", bomberManIdleAnim);
    //    }
    //    {

    //        std::vector<std::string> bomberWalkDown = {
    //            "BM_WalkDown1",
    //            "BM_WalkDown2",
    //            "BM_WalkDown3"
    //        };
    //        float frametime = 0.2f;
    //        bool loops = true;

    //        fw::Animation* bomberManIdleAnim = new fw::Animation(m_BombermanSpriteSheet, bomberWalkDown, frametime, loops);
    //        enemyCollection->AddAnimation("WalkDown", bomberManIdleAnim);
    //    }
    //    {
    //        std::vector<std::string> bomberManFrameNames = {
    //            "BM_WalkRight1",
    //            "BM_WalkRight2",
    //            "BM_WalkRight3"
    //        };
    //        float frametime = 0.2f;
    //        bool loops = true;

    //        fw::Animation* bomberManAnim = new fw::Animation(m_BombermanSpriteSheet, bomberManFrameNames, frametime, loops);
    //        enemyCollection->AddAnimation("WalkRight", bomberManAnim);
    //    }
    //    {
    //        std::vector<std::string> bomberManRight = {
    //            "BM_WalkLeft1",
    //            "BM_WalkLeft2",
    //            "BM_WalkLeft3"
    //        };
    //        float frametime = 0.2f;
    //        bool loops = true;

    //        fw::Animation* bomberManRightAnim = new fw::Animation(m_BombermanSpriteSheet, bomberManRight, frametime, loops);
    //        enemyCollection->AddAnimation("WalkLeft", bomberManRightAnim);

    //    }
    //    {
    //        std::vector<std::string> bomberManRight = {
    //            "BM_WalkUp1",
    //            "BM_WalkUp2",
    //            "BM_WalkUp3"
    //        };
    //        float frametime = 0.2f;
    //        bool loops = true;

    //        fw::Animation* bomberManRightAnim = new fw::Animation(m_BombermanSpriteSheet, bomberManRight, frametime, loops);
    //        enemyCollection->AddAnimation("WalkUp", bomberManRightAnim);
    //    }
    //    float enemySpeed = 2.0f;
    //    m_enemy = new Enemy(this, enemyPos, enemyScale, enemyRotation, enemyMesh, m_shader, enemyTexture, m_resolution, enemyCollection, enemySpeed);
    //}
    //m_pTrackingCamera = new TrackingCamera(m_player, 1.f, 1.0f);

    

}

Game::~Game()
{
    delete m_shader;
    delete m_mesh;
}

void Game::update(float deltaTime)
{
    //m_gui->startFrame(deltaTime);

    //animationPlayer->Update(deltaTime);


    //m_pTrackingCamera->Update(deltaTime);

    //m_enemy->Update(deltaTime);
    //m_player->Update(deltaTime);
    m_time = (float)fw::getTimeSinceGameStarted();
}

void Game::draw()
{
    //setup attributes
    glClearColor(0.50588f, 0.53333f, 0.92157f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    m_pTilemap->draw();
    //m_enemy->Draw(m_pTrackingCamera);
    //m_player->Draw(m_pTrackingCamera);



    //ImGui::Text("Hello, world %d", 123);
    //ImGui::ShowDemoWindow();

    //Draw Mesh's
    //for (const auto& pos : m_tripositions)
    //{
       // m_mesh->draw(m_shader, pos, m_angle, m_time, m_resolution);
    //}


    //m_mesh->draw(m_Camera, m_shader, bombermanTexture, m_pos, {0,0}, m_resolution);

    //m_mesh->draw(m_shader, fw::vec2(0.5f, -0.4f), m_angle, m_time, m_resolution);


    //m_gui->endFrame();
    m_Framework.swapBuffers();
}

void Game::OnLeftMousePressed(int* x, int* y)
{
}

void Game::OnReset()
{
}

Player* Game::GetPlayer()
{
    return m_player;
}

bool Game::IsKeyDown(int key)
{
    return m_Framework.isKeyDown(key);
}
