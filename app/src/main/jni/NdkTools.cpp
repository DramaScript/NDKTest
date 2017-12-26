#include <jni.h>
#include "NdkTools.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


JNIEXPORT jboolean

JNICALL Java_com_dramascript_ndktest_NdkTools_getBoolean
        (JNIEnv *evn, jobject obj, jboolean b) {
    unsigned char bo = b;
    bo = 1;
    return (jboolean)bo;
}

JNIEXPORT jbyte

JNICALL Java_com_dramascript_ndktest_NdkTools_getByte
        (JNIEnv *evn, jobject obj, jbyte b) {
    int i = b;
    i = 15;
    return (jbyte)
    i;
}

JNIEXPORT jchar

JNICALL Java_com_dramascript_ndktest_NdkTools_getChar
        (JNIEnv *evn, jobject obj, jchar c) {
    char ch = c;
    ch = 'S';
    return (jchar)
    ch;
}

JNIEXPORT jshort

JNICALL Java_com_dramascript_ndktest_NdkTools_getShort
        (JNIEnv *evn, jobject obj, jshort s) {
    short st = s;
    st = 100;
    return (jshort)
    st;
}

JNIEXPORT jint

JNICALL Java_com_dramascript_ndktest_NdkTools_getInt
        (JNIEnv *evn, jobject obj, jint i) {
    int a = i;
    a = 1024;
    return (jint)
    a;
}

JNIEXPORT jlong

JNICALL Java_com_dramascript_ndktest_NdkTools_getLong
        (JNIEnv *evn, jobject obj, jlong l) {
    long lg = l;
    lg = 1024L;
    return (jlong)
    lg;
}

JNIEXPORT jfloat

JNICALL Java_com_dramascript_ndktest_NdkTools_getFloat
        (JNIEnv *evn, jobject obj, jfloat f) {
    float ft = f;
    ft = 23;
    return (jfloat)
    ft;
}

JNIEXPORT jdouble

JNICALL Java_com_dramascript_ndktest_NdkTools_getDouble
        (JNIEnv *evn, jobject obj, jdouble d) {
    double dl = d;
    dl = 2048.12;
    return (jdouble)
    dl;
}

JNIEXPORT jstring

JNICALL Java_com_dramascript_ndktest_NdkTools_getString
        (JNIEnv *env, jobject obj, jstring s) {

    char *st = (char *) env->GetStringUTFChars(s, 0);
    char *str = "我很好！";
    jstring rtn;
    rtn = env->NewStringUTF(str);
    return rtn;
}

JNIEXPORT jbyteArray

JNICALL Java_com_dramascript_ndktest_NdkTools_getByteArray
        (JNIEnv *evn, jobject obj, jbyteArray ba) {

    //获得byte数组
    jbyte * bytes = evn->GetByteArrayElements(ba, 0);
    int chars_len = evn->GetArrayLength(ba);
    //返回新的byte数组
    jbyteArray arr = evn->NewByteArray(6);
    jbyte * by = evn->GetByteArrayElements(arr, 0);
    char ch[10] = "abcd";
    for (int i = 0; i < 4; ++i) {
        by[i] = ch[i];
    }
    evn->SetByteArrayRegion(arr, 0, 6, by);
    return arr;

}

JNIEXPORT jobject

JNICALL Java_com_dramascript_ndktest_NdkTools_getObject
        (JNIEnv *env, jobject obj, jobject paramIn) {

    //获取
    jclass paramInClass = env->GetObjectClass(paramIn);
    if (paramInClass == NULL) {
        return NULL;
    }
    if (env->IsInstanceOf(obj, paramInClass))//判断jobject是否是某个jclass类型。
    {
        jboolean iscopy;
        jfieldID intId = env->GetFieldID(paramInClass, "age", "I");
        jint num = (int) env->GetIntField(paramIn, intId);

        jfieldID strId = env->GetFieldID(paramInClass, "name", "Ljava/lang/String;");
        jstring str = (jstring)(env)->GetObjectField(paramIn, strId);
        const char *locstr = env->GetStringUTFChars(str, &iscopy);

        env->ReleaseStringUTFChars(str, locstr);
    }

    //返回
    jclass cls = env->FindClass("com/dramascript/ndktest/User");
    jmethodID id = env->GetMethodID(cls, "<init>", "()V");

    jobject paramOut = env->NewObjectA(cls, id, 0);

    jfieldID intId = env->GetFieldID(cls, "age", "I");
    env->SetIntField(paramOut, intId, 23);

    jfieldID strId = env->GetFieldID(cls, "name", "Ljava/lang/String;");
    env->SetObjectField(paramOut, strId, (jstring)(env)->NewStringUTF("林俊杰"));

    return paramOut;
}

