echo off
gcc main.c ./asset/*.c ./fonction/*.c ./structures/*.c -o main.exe

echo appuyer pour lancer le programe
pause
CLS
main.exe
exit