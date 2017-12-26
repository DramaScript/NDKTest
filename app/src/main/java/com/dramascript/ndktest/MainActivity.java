package com.dramascript.ndktest;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;

import butterknife.BindView;
import butterknife.ButterKnife;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    @BindView(R.id.btn_base)
    Button btnBase;
    @BindView(R.id.btn_refrance)
    Button btnRefrance;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ButterKnife.bind(this);
        btnBase.setOnClickListener(this);
        btnRefrance.setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.btn_base:
                Intent intent = new Intent(this,BaseTypeActivity.class);
                startActivity(intent);
                break;
            case R.id.btn_refrance:
                Intent intent2 = new Intent(this,RefanceTypeActivity.class);
                startActivity(intent2);
                break;
        }
    }
}
