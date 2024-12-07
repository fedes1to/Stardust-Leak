
#ifndef ZygiskImGui_HOOK_H
#define ZygiskImGui_HOOK_H

#include <jni.h>

void *hack_thread(void *arg);

#include <android/log.h>

#define LOG_TAG "LStardust"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#ifdef DEBUG_WEBSOCKET
    #define LOGWS(...) __android_log_print(ANDROID_LOG_DEBUG, "LStardust", __VA_ARGS__)
#else
    #define LOGWS(...)
#endif

#define LOGCONSOLE(...) \
    appConsole.AddLog(__VA_ARGS__); \

#define HOOKDEF(ret, func, ...) \
    ret (*orig##func)(__VA_ARGS__); \
    ret new##func(__VA_ARGS__)

#endif //ZygiskImGui_HOOK_H