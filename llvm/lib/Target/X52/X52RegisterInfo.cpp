#include "X52RegisterInfo.h"
#include "X52FrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_ENUM
#define GET_REGINFO_TARGET_DESC
#include "X52GenRegisterInfo.inc"

X52RegisterInfo::X52RegisterInfo() : X52GenRegisterInfo(X52::R0) {
}

const MCPhysReg* X52RegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
    return CSR_X52_SaveList;
}

BitVector X52RegisterInfo::getReservedRegs(const MachineFunction &MF) const {
    X52FrameLowering const *TFI = getFrameLowering(MF);

    BitVector Reserved(getNumRegs());
    Reserved.set(X52::R1);

    if (TFI->hasFP(MF)) {
        Reserved.set(X52::R2);
    }
    return Reserved;
}

bool X52RegisterInfo::requiresRegisterScavenging(const MachineFunction &MF) const {
    return false;
}

bool X52RegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                        int SPAdj, unsigned FIOperandNum,
                                        RegScavenger *RS) const {
    assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

    MachineInstr &MI = *II;
    MachineFunction &MF = *MI.getParent()->getParent();
    DebugLoc DL = MI.getDebugLoc();

    int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
    Register FrameReg;
    int Offset = getFrameLowering(MF)->getFrameIndexReference(MF, FrameIndex, FrameReg)
                .getFixed();
    Offset += MI.getOperand(FIOperandNum + 1).getImm();

    if (!isInt<16>(Offset)) {
        llvm_unreachable("");
    }

    MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
    MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
    return false;
}

Register X52RegisterInfo::getFrameRegister(const MachineFunction &MF) const {
    const TargetFrameLowering *TFI = getFrameLowering(MF);
    return TFI->hasFP(MF) ? X52::R2 : X52::R1;
}

const uint32_t* X52RegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                    CallingConv::ID CC) const {
    return CSR_X52_RegMask;
}