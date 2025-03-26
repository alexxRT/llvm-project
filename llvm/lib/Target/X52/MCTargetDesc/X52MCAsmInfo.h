#ifndef LLVM_LIB_TARGET_X52_MCTARGETDESC_X52MCASMINFO_H
#define LLVM_LIB_TARGET_X52_MCTARGETDESC_X52MCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class X52ELFMCAsmInfo : public MCAsmInfoELF {
    public:
        explicit X52ELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_X52_MCTARGETDESC_X52MCASMINFO_H