//
// Created by yobin_he on 2026/6/14.
//

#include "GLRenderContext.h"
#include "../utils/LogUtils.h"
#include "../sample/TriangleSample.h"
#include "../sample/VBOTriangleSample.h"


GLRenderContext *GLRenderContext::m_pContext = nullptr;
//GLRenderContext *m_pContext = nullptr;

GLRenderContext::GLRenderContext() {
    m_pCurSample = new VBOTriangleSample();
    m_pBeforeSample = nullptr;
}

GLRenderContext::~GLRenderContext() {
    if (m_pCurSample) {
        delete m_pCurSample;
        m_pCurSample = nullptr;
    }

    if (m_pBeforeSample) {
        delete m_pBeforeSample;
        m_pBeforeSample = nullptr;
    }
}

void GLRenderContext::OnSurfaceCreated() {
    LOGCATD("GLRenderContext::OnSurfaceCreated()");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void GLRenderContext::OnSurfaceChanged(int width, int height) {
    LOGCATD("GLRenderContext::OnSurfaceChanged [w, h] = [%d, %d]", width, height);
    glViewport(0, 0, width, height);

    m_ScreenW = width;
    m_ScreenH = height;
}

void GLRenderContext::OnDrawFrame() {
    LOGCATD("MyGLRenderContext::OnDrawFrame");
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    if (m_pBeforeSample) {
        m_pBeforeSample->Destroy();
        delete m_pBeforeSample;
        m_pBeforeSample = nullptr;
    }

    if (m_pCurSample) {
        LOGCATD("GLRenderContext::OnDrawFrame() 初始化并绘制");
        m_pCurSample->Init();
        m_pCurSample->Draw(m_ScreenW, m_ScreenH);
    }
}


//有返回值
GLRenderContext *GLRenderContext::GetInstance() {
    LOGCATD("GLRenderContext::GetInstance()");
    if (m_pContext == nullptr) {
        m_pContext = new GLRenderContext();
    }
    return m_pContext;
}

void GLRenderContext::DestroyInstance() {
    LOGCATD("GLRenderContext::DestroyInstance()");
    if (m_pContext != nullptr) {
        delete m_pContext;  //释放指针指向的内存
        m_pContext = nullptr; //将指针置为空
    }

}

