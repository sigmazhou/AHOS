#include "system.h"
#define WIDTH 80
#define HEIGHT 25

unsigned short *textptr = (unsigned short *)0xB8000;
unsigned char color = 0x0f;
int currx = 0, curry = 0;

void scrollcheck()
{
    unsigned short space = 0x20 | (color << 8);
    if (curry >= HEIGHT)
    {
        int toroll = curry - HEIGHT + 1;
        memcpy(textptr, textptr + WIDTH * toroll, (HEIGHT - toroll) * WIDTH * 2);
        memsetw(textptr + WIDTH * (HEIGHT - toroll), space, toroll * WIDTH);
        curry-=toroll;
    }
}

void mov_cursor()
{
    unsigned pos = curry * WIDTH + currx;
    outportb(0x3D4, 14);
    outportb(0x3D5, pos >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, pos);
}

void cls()
{
    unsigned short space = 0x20 | (color << 8);
    memsetw(textptr, space, HEIGHT * WIDTH);
    currx = 0;
    curry = 0;
    mov_cursor();
}

void putchar(unsigned char c)
{
    if (c == 0x08) //backspace
    {
        if (currx > 0)
            currx--;
    }
    else if (c == 0x09) //tab
    {
        currx = (currx + 8) & ~(7);
    }
    else if (c == '\r')
    {
        currx = 0;
    }
    else if (c == '\n')
    {
        curry += 1;
        currx=0;
    }
    else if (c >= ' ')
    {
        unsigned short towrite = c | (color << 8);
        memsetw(textptr + (currx + curry * WIDTH), towrite, 1);
        currx++;
    }
    if (currx > WIDTH)
    {
        currx -= WIDTH;
        curry++;
    }
    scrollcheck();
    mov_cursor();
}

void putstr(unsigned char * text){
    for (int i = 0; i < strlen(text); i++)
    {
        putchar(text[i]);
    }
}

void setcolor(unsigned char fore,unsigned char back){
    color=(back<<4)|fore;
}
void video_init(void)
{
    textptr = (unsigned short *)0xB8000;
    cls();
}