#pragma once

#include "Core/CoreHeaders.h"

namespace fw {
    class Camera;
    class Texture;
    class ShaderProgram;
    class vec2;

    struct VertexFormat
    {
        vec2 m_pos;
        vec2 m_UV;
        unsigned char r, g, b, a;

        VertexFormat(vec2 pos, vec2 uv, unsigned char nr, unsigned char ng, unsigned char nb, unsigned char na) :
            m_pos(pos), m_UV(uv), r(nr), g(ng), b(nb), a(na)
        {
        }
    };

    class Mesh
    {
    public:
        Mesh(std::vector<VertexFormat> points, int primitiveType);
        void draw(Camera* camera, ShaderProgram* shader, Texture* texture, vec2 pos, vec2 s, vec2 resolution, vec2 uvOffset, vec2 uvScale);
        //void draw();
        void updateMesh(std::vector<VertexFormat> points, int primitiveType);
    private:
        GLuint m_VBO;
        int m_numPoints;
        int m_primitiveType;
        void SetUniformVec2(ShaderProgram* shader, const GLchar* u_name, vec2 pos);
        void SetUniformFloat(ShaderProgram* shader, const GLchar* u_name, float flt);
    };

}