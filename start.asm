[BITS 32]
global start
start:
    mov esp, _sys_stack     ; This points the stack to our new stack area
    jmp stublet

ALIGN 4
mboot:


stublet:
    ;extern main
    ;call _main
    jmp $

SECTION .bss
    resb 8192               ; This reserves 8KBytes of memory here
_sys_stack:
