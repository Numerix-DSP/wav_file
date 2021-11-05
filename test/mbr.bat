@echo off

rem Batch file for building and executing client application with Microsoft Visual Studio compiler
rem This build uses the static library, release model

del %1.exe
cl %1.c -W4 -I../include
del *.obj
if exist %1.exe %1 %2 %3 %4 %5 %6 %7 %8 %9
