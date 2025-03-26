include "llvm/Target/Target.td"
include "X52RegisterInfo.td"
include "X52InstrInfo.td"


def X52InstrInfo : InstrInfo;
def X52 : Target {
    let InstructionSet = X52InstrInfo;
}
