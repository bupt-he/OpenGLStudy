#include <jni.h>
#include <string>
#include "utils/LogUtils.h"
#include "render/GLRenderContext.h"


#define NATIVE_RENDER_CLASS_NAME "com/yobin/ndkopenglstudy/render/NativeGLRender"

/**
 * 存放jni方法
 */
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL native_Init(JNIEnv *env, jobject instance) {
    LOGCATD("JNICALL native_Init");
    GLRenderContext::GetInstance(); //创建
}

JNIEXPORT void JNICALL native_UnInit(JNIEnv *env, jobject instance) {
    LOGCATD("JNICALL native_UnInit");
    GLRenderContext::DestroyInstance();
}
JNIEXPORT void JNICALL native_OnSurfaceCreated(JNIEnv *env, jobject instance) {
    GLRenderContext::GetInstance()->OnSurfaceCreated();
}

JNIEXPORT void JNICALL
native_OnSurfaceChanged(JNIEnv *env, jobject instance, jint width, jint height) {
    GLRenderContext::GetInstance()->OnSurfaceChanged(width,height);
}
JNIEXPORT void JNICALL native_OnDrawFrame(JNIEnv *env, jobject instance) {
    GLRenderContext::GetInstance()->OnDrawFrame();
}

#ifdef __cplusplus
}
#endif

static JNINativeMethod g_RenderMethods[] = {
        {"native_Init", "()V", (void *) (native_Init)},
        {"native_UnInit", "()V", (void *) (native_UnInit)},
        {"native_OnSurfaceCreated", "()V", (void *) (native_OnSurfaceCreated)},
        {"native_OnSurfaceChanged", "(II)V", (void *) (native_OnSurfaceChanged)},
        {"native_OnDrawFrame", "()V", (void *) (native_OnDrawFrame)},
};

//注册
static int RegisterNativeMethods(JNIEnv *env, const char *className, JNINativeMethod *methods, int methodNum) {
    LOGCATD("RegisterNativeMethods");
    jclass clazz = env->FindClass(className); //找到相应的class类
    if (clazz == NULL) {
        LOGCATE("RegisterNativeMethods: clazz is NULL");
        return JNI_FALSE;
    }

    if (env->RegisterNatives(clazz, methods, methodNum) < 0) {
        LOGCATE("RegisterNativeMethods: cannot register clazz");
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

//解注册
static void UnRegisterNativeMethods(JNIEnv *env, const char *className) {
    LOGCATE("UnRegisterNativeMethods");

    jclass clazz = env->FindClass(className);
    if (clazz == NULL) {
        LOGCATE("UnRegisterNativeMethods: find clazz == NULL");
        return;
    }
    if (env != NULL) {
        env->UnregisterNatives(clazz);
    }
}

extern "C" jint JNI_OnLoad(JavaVM *jvm, void *p){
    LOGCATD("==JNI_OnLoad start==");
    jint jniRet = JNI_ERR;
    JNIEnv *env = NULL;
    if (jvm->GetEnv((void **) (&env), JNI_VERSION_1_6) != JNI_OK)
    {
        return jniRet;
    }

    jint regRet = RegisterNativeMethods(env, NATIVE_RENDER_CLASS_NAME, g_RenderMethods,
    sizeof(g_RenderMethods) / sizeof(g_RenderMethods[0]));

    if(regRet != JNI_TRUE){
        return JNI_ERR;
    }

    // 注册native gl
    return JNI_VERSION_1_6;
}

extern "C" void JNI_OnUnload(JavaVM *jvm,void *p){
    JNIEnv *env = NULL;
    if (jvm->GetEnv((void **) (&env), JNI_VERSION_1_6) != JNI_OK)
    {
        return;
    }

    UnRegisterNativeMethods(env,NATIVE_RENDER_CLASS_NAME);
}