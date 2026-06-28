package com.yobin.ndkopenglstudy.render;

public class NativeGLRender {
    // Used to load the 'ndkopenglstudy' library on application startup.
    static {
        System.loadLibrary("ndkopenglstudy");
    }

    public native void native_Init();  //用于初始化

    public native void native_UnInit(); // 用于解除初始化

    public native void native_OnSurfaceCreated();

    public native void native_OnSurfaceChanged(int width, int height);

    public native void native_OnDrawFrame();

    public native void native_SetType(int type);
}
