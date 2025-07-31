@echo off

if not exist Obj mkdir Obj
if not exist Binary mkdir Binary

echo Building Debug Mode...
cl @Build.rsp /FC /EHsc /std:c++20 /MP /Fo"Obj\\" ^
   /I Include ^
   /I "D:\Projects\Software\vcpkg\installed\x64-windows-static\include" ^
   /DEBUG /Od /Zi /MDd /DDEBUG ^
   /link ^
   /LIBPATH:"D:\Projects\Software\vcpkg\installed\x64-windows-static\lib" ^
   raylib.lib glfw3.lib opengl32.lib gdi32.lib winmm.lib user32.lib shell32.lib ^
   /DEBUG /OUT:Binary\Dune2Remake_Debug.exe