#include "Pattern.h"

void** Pattern::FindInternal(Module_t mod, std::vector<int> patternBytes) // csgo simple paste
{
    const PIMAGE_NT_HEADERS ntHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>(mod.Base + mod.DosHeaders->e_lfanew);

    auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfCode;
    auto scanBytes = reinterpret_cast<std::uint8_t*>(mod.Base + ntHeaders->OptionalHeader.BaseOfCode);

    auto s = patternBytes.size();
    auto d = patternBytes.data();

    for (auto i = 0ul; i < sizeOfImage - s; ++i) {
        bool found = true;
        for (auto j = 0ul; j < s; ++j) {
            if (scanBytes[i + j] != d[j] && d[j] != -1) {
                found = false;
                break;
            }
        }
        if (found) {
            return reinterpret_cast<void**>(&scanBytes[i]);
        }
    }

    return 0x0;
}