package com.yobin.ndkopenglstudy;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.ViewTreeObserver;

import androidx.appcompat.app.AppCompatActivity;

import com.yobin.ndkopenglstudy.databinding.ActivityBasicBinding;
import com.yobin.ndkopenglstudy.render.CommonGLRender;
import com.yobin.ndkopenglstudy.render.CommonSurfaceView;

/**
 * 用于展示简单类型GL
 */
public class BasicActivity extends AppCompatActivity implements ViewTreeObserver.OnGlobalLayoutListener{
    private ActivityBasicBinding binding;

    private CommonGLRender render;
    private CommonSurfaceView commonSurfaceView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityBasicBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        render = new CommonGLRender();
        render.init(); //必须init，

        commonSurfaceView = new CommonSurfaceView(this);
        commonSurfaceView.setCommonRender(render);

        binding.glSurfaceContainer.removeAllViews();
        binding.glSurfaceContainer.addView(commonSurfaceView);
        commonSurfaceView.requestRender();

    }


    @Override
    protected void onDestroy() {
        super.onDestroy();
        render.unInit();

    }

    @Override
    protected void onPause() {
        super.onPause();
        commonSurfaceView.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        commonSurfaceView.onResume();
        commonSurfaceView.requestRender();
    }

    @Override
    public void onGlobalLayout() {
        binding.glSurfaceContainer.getViewTreeObserver().removeOnGlobalLayoutListener(this);

        //防止在onResume导致绘制失败
        commonSurfaceView = new CommonSurfaceView(this);
        commonSurfaceView.setCommonRender(render);
        binding.glSurfaceContainer.removeAllViews();
        binding.glSurfaceContainer.addView(commonSurfaceView);
        commonSurfaceView.setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);
    }
}
