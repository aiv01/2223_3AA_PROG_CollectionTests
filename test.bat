@echo off

set BAT_BASE_PATH=%~p0

if exist "%BAT_BASE_PATH%test/bin" (
    RD /S /Q "%BAT_BASE_PATH%test/bin"
)

MD "%BAT_BASE_PATH%test/bin"

clang -o "%BAT_BASE_PATH%test/bin/test.exe" -I "%BAT_BASE_PATH%include" "%BAT_BASE_PATH%test/src/*.c" "%BAT_BASE_PATH%src/*.c"