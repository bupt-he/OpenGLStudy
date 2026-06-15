//
// Created by yobin_he on 2026/6/15.
//

#include "VBOTriangleSample.h"

// Shaders
const char vShaderStr[] = "#version 300 es \n"
                                   "layout (location = 0) in vec3 position;\n"
                                   "void main()\n"
                                   "{\n"
                                   "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
                                   "}\0";
const char fShaderStr[] = "#version 300 es \n"
                                     "out vec4 color;\n"
                                     "void main()\n"
                                     "{\n"
                                     "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                     "}\n\0";


VBOTriangleSample::VBOTriangleSample() {
    m_VaoId = GL_NONE;
    m_VboId = GL_NONE;
}

VBOTriangleSample::~VBOTriangleSample() {

}

void VBOTriangleSample::Init() {
    if(m_ProgramObj) return;

    m_ProgramObj = ShaderUtils::CreateProgram(vShaderStr, fShaderStr, m_VertexShader,
                                              m_FragmentShader);


    GLfloat  vertices[] = {
            -0.5f, -0.5f, 0.0f, // Left
            0.5f, -0.5f, 0.0f, // Right
            0.0f,  0.5f, 0.0f  // Top
    };

    glGenVertexArrays(1,&m_VaoId);
    glGenBuffers(1,&m_VboId);

    glBindVertexArray(m_VaoId);

    glBindBuffer(GL_ARRAY_BUFFER,m_VboId);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 3 * sizeof(GLfloat),(GLvoid *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER,GL_NONE);
    glBindVertexArray(GL_NONE);
}

void VBOTriangleSample::Draw(int screenW, int screenH) {
    glClearColor(0.2f,0.3f,0.3f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(m_ProgramObj);
    glBindVertexArray(m_VaoId);
    glDrawArrays(GL_TRIANGLES,0,3);
    glBindVertexArray(0);
}

void VBOTriangleSample::Destroy() {
    if (m_ProgramObj) {
        ShaderUtils::DeleteProgram(m_ProgramObj);
    }
    glDeleteVertexArrays(1,&m_VaoId);
    glDeleteBuffers(1,&m_VboId);
    m_VaoId = 0;
    m_VboId = 0;
}