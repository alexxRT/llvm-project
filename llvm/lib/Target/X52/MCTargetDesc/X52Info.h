#ifndef LLVM_LIB_TARGET_X52_MCTARGETDESC_X52INFO_H
#define LLVM_LIB_TARGET_X52_MCTARGETDESC_X52INFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace X52Op {
    enum OperandType : unsigned {
        OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
    };
} // namespace X52Op

} // end namespace llvm

#endif