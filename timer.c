#include "system.h"

unsigned ticks=0;

void timer_handler(struct regs *r)
{
    /* Increment our 'tick count' */
    ticks++;

    /* Every 18 clocks (approximately 1 second), we will
    *  display a message on the screen */
    if (ticks % 100 == 0)
    {
        //putstr("One second has passed\n");
    }
}

void timer_init(int hz){
    ticks=0;

    unsigned divisor = 1193180 / hz;       /* Calculate our divisor */
    
    // D7 D6 D5 D4 D3 D2 D1 D0
    // 0  0  1  1  0  1  1  0
    // 即就是 36 H
    // 设置 8253/8254 芯片工作在模式 3 下
    outportb(0x43, 0x36);             /* Set our command byte 0x36 */

    outportb(0x40, divisor & 0xFF);   /* Set low byte of divisor */
    outportb(0x40, (divisor >> 8) & 0xFF);     /* Set high byte of divisor */

    irq_install_handler(0, &timer_handler);
}

