define dso_local void @app() {
entry:
    call void @llvm.x52.paintpixel(i32 1, i32 2, i32 3)
    call void @llvm.x52.flush()
    ret void
}

declare void @llvm.x52.paintpixel(i32, i32, i32)

declare void @llvm.x52.flush()