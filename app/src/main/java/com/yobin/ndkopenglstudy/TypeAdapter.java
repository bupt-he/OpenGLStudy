package com.yobin.ndkopenglstudy;

import android.content.Context;
import android.content.Intent;
import android.util.Pair;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.yobin.ndkopenglstudy.databinding.ItemTypeBinding;
import com.yobin.ndkopenglstudy.utils.GLTypeConst;

public class TypeAdapter extends RecyclerView.Adapter<TypeAdapter.ViewHolder> {
    private final Pair<String, Integer>[] data;
    private ItemTypeBinding binding;

    public TypeAdapter(Pair<String, Integer>[] data) {
        this.data = data;
    }

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        binding = ItemTypeBinding.inflate(LayoutInflater.from(parent.getContext()), parent, false);
        return new ViewHolder(binding.getRoot());
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        binding.tvTitle.setText(data[position].first);
        binding.tvTitle.setOnClickListener(v -> {
            Context context = holder.itemView.getContext();
            Intent intent = new Intent(context, BasicDetailActivity.class);
            intent.putExtra(GLTypeConst.TYPE_KEY, data[position].second);
            context.startActivity(intent);
        });
    }

    @Override
    public int getItemCount() {
        return data.length;
    }

    static class ViewHolder extends RecyclerView.ViewHolder {
        public ViewHolder(@NonNull View itemView) {
            super(itemView);
        }
    }
}
