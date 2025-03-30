#include "X52Subtarget.h"

#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "X52-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "X52GenSubtargetInfo.inc"

X52Subtarget::X52Subtarget(const Triple &TT, const std::string &CPU,
                        const std::string &FS, const TargetMachine &TM)
    : X52GenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS), TLInfo(TM, *this),
      FrameLowering(*this), InstrInfo() {

    };