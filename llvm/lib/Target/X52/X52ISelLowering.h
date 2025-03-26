#ifndef LLVM_LIB_TARGET_X52_X52ISELLOWERING_H
#define LLVM_LIB_TARGET_X52_X52ISELLOWERING_H

#include "X52.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class X52Subtarget;
class X52TargetMachine;

namespace X52ISD {

enum NodeType : unsigned {
    // Start the numbering where the builtin ops and target ops leave off.
    FIRST_NUMBER = ISD::BUILTIN_OP_END,
    RET,
    CALL,
    BR_CC,
};

} // namespace X52ISD

} // end namespace llvm

#endif // LLVM_LIB_TARGET_X52_X52ISELLOWERING_H