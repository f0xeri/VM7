//
// Created by Yaroslav on 17.10.2020.
//

#ifndef VM7_LOADER_H
#define VM7_LOADER_H

#include <string>
#include <fstream>
#include <exception>
#include <sstream>
#include "Types.h"
#include "Processor.h"

enum prefixes
{
    ip = 's',
    cmd = 'C',
    comment = ';',
    loadAddress = 'l',
    integer = 'i',
    uinteger = 'u',
    real = 'r'
};

inline void Load(const std::string &filename, Processor &cpu) noexcept
{
    std::ifstream file(filename);

    std::string line;
    char prefix;
    command16 cmd16{};
    command32 cmd32{};
    std::stringstream ss;

    MemUnion memUnion{};
    data dat{};
    unsigned short opcode;
    unsigned short r1;
    unsigned short r2;
    unsigned short address;

    unsigned short loadAddress = 0;
    unsigned short ip = 0;

    while (std::getline(file, line))
    {
        memUnion = {};
        dat = {};
        ss.clear();
        ss.str(line);
        ss >> prefix;

        switch (prefix)
        {
            case prefixes::ip:
                ss >> ip;
                cpu.SetIP(ip);
                break;
            case prefixes::loadAddress:
                ss >> loadAddress;
                break;
            case prefixes::cmd:
                ss >> opcode;
                ss >> r1;
                ss >> r2;

                cmd16.opcode = opcode;
                cmd16.r1 = r1;
                cmd16.r2 = r2;

                if (!ss.eof())
                {
                    ss >> address;
                    cmd32.cmd = cmd16;
                    cmd32.address = address;

                    memUnion.cmd32 = cmd32;
                    cpu.memory.LoadData(loadAddress, memUnion, 1);
                }
                else
                {
                    memUnion.cmd16 = cmd16;
                    cpu.memory.LoadData(loadAddress, memUnion, 1);
                }
                loadAddress += sizeof(MemUnion);
                break;
            case prefixes::integer:
                ss >> dat.integer;
                cpu.memory.LoadData(loadAddress, dat);
                loadAddress += sizeof(dat);
                break;
            case prefixes::uinteger:
                ss >> dat.uinteger;
                cpu.memory.LoadData(loadAddress, dat);
                loadAddress += sizeof(dat);
                break;
            case prefixes::real:
                ss >> dat.real;
                cpu.memory.LoadData(loadAddress, dat);
                loadAddress += sizeof(dat);
                break;
            case prefixes::comment:
            default:
                continue;
        }
    }
}

#endif //VM7_LOADER_H
