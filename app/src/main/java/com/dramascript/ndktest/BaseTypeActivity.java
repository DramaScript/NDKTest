package com.dramascript.ndktest;

import android.app.Activity;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.view.View;
import android.widget.Button;

import butterknife.BindView;
import butterknife.ButterKnife;
import butterknife.OnClick;

public class BaseTypeActivity extends Activity {

    @BindView(R.id.btn_boolean)
    Button btnBoolean;
    @BindView(R.id.btn_byte)
    Button btnByte;
    @BindView(R.id.btn_char)
    Button btnChar;
    @BindView(R.id.btn_short)
    Button btnShort;
    @BindView(R.id.btn_int)
    Button btnInt;
    @BindView(R.id.btn_long)
    Button btnLong;
    @BindView(R.id.btn_float)
    Button btnFloat;
    @BindView(R.id.btn_double)
    Button btnDouble;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_base);
        ButterKnife.bind(this);
    }

    @OnClick({R.id.btn_boolean, R.id.btn_byte, R.id.btn_char, R.id.btn_short, R.id.btn_int, R.id.btn_long, R.id.btn_float, R.id.btn_double})
    public void onViewClicked(View view) {
        NdkTools ndkTools = new NdkTools();
        switch (view.getId()) {
            case R.id.btn_boolean:
                ToastTools.showToast(ndkTools.getBoolean(false)+"",this);
                break;
            case R.id.btn_byte:
                ToastTools.showToast(ndkTools.getByte("1".getBytes()[0])+"",this);
                break;
            case R.id.btn_char:
                ToastTools.showToast(ndkTools.getChar('A')+"",this);
                break;
            case R.id.btn_short:
                short s = 1;
                ToastTools.showToast(ndkTools.getShort(s)+"",this);
                break;
            case R.id.btn_int:
                ToastTools.showToast(ndkTools.getInt(0)+"",this);
                break;
            case R.id.btn_long:
                ToastTools.showToast(ndkTools.getLong(10L)+"",this);
                break;
            case R.id.btn_float:
                ToastTools.showToast(ndkTools.getFloat(10f)+"",this);
                break;
            case R.id.btn_double:
                ToastTools.showToast(ndkTools.getDouble(10.10)+"",this);
                break;
        }
    }
}
