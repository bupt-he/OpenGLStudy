//
// Created by yobin_he on 2026/6/15.
//

#ifndef NDKOPENGLSTUDY_VBOTRIANGLESAMPLE_H
#define NDKOPENGLSTUDY_VBOTRIANGLESAMPLE_H

#include "../base/GLBaseSample.h"

class VBOTriangleSample : public GLBaseSample{
public:
    VBOTriangleSample();

    ~VBOTriangleSample();

    virtual void Init();

    virtual void Draw(int screenW, int screenH);

    virtual void Destroy();

private:
    GLuint m_VaoId;
    GLuint m_VboId;
};


#endif //NDKOPENGLSTUDY_VBOTRIANGLESAMPLE_H
