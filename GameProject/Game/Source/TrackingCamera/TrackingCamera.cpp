#include "Framework.h"
#include "TrackingCamera.h"
#include "GameObject/GameObject.h"

TrackingCamera::TrackingCamera(fw::GameObject* obj, float spd, float initialZoom) :
    Camera(obj->GetPosition(), initialZoom, 1.0f),
    m_TrackedObject(obj),
    m_Speed(spd)
{
}

TrackingCamera::~TrackingCamera()
{
}

void TrackingCamera::Update(float deltaTime)
{


    // Move camera towards the tracked 
    

    m_Position -= (m_Position - m_TrackedObject->GetPosition()) * m_Speed * deltaTime;

    float distance = (m_Position - m_TrackedObject->GetPosition()).length();

    // Camera zoom
    m_Zoom = 2.5f / (distance + 1.f);

}

void TrackingCamera::SetTargetZoom(float zoom)
{
    m_TargetZoom = zoom;
}
