#include "Mesh.h"
#include "Shaders/ShaderProgram.h"
#include "Texture/Texture.h"
#include "Vector/Vector.h"
#include "Camera/Camera.h"

namespace fw {

    Mesh::Mesh(std::vector<VertexFormat> points, int primitiveType) :
        m_numPoints((int)points.size()),
        m_primitiveType(primitiveType)
    {
        glGenBuffers(1, &m_VBO);

        int size = sizeof(VertexFormat) * m_numPoints;
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, size, points.data(), GL_STATIC_DRAW);
    }


    void Mesh::updateMesh(std::vector<VertexFormat> points, int primitiveType)
    {
        glDeleteBuffers(1, &m_VBO);
        glGenBuffers(1, &m_VBO);

        int size = sizeof(VertexFormat) * m_numPoints;
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, size, points.data(), GL_STATIC_DRAW);
    }

    void Mesh::draw(Camera* camera, ShaderProgram* shader, Texture* texture, vec2 pos, vec2 s, vec2 resolution, vec2 uvOffset, vec2 uvScale)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        //setup uniforms
        glUseProgram(shader->getProgram());

        SetUniformVec2(shader, "u_Zoom", s * camera->GetZoom());

        SetUniformVec2(shader, "u_offset", pos);
        SetUniformVec2(shader, "u_CameraPosition", camera->GetPosition());
        SetUniformVec2(shader, "u_Resolution", resolution);

        /*
        uniform vec2 m_uvOffset;
uniform vec2 m_uvScale;
        */
        SetUniformVec2(shader, "u_uvOffset", uvOffset);
        SetUniformVec2(shader, "m_uvScale", uvScale);

        int textureUnitNumber = 8;
        glActiveTexture(GL_TEXTURE0 + textureUnitNumber);
        glBindTexture(GL_TEXTURE_2D, texture->GetTextureID());
        GLint colorTexture = glGetUniformLocation(shader->getProgram(), "u_texture");
        glUniform1i(colorTexture, textureUnitNumber);


        // setup attributes
        GLint loc = glGetAttribLocation(shader->getProgram(), "a_position");
        if (loc != -1)
        {
            glEnableVertexAttribArray(loc);
            glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
        }

        GLint locUV = glGetAttribLocation(shader->getProgram(), "a_UV");
        if (locUV != -1)
        {
            glEnableVertexAttribArray(locUV);
            glVertexAttribPointer(locUV, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)8);
        }


        GLint locColour = glGetAttribLocation(shader->getProgram(), "a_colour");
        if (locColour != -1)
        {
            glEnableVertexAttribArray(locColour);
            glVertexAttribPointer(locColour, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(VertexFormat), (void*)12);
        }




        // draw the primitive
        glDrawArrays(m_primitiveType, 0, m_numPoints);
    }

    void Mesh::SetUniformVec2(ShaderProgram* shader, const GLchar* u_name, fw::vec2 vec2)
    {
        GLint positionLoc = glGetUniformLocation(shader->getProgram(), u_name);
        glUniform2f(positionLoc, vec2.x, vec2.y);
    }

    void Mesh::SetUniformFloat(ShaderProgram* shader, const GLchar* u_name, float flt)
    {
        GLint positionLoc = glGetUniformLocation(shader->getProgram(), u_name);
        glUniform1f(positionLoc, flt);
    }

}