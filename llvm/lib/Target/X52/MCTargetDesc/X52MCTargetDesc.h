#ifndef LLVM_LIB_TARGET_X52_MCTARGETDESC_X52MCTARGETDESC_H
#define LLVM_LIB_TARGET_X52_MCTARGETDESC_X52MCTARGETDESC_H


#define GET_REGINFO_ENUM
#include "X52GenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "X52GenInstrInfo.inc"

#include <memory>
namespace llvm {
    class MCCodeEmitter;
    class MCContext;
    class MCInstrInfo;
    class MCAsmBackend;
    class MCObjectTargetWriter;
    class MCRegisterInfo;
    class MCSubtargetInfo;
    class MCTargetOptions;
    class Target;

    MCCodeEmitter* createX52MCCodeEmitter(const MCInstrInfo& MCII, MCContext& Ctx);
    MCAsmBackend* createX52AsmBackend(const Target &T, const MCSubtargetInfo &STI,
        const MCRegisterInfo &MRI,
        const MCTargetOptions &Options);

    std::unique_ptr<MCObjectTargetWriter> createX52ELFObjectWriter(bool Is64Bit,
            uint8_t OSABI);
}


#endif // LLVM_LIB_TARGET_X52_MCTARGETDESC_X52MCTARGETDESC_H