JNIEXPORT jobjectArray

JNICALL Java_com_dramascript_ndktest_NdkTools_getObjectArray
        (JNIEnv *env, jobject _obj, jobjectArray objarr) {

    //获取
    //JNI提供了两个函数来访问对象数组，GetObjectArrayElement返回数组中指定位置的元素，
    // SetObjectArrayElement修改数组中指定位置的元素。与基本类型不同的是，我们不能一次得到数据
    // 中的所有对象元素或者一次复制多个对象元素到缓冲区。
    jobject objects = env->GetObjectArrayElement(objarr, 0);//返回第0个对象
    jsize length = (env)->GetArrayLength(objarr);

    //返回

    //申明一个object数组
    jobjectArray args = 0;
    //获取object所属类,一般为ava/lang/Object就可以了
    jclass objClass = (env)->FindClass("java/lang/Object");
    //新建object数组
    args = (env)->NewObjectArray(5, objClass, 0);


    //给每一个实例的变量付值，并且将实例作为一个object，添加到objcet数组中
    for (int i = 0; i < 5; i++) {
        jclass cls = env->FindClass("com/dramascript/ndktest/User");
        jmethodID id = env->GetMethodID(cls, "<init>", "()V");

        jobject paramOut = env->NewObjectA(cls, id, 0);

        jfieldID intId = env->GetFieldID(cls, "age", "I");
        env->SetIntField(paramOut, intId, 23);

        jfieldID strId = env->GetFieldID(cls, "name", "Ljava/lang/String;");
        env->SetObjectField(paramOut, strId, (jstring)(env)->NewStringUTF("书戏"));

        //添加到objcet数组中
        (env)->SetObjectArrayElement(args, i, paramOut);
    }
    return args;
}

JNIEXPORT jobject

JNICALL Java_com_dramascript_ndktest_NdkTools_getObjectList
        (JNIEnv *env, jobject obj) {

    jclass list_cls = env->FindClass("Ljava/util/ArrayList;");//获得ArrayList类引用
    jmethodID list_costruct = env->GetMethodID(list_cls, "<init>", "()V"); //获得得构造函数Id
    jobject list_obj = env->NewObject(list_cls, list_costruct); //创建一个Arraylist集合对象
    //或得Arraylist类中的 add()方法ID，其方法原型为： boolean add(Object object) ;
    jmethodID list_add = env->GetMethodID(list_cls, "add", "(Ljava/lang/Object;)Z");

    jclass cls = env->FindClass("com/dramascript/ndktest/User");
    jmethodID id = env->GetMethodID(cls, "<init>", "()V");

    for (int i = 0; i < 3; i++) {
        jobject paramOut = env->NewObject(cls, id);
        env->CallBooleanMethod(list_obj, list_add, paramOut); //执行Arraylist类实例的add方法，添加一个stu对象
    }
    return list_obj;
}

JNIEXPORT void JNICALL Java_com_dramascript_ndktest_NdkTools_callSetData
(JNIEnv *env, jobject obj){

    jclass clz = env->FindClass("com/dramascript/ndktest/NdkTools");
    jmethodID mid = env->GetMethodID(clz, "setData", "(Ljava/lang/String;I)V");
    env->CallVoidMethod(obj, mid, env->NewStringUTF("haha in C ."),20);
    

}
