#ifndef LLVM_LIB_TARGET_X52_X52REGISTERINFO_H
#define LLVM_LIB_TARGET_X52_X52REGISTERINFO_H

#define GET_REGINFO_HEADER
#include "X52GenRegisterInfo.inc"

namespace llvm {

struct X52RegisterInfo : public X52GenRegisterInfo {
    public:
        X52RegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_X52_X52REGISTERINFO_H