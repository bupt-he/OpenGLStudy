//
// Created by yobin_he on 2026/6/28.
//

#ifndef NDKOPENGLSTUDY_EBORECTANGLESAMPLE_H
#define NDKOPENGLSTUDY_EBORECTANGLESAMPLE_H

#include "GLBaseSample.h"

/**
 *  用于增加EBO 索引缓冲对象
 */
class EBORectangleSample:public GLBaseSample {
public:
    EBORectangleSample();

    virtual ~EBORectangleSample();

    virtual void Init();

    virtual void Draw(int screenW, int screenH);

    virtual void Destroy();

private:
    GLuint m_VaoId;
    GLuint m_VboId;
    GLuint m_EboId;
};


#endif //NDKOPENGLSTUDY_EBORECTANGLESAMPLE_H
