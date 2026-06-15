package com.yobin.ndkopenglstudy;

import androidx.appcompat.app.AppCompatActivity;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.TextView;

import com.yobin.ndkopenglstudy.databinding.ActivityMainBinding;
import com.yobin.ndkopenglstudy.render.CommonGLRender;
import com.yobin.ndkopenglstudy.render.CommonSurfaceView;

public class MainActivity extends AppCompatActivity {
    private ActivityMainBinding binding;

    private CommonGLRender render;
    private CommonSurfaceView commonSurfaceView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());


        render = new CommonGLRender();
        render.init(); //必须init，

        commonSurfaceView = new CommonSurfaceView(this);
        commonSurfaceView.setCommonRender(render);

//        FrameLayout.LayoutParams params = (FrameLayout.LayoutParams) binding.glSurfaceContainer.getLayoutParams();
//        params.width = ViewGroup.LayoutParams.MATCH_PARENT;
//        params.height = ViewGroup.LayoutParams.MATCH_PARENT;
//        commonSurfaceView.setLayoutParams(params);

        binding.glSurfaceContainer.removeAllViews();
        binding.glSurfaceContainer.addView(commonSurfaceView);

        commonSurfaceView.requestRender();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        render.unInit();
    }
}