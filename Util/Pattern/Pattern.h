#pragma once

#include "../Memory/Memory.h"

#include <string>
#include <string_view>
#include <vector>
#include <iostream>

namespace Pattern
{
    constexpr std::vector<int> IdaToBytes(std::string idaBytes) // csgo simple ahh
    {
        auto bytes = std::vector<int>{};
        auto start = idaBytes.data();
        auto end = start + idaBytes.size();

        for (auto current = start; current < end; ++current) {
            if (*current == '?') {
                ++current;
                if (*current == '?')
                    ++current;
                bytes.push_back(-1);
            }
            else {
                bytes.push_back(strtoul(current, &current, 16));
            }
        }

        return bytes;
    }

    void** FindInternal(Module_t mod, std::vector<int> patternBytes);

    template<typename T = DWORD>
    constexpr T Find(Module_t mod, const char* pattern)
    {
        return reinterpret_cast<T>(FindInternal(mod, IdaToBytes(pattern)));
    }
}