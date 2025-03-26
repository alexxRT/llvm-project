add_llvm_component_group(X52)

set (LLVM_TARGET_DEFINITIONS X52.td)

tablegen(LLVM X52GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM X52GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM X52GenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM X52GenMCPseudoLowering.inc -gen-pseudo-lowering)

add_public_tablegen_target(X52CommonTableGen)

add_llvm_target(X52CodeGen
  X52TargetMachine.cpp
  X52RegisterInfo.cpp
  X52InstrInfo.cpp
  X52Subtarget.cpp
  X52AsmPrinter.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  MC
  Support
  Target
  X52Info
  AsmPrinter

  ADD_TO_COMPONENT
  X52
)

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
