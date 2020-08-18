//test file & code generator
#include <stdio.h>
//#include <iostream>
//using namespace std;

int main(){
    char a[]="qwertyuiop[]asdfghjkl;'`\\zxcvbnm,./";
    int i=0;
    while(a[i]!='\0'){
        printf("'%c',",a[i]);
        i++;
    }

    getchar();
    return 0;
}