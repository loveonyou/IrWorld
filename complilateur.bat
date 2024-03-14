echo off
gcc main.c ./asset/*.c ./fonction/*.c ./structures/*.c -o IrWorld.exe

echo appuyer pour lancer le programe
pause
CLS
IrWorld.exe
exit