//
// Created by Yaroslav on 16.10.2020.
//

#include <cstring>
#include "Memory.h"

void Memory::LoadData(uint16_t address, const data &dat)
{
    MemUnion res{dat};
    std::memcpy(&memory[address], res.bytes, 4);
}

data Memory::GetData(uint16_t address) noexcept
{
    MemUnion res{};
    std::memcpy(&res.bytes, &memory[address], 4);
    return res.data_;
}

void Memory::LoadData(uint16_t address, MemUnion dat, int n)
{
    std::memcpy(&memory[address], dat.bytes, 4);
}
