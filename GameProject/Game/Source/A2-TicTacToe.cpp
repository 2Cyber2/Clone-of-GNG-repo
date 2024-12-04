//#include "A2-TicTacToe.h"
//
//#include <string>
//#include <fstream>
//#include <Utility/Utility.h>
//
////Used to get PI
//#define _USE_MATH_DEFINES
//#include <math.h>
//
//// Used to get rand()
//#include <random>
//
//
//TicTacToe::TicTacToe(fw::FWCore& framework) :
//    fw::GameCore(framework),
//    m_boardSize(1.0f),
//    m_cellSize(m_boardSize/3.0f),
//    m_res(fw::vec2((float)framework.getWindowWidth(), (float)framework.getWindowHeight())),
//    aspectRatio(m_res.x/m_res.y)
//{
//
//    m_shader = new fw::ShaderProgram("Data/Shaders/basic.vert", "Data/Shaders/basic.frag");
//
//    
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            m_gameState[i][j] = shape::Shape_Empty;
//        }
//    }
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//    MakeBoard(m_boardAttribs);
//    m_mesh = new fw::Mesh(m_boardAttribs, GL_LINES);
//    m_pos = fw::vec2(0, 0);
//
//    glLineWidth(10.5f);
//    std::vector<fw::VertexFormat> circle;
//
//    int op = 255;
//    int r = 255, g = 0, b = 0;
//    MakeCircle(200, 0.2f, circle);
//    m_oMesh = new fw::Mesh(circle, GL_LINE_STRIP);
//
//    int xr = 0, xg = 255, xb = 0;
//    std::vector<fw::VertexFormat> xAttribs;
//    MakeX(0.16f, aspectRatio, xAttribs);
//    m_xMesh = new fw::Mesh(xAttribs, GL_LINES);
//
//
//
//
//
//    MakeCircle(200, 0.5f, m_WinCircle);
//    m_winCircleMesh = new fw::Mesh(m_WinCircle, GL_LINE_STRIP);
//
//    MakeX(0.5f, aspectRatio, m_WinX);
//    m_winXMesh = new fw::Mesh(m_WinX, GL_LINES);
//
//
//    m_WinStar =
//    {
//        fw::VertexFormat{fw::vec2(0.0f,0.4f), 0, 0, 0 ,0},
//        fw::VertexFormat{fw::vec2(0.14f,0.0f), 0, 0, 0 ,0},
//        fw::VertexFormat{fw::vec2(-0.14f,0.0f), 0, 0, 0 ,0},
//        fw::VertexFormat{fw::vec2(0.4f,0.0f), 0, 0, 0 ,0},
//        fw::VertexFormat{fw::vec2(0.0f,-0.6f), 0, 0, 0 ,0},
//        fw::VertexFormat{fw::vec2(-0.4f,0.0f), 0, 0, 0 ,0},
//        fw::VertexFormat{fw::vec2(0.0f,-0.6f), 0, 0, 0 ,0},
//        fw::VertexFormat{fw::vec2(-0.24f,-0.84f), 0, 0, 0 ,0},
//        fw::VertexFormat{fw::vec2(-0.16f,-0.36f), 0, 0, 0 ,0},
//        fw::VertexFormat{fw::vec2(0.0f,-0.6f), 0, 0, 0 ,0},
//        fw::VertexFormat{fw::vec2(0.24f,-0.84f), 0, 0, 0 ,0},
//        fw::VertexFormat{fw::vec2(0.16f,-0.36f), 0, 0, 0 ,0},
//
//    };
//    m_winStarMesh = new fw::Mesh(m_WinStar, GL_TRIANGLES);
//}
//
//TicTacToe::~TicTacToe()
//{
//    delete m_shader;
//    delete m_mesh;
//    delete m_xMesh;
//    delete m_oMesh;
//    delete m_winCircleMesh;
//    delete m_winXMesh;
//    delete m_winStarMesh;
//}
//
//void TicTacToe::update(float deltaTime)
//{
//    if (PlayerWin())
//    {
//        m_timer = m_timer - deltaTime;
//        
//        for (int i = 0; i < m_showShape; i++)
//        {
//            winShapeOpacity[i] = winShapeOpacity[i] - 0.75f * deltaTime;
//        }
//        
//        if (m_timer < 0.0f)
//        {
//            static std::random_device rd;
//            static std::mt19937 eng(rd());
//            static std::uniform_real_distribution<float> distr(-1.0f, 1.0f);
//            static std::uniform_real_distribution<float> col(0.0f, 1.0f);
//            static std::uniform_real_distribution<float> size(0.5f, 1.4f);
//
//            
//            for (int i = 0; i < 10; i++)
//            {
//                if (winShapeOpacity[i] <= 0.0f)
//                {
//                    winShapeOpacity[i] = 1.0f;
//                    winShapeScale[i] = size(eng);
//                    m_WinR[i] = col(eng);
//                    m_WinG[i] = col(eng);
//                    m_WinB[i] = col(eng);
//                    m_winShapePos[i] = fw::vec2(distr(eng), distr(eng));
//
//                    m_showShape--;
//
//                    break;
//                }
//            }
//
//
//            if (m_showShape <= 10)
//            {
//                m_showShape++;
//            }
//            m_timer = 0.2f;
//        }
//    }
//}
//
//void TicTacToe::draw()
//{
//    //setup attributes
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//
//        m_mesh->draw(m_shader, m_pos, 1.0f,1.0f,1.0f,1.0f, 1.0f, m_res);
//
//
//        for (const auto& pos : m_oPositions)
//        {
//            m_oMesh->draw(m_shader, pos, 255.0f, 0,0,255, 1.0f, m_res);
//        }
//
//        for (const auto& pos : m_xPositions)
//        {
//            m_xMesh->draw(m_shader, pos, 0,255.0f, 0, 255, 1.0f,m_res);
//        }
//
//        if (PlayerWin())
//        {
//            for (int i = 0; i < m_showShape; i++)
//            {
//                if (m_shapeThatWon == shape::Shape_O)
//                {
//                    m_winCircleMesh->draw(m_shader, m_winShapePos[i], m_WinR[i], m_WinG[i], m_WinB[i], winShapeOpacity[i], winShapeScale[i], m_res);
//                }
//                else
//                {
//                    m_winXMesh->draw(m_shader, m_winShapePos[i], m_WinR[i], m_WinG[i], m_WinB[i], winShapeOpacity[i], winShapeScale[i], m_res);
//                }
//                m_winStarMesh->draw(m_shader,  m_winShapePos[i], m_WinR[i], m_WinG[i], m_WinB[i], winShapeOpacity[i], winShapeScale[i], m_res);
//            }
//        }
//
//
//    m_Framework.swapBuffers();
//}
//
//
//
//
//
//void TicTacToe::OnLeftMousePressed(int* x, int* y)
//{
//    float tempX = (*(x) - m_res.x / 2) / (m_res.x / 2);
//    float tempY = -(*(y) - m_res.y / 2) / (m_res.y / 2);
//
//
//
//    for (int row = 0; row < 3; ++row) {
//        for (int col = 0; col < 3; ++col) {
//
//            fw::vec2 cellMin((m_pos.x - (m_boardSize / 2) + (col * m_cellSize)), (m_pos.y - (m_boardSize / 2) * aspectRatio + (row * m_cellSize * aspectRatio)));
//            fw::vec2 cellMax((cellMin.x + m_cellSize), (cellMin.y + m_cellSize * aspectRatio));
//
//            if (IsMouseInCell(fw::vec2(tempX, tempY), cellMin, cellMax))
//            {
//                if (IsCellOccupied(cellMin))
//                {
//                    return;
//                }
//                if (!PlayerWin())
//                {
//                    shape s;
//                    PlaceShape(cellMin, s);
//                    m_gameState[row][col] = s;
//                }
//                return; 
//            }
//        }
//    }
//}
//
//bool TicTacToe::PlayerWin()
//{
//    for (int i = 0; i < 3; i++)
//    {
//        //check virtial
//        if (m_gameState[0][i] == shape::Shape_X && m_gameState[1][i] == shape::Shape_X && m_gameState[2][i] == shape::Shape_X)
//        {
//            m_shapeThatWon = shape::Shape_X;
//            return true;
//        }
//        else if(m_gameState[0][i] == shape::Shape_O && m_gameState[1][i] == shape::Shape_O && m_gameState[2][i] == shape::Shape_O)
//        {
//            m_shapeThatWon = shape::Shape_O;
//            return true;
//        }
//        //check horizontal
//        else if (m_gameState[i][0] == shape::Shape_X && m_gameState[i][1] == shape::Shape_X && m_gameState[i][2] == shape::Shape_X)
//        {
//            m_shapeThatWon = shape::Shape_X;
//            return true;
//        }
//        else if(m_gameState[i][0] == shape::Shape_O && m_gameState[i][1] == shape::Shape_O && m_gameState[i][2] == shape::Shape_O)
//        {
//            m_shapeThatWon = shape::Shape_O;
//            return true;
//        }
//    }
//
//    // Check diagonals
//    if ((m_gameState[0][0] == shape::Shape_X && m_gameState[1][1] == shape::Shape_X && m_gameState[2][2] == shape::Shape_X) ||
//        (m_gameState[0][2] == shape::Shape_X && m_gameState[1][1] == shape::Shape_X && m_gameState[2][0] == shape::Shape_X))
//    {
//        m_shapeThatWon = shape::Shape_X;
//        return true;
//    }
//    else if ((m_gameState[0][0] == shape::Shape_O && m_gameState[1][1] == shape::Shape_O && m_gameState[2][2] == shape::Shape_O)
//        || (m_gameState[0][2] == shape::Shape_O && m_gameState[1][1] == shape::Shape_O && m_gameState[2][0] == shape::Shape_O))
//    {
//        m_shapeThatWon = shape::Shape_O;
//        return true;
//    }
//
//
//
//    return false;
//}
//
//void TicTacToe::OnReset()
//{
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            m_gameState[i][j] = shape::Shape_Empty;
//        }
//    }
//    m_xPositions.clear();
//    m_oPositions.clear();
//}
//
//
//bool TicTacToe::IsMouseInCell(fw::vec2 mousePos, fw::vec2(cellMin), fw::vec2(cellMax))
//{
//    if (mousePos.x >= cellMin.x && mousePos.x <= cellMax.x && mousePos.y >= cellMin.y && mousePos.y <= cellMax.y)
//    {
//        return true;
//    }
//    return false;
//}
//
//bool TicTacToe::IsCellOccupied(fw::vec2 cellMin)
//{
//    for (const auto& pos : m_oPositions) {
//        if (pos.x == cellMin.x + (m_cellSize / 2) && pos.y == cellMin.y + (m_cellSize * aspectRatio / 2)) {
//            return true;
//        }
//    }
//    for (const auto& pos : m_xPositions) {
//        if (pos.x == cellMin.x + (m_cellSize / 2) && pos.y == cellMin.y + (m_cellSize * aspectRatio / 2)) {
//            return true;
//        }
//    }
//
//
//    return false;
//}
//void TicTacToe::PlaceShape(fw::vec2 cellMin, shape& s)
//{
//    fw::vec2 center;
//    
//    center.x = cellMin.x + (m_cellSize / 2);
//    center.y = cellMin.y + (m_cellSize * aspectRatio /2);
//
//    if (isCircle) {
//        m_oPositions.push_back(center);
//        s = shape::Shape_O;
//        isCircle = false;
//    }
//    else {
//        m_xPositions.push_back(center);
//        s = shape::Shape_X;
//        isCircle = true;
//    }
//}
//
//
//void TicTacToe::MakeBoard(std::vector<fw::VertexFormat>& boardAttribs)
//{
//        float cellSize = m_boardSize / 3.0f;
//
//        // Vertical lines
//        for (int i = 1; i < 3; ++i) 
//        {
//            float x = (i * cellSize) - (m_boardSize / 2.0f); 
//            fw::vec2 start(x, -((m_boardSize/2) * aspectRatio)); 
//            fw::vec2 end(x, (m_boardSize/2) * aspectRatio); 
//
//            boardAttribs.push_back(fw::VertexFormat(start, 100, 75, 255, 255));
//            boardAttribs.push_back(fw::VertexFormat(end, 0, 225, 255, 255));   
//        }
//
//        // Horizontal lines
//        for (int i = 1; i < 3; ++i)
//        {
//            float y = (i * cellSize) - (m_boardSize / 2.0f); 
//            fw::vec2 start(-m_boardSize / 2.0f, y * aspectRatio);
//            fw::vec2 end(m_boardSize / 2.0f, y * aspectRatio);
//
//            boardAttribs.push_back(fw::VertexFormat(start, 0, 225, 255, 255));
//            boardAttribs.push_back(fw::VertexFormat(end, 0, 100, 255, 255));
//        }
//
//}
//
//void TicTacToe::MakeCircle(int numSides, float radius, std::vector<fw::VertexFormat>& circleAttribs)
//{
//    circleAttribs.clear();
//    float x = 0.0f, y = 0.0f;
//    float angle = 0.0f;
//    float angleRadians = 0.0f;
//    for (int i = 0; i < numSides - 1; i++)
//    {
//        angle = ((M_PI * 2.0f)/ numSides) * i;
//        x = cos(angle) * radius / aspectRatio;
//        y = sin(angle) * radius;
//        circleAttribs.push_back(fw::VertexFormat(fw::vec2(x, y), 0, 0, 0, 0));
//    }
//    circleAttribs.push_back(circleAttribs[0]);
//}
//
//
//
//void TicTacToe::MakeX(float size, float aspectRatio, std::vector<fw::VertexFormat>& xAttribs)
//{
//    xAttribs.clear();
//    fw::vec2 topLeft(-size / aspectRatio, size);
//    fw::vec2 topRight(size / aspectRatio, size);
//    fw::vec2 bottomLeft(-size / aspectRatio, -size);
//    fw::vec2 bottomRight(size / aspectRatio, -size);
//
//    xAttribs.push_back(fw::VertexFormat(topLeft, 0, 0, 0, 0));
//    xAttribs.push_back(fw::VertexFormat(bottomRight, 0, 0, 0, 0));
//    xAttribs.push_back(fw::VertexFormat(topRight, 0, 0, 0, 0));
//    xAttribs.push_back(fw::VertexFormat(bottomLeft, 0, 0,0 , 0));
//}
