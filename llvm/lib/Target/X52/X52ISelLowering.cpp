#include "X52ISelLowering.h"
#include "X52RegisterInfo.h"
#include "X52Subtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "X52-lower"

using namespace llvm;


X52TargetLowering::X52TargetLowering(const TargetMachine &TM, const X52Subtarget &STI) : TargetLowering(TM), STI(STI) {
    addRegisterClass(MVT::i32, &X52::GPRRegClass);
}

const char* X52TargetLowering::getTargetNodeName(unsigned Opcode) const {
    switch(Opcode) {
        case X52ISD::CALL:
            return "X52ISD::CALL";
        case X52ISD::RET:
            return "X52ISD::RET";
        default:
            return nullptr;
    }
}