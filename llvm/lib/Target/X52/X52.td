include "llvm/Target/Target.td"
include "X52RegisterInfo.td"
include "X52InstrInfo.td"

class Proc<string Name, list<SubtargetFeature> Features>
  : Processor<Name, NoItineraries, Features>;

 def : Proc<"generic", []>;


def X52InstrInfo : InstrInfo;
def X52 : Target {
    let InstructionSet = X52InstrInfo;
}
