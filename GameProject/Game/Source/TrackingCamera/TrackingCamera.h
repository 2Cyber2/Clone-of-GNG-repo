#include "Camera/Camera.h"

class TrackingCamera : public fw::Camera
{
private:
    fw::GameObject* m_TrackedObject;
    float m_Speed;
    float m_TargetZoom;

public:
    TrackingCamera(fw::GameObject* obj, float spd, float initialZoom);
    ~TrackingCamera();

    void Update(float deltaTime);

    // Setters
    void SetTargetZoom(float zoom);
};