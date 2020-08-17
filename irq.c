#include "system.h"

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

int_handler_t irq_handler_list[16];

void irq_install_handler(int irq, int_handler_t handler)
{
    irq_handler_list[irq]=handler;
}

void irq_uninstall_handler(int irq){
    irq_handler_list[irq]=0;
}

void irq_handler(struct regs *r)
{
    //putchar('w');
    if(irq_handler_list[r->int_no-32]){
        irq_handler_list[r->int_no-32](r);
    }
    if (r->int_no >= 40)
    {
        outportb(0xA0, 0x20);
    }

    /* In either case, we need to send an EOI to the master
    *  interrupt controller too */
    outportb(0x20, 0x20);
}

void irq_init()
{
    // 重新映射 IRQ 表
    // 两片级联的 Intel 8259A 芯片
    // 主片端口 0x20 0x21
    // 从片端口 0xA0 0xA1

    // 初始化主片、从片
    // 0001 0001
    outportb(0x20, 0x11);
    outportb(0xA0, 0x11);

    // 设置主片 IRQ 从 0x20(32) 号中断开始
    outportb(0x21, 0x20);

    // 设置从片 IRQ 从 0x28(40) 号中断开始
    outportb(0xA1, 0x28);

    // 设置主片 IR2 引脚连接从片
    outportb(0x21, 0x04);

    // 告诉从片输出引脚和主片 IR2 号相连
    outportb(0xA1, 0x02);

    // 设置主片和从片按照 8086 的方式工作
    outportb(0x21, 0x01);
    outportb(0xA1, 0x01);

    // 设置主从片允许中断
    outportb(0x21, 0x0);
    outportb(0xA1, 0x0);

    idt_set_gate(32, (unsigned)irq0, 0x08, 0x8E);
    idt_set_gate(33, (unsigned)irq1, 0x08, 0x8E);
    idt_set_gate(34, (unsigned)irq2, 0x08, 0x8E);
    idt_set_gate(35, (unsigned)irq3, 0x08, 0x8E);
    idt_set_gate(36, (unsigned)irq4, 0x08, 0x8E);
    idt_set_gate(37, (unsigned)irq5, 0x08, 0x8E);
    idt_set_gate(38, (unsigned)irq6, 0x08, 0x8E);
    idt_set_gate(39, (unsigned)irq7, 0x08, 0x8E);
    idt_set_gate(40, (unsigned)irq8, 0x08, 0x8E);
    idt_set_gate(41, (unsigned)irq9, 0x08, 0x8E);
    idt_set_gate(42, (unsigned)irq10, 0x08, 0x8E);
    idt_set_gate(43, (unsigned)irq11, 0x08, 0x8E);
    idt_set_gate(44, (unsigned)irq12, 0x08, 0x8E);
    idt_set_gate(45, (unsigned)irq13, 0x08, 0x8E);
    idt_set_gate(46, (unsigned)irq14, 0x08, 0x8E);
    idt_set_gate(47, (unsigned)irq15, 0x08, 0x8E);

    memset(irq_handler_list, 0, sizeof(irq_handler_list[0]) * 16);
}
