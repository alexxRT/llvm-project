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

def simm16 : Operand<i32>, ImmLeaf<i32, [{return isInt<16>(Imm);}]> {
let ParserMatchClass = X52mAsmOperand<16>;
let EncoderMethod = "getSImm16OpValue";
let DecoderMethod = "decodeX52mOperand<16>";
let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
    return isInt<16>(Imm);
    return MCOp.isBareSymbolRef();
}];
let OperandType = "OPERAND_SIMM16";
let OperandNamespace = "X52Op";
}

//===----------------------------------------------------------------------===//
// X52 Instructions
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1, r2 = 0,
r3_imm = 0 in
def BR : X52Inst<0xAA, (outs), (ins GPR:$r1), "BR $r1",
                [(brind GPR:$r1)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET : X52PseudoInst<(outs), (ins), "# PseudoRET",
                [(X52_ret)]>,
                PseudoInstExpansion<(BR R0)>;

// movli
let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1, r2 = 0 in
def MOVLI : X52Inst<0xAB, (outs GPR:$r1), (ins simm16:$r3_imm),
                    "MOVli $r1 $r3_imm",
                    [(set GPR:$r1, simm16:$r3_imm)]>;

// flush_window
let r1 = 0, r2 = 0, r3_imm = 0 in
def FLUSH : X52Inst<0xBC, (outs), (ins), "FLUSH", [(int_x52_flush)]>;

// paint_pixel
def PAINTPIXEL : X52Inst<0xDF, (outs), (ins GPR:$r1, GPR:$r2, GPR:$r3_imm),
                    "PAINTPIXEL $r1 $r2 $r3_imm", [(int_x52_paintpixel GPR:$r1, GPR:$r2, GPR:$r3_imm)]>;
