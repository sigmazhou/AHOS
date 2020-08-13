#include "system.h"

unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count){
    for(;count>0;count--){
        *dest++=*src++;
    }
    return dest;
}
unsigned char *memset(unsigned char *dest, unsigned char val, int count){
    for(;count>0;count--){
        *dest++=val;
    }
    return dest;
}
unsigned short *memsetw(unsigned short *dest, unsigned short val, int count){
    for(;count>0;count--){
        *dest++=val;
    }
    return dest;
}
int strlen(const char *str){
    int len=0;
    while(*str != 0) len++;
    return len;
}
unsigned char inportb (unsigned short _port){
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}
void outportb (unsigned short _port, unsigned char _data){
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

void fmain(){

    while(1);
}
