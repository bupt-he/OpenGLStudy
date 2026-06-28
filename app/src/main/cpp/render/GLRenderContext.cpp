//
// Created by yobin_he on 2026/6/14.
//

#include "GLRenderContext.h"
#include "../utils/LogUtils.h"
#include "../sample/TriangleSample.h"
#include "../sample/VBOTriangleSample.h"
#include "EBORectangleSample.h"

#define TYPE_TRIANGLE  100
#define TYPE_VBO_TRIANGLE  TYPE_TRIANGLE + 1
#define TYPE_EBO_RECTANGLE TYPE_TRIANGLE + 2



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

void GLRenderContext::SetType(int type) {
    m_pBeforeSample = m_pCurSample;
    LOGCATE("MyGLRenderContext::SetType 0 m_pBeforeSample = %p", m_pBeforeSample);
    switch (type) {
        case TYPE_TRIANGLE:
            m_pCurSample = new TriangleSample();
            break;

        case TYPE_VBO_TRIANGLE:
            m_pCurSample = new VBOTriangleSample();
            break;

        case TYPE_EBO_RECTANGLE:
            m_pCurSample = new EBORectangleSample();
            break;
        default:
            m_pCurSample = nullptr;
    }
    LOGCATE("MyGLRenderContext::SetType 0 m_pCurSample = %p", m_pCurSample);
}


//有返回值
GLRenderContext *GLRenderContext::GetInstance() {
    LOGCATD("GLRenderContext::GetInstance()==============");
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

