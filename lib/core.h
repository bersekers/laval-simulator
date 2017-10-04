#ifndef SIMULATOR_CORE_H
#define SIMULATOR_CORE_H

#include <array>
#include <vector>
#include <cstdint>
#include <functional>

#include "instruction_factory.h"
#include "memory.h"
#include "opcodes.h"
#include "registers.h"
#include "settings.h"


class CoreArray;


class Core
{
public:
    Core();

    void check();

    void link(CoreArray *cores, size_t id, Memory_t *mem);

    void fetch();

    void step2();

    void execute(const InstructionBase& raw_instruction);

    void sync();

    Core(Core&) = delete;

    Core& operator=(Core&) = delete;

private:
    Registers registers;
    Memory_t *mem;

    size_t id;
    CoreArray *cores;
    InstructionFactory factory;
};


#endif //SIMULATOR_CORE_H