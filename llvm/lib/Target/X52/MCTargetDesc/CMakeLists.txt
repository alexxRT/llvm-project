add_llvm_component_library(LLVMX52Desc
  X52MCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  Support
  X52Info

  ADD_TO_COMPONENT
  X52
)
