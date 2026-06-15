package com.yobin.ndkopenglstudy.render;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.ScaleGestureDetector;

import androidx.annotation.NonNull;

/**
 * 1. 设置render
 * todo 增加手势操作
 */
public class CommonSurfaceView extends GLSurfaceView implements ScaleGestureDetector.OnScaleGestureListener{
    private CommonGLRender commonGLRender;
    public CommonSurfaceView(Context context) {
        this(context,null);
    }

    public CommonSurfaceView(Context context, AttributeSet attrs) {
        super(context, attrs);
        setEGLContextClientVersion(3);
        setEGLConfigChooser(8, 8, 8, 8, 8, 8);
//        setRenderer(commonGLRender);
//        setRenderMode(RENDERMODE_WHEN_DIRTY);
    }

    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        super.onMeasure(widthMeasureSpec, heightMeasureSpec);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        return super.onTouchEvent(event);
    }


    // 放大
    @Override
    public boolean onScale(@NonNull ScaleGestureDetector detector) {
        return false;
    }

    //缩放开始
    @Override
    public boolean onScaleBegin(@NonNull ScaleGestureDetector detector) {
        return false;
    }

    //缩放结束
    @Override
    public void onScaleEnd(@NonNull ScaleGestureDetector detector) {

    }

    public void setCommonRender(CommonGLRender commonGLRender) {
        setRenderer(commonGLRender);
        setRenderMode(RENDERMODE_WHEN_DIRTY);
        this.commonGLRender = commonGLRender;
    }

    public CommonGLRender getCommonRender() {
        return commonGLRender;
    }
}
