/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_acces_aiousb_DIOStreamSubsystem */

#ifndef _Included_com_acces_aiousb_DIOStreamSubsystem
#define _Included_com_acces_aiousb_DIOStreamSubsystem
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_acces_aiousb_DIOStreamSubsystem
 * Method:    setClock
 * Signature: (IZ[D)I
 */
JNIEXPORT jint JNICALL Java_com_acces_aiousb_DIOStreamSubsystem_setClock
  (JNIEnv *, jobject, jint, jboolean, jdoubleArray);

/*
 * Class:     com_acces_aiousb_DIOStreamSubsystem
 * Method:    streamOpen
 * Signature: (IZ)I
 */
JNIEXPORT jint JNICALL Java_com_acces_aiousb_DIOStreamSubsystem_streamOpen
  (JNIEnv *, jobject, jint, jboolean);

/*
 * Class:     com_acces_aiousb_DIOStreamSubsystem
 * Method:    streamClose
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_acces_aiousb_DIOStreamSubsystem_streamClose
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_acces_aiousb_DIOStreamSubsystem
 * Method:    streamFrame
 * Signature: (I[C[I)I
 */
JNIEXPORT jint JNICALL Java_com_acces_aiousb_DIOStreamSubsystem_streamFrame
  (JNIEnv *, jobject, jint, jcharArray, jintArray);

#ifdef __cplusplus
}
#endif
#endif