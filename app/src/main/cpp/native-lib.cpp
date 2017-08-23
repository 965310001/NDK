#include <jni.h>
#include <string>

#include <android/log.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_administrator_ndk_MainActivity_testMap(JNIEnv *env, jobject instance,
                                                        jobject map) {
    jclass jclass1=env->GetObjectClass(map);
    jmethodID jmethodID1=env->GetMethodID(jclass1,"get","(Ljava/lang/Object;)L/java/lang/String");
    jstring jstring1= (jstring) env->CallObjectMethod(map, jmethodID1,env->NewStringUTF("name"));
    __android_log_print(ANDROID_LOG_INFO,"JNI","%s",env->GetStringUTFChars(jstring1,NULL));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_administrator_ndk_MainActivity_testInt(JNIEnv *env, jobject instance, jint i,jboolean jboolean1,jchar jchar1,
                                                        jstring jstring1,jobjectArray jarray1,jintArray jintArray1,
jcharArray jcharArray1,jbooleanArray jbooleanArray1) {

    __android_log_print(ANDROID_LOG_INFO,"JNI","%d",jboolean1);
    const char * str=  env->GetStringUTFChars(jstring1,NULL);
    if (jboolean1){
        __android_log_print(ANDROID_LOG_INFO,"JNI","true");
    }else{
        __android_log_print(ANDROID_LOG_INFO,"JNI","false");
    }
    jsize size=env->GetArrayLength(jintArray1);
    __android_log_print(ANDROID_LOG_INFO,"JNI","int数组长度:%d",size);
    size=env->GetArrayLength(jarray1);
    __android_log_print(ANDROID_LOG_INFO,"JNI","string数组长度:%d",size);

    //int[] 数组循环
    jint  *jint1=env->GetIntArrayElements(jintArray1,NULL);
    for(int i=0;i <size;i++){//数组下标访问
        __android_log_print(ANDROID_LOG_INFO,"JNI","开始循环：%d",jint1[i]);
    }
    for(int i=0;i <size;i++){//指针下标
        __android_log_print(ANDROID_LOG_INFO,"JNI","开始循环：%d",*jint1);
        jint1++;
    }

    //string[] 循环
    size= env->GetArrayLength(jarray1);
    __android_log_print(ANDROID_LOG_INFO,"JNI","string数组长度:%d",size);
    for(int i=0;i <size;i++){
         jstring str= (jstring) env->GetObjectArrayElement(jarray1,i);
        __android_log_print(ANDROID_LOG_INFO,"JNI","string内容:%s",env->GetStringUTFChars(str,NULL));
    }

    //char[] 循环
    size=env->GetArrayLength(jcharArray1);
    jchar *jchars=env->GetCharArrayElements(jcharArray1,NULL);
    for(int i=0;i <size;i++){
        __android_log_print(ANDROID_LOG_INFO,"JNI","char访问:%c",*jchars);
        jchars++;
    }
    jchars=env->GetCharArrayElements(jcharArray1,NULL);
    for(int i=0;i <size;i++){
        __android_log_print(ANDROID_LOG_INFO,"JNI","char访问:%c",jchars[i]);
    }

    //booole[] 循环
    size=env->GetArrayLength(jbooleanArray1);
    jboolean *jbooleans=env->GetBooleanArrayElements(jbooleanArray1,NULL);
    for (int i = 0; i < size; ++i) {
        __android_log_print(ANDROID_LOG_INFO,"JNI","boole:%s",*jbooleans?"true":"false");
        jbooleans++;
    }
    jbooleans=env->GetBooleanArrayElements(jbooleanArray1,NULL);
    for (int i = 0; i < size; ++i) {
        __android_log_print(ANDROID_LOG_INFO,"JNI","boole:%s",jbooleans[i]?"true":"false");
    }

    __android_log_print(ANDROID_LOG_INFO,"JNI","%s",str);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_administrator_ndk_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
