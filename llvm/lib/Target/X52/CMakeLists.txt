add_llvm_component_group(X52)

add_llvm_target(X52CodeGen
  X52TargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  X52Info

  ADD_TO_COMPONENT
  X52
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
