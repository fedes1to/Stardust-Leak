//
// Created by lbert on 2/9/2023.
//
#ifndef ZYGISKPG_MISC_H
#define ZYGISKPG_MISC_H

#include "Dobby/dobby.h"
#include "Unity/Unity.h"
#include "KittyMemory/KittyMemory.hpp"
#include "KittyMemory/KittyScanner.hpp"
#include "KittyMemory/MemoryPatch.hpp"

bool init = false;

using KittyMemory::ProcMap;
using KittyScanner::RegisterNativeFn;

ProcMap g_il2cppBaseMap;
std::vector<ProcMap> unityMaps;

std::vector<MemoryPatch> memoryPatches;
std::vector<uint64_t> offsetVector;

std::string user, pass;

bool isEmu;

int glHeight, glWidth;

uintptr_t startAddr, libLength;

// Patching a offset with switch.
void patchOffset(uint64_t offset, std::string hexBytes, bool isOn) {

    MemoryPatch patch = MemoryPatch::createWithHex(offset, hexBytes);

    //Check if offset exists in the offsetVector
    if (std::find(offsetVector.begin(), offsetVector.end(), offset) != offsetVector.end()) {
        //LOGE(OBFUSCATE("Already exists"));
        std::vector<uint64_t>::iterator itr = std::find(offsetVector.begin(), offsetVector.end(), offset);
        patch = memoryPatches[std::distance(offsetVector.begin(), itr)]; //Get index of memoryPatches vector
    } else {
        memoryPatches.push_back(patch);
        offsetVector.push_back(offset);
        //LOGI(OBFUSCATE("Added"));
    }

    if (!patch.isValid()) {
        return;
    }
    if (isOn && patch.get_CurrBytes() == patch.get_OrigBytes()) {
        patch.Modify();
    } else if (!isOn && patch.get_CurrBytes() != patch.get_OrigBytes()) {
        patch.Restore();
    }
}

uintptr_t string2Offset(const char *c) {
    int base = 16;
    // See if this function catches all possibilities.
    // If it doesn't, the function would have to be amended
    // whenever you add a combination of architecture and
    // compiler that is not yet addressed.
    static_assert(sizeof(uintptr_t) == sizeof(unsigned long)
                  || sizeof(uintptr_t) == sizeof(unsigned long long),
                  "Please add string to handle conversion for this architecture.");

    // Now choose the correct function ...
    if (sizeof(uintptr_t) == sizeof(unsigned long)) {
        return strtoul(c, nullptr, base);
    }

    // All other options exhausted, sizeof(uintptr_t) == sizeof(unsigned long long))
    return strtoull(c, nullptr, base);
}

// implemented by acessor
// deprecated, use monoString->getString();
std::string read_mono_string(char * ptr) {
    /* the length of a mono string (offset 16 bytes)
     string in utf16 starts at 20-th byte */
    int length = *(int*)(ptr + 16);
    // the pointer to the start of the hwid (offset 20 bytes)
    char16_t * start = (char16_t*)(ptr + 20);
    // ascii string to log
    std::string str(length, ' ');
    //char* str = (char*)malloc(length * 2 + 1);
    for (int i = 0; i < length; i++) {
        if (start[i] <= 0x7f)
            str[i] = start[i];
        else str[i] = '?';
    }
    //str[length-1] = '\0';
    return str;
}

template<typename T>
inline T GetAssemblyField(const char* __namespace, const char* __class, const char* __field) {
    return GetStaticField<T>(il2cpp_class_from_name(LibImages.AssemblyCSharp, __namespace, __class), __field);
}

#define CreateIl2cppString(str) ((il2cppString*)il2cpp_string_new(str))
#define GetClass_API(img, namespaze, name) ((Il2CppClass*)il2cpp_class_from_name(img, namespaze, name))
#define GetType_API(img, namespaze, name) ((Il2CppType*)il2cpp_class_get_type(GetClass_API(img, namespaze, name)))

#define HOOK(offset, ptr, orig) DobbyHook((void *)(g_il2cppBaseMap.startAddress + string2Offset(OBFUSTR(offset))), (void *)ptr, (void **)&orig)
#define HOOKD(offset, func) DobbyHook((void *)(g_il2cppBaseMap.startAddress + string2Offset(OBFUSTR(offset))), (void *)func, (void **)&old_##func)
#define HOOK_IL2CPP(namespaze, klass, methodname, argscount, func) DobbyHook((void*)GetMethodPointer(il2cpp_class_from_name(FindImage(namespaze, klass), namespaze, klass), methodname, argscount), (void *)func, (void **)&old_##func)
#define PATCH(offset, hex) patchOffset(g_il2cppBaseMap.startAddress + string2Offset(OBFUSTR(offset)), OBFUSTR(hex), true)
#define PATCH_IL2CPP(absolute, hex) patchOffset(absolute, OBFUSTR(hex), true)
#define PATCH_SWITCH(offset, hex, boolean) patchOffset(g_il2cppBaseMap.startAddress + string2Offset(OBFUSTR(offset)), OBFUSTR(hex), boolean)
#define PATCH_SWITCH_IL2CPP(absolute, hex, boolean) patchOffset(absolute, OBFUSTR(hex), boolean)
#define RESTORE(offset) patchOffset(string2Offset(OBFUSCATE(offset)), "", false)
#define OFFSET(offset) (g_il2cppBaseMap.startAddress + string2Offset(OBFUSTR(offset)))
#define OFFSET_IL2CPP(namespaze, klass, methodname, argscount) GetMethodPointer(il2cpp_class_from_name(FindImage(namespaze, klass), namespaze, klass), methodname, argscount)

#endif //ZYGISKPG_MISC_H