#include "MCTargetDesc/X52MCTargetDesc.h"
#include "X52.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCValue.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

namespace {
    class X52ELFObjectWriter : public MCELFObjectTargetWriter {
        public:
            X52ELFObjectWriter(bool Is64Bit, uint8_t OSABI)
            : MCELFObjectTargetWriter(Is64Bit, OSABI, ELF::EM_X52,
                                 /*HasRelocationAddend*/ true) {}

            ~X52ELFObjectWriter() override = default;

        protected:
            unsigned getRelocType(MCContext &Ctx, const MCValue &Target,
                         const MCFixup &Fixup, bool IsPCRel) const override;

            bool needsRelocateWithSymbol(const MCValue &Val, const MCSymbol &Sym,
                                unsigned Type) const override;
    };
} // namespace

unsigned X52ELFObjectWriter::getRelocType(MCContext &Ctx, const MCValue &Target,
                                           const MCFixup &Fixup,
                                           bool IsPCRel) const {
    MCFixupKind Kind = Fixup.getKind();
    if (Kind >= FirstLiteralRelocationKind)
        return Kind - FirstLiteralRelocationKind;

    llvm_unreachable("Unimplemented fixup -> relocation");
}

bool X52ELFObjectWriter::needsRelocateWithSymbol(const MCValue &,
                                                  const MCSymbol &,
                                                  unsigned Type) const {
    return false;
}

std::unique_ptr<MCObjectTargetWriter> llvm::createX52ELFObjectWriter(bool Is64Bit, uint8_t OSABI) {
       return std::make_unique<X52ELFObjectWriter>(Is64Bit, OSABI);
}