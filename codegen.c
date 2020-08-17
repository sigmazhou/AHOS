//test file & code generator
#include <stdio.h>
//#include <iostream>
//using namespace std;

int main(){
    for(int i=0;i<32;i++){
        printf("idt_set_gate(%d, (unsigned)isr%d, 0x08, 0x8E);\n",i,i);
    }

    //getchar();
    return 0;
}