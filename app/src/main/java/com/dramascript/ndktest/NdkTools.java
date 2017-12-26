package com.dramascript.ndktest;

import android.util.Log;

import java.util.ArrayList;

/**
 * @CreadBy ：DramaScript
 * @date 2017/10/16
 */
public class NdkTools {

    static {
        System.loadLibrary("NdkTools");
    }

    public void setData(String s,int a,String str){
        Log.e("tag","String:"+s+",int:"+a+",str="+str);
    }

    /**
     *从c/c++中获取数据
     */

    //获取boolean
    public native boolean getBoolean(boolean b);

    //获取Byte
    public native byte getByte(byte b);

    //获取Char
    public native char getChar(char c);

    //获取Short
    public native short getShort(short s);

    //获取Int
    public native int getInt(int i);

    //获取Long
    public native long getLong(long l);

    //获取Float
    public native float getFloat(float f);

    //获取Double
    public native double getDouble(double d);

    //获取String
    public native String getString(String str);

    //获取byte[]
    public native byte[] getByteArray(byte[] arr);

    //获取自定义对象
    public native User getObject(User object);

    //获取对象数组
    public native User[] getObjectArray(User[] arr);

    //获取对象集合
    public native ArrayList<User> getObjectList();

    //回调java代码
    public native void callSetData();

}
