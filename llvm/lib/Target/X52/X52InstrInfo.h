#ifndef LLVM_LIB_TARGET_X52_X52INSTRINFO_H
#define LLVM_LIB_TARGET_X52_X52INSTRINFO_H

#include "X52RegisterInfo.h"
#include "MCTargetDesc/X52Info.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "X52GenInstrInfo.inc"

namespace llvm {

class X52Subtarget;

class X52InstrInfo : public X52GenInstrInfo {
    public:
        X52InstrInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_X52_X52INSTRINFO_H