@echo off


set CommonCompilerFlags= -std:c++latest -Zi -Wall -Wpedantic -fdiagnostics-absolute-paths -gcodeview -Wconversion -Wsign-conversion -Wnull-dereference -Wundef -Wno-missing-prototypes -Wno-language-extension-token -Wno-nested-anon-types -Wno-missing-field-initializers -Wno-gnu-anonymous-struct -Wno-unused-macros -Wno-old-style-cast -Wmissing-declarations -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wshadow -Od -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-undef -Wno-unsafe-buffer-usage -Wno-cast-function-type-strict -Wno-cast-function-type-mismatch

set CommonLinkerFlags=user32.lib Shell32.lib

if not exist ..\build mkdir ..\build
pushd ..\build

clang-cl %CommonCompilerFlags%  ..\code\cursor.cpp /link /DLL /out:cursor.dll
clang-cl %CommonCompilerFlags%  ..\code\win32_cursor.cpp /link %CommonLinkerFlags%


popd