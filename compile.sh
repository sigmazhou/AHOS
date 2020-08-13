pwd
nasm -f elf64 -o start.o start.asm
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -c -o main.o main.c
ld -T link.ld -o kernel.tmp start.o  main.o 
objcopy -O binary kernel.tmp kernel.bin
