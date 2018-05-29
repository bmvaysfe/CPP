#include<stdio.h>
#include<wchar.h>
struct A{};

struct MyData
{
    short Data1;
    short Data2;
    short Data3;
};

struct MixedData
{
    char Data1;
    short Data2;
    int Data3;
    char Data4;
};

#if 0

    After compilation the data structure will be supplemented with padding bytes
    to ensure a proper alignment for each of its members:

struct MixedData  /* After compilation in 32-bit x86 machine */
{
    char Data1; /* 1 byte */
    char Padding1[1]; /* 1 byte for the following 'short' to be aligned on a 
    2 byte boundary assuming that the address where structure begins is an 
    even number */
    short Data2; /* 2 bytes */
    int Data3;  /* 4 bytes - largest structure member */
    char Data4; /* 1 byte */
    char Padding2[3]; /* 3 bytes to make total size of the structure 12 bytes */
};

#endif

struct MixedData2  /* after reordering */
{
    char Data1;
    char Data4;   /* reordered */
    short Data2;
    int Data3;  
};

int main()
{
    printf("Size of some fundamental data types\n\n");
    printf("char: %3u byte\n", sizeof(char));
    printf("short: %3u bytes\n", sizeof(short));
    printf("int: %3u bytes\n", sizeof(int));
    printf("long: %3u bytes\n", sizeof(long));
    printf("unsigned: %3u bytes\n", sizeof(unsigned));
    printf("float: %3u bytes\n", sizeof(float));
    printf("double: %3u bytes\n", sizeof(double));
    printf("long double: %3u bytes\n", sizeof(long double));
    printf("size of an empty structure is %3u bytes\n", sizeof(struct A));
    printf("sizeof(void *)=%u bytes\n", sizeof(void *)); /* 4 bytes */
    printf("sizeof(wchar_t)=%u bytes\n", sizeof(wchar_t)); /* 2 bytes */
//    printf("sizeof(char16_t)=%u bytes\n", sizeof(char16_t)); /* 2 bytes */
    
    printf("sizeof(struct MyData) = %u\n", sizeof(struct MyData)); /* 6 bytes */
    printf("sizeof(struct MixedData) = %u\n", sizeof(struct MixedData)); /* 12 bytes */
    printf("sizeof(struct MixedData2) = %u\n", sizeof(struct MixedData2)); /* 8 bytes */
    return 0;
}
