#include "system.h"

char * reversestr(char * ori){
    static char rev[32];
    memset(rev,0,sizeof(rev[0])*32);
    int i=strlen(ori),j=0;
    for(;i>0;i--){
        rev[j]=ori[i-1];
        j++;
    }
    rev[j]='\0';
    return rev;
}

char * uinttostr(unsigned num){
    char numtable[10]={'0','1','2','3','4','5','6','7','8','9'};
    int i=0;
    char str[32];
    memset(str,0,sizeof(str[0])*32);
    while(num>0){
        int curr=num%10;
        num=num/10;
        str[i]=numtable[curr];
        i++;
    }
    str[i]='\0';
    return reversestr(str);
}

