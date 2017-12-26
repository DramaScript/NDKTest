package com.dramascript.ndktest;

import android.content.Context;
import android.widget.Toast;

/**
 * @CreadBy ：DramaScript
 * @date 2017/10/25
 */
public class ToastTools {

    public static void showToast(String content, Context context){
        Toast.makeText(context,"返回的结果："+content,Toast.LENGTH_SHORT).show();
    }
}
