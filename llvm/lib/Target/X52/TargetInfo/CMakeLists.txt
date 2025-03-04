add_llvm_component_library(LLVMX52Info
  X52TargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  X52
  )
