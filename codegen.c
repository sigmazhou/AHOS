//test file & code generator
#include <stdio.h>
//#include <iostream>
//using namespace std;

int main(){
    for(int i=0;i<16;i++){
        printf("idt_set_gate(%d, (unsigned)irq%d, 0x08, 0x8E);\n",i+32,i);
    }

    //getchar();
    return 0;
}