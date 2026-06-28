//
// Created by yobin_he on 2026/6/14.
//

#ifndef NDKOPENGLSTUDY_GLRENDERCONTEXT_H
#define NDKOPENGLSTUDY_GLRENDERCONTEXT_H

#include "../base/GLBaseSample.h"
#include <GLES3/gl3.h>

class GLRenderContext {
    GLRenderContext();
    virtual ~GLRenderContext();
public:
    void OnSurfaceCreated();
    void OnSurfaceChanged(int width, int height);
    void OnDrawFrame();

    void SetType(int type);

    //创建单例模式
    static GLRenderContext* GetInstance();
    static void DestroyInstance();

private:
    static GLRenderContext *m_pContext;

    GLBaseSample *m_pBeforeSample;
    GLBaseSample *m_pCurSample;

    int m_ScreenW;
    int m_ScreenH;
};


#endif //NDKOPENGLSTUDY_GLRENDERCONTEXT_H
