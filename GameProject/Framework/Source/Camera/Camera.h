#pragma once

#include "Core/CoreHeaders.h"


namespace fw {

    class Camera
    {
    public:
        Camera(vec2 position = { 0.0f, 0.0f }, float zoom = 1.0f, float aspectRatio = 1.0f)
            : m_Position(position), m_Zoom(zoom), m_AspectRatio(aspectRatio) {}
        ~Camera() {}
        
        //Setters
        void SetPosition(vec2 position) {
            m_Position = position;
        }
        void SetZoom(float zoom) {
            m_Zoom = zoom;
        }
        void SetAspectRatio(float aspectRatio) {
            m_AspectRatio = aspectRatio;
        }

        //Getters
        vec2 GetPosition() {
            return m_Position;
        }
        float GetZoom()
        {
            return m_Zoom;
        }
        float GetAspectRatio()
        {
            return m_AspectRatio;
        }
    protected:
        vec2 m_Position;
        float m_Zoom;
        float m_AspectRatio;
    };

}