//
// Created by Yaroslav on 16.10.2020.
//

#include "Memory.h"

void Memory::LoadData(uint16_t address, const data &dat)
{
    MemUnion res{dat};
    for (int i = address, k = 0; i < address + sizeof(res); ++i, ++k) memory[i] = res.bytes[k];
}

data Memory::GetData(uint16_t address) noexcept
{
    MemUnion res{};
    for (int i = address, k = 0; i < address + sizeof(res); ++i, ++k) res.bytes[k] = memory[i];
    return res.data_;
}

void Memory::LoadData(uint16_t a, MemUnion dat, int n)
{
    for (int i = a, k = 0; i < a + n; ++i, ++k)
        memory[i] = dat.bytes[k];
}
