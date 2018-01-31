#include <jni.h>
#include <string>

void callJavaMethod(JNIEnv *env, jobject jobj) {
    char *str = "call from c++";

    jclass clazz = env->FindClass("com/example/maotongfei/ndkdemo/HelloNDK");
    if (clazz == NULL) {
        printf("class is null");
        return;
    }

    jmethodID method = env->GetStaticMethodID(clazz,"javaStaticMethod","()V");
    if (method == NULL) {
        printf("not found method");
    }

    env->CallStaticVoidMethod(clazz,method);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_maotongfei_ndkdemo_HelloNDK_getFromJNINew(JNIEnv *env, jobject instance) {


    std::string hello = "Hello from C++ NEW";
    callJavaMethod(env,instance);
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_maotongfei_ndkdemo_HelloNDK_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

