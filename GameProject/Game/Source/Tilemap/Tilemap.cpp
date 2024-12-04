#include "Tilemap.h"
#include "Game.h"

using fw::vec2;
using fw::ivec2;

Tilemap::Tilemap(Game* pGame, const char* layout, ivec2 mapSize, vec2 tileSize) :
    m_pGame(pGame), m_MapSize(mapSize), m_TileSize(tileSize)
{
    m_pLayout = new TileTypes[mapSize.x * mapSize.y];

    for (int i = 0; i < mapSize.x * mapSize.y; i++)
    {
        if (layout[i] == ',') m_pLayout[i] = TileTypes::Grass;
        if (layout[i] == 'X') m_pLayout[i] = TileTypes::Wall;
        if (layout[i] == 'w') m_pLayout[i] = TileTypes::Water;
        if (layout[i] == '#') m_pLayout[i] = TileTypes::Empty;
    }
}

Tilemap::~Tilemap()
{
}

void Tilemap::draw()
{
    for (int y = 0; y < m_MapSize.y; y++)
    {
        for (int x = 0; x < m_MapSize.x; x++)
        {
            int flippedY = m_MapSize.y - 1 -y;
            int index = y * m_MapSize.x + x;
            TileTypes tileType = m_pLayout[index];
            int textureIndex = static_cast<int>(tileType);

            if (tileType != TileTypes::Empty)
                m_pGame->m_pMesh->draw(m_pGame->m_pCamera, m_pGame->m_shader, m_pGame->m_pTextures[textureIndex], vec2(x, flippedY) * m_TileSize, vec2{1.0f,1.0f}, m_pGame->m_resolution, vec2{0.0f, 0.0f}, vec2{1.0f, 1.0f });
        }
    }
}
