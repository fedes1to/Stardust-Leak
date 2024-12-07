#define DEBUG_WEBSOCKET

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cinttypes>

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <limits>
#include <iostream>
#include <chrono>
#include <filesystem>
#include <unordered_set>

#include <unistd.h>
#include <sys/system_properties.h>
#include <dlfcn.h>
#include <dirent.h>
#include <sys/stat.h>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <android/input.h>
#include <android/keycodes.h>

#include "xdl/include/xdl.h"
#include "il2cpp/il2cpp-types.h"
#include "il2cpp/il2cpp-utils.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_internal.h"
#include "ImGui/backends/imgui_impl_opengl3.h"
#include "ImGui/backends/imgui_impl_android.h"
#include "Includes/Dobby/dobby.h"
#include "Include/obfusheader.h"
#include "Game/Auth.h"
#include "Misc.h"
#include "Include/json.hpp"
#include "Include/JNIStuff.h"
#include "Include/touch_bnm.h"
#include "Include/Roboto-Regular.h"
#include "Icons/IconsKenney.h"
#include "Stardust/Stacktracer.h"
#include "console.h"
#include "Unity/Unity.h"
#include "Hook.h"
#include "Unity/Quaternion.h"
#include "Unity/Rect.h"
#include "Stardust/Patch.h"
#include "Drawing.h"
#include "Lists.h"
#include "Include/Stardust/Config.h"
#include "Features/Websocket.h"
#include "Game/Pointers.h"
#include "Game/Functions.h"
#include "Game/Patches.h"
#include "Game/Hooks.h"
#include "Menu.h"
#include "Features/SceneExplorer/HierarchyView.h"
#include "Features/SceneExplorer/InspectorView.h"

const char * sensitiveStrings[] = {
        "/su", "superuser", "magisk", "topjohnwu",
        "luckypatcher", "chelpus", "Kinguser",
        "supersu", "busybox", "kernelsu", "daemonsu",
        "/proc/self/attr/prev", "bstfolder", "libmaa.so"
};

HOOKDEF(void*, access_hook, const char *filename, int mode) {
    for (int i = 0; i < IM_ARRAYSIZE(sensitiveStrings); i++) {
        if (strstr(filename, sensitiveStrings[i]))
            return origaccess_hook("very_real_file", mode);
    }
    return origaccess_hook(filename, mode);
}

HOOKDEF(FILE*, fopen_hook, const char *fname, const char *mode) {
    for (int i = 0; i < IM_ARRAYSIZE(sensitiveStrings); i++) {
        if (strstr(fname, sensitiveStrings[i]))
            return origfopen_hook("very_real_file", mode);
    }
    return origfopen_hook(fname, mode);
}

void SetupImgui() {
    IMGUI_CHECKVERSION();
    CreateContext();
    ImGuiIO &io = GetIO();
    io.DisplaySize = ImVec2((float) glWidth, (float) glHeight);
    ImGui_ImplOpenGL3_Init("#version 100");
    CustomImGuiStyle();
    ImFontConfig font_config;
    font_config.PixelSnapH = false;
    font_config.OversampleH = 5;
    font_config.OversampleV = 5;
    font_config.RasterizerMultiply = 1.2f;

    static const ImWchar ranges[] =
            {
                    0x0020, 0x00FF, // Basic Latin + Latin Supplement
                    0x0400, 0x052F, // Cyrillic + Cyrillic Supplement
                    0x2DE0, 0x2DFF, // Cyrillic Extended-A
                    0xA640, 0xA69F, // Cyrillic Extended-B
                    0xE000, 0xE226, // icons
                    0,
            };

    font_config.GlyphRanges = ranges;

    GetStyle().ScaleAllSizes(4.0f);
    io.Fonts->AddFontFromMemoryTTF(Roboto_Regular, 26, 26.0f, &font_config, ranges);

    static const ImWchar icons_ranges[] = { ICON_MIN_KI, ICON_MAX_16_KI, 0 };
    ImFontConfig icons_config;
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.GlyphMinAdvanceX = 56;
    io.Fonts->AddFontFromMemoryCompressedBase85TTF( GeticonFont_compressed_data_base85(), 56, &icons_config, icons_ranges );
}

bool iskeyboardopen = false;

EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);

    if (!init) {
        SetupImgui();
        init = true;
    }

    ImGuiIO &io = GetIO();
    if (io.WantTextInput && !iskeyboardopen && !isEmu) {
        displayKeyboard();
        iskeyboardopen = true;
    } else if (!io.WantTextInput && iskeyboardopen && !isEmu) {
        displayKeyboard();
        iskeyboardopen = false;
    }

    ImGui_ImplOpenGL3_NewFrame();
    NewFrame();

    if (isVerifed) {
        NewDrawMenu();
        DrawESP();
        if (showing_term)
            appConsole.Draw("Stardust Console", nullptr);
		if (isSceneExplorerOpen)
		{
			sceneExplorer::hierarchyView::Draw();
			sceneExplorer::inspectorView::Draw();
		}
    }
    else {
        DrawLoginPanel();
    }

    EndFrame();
    Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    ImGui_ImplOpenGL3_RenderDrawData(GetDrawData());

    if (isVerifed)
        Patches();

    return old_eglSwapBuffers(dpy, surface);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void * reserved)
{
    JNIEnv* env;
    // updated input method?
    jvm = vm;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);

    UnityPlayer_cls = env->FindClass(OBFUSTR("com/unity3d/player/UnityPlayer"));
    UnityPlayer_CurrentActivity_fid = env->GetStaticFieldID(UnityPlayer_cls,
                                                            OBFUSTR("currentActivity"),
                                                            OBFUSTR("Landroid/app/Activity;"));

    guid = xg::newGuid(env).str();
    guid.erase(std::remove(guid.begin(), guid.end(), '-'), guid.end());
    hwid = get_hardware_id(env);

    int ret;
    pthread_t ntid;
    if ((ret = pthread_create(&ntid, nullptr, hack_thread, nullptr)))
        LOGE("can't create thread: %s\n", strerror(ret));
    return JNI_VERSION_1_6;
}

