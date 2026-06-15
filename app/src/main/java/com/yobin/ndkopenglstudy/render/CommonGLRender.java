package com.yobin.ndkopenglstudy.render;

import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * 将render的方法回调给Native
 */
public class CommonGLRender implements GLSurfaceView.Renderer {
    private NativeGLRender nativeGLRender;

    public CommonGLRender() {
        //创建nativeGlRender
        nativeGLRender = new NativeGLRender();
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        nativeGLRender.native_OnDrawFrame();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        nativeGLRender.native_OnSurfaceChanged(width, height);
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        nativeGLRender.native_OnSurfaceCreated();
    }

    public void init() {
        nativeGLRender.native_Init();
    }

    public void unInit() {
        nativeGLRender.native_UnInit();
    }

    ///////////////////////////////////////////////////////////////////////////
    // 新增方法，用于更新相关参数。
    ///////////////////////////////////////////////////////////////////////////
    public void setShader(String vShader,String fShader){ //添加shader

    }

    public void setImageData(int formate, int width,int height,byte[] bytes){ //设置图片

    }

}
