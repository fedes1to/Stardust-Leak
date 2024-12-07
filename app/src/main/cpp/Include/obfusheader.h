#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*
obfusheader.h is a set of compile-time obfuscation tools for C++14 and newer only. Supported:
string literal, decimal, method call obfuscation.

port to C++11, (in question)
support pure C DONE

This is LITERALLY BETTER THEN OLLVM <- FALSE !

🧊 If you want to skid this, at least don't remove this text cause this took a lot of time to make
🧊 Made by github.com/ac3ss0r 🧊
*/

#define Seed ((__TIME__[7] - '0') * 1  + (__TIME__[6] - '0') * 10  + \
              (__TIME__[4] - '0') * 60   + (__TIME__[3] - '0') * 600 + \
              (__TIME__[1] - '0') * 3600 + (__TIME__[0] - '0') * 36000)
#define RandomNumber(Min, Max) (Min + (Seed % (Max - Min + 1)))

/*
Macroses here  🧊

- Note that OBFUSCALL supports Linux/Android only and only works with exported methods (including any libs)
- Also OBFUSINT/OBFUSLONG supports similar types and booleans but also forces the compiler to generate aditional garbage funcs on arm64 for error handling
*/

#define OBFUSTR_KEY(str, key) (char*)[]() -> decryptor<sizeof(str)/sizeof(str[0]), key>& { \
		constexpr auto len = sizeof(str)/sizeof(str[0]); \
		constexpr auto data = encrypted_data<len, key>(str); \
		thread_local auto decrypted = decryptor<len, key>(data); \
		return decrypted; \
	}()
#define OBFUSTR(str) (OBFUSTR_KEY(str, (char)RandomNumber(1, 255)))

#define OBFUSINT_BASE(val, base) ((int)str2dec(OBFUSTR(#val), base))
#define OBFUSLONG_BASE(val, base) (str2dec(OBFUSTR(#val), base))
#define OBFUSINT(val) OBFUSINT_BASE(val, 10)
#define OBFUSLONG(val) OBFUSLONG_BASE(val, 10)
#define OBFUSPTR(hex) (str2ptr(OBFUSTR(#hex)))

// call obfuscation is different on linux and windows
#if defined(__linux__) || defined(__ANDROID__)
#include <dlfcn.h>
#define OBFUSCALL(mtd, def) ((def)(dlsym(RTLD_DEFAULT, OBFUSTR(mtd))))
#elif _WIN32
// TODO add winapi impl
#endif

// templates for encryption 🧊

template <size_t N, char key>
class encrypted_data {
public:
    constexpr encrypted_data(const char* str) {
        for (int i = 0; i < N; i++)
            data[i] = str[i] ^ (key + i);
    }

    constexpr const char * get() const {
        return &data[0];
    }

    char data[N] {};
};

template <size_t N, char key>
class decryptor {
public:
    decryptor(const encrypted_data<N, key>& data) {
        for (int i = 0; i < N; i++)
            m_data[i] = data.get()[i];
    }

    ~decryptor() {
        for (int i = 0; i < N; i++)
            m_data[i] = NULL;
    }

    operator char*() {
        if (!decrypted) {
            for (int i = 0; i < N; i++)
                m_data[i] = m_data[i] ^ (key + i);
        }
        decrypted = true;
        return m_data;
    }

    bool decrypted = false;
    char m_data[N] {};
};

// converting methods

inline long str2dec(const char * c, int base) {
    if (strcmp(c, OBFUSTR("true")) == 0)
        return 1;
    return strtol(c, NULL, base);
}

inline uintptr_t str2ptr(const char * c) {
    static_assert(sizeof(uintptr_t) == sizeof(unsigned long)
                  || sizeof(uintptr_t) == sizeof(unsigned long long),
                  "Please add string to handle conversion for this architecture.");
    // Now choose the correct function ...
    if (sizeof(uintptr_t) == sizeof(unsigned long))
        return strtoul(c, nullptr, 16);
    // All other options exhausted, sizeof(uintptr_t) == sizeof(unsigned long long))
    return strtoull(c, nullptr, 16);
}