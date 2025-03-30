#ifndef LLVM_LIB_TARGET_X52_X52TARGETMACHINE_H
#define LLVM_LIB_TARGET_X52_X52TARGETMACHINE_H

#include "llvm/Target/TargetMachine.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include "X52Subtarget.h"
#include <optional>

namespace llvm {
extern Target TheX52Target;

class X52TargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  X52Subtarget Subtarget;
public:
  X52TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                      StringRef FS, const TargetOptions &Options,
                      std::optional<Reloc::Model> RM,
                      std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                      bool JIT, bool isLittle);

  X52TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                      StringRef FS, const TargetOptions &Options,
                      std::optional<Reloc::Model> RM,
                      std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                      bool JIT);

  TargetPassConfig* createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile* getObjFileLowering() const override;
  const X52Subtarget* getSubtargetImpl(const Function &) const override {
    return &Subtarget;
  }
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_X52_X52TARGETMACHINE_H