#ifndef LLVM_LIB_TARGET_X52_INSTPRINTER_X52INSTPRINTER_H
#define LLVM_LIB_TARGET_X52_INSTPRINTER_X52INSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCRegister.h"

namespace llvm {

class X52InstPrinter : public MCInstPrinter {
public:
    X52InstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                const MCRegisterInfo &MRI)
        : MCInstPrinter(MAI, MII, MRI) {}

    std::pair<const char *, uint64_t> getMnemonic(const MCInst &MI) const override;
    void printInstruction(const MCInst *MI, uint64_t Address, raw_ostream& O);
    static const char* getRegisterName(MCRegister Reg);

    void printRegName(raw_ostream &O, MCRegister Reg) override;
    void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                const MCSubtargetInfo &STI, raw_ostream &O) override;

    void printOperand(const MCInst* MI, int OpNo, raw_ostream& O);

};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_X52_INSTPRINTER_X52INSTPRINTER_H