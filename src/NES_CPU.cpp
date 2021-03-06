//
// Created by protobit on 21/08/2020.
//

#include "NES_CPU.hpp"

NES_CPU::NES_CPU() {
    mem = new NES_Memory();
    stk = new NES_Stack(mem);
}

void NES_CPU::executeInstruction(uint32_t instruction) {
    getInstruction(utils::getBits<uint32_t, uint8_t>(instruction,8,0));
    r_ProgramCounter++;
}

void NES_CPU::startExec() {
    r_ProgramCounter = mem->at(0xFFFC)<<8&mem->at(0xFFFD);
}
