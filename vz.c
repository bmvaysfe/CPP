//	Verizon interview 08.14.15

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<math.h>
#include<ctype.h>

#define SQ(n) (n*n)

int main(int argc, char**argv)
{
	    char c='\101';  //	'\' stands for octal, c='A' here
	    int *array[3];
	//    int (*ptr)[]=array;
		int i =4;
	    int x = sizeof(L"Hello world!");	// 26	// L is a flag for long literals, i.e. Unicode
	    int x1 = sizeof("Hello world!");	// 13
	    
	    int cc=0, d=10, e = 15, k;
    	
    	union test{
    		int a;
    		int b;
    	}testU;
    	
    	typedef union {
    		short word; char s[2];
    	}U2;
    	
    	printf("x=%d\n", x);	//	26
		printf("x1=%d\n", x1);	//	13
		

	//	1. 	AAA	
    	testU.a=7; testU.b=12;
    	printf("AAA%d\n",testU.a+testU.b); // 24

	//	2.	BBB
    	printf("BBB%d\n", 2*3/4);  // 1


	//	3.	CCC
    	printf("CCC%d\n", 64/SQ(4));  // 4
    	
    	//	4.	DDD	
    	k=cc>1?d>2||e>5?10:20:30;	//	30
    	printf("DD%d\n", k);  // 	30
    	
    
    	
    	U2 ee={1};
   		printf("EE%d\n", ee.s[0]);  //1
    
    	putchar(c);	// A
		puts("\n\nTesting switch pitfalls\n");
		switch(i) {
    		default:;
    		case 3:
    			i+=5;
    			puts("\nhere");	// Here
    			break;
    		case 8:
    			puts("there");
    			break;
    	};
    	printf("i=%d\n", i); 
    	
    	switch(x) 
    	{
	    	case 0: x=1;
	    	case 1: x=3;
	    	case 2: x+=4;
	    	case 3:	x=2;
	    	default: x+=2;
    	};
    	printf("x=%d\n", x); // x = 4
    	
    	
    	return 0;
}
