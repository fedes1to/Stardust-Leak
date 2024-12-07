#define DO_API(r, n, p) r (*n) p

#include "il2cpp-api-functions.h"
#include "../Hook.h"

#undef DO_API

#define DEFAULTS_INIT(field, ns, n) CSharpTypeClass.field = il2cpp_class_from_name(LibImages.Corlib, ns, n);

bool il2cppApiLoaded = false;
long il2cpp_base = 0;
Il2CppDomain* domain;
size_t libCount;
const Il2CppAssembly** libs;

struct CSharpTypeClass {
    Il2CppClass* Byte;
    Il2CppClass* Boolean;
    Il2CppClass* Int16;
    Il2CppClass* Int32;
    Il2CppClass* Int64;
    Il2CppClass* Float;
    Il2CppClass* Double;
    Il2CppClass* Char;
    Il2CppClass* String;
    Il2CppClass* Object;
    Il2CppClass* Array;
} CSharpTypeClass;

struct LibImages {
    const Il2CppImage* Corlib;
    const Il2CppImage* UnityCoreModule;
	const Il2CppImage* UnityPhysicsModule;
    const Il2CppImage* AssemblyCSharp;
    const Il2CppImage* NewtonsoftJson;
} LibImages;

void init_il2cpp_api(void *handle) {
#define DO_API(r, n, p) {                      \
    n = (r (*) p) xdl_sym(handle, #n, nullptr);\
}

#include "il2cpp-api-functions.h"

#undef DO_API
}

const Il2CppImage* FindImage(const char* _namespace, const char* _class) {
    size_t size;
    auto assemblies = il2cpp_domain_get_assemblies(il2cpp_domain_get(), &size);
    for (int i = 0; i < size; ++i)
    {
        auto img = il2cpp_assembly_get_image(assemblies[i]);

        void *klass = il2cpp_class_from_name(img, _namespace, _class);
        if (klass) {
            //found correct image, return it.
            return img;
        }
    }

    LOGE("Failed to find image for class %s", _class);
    return 0;
}

// fields
template<typename T>
T GetStaticField(Il2CppClass* klass, const char* fieldName) {
    auto field = il2cpp_class_get_field_from_name(klass, fieldName);
    if (field != nullptr) {
        T var;
        il2cpp_field_static_get_value(field, &var);
        return var;
    }
    return (T)NULL;
}

uintptr_t GetFieldPtr(Il2CppClass* klass, const char* fieldName) {
    auto field = il2cpp_class_get_field_from_name(klass, fieldName);
    if (field != nullptr)
        return il2cpp_field_get_offset(field);
    return NULL;
}

template<typename T>
void SetStaticField(Il2CppClass* klass, const char* fieldName, T value) {
    auto field = il2cpp_class_get_field_from_name(klass, fieldName);
    if (field != nullptr) {
        il2cpp_field_static_set_value(field, &value);
    }
}

// methods
uintptr_t GetMethodPointer(Il2CppClass* klass, const char* name, int argsCount) {
    auto field = il2cpp_class_get_method_from_name(klass, name, argsCount);
    if (field != nullptr) {
        return (uintptr_t)field->methodPointer;
    }
	LOGE("Couldn't find method %s.", name);
    return NULL;
}

template<typename T>
T UnboxIl2cppObject(Il2CppObject* obj) {
    return *static_cast<T*>(il2cpp_object_unbox(obj));
}