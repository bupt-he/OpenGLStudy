package com.yobin.ndkopenglstudy;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.Pair;
import android.view.ViewTreeObserver;

import androidx.appcompat.app.AppCompatActivity;

import com.yobin.ndkopenglstudy.databinding.ActivityBasicListBinding;
import com.yobin.ndkopenglstudy.render.CommonGLRender;
import com.yobin.ndkopenglstudy.render.CommonSurfaceView;
import com.yobin.ndkopenglstudy.utils.GLTypeConst;

/**
 * 用于展示简单类型GL
 */
public class BasicListActivity extends AppCompatActivity{
    private ActivityBasicListBinding binding;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityBasicListBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        TypeAdapter adapter = new TypeAdapter(data);
        binding.rvContent.setAdapter(adapter);
    }


    private Pair<String, Integer>[] data = new Pair[]{
            new Pair<>("普通三角形", GLTypeConst.TYPE_TRIANGLE),
            new Pair<>("VBO三角形", GLTypeConst.TYPE_VBO_TRIANGLE),  //其实就是采用了vao vbo来处理buffer
    };
}
