#include "X52.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"
#include "clang/Basic/TargetBuiltins.h"

using namespace clang;
using namespace clang::targets;

static constexpr Builtin::Info BuiltinInfo[] = {
    #define BUILTIN(ID, TYPE, ATTRS)                                               \
      {#ID, TYPE, ATTRS, nullptr, HeaderDesc::NO_HEADER, ALL_LANGUAGES},
    #include "clang/Basic/BuiltinsX52.def"
};

void SimTargetInfo::getTargetDefines(const LangOptions &Opts,
                                    MacroBuilder &Builder) const {
    Builder.defineMacro("__x52__");
}

ArrayRef<Builtin::Info> X52TargetInfo::getTargetBuiltins() const {
    return llvm::ArrayRef(BuiltinInfo,
        clang::X52::LastTSBuiltin - Builtin::FirstTSBuiltin);
}