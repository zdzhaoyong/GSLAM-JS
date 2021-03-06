######################################################################
# Automatically generated by qmake (3.0) Mon Sep 10 17:20:07 2018
######################################################################

TEMPLATE = app
TARGET = GSLAM-JS
INCLUDEPATH += .\
/data/zhaoyong/Program/Apps/SLAM/GSLAM-JS/nbind/include

DEFINES+=__EMSCRIPTEN__ BUILDING_NODE_EXTENSION
# Input
HEADERS += nbind/test/Coord.h \
           node_modules/nan/nan.h \
           node_modules/nan/nan_callbacks.h \
           node_modules/nan/nan_callbacks_12_inl.h \
           node_modules/nan/nan_callbacks_pre_12_inl.h \
           node_modules/nan/nan_converters.h \
           node_modules/nan/nan_converters_43_inl.h \
           node_modules/nan/nan_converters_pre_43_inl.h \
           node_modules/nan/nan_define_own_property_helper.h \
           node_modules/nan/nan_implementation_12_inl.h \
           node_modules/nan/nan_implementation_pre_12_inl.h \
           node_modules/nan/nan_json.h \
           node_modules/nan/nan_maybe_43_inl.h \
           node_modules/nan/nan_maybe_pre_43_inl.h \
           node_modules/nan/nan_new.h \
           node_modules/nan/nan_object_wrap.h \
           node_modules/nan/nan_persistent_12_inl.h \
           node_modules/nan/nan_persistent_pre_12_inl.h \
           node_modules/nan/nan_private.h \
           node_modules/nan/nan_string_bytes.h \
           node_modules/nan/nan_typedarray_contents.h \
           node_modules/nan/nan_weak.h \
           nbind/include/nbind/api.h \
           nbind/include/nbind/ArgStorage.h \
           nbind/include/nbind/BindClass.h \
           nbind/include/nbind/BindDefiner.h \
           nbind/include/nbind/Buffer.h \
           nbind/include/nbind/common.h \
           nbind/include/nbind/FunctionDefiner.h \
           nbind/include/nbind/MethodDef.h \
           nbind/include/nbind/nbind.h \
           nbind/include/nbind/noconflict.h \
           nbind/include/nbind/Policy.h \
           nbind/include/nbind/TypeID.h \
           nbind/include/nbind/TypeStd.h \
           nbind/include/nbind/TypeTransformer.h \
           nbind/include/nbind/wire.h \
           nbind/include/nbind/em/ArgFromWire.h \
           nbind/include/nbind/em/BindingStd.h \
           nbind/include/nbind/em/BindingType.h \
           nbind/include/nbind/em/Buffer.h \
           nbind/include/nbind/em/Callback.h \
           nbind/include/nbind/em/Caller.h \
           nbind/include/nbind/em/Creator.h \
           nbind/include/nbind/em/External.h \
           nbind/include/nbind/em/Int64.h \
           nbind/include/nbind/em/NBind.h \
           nbind/include/nbind/em/Pool.h \
           nbind/include/nbind/em/StdFunction.h \
           nbind/include/nbind/em/ValueObj.h \
           nbind/include/nbind/signature/BaseSignature.h \
           nbind/include/nbind/signature/CallbackSignature.h \
           nbind/include/nbind/signature/ConstructorSignature.h \
           nbind/include/nbind/signature/FunctionSignature.h \
           nbind/include/nbind/signature/GetterSignature.h \
           nbind/include/nbind/signature/MethodSignature.h \
           nbind/include/nbind/signature/SetterSignature.h \
           nbind/include/nbind/signature/SignatureParam.h \
           nbind/include/nbind/v8/ArgFromWire.h \
           nbind/include/nbind/v8/BindingStd.h \
           nbind/include/nbind/v8/BindingType.h \
           nbind/include/nbind/v8/BindWrapper.h \
           nbind/include/nbind/v8/Buffer.h \
           nbind/include/nbind/v8/Callback.h \
           nbind/include/nbind/v8/Caller.h \
           nbind/include/nbind/v8/Convert.h \
           nbind/include/nbind/v8/Creator.h \
           nbind/include/nbind/v8/External.h \
           nbind/include/nbind/v8/Int64.h \
           nbind/include/nbind/v8/NBind.h \
           nbind/include/nbind/v8/Output.h \
           nbind/include/nbind/v8/Overloader.h \
           nbind/include/nbind/v8/StdFunction.h \
           nbind/include/nbind/v8/ValueObj.h \
           node_modules/nbind/include/nbind/api.h \
           node_modules/nbind/include/nbind/ArgStorage.h \
           node_modules/nbind/include/nbind/BindClass.h \
           node_modules/nbind/include/nbind/BindDefiner.h \
           node_modules/nbind/include/nbind/Buffer.h \
           node_modules/nbind/include/nbind/common.h \
           node_modules/nbind/include/nbind/FunctionDefiner.h \
           node_modules/nbind/include/nbind/MethodDef.h \
           node_modules/nbind/include/nbind/nbind.h \
           node_modules/nbind/include/nbind/noconflict.h \
           node_modules/nbind/include/nbind/Policy.h \
           node_modules/nbind/include/nbind/TypeID.h \
           node_modules/nbind/include/nbind/TypeStd.h \
           node_modules/nbind/include/nbind/TypeTransformer.h \
           node_modules/nbind/include/nbind/wire.h \
           node_modules/nbind/include/nbind/em/ArgFromWire.h \
           node_modules/nbind/include/nbind/em/BindingStd.h \
           node_modules/nbind/include/nbind/em/BindingType.h \
           node_modules/nbind/include/nbind/em/Buffer.h \
           node_modules/nbind/include/nbind/em/Callback.h \
           node_modules/nbind/include/nbind/em/Caller.h \
           node_modules/nbind/include/nbind/em/Creator.h \
           node_modules/nbind/include/nbind/em/External.h \
           node_modules/nbind/include/nbind/em/Int64.h \
           node_modules/nbind/include/nbind/em/NBind.h \
           node_modules/nbind/include/nbind/em/Pool.h \
           node_modules/nbind/include/nbind/em/StdFunction.h \
           node_modules/nbind/include/nbind/em/ValueObj.h \
           node_modules/nbind/include/nbind/signature/BaseSignature.h \
           node_modules/nbind/include/nbind/signature/CallbackSignature.h \
           node_modules/nbind/include/nbind/signature/ConstructorSignature.h \
           node_modules/nbind/include/nbind/signature/FunctionSignature.h \
           node_modules/nbind/include/nbind/signature/GetterSignature.h \
           node_modules/nbind/include/nbind/signature/MethodSignature.h \
           node_modules/nbind/include/nbind/signature/SetterSignature.h \
           node_modules/nbind/include/nbind/signature/SignatureParam.h \
           node_modules/nbind/include/nbind/v8/ArgFromWire.h \
           node_modules/nbind/include/nbind/v8/BindingStd.h \
           node_modules/nbind/include/nbind/v8/BindingType.h \
           node_modules/nbind/include/nbind/v8/BindWrapper.h \
           node_modules/nbind/include/nbind/v8/Buffer.h \
           node_modules/nbind/include/nbind/v8/Callback.h \
           node_modules/nbind/include/nbind/v8/Caller.h \
           node_modules/nbind/include/nbind/v8/Convert.h \
           node_modules/nbind/include/nbind/v8/Creator.h \
           node_modules/nbind/include/nbind/v8/External.h \
           node_modules/nbind/include/nbind/v8/Int64.h \
           node_modules/nbind/include/nbind/v8/NBind.h \
           node_modules/nbind/include/nbind/v8/Output.h \
           node_modules/nbind/include/nbind/v8/Overloader.h \
           node_modules/nbind/include/nbind/v8/StdFunction.h \
           node_modules/nbind/include/nbind/v8/ValueObj.h
