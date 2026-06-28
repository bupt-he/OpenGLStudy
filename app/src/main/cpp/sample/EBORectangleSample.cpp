//
// Created by yobin_he on 2026/6/28.
//

#include "EBORectangleSample.h"


// Shaders
//const char vShaderStr[] = "#version 300 es \n"
//                          "layout (location = 0) in vec3 position;\n"
//                          "void main()\n"
//                          "{\n"
//                          "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
//                          "}\0";
//const char fShaderStr[] = "#version 300 es \n"
//                          "out vec4 color;\n"
//                          "void main()\n"
//                          "{\n"
//                          "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//                          "}\n\0";

// Shaders
const char vShaderStr[] = "#version 300 es\n"
                                   "layout (location = 0) in vec3 position;\n"
                                   "void main()\n"
                                   "{\n"
                                   "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
                                   "}\0";
const char fShaderStr[] = "#version 300 es\n"
                                     "out vec4 color;\n"
                                     "void main()\n"
                                     "{\n"
                                     "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                     "}\n\0";


EBORectangleSample::EBORectangleSample() {
    m_VaoId = GL_NONE;
    m_VboId = GL_NONE;
    m_EboId = GL_NONE;
}

EBORectangleSample::~EBORectangleSample(){
    //用于释放
};

void EBORectangleSample::Init() {

    if (m_ProgramObj) return;

    m_ProgramObj = ShaderUtils::CreateProgram(vShaderStr, fShaderStr, m_VertexShader,
                                              m_FragmentShader);

    GLfloat vertices[] = {
            0.5f, 0.5f, 0.0f,   // 右上角
            0.5f, -0.5f, 0.0f,  // 右下角
            -0.5f, -0.5f, 0.0f, // 左下角
            -0.5f, 0.5f, 0.0f   // 左上角
    };

    GLushort indices[] = { // 注意索引从0开始!
            0, 1, 3, // 第一个三角形
            1, 2, 3  // 第二个三角形
    };

    glGenVertexArrays(1,&m_VaoId);
    glGenBuffers(1, &m_VboId);
    glGenBuffers(1, &m_EboId);

    glBindVertexArray(m_VaoId);

    glBindBuffer(GL_ARRAY_BUFFER, m_VboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices,GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_EboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices,GL_STATIC_DRAW);

    //设置规则
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (const void *)0);

    glEnableVertexAttribArray(GL_NONE);
    glBindBuffer(GL_ARRAY_BUFFER,GL_NONE);
    glBindVertexArray(GL_NONE);
}

void EBORectangleSample::Draw(int screenW, int screenH) {
//    // Clear the colorbuffer
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
//
    glUseProgram(m_ProgramObj);
    GO_CHECK_GL_ERROR();
    glBindVertexArray(m_VaoId);
    GO_CHECK_GL_ERROR();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (const void *)0);
    GO_CHECK_GL_ERROR();
    glBindVertexArray(GL_NONE);
}

void EBORectangleSample::Destroy() {
    if (m_ProgramObj) {
        ShaderUtils::DeleteProgram(m_ProgramObj);
    }

    glDeleteVertexArrays(1, &m_VaoId);
    glDeleteBuffers(1, &m_VboId);
    glDeleteBuffers(1, &m_VaoId);

    m_VaoId = GL_NONE;
    m_VboId = GL_NONE;
    m_EboId = GL_NONE;
}