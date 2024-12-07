#include "KittyMemory/KittyInclude.hpp"

class Patch : public MemoryPatch {
public:
    bool* value;
    std::string hexCode;
    uintptr_t offset;
    Patch(uintptr_t offset, const std::string& hexCode);
    Patch(uintptr_t offset, const std::string& hexCode, bool enabled);
    Patch(uintptr_t offset, const std::string& hexCode, bool* value);
    operator bool() { return this->value; }
    void operator=(bool* set) { this->value = set; }
    bool operator==(bool* set) { return this->value == set; }
};

template <typename T>
class Pointer;

template <typename R, typename... Args>
class Pointer<R(Args...)>
{
public:
    Pointer() = default;
    explicit Pointer(uintptr_t offset) {
        m_Function = reinterpret_cast<R(*)(Args...)>(offset);
    }

    inline Pointer& operator=(uintptr_t offset) {
        m_Function = reinterpret_cast<R(*)(Args...)>(offset);
        return *this;
    }
    inline R operator()(Args... args) {
        return m_Function(std::forward<Args>(args)...);
    }

private:
    R(*m_Function)(Args...);
};

template <typename T>
class FieldOffset
{
public:
    FieldOffset(void* instance, std::string className, std::string fieldName);
    void operator=(T set) { (T&)(*(T *) ((uint64_t) instance + m_Offset)) = set; }
    bool operator==(T set) { (T&)(*(T *) ((uint64_t) instance + m_Offset)) == set; }
    void operator()() { return (T&)(*(T *) ((uint64_t) instance + m_Offset)); }
private:
    uintptr_t m_Offset;
    void* instance;
};

template<typename T>
FieldOffset<T>::FieldOffset(void* instance, std::string className, std::string fieldName) : instance(instance) {
    std::stringstream stream(className);
    std::string segment;
    std::vector<std::string> args;

    while(std::getline(stream, segment, '.')) {
        args.push_back(segment);
    }

    if (args.size() == 1) {
        m_Offset = GetFieldPtr(il2cpp_class_from_name(LibImages.AssemblyCSharp, "", className.c_str()), fieldName.c_str());
    } else {
        m_Offset = GetFieldPtr(il2cpp_class_from_name(LibImages.AssemblyCSharp, args[0].c_str(), args[1].c_str()), fieldName.c_str());
    }
}

std::vector<Patch*> patches;

Patch::Patch(uintptr_t offset, const std::string &hexCode) : offset(offset), hexCode(hexCode) {
    value = (bool*)(false);
    patches.push_back(this); // used for refreshPatches()
}

Patch::Patch(uintptr_t offset, const std::string &hexCode, bool enabled) : offset(offset), hexCode(hexCode) {
    value = (bool*)(enabled);
    patches.push_back(this); // used for refreshPatches()
}

Patch::Patch(uintptr_t offset, const std::string& hexCode, bool* value) : offset(offset), hexCode(hexCode), value(value) {
    patches.push_back(this); // used for refreshPatches()
}

void initializePatches() {
    for (Patch *patch : patches) {
        patch->_address = startAddr + patch->offset;
        patch->_size = patch->hexCode.length() / 2;
        patch->_orig_code.resize(patch->_size);
        patch->_patch_code.resize(patch->_size);
        KittyUtils::dataFromHex(patch->hexCode, &patch->_patch_code[0]);
        KittyMemory::memRead(reinterpret_cast<const void *>(patch->_address), &patch->_orig_code[0], patch->_size);
    }
}

void refreshPatches() {
    for (Patch *patch : patches) {
        if (patch->value && patch->get_CurrBytes() == patch->get_OrigBytes()) {
            patch->Modify();
        } else if (!patch->value && patch->get_CurrBytes() != patch->get_OrigBytes()) {
            patch->Restore();
        }
    }
}