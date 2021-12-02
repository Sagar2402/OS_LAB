#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main()
{
    int a=81;
    float b=9.1;
    char c='s';
    char str[]="Lab";
  	printf("a=%d b=%f c=%c str=%s hexadecimal for a=%x Octal for a=%o \n",a,b,c,str,a,a);
  	errno=EPERM;
    printf("Error Access Errno= %m\n");
}
