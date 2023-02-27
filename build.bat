@echo off

if exist "bin"
(
    RD /S /Q "bin"
)

MD "bin"

clang -o bin\test.exe -Iinclude test\*.c src\*.c