#ifndef LLVM_LIB_TARGET_X52_X52_H
#define LLVM_LIB_TARGET_X52_X52_H


#include "MCTargetDesc/X52MCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
    class X52TargetMachine;
    class FunctionPass;
    class SimSubtarget;
    class AsmPrinter;
    class InstructionSelector;
    class MCInst;
    class MCOperand;
    class MachineInstr;
    class MachineOperand;
    class PassRegistry;

    bool lowerX52MachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI, AsmPrinter &AP);
    bool LowerX52MachineOperandToMCOperand(const MachineOperand &MO, MCOperand &MCOp, const AsmPrinter &AP);


    FunctionPass* createX52ISelDag(X52TargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_X52_X52_H