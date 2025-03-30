add_llvm_component_library(LLVMX52Desc
  X52MCTargetDesc.cpp
  X52MCAsmInfo.cpp
  X52InstPrinter.cpp
  
  LINK_COMPONENTS
  MC
  Support
  X52Info

  ADD_TO_COMPONENT
  X52
)
