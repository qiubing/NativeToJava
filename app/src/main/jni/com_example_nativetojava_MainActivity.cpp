#include "com_example_nativetojava_MainActivity.h"
#include <android/log.h>
#include <stdlib.h>
#include <stdio.h>

#define LOG_TAG "NativeToJava"
/*
 * Class:     com_example_nativetojava_MainActivity
 * Method:    callbackFromNative
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_nativetojava_MainActivity_callbackFromNative
  (JNIEnv *env, jobject thiz){
      __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,"callbackFromNative()...");
      //获取Java类对象
      jclass clazz = env->FindClass("com/example/nativetojava/MainActivity");
      //获取mName属性ID
      jfieldID name = env->GetFieldID(clazz,"mName","Ljava/lang/String;");
      //获取sNumber静态属性ID
      jfieldID number = env->GetStaticFieldID(clazz,"sNumber","I");
      //获取showMessage方法ID
      jmethodID showMessage = env->GetMethodID(clazz,"showMessage","(Ljava/lang/String;)V");

      //获取mName属性的值
      jstring nameStr = (jstring)env->GetObjectField(thiz,name);
      //将Java中的字符串转换为C/C++中的字符数组
      const char *temp = env->GetStringUTFChars(nameStr,NULL);
      __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,"callbackFromNative()...name:%s",temp);
      //释放C/C++数组
      env->ReleaseStringUTFChars(nameStr,temp);
      //创建一个String对象
      jstring nativeStr = env->NewStringUTF("Native");
      //更新Java中的mName属性值
      env->SetObjectField(thiz,name,nativeStr);

      //获取sNumber静态属性的值
      jint num = env->GetStaticIntField(clazz,number);
      __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,"callbackFromNative()...number:%d",num);
      //更新sNumber静态属性的值
      env->SetStaticIntField(clazz,number,num+100);
      jstring message = env->NewStringUTF("native to java now");
      //调用Java中的showMessage方法
      env->CallVoidMethod(thiz,showMessage,message);
 }
