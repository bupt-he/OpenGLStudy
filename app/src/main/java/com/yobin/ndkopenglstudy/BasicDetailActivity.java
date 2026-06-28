package com.yobin.ndkopenglstudy;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.Log;
import android.view.ViewTreeObserver;

import androidx.appcompat.app.AppCompatActivity;

import com.yobin.ndkopenglstudy.databinding.ActivityBasicDetailBinding;
import com.yobin.ndkopenglstudy.render.CommonGLRender;
import com.yobin.ndkopenglstudy.render.CommonSurfaceView;
import com.yobin.ndkopenglstudy.utils.GLTypeConst;

public class BasicDetailActivity extends AppCompatActivity implements ViewTreeObserver.OnGlobalLayoutListener{

    private ActivityBasicDetailBinding binding;

    private CommonGLRender render;
    private CommonSurfaceView commonSurfaceView;

    public static final String TAG = "BasicDetailActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityBasicDetailBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        int type = getIntent().getIntExtra(GLTypeConst.TYPE_KEY, GLTypeConst.TYPE_TRIANGLE);

        render = new CommonGLRender();
        render.init(); //必须init，
        render.setType(type);

        Log.d(TAG,"type is " + type);
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

//        防止在onResume导致绘制失败
        commonSurfaceView = new CommonSurfaceView(this);
        commonSurfaceView.setCommonRender(render);
        binding.glSurfaceContainer.removeAllViews();
        binding.glSurfaceContainer.addView(commonSurfaceView);
        commonSurfaceView.setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);
    }
}
