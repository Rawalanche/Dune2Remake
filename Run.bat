@echo off
call "%ProgramFiles%\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
start "" "%LOCALAPPDATA%\Programs\Microsoft VS Code\Code.exe" Dune2Remake.code-workspace
exit