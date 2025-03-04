#include "TargetInfo/X52TargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheX52Target() {
  static Target TheX52Target;
  return TheX52Target;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeX52TargetInfo() {
  RegisterTarget<Triple::X52> X(getTheX52Target(), "X52", "X52 32",
                                   "X52");
}