void *hack_thread(void *) {
    do {
        sleep(1);
        g_il2cppBaseMap = KittyMemory::getElfBaseMap(OBFUSTR("libil2cpp.so"));
    } while (!g_il2cppBaseMap.isValid());

    do {
        unityMaps = KittyMemory::getMapsEndWith(OBFUSTR("libunity.so"));
    } while (unityMaps.empty());

    std::ifstream file(OBFUSTR("/storage/emulated/0/Android/data/com.pixel.gun3d/account.txt"));

    bypassHooks();

    libLength = g_il2cppBaseMap.length;
    startAddr = g_il2cppBaseMap.startAddress;

    void *accessPtr = DobbySymbolResolver(OBFUSTR("libc.so"), OBFUSTR("access")),
            *fopenPtr = DobbySymbolResolver(OBFUSTR("libc.so"), OBFUSTR("fopen"));
    DobbyHook(accessPtr, (void *) newaccess_hook, (void **) &origaccess_hook);
    DobbyHook(fopenPtr, (void *) newfopen_hook, (void **) &origfopen_hook);

    RegisterNativeFn injecteventptr = KittyScanner::findRegisterNativeFn(unityMaps, OBFUSTR("nativeInjectEvent"));

    // will be needed next update

    RegisterNativeFn sendmessageptr = KittyScanner::findRegisterNativeFn(unityMaps, OBFUSTR("nativeUnitySendMessage"));

    if (sendmessageptr.isValid()) {
        DobbyHook(sendmessageptr.fnPtr, (void *) newnativeUnitySendMessage, (void **) &orignativeUnitySendMessage);
    } else {
        LOGW("sendmessageptr isnt valid, skill issue");
    }


    if (injecteventptr.isValid()) {
        DobbyHook(injecteventptr.fnPtr, (void *) newnativeInjectEvent, (void **) &orignativeInjectEvent);
    } else {
        Input::Attach();
        Input::setEmulator();
        Input::Setup();
        isEmu = true;
    }

    auto il2cppHandle = xdl_open(OBFUSTR("libil2cpp.so"), 0);

    init_il2cpp_api(il2cppHandle);
    if (il2cpp_domain_get_assemblies != nullptr) {

        Dl_info dlInfo;
        if (dladdr((void *) il2cpp_domain_get_assemblies, &dlInfo)) {
            il2cpp_base = reinterpret_cast<uint64_t>(dlInfo.dli_fbase);
        }

        while (!il2cpp_is_vm_thread(nullptr)) {
            sleep(1);
        }

        domain = il2cpp_domain_get();
        il2cpp_thread_attach(domain);
        LibImages.Corlib = il2cpp_get_corlib();
        libs = il2cpp_domain_get_assemblies(domain, &libCount);

        for (int i = 0; i < libCount; ++i) {
            const Il2CppImage *img = il2cpp_assembly_get_image(libs[i]);
            const char *img_name = il2cpp_image_get_name(img);
            if (strcmp(img_name, OBFUSTR("Assembly-CSharp.dll")) == 0) {
                LibImages.AssemblyCSharp = img;
            }
            if (strcmp(img_name, OBFUSTR("UnityEngine.CoreModule.dll")) == 0) {
                LibImages.UnityCoreModule = img;
            }
			if (strcmp(img_name, OBFUSTR("UnityEngine.PhysicsModule.dll")) == 0) {
				LibImages.UnityPhysicsModule = img;
			}
        }

        DEFAULTS_INIT(Byte, "System", "Byte");
        DEFAULTS_INIT(Boolean, "System", "Boolean");
        DEFAULTS_INIT(Int16, "System", "Int16");
        DEFAULTS_INIT(Int32, "System", "Int32");
        DEFAULTS_INIT(Int64, "System", "Int64");
        DEFAULTS_INIT(Float, "System", "Single");
        DEFAULTS_INIT(Double, "System", "Double");
        DEFAULTS_INIT(Char, "System", "Char");
        DEFAULTS_INIT(String, "System", "String");
        DEFAULTS_INIT(Object, "System", "Object");
        DEFAULTS_INIT(Array, "System", "Array");

    } else {
        LOGI("fail initialize to il2cpp.");
    }

    if (file.is_open()) {
        std::ostringstream sstr;
        sstr << file.rdbuf();
        std::string s = sstr.str();
        std::string contents = xor_shift(s, OBFUSTR("ZhEbCs6DDHLwIGA4"));
        auto j = nlohmann::json::parse(contents);
        isVerifed = login(j[OBFUSTR("username")], j[OBFUSTR("password")]); // NEW AUTH METHOD
    }

    std::ifstream f(OBFUSTR("/storage/emulated/0/Android/data/com.pixel.gun3d/acc.txt"));
    if (f.is_open()) {
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(f, line)) {
            lines.push_back(line);
        }
        std::string lcluser = lines[0];
        std::string lclpwd = lines[1];

        lcluser.erase(std::remove(lcluser.begin(), lcluser.end(), '\r'), lcluser.end());
        lcluser.erase(std::remove(lcluser.begin(), lcluser.end(), '\n'), lcluser.end());

        lclpwd.erase(std::remove(lclpwd.begin(), lclpwd.end(), '\r'), lclpwd.end());
        lclpwd.erase(std::remove(lclpwd.begin(), lclpwd.end(), '\n'), lclpwd.end());

        isVerifed = login(lcluser, lclpwd);
        if (isVerifed) {
            std::remove(OBFUSTR("/storage/emulated/0/Android/data/com.pixel.gun3d/acc.txt"));
            nlohmann::json j;
            j[OBFUSTR("username")] = lcluser;
            j[OBFUSTR("password")] = lclpwd;
            std::string s = j.dump();
            std::string contents = xor_shift(s, OBFUSTR("ZhEbCs6DDHLwIGA4"));
            std::ofstream out(
                    OBFUSTR("/storage/emulated/0/Android/data/com.pixel.gun3d/account.txt"));
            out << contents;
            out.close();
        }
    }

    if (isVerifed) {
        Pointers();
        Hooks();
    } else {
        Pointers2(); // non auth pointers
        Hooks2(); // non auth hooks
    }

    void *eglSwapBuffers = DobbySymbolResolver(OBFUSTR("libEGL.so"), OBFUSTR("eglSwapBuffers"));
    DobbyHook(eglSwapBuffers, (void *) hook_eglSwapBuffers, (void **) &old_eglSwapBuffers);

    if (isEmu)
        Input::Detach();

    LOGW("Draw Done!");

    return nullptr;
}