SOURCES += cpp/js_wrapper.cpp \
           nbind/src/common.cc \
           nbind/src/reflect.cc \
           nbind/test/Array.cc \
           nbind/test/Buffers.cc \
           nbind/test/Callback.cc \
           nbind/test/Functions.cc \
           nbind/test/GetterSetter.cc \
           nbind/test/Inheritance.cc \
           nbind/test/Nullable.cc \
           nbind/test/Overload.cc \
           nbind/test/PrimitiveMethods.cc \
           nbind/test/Reference.cc \
           nbind/test/Smart.cc \
           nbind/test/Strict.cc \
           nbind/test/Value.cc \
           nbind/src/em/Binding.cc \
           nbind/src/v8/Binding.cc \
           nbind/src/v8/Buffer.cc \
           node_modules/nbind/src/common.cc \
           node_modules/nbind/src/reflect.cc \
           node_modules/node-gyp/src/win_delay_load_hook.cc \
           node_modules/nbind/src/em/Binding.cc \
           node_modules/nbind/src/v8/Binding.cc \
           node_modules/nbind/src/v8/Buffer.cc \
           node_modules/node-gyp/gyp/data/win/large-pdb-shim.cc
TRANSLATIONS += nbind/src/common.ts \
                nbind/src/int64.ts \
                nbind/src/nbind.ts \
                nbind/src/reflect.ts \
                nbind/src/shim.ts \
                nbind/src/todts.ts \
                nbind/src/Type.ts \
                nbind/test/test.ts \
                node_modules/fast-deep-equal/index.d.ts \
                node_modules/safe-buffer/index.d.ts \
                node_modules/tweetnacl/nacl.d.ts \
                nbind/src/em/BindClass.ts \
                nbind/src/em/BindingStd.ts \
                nbind/src/em/BindingType.ts \
                nbind/src/em/Buffer.ts \
                nbind/src/em/Callback.ts \
                nbind/src/em/Caller.ts \
                nbind/src/em/em-api.ts \
                nbind/src/em/emscripten.d.ts \
                nbind/src/em/External.ts \
                nbind/src/em/GC.ts \
                nbind/src/em/Globals.ts \
                nbind/src/em/Resource.ts \
                nbind/src/em/ValueObj.ts \
                nbind/src/em/Wrapper.ts \
                node_modules/ajv/lib/ajv.d.ts \
                node_modules/autogypi/dist/autogypi.d.ts \
                node_modules/autogypi/dist/cli.d.ts \
                node_modules/autogypi/typings/browser.d.ts \
                node_modules/autogypi/typings/main.d.ts \
                node_modules/emscripten-library-decorator/dist/dump-em-lib.d.ts \
                node_modules/emscripten-library-decorator/dist/index.d.ts \
                node_modules/nbind/dist/common.d.ts \
                node_modules/nbind/dist/int64.d.ts \
                node_modules/nbind/dist/nbind.d.ts \
                node_modules/nbind/dist/reflect.d.ts \
                node_modules/nbind/dist/shim.d.ts \
                node_modules/nbind/dist/todts.d.ts \
                node_modules/nbind/dist/Type.d.ts \
                node_modules/performance-now/src/index.d.ts \
                node_modules/autogypi/typings/browser/ambient/commander/index.d.ts \
                node_modules/autogypi/typings/browser/ambient/node/index.d.ts \
                node_modules/autogypi/typings/browser/definitions/bluebird/index.d.ts \
                node_modules/autogypi/typings/main/ambient/commander/index.d.ts \
                node_modules/autogypi/typings/main/ambient/node/index.d.ts \
                node_modules/autogypi/typings/main/definitions/bluebird/index.d.ts
