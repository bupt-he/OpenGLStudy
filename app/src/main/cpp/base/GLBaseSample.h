//
// Created by yobin_he on 2026/6/14.
//

#ifndef NDKOPENGLSTUDY_GLBASESAMPLE_H
#define NDKOPENGLSTUDY_GLBASESAMPLE_H

#include "GLES3/gl3.h"
#include "../utils/ShaderUtils.h"
#include "../utils/LogUtils.h"

class GLBaseSample{
public:
    GLBaseSample(){
        m_ProgramObj = 0;
        m_VertexShader = 0;
        m_FragmentShader = 0;
    }

    virtual void Init() = 0;

    virtual void Draw(int screenW, int screenH) = 0;

    virtual void Destroy() = 0;

protected:
    GLuint m_ProgramObj;
    GLuint m_VertexShader;
    GLuint m_FragmentShader;
};

#endif //NDKOPENGLSTUDY_GLBASESAMPLE_H
