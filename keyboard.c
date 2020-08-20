#include "system.h"

/*key mapping:
esc-1-]-\n-ctrl-a-'-`-Lshift-\-z-Rshift-*-alt-space(57)
up 72 l 75 down 80 r 77
*/
static char isshift = 0;
char keymap[128] = {
    '.', '.', // unknown and esc
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']',
    '\n', '.', //ctrl
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
    '`', '.', '\\',                                        //lshift
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '.', //rshift
    '*', '.', ' '                                          //alt,57

};
//nt a='1';
void kb_handler(struct regs *r)
{
    unsigned key = inportb(0x60);
    if (key & 0x80)
    {
        //putstr("released");
        key = key ^ 0x80;
        if (key == 42 || key == 54)
        {
            isshift = 0;
        }
    }
    else
    {
        //putstr(uinttostr(key));
        if (isshift)
        {
            if(keymap[key]>=97&&keymap[key]<=122){
                putchar(keymap[key]-32);
            }
        }
        else
        {
            if (key == 42 || key == 54) //shift
            {
                isshift = 1;
            }
            else
            {
                putchar(keymap[key]);
            }
        }
    }
}

void kb_init()
{
    irq_install_handler(1, &kb_handler);
    //putstr(uinttostr(strlen(keymap)));
}