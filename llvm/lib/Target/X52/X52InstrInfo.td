//===----------------------------------------------------------------------===//
// X52 profiles and nodes
//===----------------------------------------------------------------------===//

def X52_ret      : SDNode<"X52ISD::RET", SDTNone,
                            [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "X52InstrFormats.td"

//===----------------------------------------------------------------------===//
// X52 Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

class X52mAsmOperand<int width> : AsmOperandClass {
let Name = "X52m" # width;
let RenderMethod = "addImmOperands";
let DiagnosticType = !strconcat("Invalid", Name);
}

def X52m16 : Operand<i32>, ImmLeaf<i32, [{return isInt<16>(Imm);}]> {
let ParserMatchClass = X52mAsmOperand<16>;
let EncoderMethod = "getImmOpValue";
let DecoderMethod = "decodeX52mOperand<16>";
let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
    return isInt<16>(Imm);
    return MCOp.isBareSymbolRef();
}];
let OperandType = "OPERAND_X52M16";
let OperandNamespace = "X52Op";
}

//===----------------------------------------------------------------------===//
// X52 Instructions
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1 in
def BR : X52Inst<0x0, (outs), (ins GPR:$rs1), "BR $rs1",
                [(brind GPR:$rs1)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET : X52PseudoInst<(outs), (ins), "# PseudoRET",
                [(X52_ret)]>,
                PseudoInstExpansion<(BR R0)>;

// movli
let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1 in
def MOVLI : X52Inst<0x0, (outs GPR:$rd), (ins X52m16:$imm),
                    "MOVli $rd $imm",
                    [(set GPR:$rd, X52m16:$imm)]>;