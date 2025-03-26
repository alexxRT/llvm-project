#ifndef LLVM_LIB_TARGET_X52_X52FRAMELOWERING_H
#define LLVM_LIB_TARGET_X52_X52FRAMELOWERING_H

#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {

class X52FrameLowering : public TargetFrameLowering {
public:
    explicit X52FrameLowering() : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(4), 0) {

    };

    /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
    /// the function.
    void emitPrologue(MachineFunction &MF,
                        MachineBasicBlock &MBB) const override {}
    void emitEpilogue(MachineFunction &MF,
                        MachineBasicBlock &MBB) const override {}

    /// hasFP - Return true if the specified function should have a dedicated
    /// frame pointer register. For most targets this is true only if the function
    /// has variable sized allocas or if frame pointer elimination is disabled.
    bool hasFPImpl(const MachineFunction &MF) const override { return false; }
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_X52_X52FRAMELOWERING_H