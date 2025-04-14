@echo off
echo Setting up environment...
set "RAYLIB_PATH=C:\raylib\raylib"
set "COMPILER_PATH=C:\raylib\w64devkit\bin"
set "PATH=%COMPILER_PATH%;%PATH%"

set "CC=g++"
set "CFLAGS=%RAYLIB_PATH%\src\raylib.rc.data -s -static -O2 -std=c++20 -Wall -I%RAYLIB_PATH%\src -Iexternal -DPLATFORM_DESKTOP"
set "LDFLAGS=-lraylib -lopengl32 -lgdi32 -lwinmm"

echo Cleaning old build...
if exist SnakeGame.exe del /f SnakeGame.exe

echo Compiling...
%CC% --version
%CC% -o SnakeGame.exe *.cpp %CFLAGS% %LDFLAGS%

if errorlevel 1 (
    echo Compilation failed.
    exit /b 1
)

echo Running the game...
SnakeGame.exe
