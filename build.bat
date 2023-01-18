@echo off

set BAT_BASE_PATH=%~p0

if exist "%BAT_BASE_PATH%library" (
    RD /S /Q "%BAT_BASE_PATH%library"
)

MD "%BAT_BASE_PATH%library"

clang -shared -o "%BAT_BASE_PATH%library/vector.dll" -I "%BAT_BASE_PATH%include" "%BAT_BASE_PATH%src/*.c"