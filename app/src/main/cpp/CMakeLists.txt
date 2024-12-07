cmake_minimum_required(VERSION 3.4.1)

project(stardust)

aux_source_directory(xdl xdl-src)

add_library(
        stardust
        SHARED
        Stardust.cpp
        Include/touch_bnm.cpp
        Include/guid.cpp
        Include/ByNameModding/BNM.cpp
        ImGui/imgui.cpp
        ImGui/imgui_draw.cpp
        ImGui/imgui_demo.cpp
        ImGui/imgui_widgets.cpp
        ImGui/imgui_tables.cpp
        ImGui/imgui_stdlib.cpp
        ImGui/user_interface.cpp
        ImGui/backends/imgui_impl_opengl3.cpp
        ImGui/backends/imgui_impl_android.cpp
        Include/KittyMemory/KittyArm64.cpp
        Include/KittyMemory/KittyMemory.cpp
        Include/KittyMemory/KittyScanner.cpp
        Include/KittyMemory/KittyUtils.cpp
        Include/KittyMemory/MemoryBackup.cpp
        Include/KittyMemory/MemoryPatch.cpp
        ${xdl-src}
        )

include_directories(xdl/include)
include_directories(KittyMemory)
include_directories(Include)
include_directories(Includes)
include_directories(ImGui)
include_directories(ImGui/backends)

set(DOBBY_LIB ${CMAKE_CURRENT_SOURCE_DIR}/libs/${CMAKE_ANDROID_ARCH_ABI}/libdobby.a)
set(CURL_LIB ${CMAKE_CURRENT_SOURCE_DIR}/libs/${CMAKE_ANDROID_ARCH_ABI}/libcurl.a)
set(KITTY_LIB ${CMAKE_CURRENT_SOURCE_DIR}/Include/KittyMemory/Deps/Keystone/libs-android/${CMAKE_ANDROID_ARCH_ABI}/libkeystone.a)

find_library(log-lib log)
find_library(egl EGL)
find_library(android android)
find_library(GLESV2_LIB GLESv2)
find_library(LZ_LIB z)
if (${ANDROID_PLATFORM_LEVEL} LESS 12)
    message(FATAL_ERROR "OpenGL 2 is not supported before API level 11 /
                      (currently using ${ANDROID_PLATFORM_LEVEL}).")
    return()
elseif (${ANDROID_PLATFORM_LEVEL} LESS 18)
    add_definitions("-DDYNAMIC_ES3")
    set(GL3STUB_SRC gl3stub.c)
    set(OPENGL_LIB GLESv2)
else ()
    set(OPENGL_LIB GLESv3)
endif (${ANDROID_PLATFORM_LEVEL} LESS 12)

target_link_libraries(
        stardust
        log
        ${KITTY_LIB}
        ${DOBBY_LIB}
        ${CURL_LIB}
        ${OPENGL_LIB}
        ${GLESV2_LIB}
        ${android}
        ${egl}
        ${LZ_LIB}
        )