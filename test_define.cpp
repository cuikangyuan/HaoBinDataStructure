#include<stdio.h>

struct JNIEnv
{
};

struct RegJNIRec {
    int (*mProc)(JNIEnv* env);
};

int register_com_android_internal_os_RuntimeInit(JNIEnv* env);



#define REG_JNI(name) { name }

static const RegJNIRec gRegJNI[] = {
    REG_JNI(register_com_android_internal_os_RuntimeInit),
    {register_com_android_internal_os_RuntimeInit}
};

int register_com_android_internal_os_RuntimeInit(JNIEnv* env)
{
    return 9999;
}

int main()
{
   JNIEnv* env; 
   
   printf("%d\n", gRegJNI[0].mProc(env));
   printf("%d", 1111);

   return 0;
}