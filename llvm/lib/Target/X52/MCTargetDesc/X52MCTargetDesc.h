#ifndef LLVM_LIB_TARGET_X52_MCTARGETDESC_X52MCTARGETDESC_H
#define LLVM_LIB_TARGET_X52_MCTARGETDESC_X52MCTARGETDESC_H


#define GET_REGINFO_ENUM
#include "X52GenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "X52GenInstrInfo.inc"

namespace llvm {
    class MCCodeEmitter;
    class MCContext;
    class MCInstrInfo;

    MCCodeEmitter* createX52MCCodeEmitter(const MCInstrInfo& MCII, MCContext& Ctx);
}


#endif // LLVM_LIB_TARGET_X52_MCTARGETDESC_X52MCTARGETDESC_H
