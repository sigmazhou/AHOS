#include "system.h"

struct idt_entry{
    unsigned short base_low;
    unsigned short selector;
    unsigned char always0;
    unsigned char flags;
    unsigned short base_high;
}__attribute__((packed));

struct idt_ptr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));


struct idt_entry idt[256];
struct idt_ptr iptr;

extern void idt_load();

void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
    /* We'll leave you to try and code this function: take the
    *  argument 'base' and split it up into a high and low 16-bits,
    *  storing them in idt[num].base_hi and base_lo. The rest of the
    *  fields that you must set in idt[num] are fairly self-
    *  explanatory when it comes to setup */
   idt[num].base_low=base & 0xFFFF;
   idt[num].base_high=(base >> 16) & 0xFFFF;
   idt[num].selector=sel;
   
    // 先留下 0x60 这个魔数，以后实现用户态时候
    // 这个与运算可以设置中断门的特权级别为 3
   idt[num].flags=flags;    // | 0x60
   idt[num].always0=0;
}

void idt_init(){
    iptr.limit=(sizeof (struct idt_entry) * 256) - 1;
    iptr.base=&idt;

    /* Clear out the entire IDT, initializing it to zeros */
    memset(&idt, 0, sizeof(struct idt_entry) * 256);

    /* Add any new ISRs to the IDT here using idt_set_gate */

    /* Points the processor's internal register to the new IDT */
    idt_load();
}