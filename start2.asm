; Multiboot macros to make a few lines later more readable
MULTIBOOT_PAGE_ALIGN	equ 1<<0
MULTIBOOT_MEMORY_INFO	equ 1<<1
MULTIBOOT_AOUT_KLUDGE	equ 1<<16
MULTIBOOT_HEADER_MAGIC	equ 0x1BADB002
MULTIBOOT_HEADER_FLAGS	equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | MULTIBOOT_AOUT_KLUDGE
MULTIBOOT_CHECKSUM	equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

[BITS 32]
section .text
dd MULTIBOOT_HEADER_MAGIC
dd MULTIBOOT_HEADER_FLAGS
dd MULTIBOOT_CHECKSUM

[global start]
[global mboot_ptr]
[extern main]
start:
    cli
    mov esp, _sys_stack     ; This points the stack to our new stack area
    mov ebp,0
    and esp, 0FFFFFFF0H
    mov [mboot_ptr],ebx
    call main
    jmp infloop


infloop:
    hlt
    jmp infloop

SECTION .bss
stack:
    resb 32768              ; This reserves 8KBytes of memory here
mboot_ptr:
    resb 4

_sys_stack equ $-stack-1
