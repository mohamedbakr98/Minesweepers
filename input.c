#include "input.h"
#include <stdio.h>
int getUnsignedInteger(){
    int r,input;
    char newLine;
    r = scanf("%d%c",&input,&newLine);
    if(r == 2 && input > 0 && newLine == '\n'){
        fflush(stdin);
        return input;
    }
    fflush(stdin);
    return -1;
}
char* GetName(char *buffer){
    int flag = 0;
    gets(buffer);
    int i = 0;
    while(buffer[i] != '\0'){
        if(buffer[i] < 65 || buffer[i] >122){
            flag = 1;
        }
        i++;
    }
    if(flag == 0){
        return buffer;
    }
    buffer[0] = '\0';
    return buffer;
}
