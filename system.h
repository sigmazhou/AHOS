#pragma once


/* This defines what the stack looks like after an ISR was running */
struct regs
{
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    unsigned int int_no, err_code;    /* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */ 
};

typedef void (*int_handler_t)(struct regs *);

extern unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);
extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);
extern int strlen(const char *str);
extern unsigned char inportb (unsigned short _port);
extern void outportb (unsigned short _port, unsigned char _data);

extern void cls();
extern void putchar(unsigned char c);
extern void putstr(unsigned char *str);
extern void setcolor(unsigned char forecolor, unsigned char backcolor);
extern void video_init();
	
extern void gdt_init();

extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
extern void idt_init();

extern void isr_init();

extern void irq_init();

extern void irq_install_handler(int irq, int_handler_t handler);
extern void irq_uninstall_handler(int irq);

extern void timer_init(int hz);

extern char * uinttostr(unsigned num);
		