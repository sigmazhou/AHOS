#pragma once

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
extern void init_video();
		