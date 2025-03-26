#include "X52RegisterInfo.h"
#include "X52FrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_ENUM
#define GET_REGINFO_TARGET_DESC
#include "X52GenRegisterInfo.inc"

X52RegisterInfo::X52RegisterInfo() : X52GenRegisterInfo(X52::R0) {
}