package com.dramascript.ndktest;

import android.app.Activity;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.view.View;
import android.widget.Button;

import butterknife.BindView;
import butterknife.ButterKnife;
import butterknife.OnClick;

public class RefanceTypeActivity extends Activity {

    @BindView(R.id.btn_string)
    Button btnString;
    @BindView(R.id.btn_base)
    Button btnBase;
    @BindView(R.id.btn_refrance)
    Button btnRefrance;
    @BindView(R.id.btn_array)
    Button btnArray;
    @BindView(R.id.btn_callback)
    Button btnCallback;
    @BindView(R.id.btn_thread)
    Button btnThread;
    @BindView(R.id.btn_list)
    Button btnList;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_refance);
        ButterKnife.bind(this);
    }

    @OnClick({R.id.btn_string, R.id.btn_base, R.id.btn_refrance, R.id.btn_array, R.id.btn_list, R.id.btn_callback, R.id.btn_thread})
    public void onViewClicked(View view) {
        NdkTools ndkTools = new NdkTools();
        switch (view.getId()) {
            case R.id.btn_string:
                ToastTools.showToast(ndkTools.getString("你好吗？ "), this);
                break;
            case R.id.btn_base:
                byte[] byteArray = ndkTools.getByteArray("你好吗？ ".getBytes());
                ToastTools.showToast(new String(byteArray), this);
                break;
            case R.id.btn_refrance:
                User user = new User();
                User object = ndkTools.getObject(user);
                ndkTools.getObject(user);
                ToastTools.showToast(object.name + "," + object.age, this);
                break;
            case R.id.btn_array:
                User[] arr = new User[10];
                User[] objectArray = ndkTools.getObjectArray(arr);
                if (objectArray != null && objectArray.length != 0) {
                    User user1 = objectArray[0];
                    ToastTools.showToast(user1.name + "," + user1.age, this);
                }
                break;
            case R.id.btn_list:
                ToastTools.showToast(ndkTools.getObjectList().size()+"", this);
                break;
            case R.id.btn_callback:
                ndkTools.callSetData();
                break;
            case R.id.btn_thread:

                break;
        }
    }

}
