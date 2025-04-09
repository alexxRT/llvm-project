let TargetPrefix = "x52" in {  // All intrinsics start with "llvm.x52.".

  def int_x52_paintpixel: ClangBuiltin<"x52PaintPixel">,
    Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

  def int_x52_flush: ClangBuiltin<"x52Flush">,
    Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

  } // TargetPrefix = "x52"