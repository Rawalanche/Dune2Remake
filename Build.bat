@echo off

call "%ProgramFiles%\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

if not exist Obj mkdir Obj
if not exist Bin mkdir Bin

cl @Build.rsp /EHsc /O2 /Fo"Obj\\" ^
   /I Include ^
   /I "D:\Projects\Software\vcpkg\installed\x64-windows-static\include" ^
   /link ^
   /LIBPATH:"D:\Projects\Software\vcpkg\installed\x64-windows-static\lib" ^
   raylib.lib glfw3.lib opengl32.lib gdi32.lib winmm.lib user32.lib shell32.lib ^
   /OUT:bin\Dune2Remake.exe