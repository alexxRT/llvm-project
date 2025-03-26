#ifndef LLVM_LIB_TARGET_X52_X52_H
#define LLVM_LIB_TARGET_X52_X52_H


#include "MCTargetDesc/X52MCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
    class X52TargetMachine;
    class FunctionPass;

    FunctionPass* createX52ISelDag(X52TargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_X52_X52_H