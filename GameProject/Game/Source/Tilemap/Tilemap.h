#pragma once
#include "Framework.h"
#include "Vector/Vector.h"

class Game;

class Tilemap
{
public:
    enum TileTypes
    {
        Empty,
        Grass,
        Wall,
        Water
    };

public:
    Tilemap(Game* pGame, const char* layout, fw::ivec2 mapSize, fw::vec2 tileSize);
    ~Tilemap();

    void draw();
private:
    Game* m_pGame;
    TileTypes* m_pLayout;
    //const char* m_pLayout;
    fw::ivec2 m_MapSize;
    fw::vec2 m_TileSize;
};
