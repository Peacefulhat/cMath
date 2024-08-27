#!/usr/bin/zsh
gcc -o main main.c ./mathFiles/matrix.c ./mathFiles/vec.c -lm
#gdb main
./main
