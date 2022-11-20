REM run as Administrator
@echo off
cd /d %~dp0
set DOWNLOADS_DIR=%USERPROFILE%\Downloads
set DOWNLOADS_DIR_LINUX=%DOWNLOADS_DIR:\=/%

set PATH=%DOWNLOADS_DIR%\gp550-20221117-win64-mingw\gnuplot\bin;

@REM set PATH=D:\Softwares\gp550-20221117-win64-mingw\gnuplot\bin;

cd cmake-build && ^
gnuplot-cpp-playground.exe
pause