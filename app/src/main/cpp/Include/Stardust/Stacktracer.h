#pragma once

#include "dlfcn.h"
#include "stdio.h"
#include "unwind.h"
#include "stdint.h"

#define BACKTRACE_BUFFER_SIZE 2048

struct BacktraceState {
    void** current;
    void** end;
};

static _Unwind_Reason_Code unwindCallback(struct _Unwind_Context* context, void* arg) {
    struct BacktraceState* state = (struct BacktraceState*)arg;
    uintptr_t pc = _Unwind_GetIP(context);
    if (pc) {
        if (state->current == state->end) {
            return _URC_END_OF_STACK;
        } else {
            *state->current++ = (void*)pc;
        }
    }
    return _URC_NO_REASON;
}

size_t captureBacktrace(void** buffer, size_t max) {
    struct BacktraceState state = {buffer, buffer + max};
    _Unwind_Backtrace(unwindCallback, &state);

    return state.current - buffer;
}

void printBacktrace(void** buffer, size_t count) {
    const uintptr_t lower_bound = 0x1840000;
    const uintptr_t upper_bound = 0x6500000;

    LOGD("---------- KarmaTrace ----------\n");
    for (size_t idx = 0; idx < count; ++idx) {
        const void* addr = buffer[idx];
        const char* symbol = "";
        const char* libname = "";

        Dl_info info;
        if (dladdr(addr, &info)) {
            if (info.dli_sname) {
                symbol = info.dli_sname;
            }
            if (info.dli_fname) {
                libname = info.dli_fname;
            }
        }

        uintptr_t addr_value = reinterpret_cast<uintptr_t>(addr);
        uintptr_t offset_addr = addr_value - startAddr;

        if (std::string(libname).find("libil2cpp.so") != std::string::npos && 
            offset_addr >= lower_bound && offset_addr <= upper_bound) {
            LOGD("%-3zd %*p %s\n", idx, int(2 + sizeof(void*) * 2), (void*)offset_addr, symbol);
        }
    }
    LOGD("--------------------------------");
}

void backtrace() {
    void* buffer[BACKTRACE_BUFFER_SIZE];
    size_t count = captureBacktrace(buffer, BACKTRACE_BUFFER_SIZE);

    printBacktrace(buffer, count);
}