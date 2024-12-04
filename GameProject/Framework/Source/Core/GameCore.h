#pragma once

namespace fw {

class FWCore;

class GameCore
{
public:
    GameCore(FWCore& framework);
    virtual ~GameCore();

    virtual void update(float deltaTime) = 0;
    virtual void draw() = 0;
    virtual void OnLeftMousePressed(int* x, int* y) = 0;
    virtual void OnReset() = 0;
protected:
    FWCore& m_Framework;
};

} // namespace fw
