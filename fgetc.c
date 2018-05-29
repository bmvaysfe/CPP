/* This program copies itself to stdout */

#include<stdio.h>

int main(int argc, char**argv)
{
    int c;
    
    FILE *fp=fopen(__FILE__, "r");
    c=fgetc(fp);
    while(c!=EOF) {
        putchar(c);
        c=fgetc(fp);
    }
    fclose(fp);
    return 0;
}
