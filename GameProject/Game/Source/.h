//#pragma once
//
//#include "Framework.h"
//
//
//class TicTacToe : public fw::GameCore
//{
//
//public:
//    TicTacToe(fw::FWCore& framework);
//    virtual ~TicTacToe();
//
//    virtual void update(float deltaTime) override;
//    virtual void draw() override;
//    virtual void OnLeftMousePressed(int* x, int* y) override;
//    virtual void OnReset() override;
//
//private:
//    enum class shape
//    {
//        Shape_Empty,
//        Shape_X,
//        Shape_O
//    };
//
//    shape m_gameState[3][3];
//    shape m_shapeThatWon = shape::Shape_Empty;
//public:
//    void MakeBoard(std::vector<fw::VertexFormat>& boardAttribs);
//    void MakeCircle(int numSides, float radius, std::vector<fw::VertexFormat> &circleAttribs);
//    void MakeX(float size, float aspectRatio,std::vector<fw::VertexFormat>& xAttribs);
//
//
//    bool IsMouseInCell(fw::vec2 mousePos, fw::vec2(cellMin), fw::vec2(cellMax));
//    bool IsCellOccupied(fw::vec2 cellMin);
//    void PlaceShape(fw::vec2 cellMin, shape& s);
//
//    bool PlayerWin();
//private:
//    std::vector<fw::vec2> m_oPositions;
//    std::vector<fw::vec2> m_xPositions;
//    fw::ShaderProgram* m_shader;
//    fw::Mesh* m_mesh;
//    fw::Mesh* m_xMesh;
//    fw::Mesh* m_oMesh;
//    fw::vec2 m_pos;
//
//    float m_time = 0.0f;
//    float m_angle = 0.0f;
//    bool isCircle = true;
//
//private:
//    std::vector<fw::VertexFormat> m_boardAttribs;
//    const float m_boardSize;
//    const float m_cellSize;
//    const fw::vec2 m_res;
//    const float aspectRatio;
//
//private:
//
//    float m_WinR[10], m_WinG[10], m_WinB[10];
//    float winShapeScale[10];
//    float winShapeOpacity[10] = {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}; //,winCircleOpacity = 255, winCircleOpacity = 255;
//    std::vector<fw::VertexFormat> m_WinCircle, m_WinX, m_WinStar;
//    fw::Mesh* m_winCircleMesh; 
//    fw::Mesh* m_winXMesh;
//    fw::Mesh* m_winStarMesh;
//    fw::vec2 m_winShapePos[10]{};
//    float WinShapeSize;
//    float m_timer = 0.0f;
//    float m_otherTimer = 4.25;
//    int m_showShape = 0;
//
//
//};