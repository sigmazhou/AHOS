nasm -f elf32 -o start.o start.asm
gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I. -c -o main.o main.c

gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I. -c -o screen.o screen.c

gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I. -c -o gdt.o gdt.c

gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I. -c -o idt.o idt.c

gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I. -c -o isr.o isr.c

gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I. -c -o irq.o irq.c

gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I. -c -o timer.o timer.c

gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I. -c -o keyboard.o keyboard.c

gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fno-stack-protector -I. -c -o string.o string.c

ld -m elf_i386 -T link.ld -o ahos-kernel.elf *.o #start.o main.o screen.o gdt.o idt.o isr.o
#objcopy -O binary kernel.elf kernel.bin
