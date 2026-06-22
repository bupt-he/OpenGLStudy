package com.yobin.ndkopenglstudy;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.RenderNode;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.Pair;
import android.view.ViewGroup;
import android.view.ViewTreeObserver;
import android.widget.FrameLayout;
import android.widget.TextView;

import com.yobin.ndkopenglstudy.databinding.ActivityMainBinding;
import com.yobin.ndkopenglstudy.render.CommonGLRender;
import com.yobin.ndkopenglstudy.render.CommonSurfaceView;

public class MainActivity extends AppCompatActivity{
    private ActivityMainBinding binding;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        SampleAdapter adapter = new SampleAdapter(data);
        binding.rvContent.setAdapter(adapter);
    }

    private Pair<String, Class>[] data = new Pair[]{
            new Pair<>("入门篇", BasicActivity.class),
    };



}