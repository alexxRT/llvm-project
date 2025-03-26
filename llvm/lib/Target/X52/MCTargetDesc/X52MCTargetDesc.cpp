#include "MCTargetDesc/X52Info.h"
#include "X52MCTargetDesc.h"
#include "TargetInfo/X52TargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"


using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "X52GenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "X52GenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "X52GenSubtargetInfo.inc"


static MCRegisterInfo* createX52MCRegisterInfo(const Triple& TT) {
	MCRegisterInfo* X = new MCRegisterInfo();
	InitX52MCRegisterInfo(X, X52::R0);
	return X;
}

static MCInstrInfo *createX52MCInstrInfo() {
	MCInstrInfo *X = new MCInstrInfo();
	InitX52MCInstrInfo(X);
	return X;
}

static MCSubtargetInfo *createX52MCSubtargetInfo(const Triple &TT,
	StringRef CPU, StringRef FS) {
return createX52MCSubtargetInfoImpl(TT, CPU, CPU, FS);
}


// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeX52TargetMC() {
	Target& TheX52Target = getTheX52Target();
	// Register the MC register info.
	TargetRegistry::RegisterMCRegInfo(TheX52Target,
createX52MCRegisterInfo);
	TargetRegistry::RegisterMCInstrInfo(TheX52Target,
createX52MCInstrInfo);
	TargetRegistry::RegisterMCSubtargetInfo(TheX52Target,
createX52MCSubtargetInfo);
}
