//
// Created by yobin_he on 2026/6/14.
//

#ifndef NDKOPENGLSTUDY_TRIANGLESAMPLE_H
#define NDKOPENGLSTUDY_TRIANGLESAMPLE_H

/**
 * case1 构建一个三角形
 */

#include "../base/GLBaseSample.h"

class TriangleSample : public GLBaseSample {
public:
    TriangleSample();

    virtual ~TriangleSample();

    virtual void Init();

    virtual void Draw(int screenW, int screenH);

    virtual void Destroy();

private:

};


#endif //NDKOPENGLSTUDY_TRIANGLESAMPLE_H
