JavaVM *jvm;
jclass UnityPlayer_cls;
jfieldID UnityPlayer_CurrentActivity_fid;
JNIEnv* getEnv() {
    JNIEnv *env;
    int status = jvm->GetEnv((void**)&env, JNI_VERSION_1_6);
    if(status < 0) {
        status = jvm->AttachCurrentThread(&env, NULL);
        if(status < 0) {
            LOGE(OBFUSTR("Error Getting JNI"), 1);
            return nullptr;
        }
    }
    return env;
}

void displayKeyboard() {
    JNIEnv *env = getEnv();
    jclass ctx = env->FindClass(OBFUSTR("android/content/Context"));
    jfieldID fid = env->GetStaticFieldID(ctx, OBFUSTR("INPUT_METHOD_SERVICE"), OBFUSTR("Ljava/lang/String;"));
    jmethodID mid = env->GetMethodID(ctx, OBFUSTR("getSystemService"), OBFUSTR("(Ljava/lang/String;)Ljava/lang/Object;"));
    jobject context = env->GetStaticObjectField(UnityPlayer_cls, UnityPlayer_CurrentActivity_fid);
    jobject InputManObj = env->CallObjectMethod(context, mid, (jstring) env->GetStaticObjectField(ctx, fid));
    jclass ClassInputMethodManager = env->FindClass(OBFUSTR("android/view/inputmethod/InputMethodManager"));
    jmethodID toggleSoftInputId = env->GetMethodID(ClassInputMethodManager, OBFUSTR("toggleSoftInput"), OBFUSTR("(II)V"));
    env->CallVoidMethod(InputManObj, toggleSoftInputId, 0, 2);
}

jmethodID MotionEvent_getX;
jmethodID MotionEvent_getY;
jmethodID MotionEvent_getAction;
jmethodID KeyEvent_getUnicodeChar;
jmethodID KeyEvent_getMetaState;
jmethodID KeyEvent_getAction;
jmethodID KeyEvent_getKeyCode;
HOOKDEF(jboolean, nativeInjectEvent, JNIEnv *env, jobject thiz, jobject inputEvent)
{
    if (init)
    {
        jclass MotionEventCls = env->FindClass(OBFUSTR("android/view/MotionEvent"));
        jclass KeyEventCls = env->FindClass(OBFUSTR("android/view/KeyEvent"));
        if (env->IsInstanceOf(inputEvent, MotionEventCls))
        {
            if (!MotionEvent_getX)
                MotionEvent_getX = env->GetMethodID(MotionEventCls, OBFUSTR("getX"),
                                                    OBFUSTR("()F"));
            if (!MotionEvent_getY)
                MotionEvent_getY = env->GetMethodID(MotionEventCls, OBFUSTR("getY"),
                                                    OBFUSTR("()F"));
            if (!MotionEvent_getAction)
                MotionEvent_getAction = env->GetMethodID(MotionEventCls, OBFUSTR("getAction"),
                                                         OBFUSTR("()I"));
            ImGuiIO &io = ImGui::GetIO();
            auto x = env->CallFloatMethod(inputEvent, MotionEvent_getX);
            auto y = env->CallFloatMethod(inputEvent, MotionEvent_getY);
            auto event_action = env->CallIntMethod(inputEvent,
                                             MotionEvent_getAction);
            ImGui_ImplAndroid_HandleInputEvent(x, y, event_action);

            if (io.WantCaptureMouse)
                return true;
        } else if (env->IsInstanceOf(inputEvent, KeyEventCls))
        {
            ImGuiIO &io = ImGui::GetIO();
            if (!KeyEvent_getAction)
                KeyEvent_getAction = env->GetMethodID(KeyEventCls, OBFUSTR("getAction"),
                                                      OBFUSTR("()I"));
            if (env->CallIntMethod(inputEvent, KeyEvent_getAction) == 0)
            {
                if (!KeyEvent_getKeyCode)
                    KeyEvent_getKeyCode = env->GetMethodID(KeyEventCls, OBFUSTR("getKeyCode"),
                                                           OBFUSTR("()I"));
                if (!KeyEvent_getUnicodeChar)
                    KeyEvent_getUnicodeChar = env->GetMethodID(KeyEventCls,
                                                               OBFUSTR("getUnicodeChar"),
                                                               OBFUSTR("(I)I"));
                if (!KeyEvent_getMetaState)
                    KeyEvent_getMetaState = env->GetMethodID(KeyEventCls, OBFUSTR("getMetaState"),
                                                             OBFUSTR("()I"));
                int KeyCode = env->CallIntMethod(inputEvent, KeyEvent_getKeyCode);
                io.AddKeyEvent(ImGui_ImplAndroid_KeyCodeToImGuiKey(KeyCode), true);
                io.AddInputCharacter(env->CallIntMethod(inputEvent, KeyEvent_getUnicodeChar,env->CallIntMethod(inputEvent,KeyEvent_getMetaState)));
            }
            if (env->CallIntMethod(inputEvent, KeyEvent_getAction) == 1)
            {
                if (!KeyEvent_getKeyCode)
                    KeyEvent_getKeyCode = env->GetMethodID(KeyEventCls, OBFUSTR("getKeyCode"),
                                                           OBFUSTR("()I"));
                int KeyCode = env->CallIntMethod(inputEvent, KeyEvent_getKeyCode);
                io.AddKeyEvent(ImGui_ImplAndroid_KeyCodeToImGuiKey(KeyCode), false);
            }
        }
    }
    return orignativeInjectEvent(env, thiz, inputEvent);
}

HOOKDEF(void, nativeUnitySendMessage, JNIEnv *env, jclass thiz, jstring jstr, jstring jstr2, jbyteArray bArr) {
    // code to log each shit
    jboolean isCopy1, isCopy2, isCopy3;
    const char* str1 = env->GetStringUTFChars(jstr, &isCopy1);
    const char* str2 = env->GetStringUTFChars(jstr2, &isCopy2);
    jbyte* b = env->GetByteArrayElements(bArr, &isCopy3);
    // LOGW("Called UnitySendMessage: %s, %s, %s", str1, str2, (char*)b);
    orignativeUnitySendMessage(env, thiz, jstr, jstr2, bArr);
}