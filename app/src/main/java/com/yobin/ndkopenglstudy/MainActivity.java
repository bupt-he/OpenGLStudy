package com.yobin.ndkopenglstudy;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Pair;

import com.yobin.ndkopenglstudy.databinding.ActivityMainBinding;

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
            new Pair<>("入门篇", BasicListActivity.class),
    };



}