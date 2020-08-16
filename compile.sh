nasm -f elf32 -o start.o start.asm
gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I. -c -o main.o main.c

gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I. -c -o screen.o screen.c

gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I. -c -o gdt.o gdt.c

ld -m elf_i386 -T link.ld -o kernel.elf start.o  main.o screen.o gdt.o
#objcopy -O binary kernel.elf kernel.bin
