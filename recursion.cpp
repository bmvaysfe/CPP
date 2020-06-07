/*
    recursion.cpp
    This file has test answers for interview questions
    I've seen so far. 
    Since June 2010, bitwise operations questions are ALSO in bits.c
*/    

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cassert>  // for assert()
#include<set>
#include<vector>
#include<string>
#include<limits.h>
#include<cctype>
#include<cstring>
#include<algorithm>

using namespace std;

//	RECURSION

//    Accenture 2007
/*
   The Fibonacci series is a series of numbers in which the first two terms are 1 
   and each subsequent term is the sum of the previous two, thus 1, 1, 2, 3, 5, 8, 13, 21, and so on. 
   Please write a function that prints successive terms in this series. 
   It should take one parameter, which is the number of terms to print. 
   It should not allocate excessive amounts of memory, and it should deal correctly 
   with any value of the input parameter.   You may answer this question in Java, C, C++, or C#.
   As an example, if the input is 6, the output should be the first six terms of the series, "1, 1, 2, 3, 5, 8".
*/


	//	Recursive Version of Fibonacci numbers
	//	O(2^n)
	static int fib(int n) 
	{
		if(n<=1)
			return n;
		else
			return fib(n-1)+fib(n-2);
	}

	//	Iterative Version of Fibonacci numbers
	//	O(n)
	static int fib1(int num)
	{
		int term1=0, term2=1, i, temp;

		if(num==0)
			return 0;
		if(num==1)
			return 1;

		for(i=2; i<=num; i++)
		{
			temp=term1;
			term1=term2;
			term2=term1+temp;
		}
		return term2;
	}
	
// Recursive multiplication by addition
	static int mult(int a, int b)
	{
		if(b==0)
			return 0;
		else
			return a+mult(a, b-1);
	}

//  Hanoi Towers

//
//	test of Towers of Hanoi routine
//
//	Described in Chapter 3 of
//	Data Structures in C++ using the STL
//	Published by Addison-Wesley, 1997
//	Written by Tim Budd, budd@cs.orst.edu
//	Oregon State University
void Hanoi (int n, char a, char b, char c)
	// move n disks from tower a to tower b, using tower c
{
	if (n == 1) {
			// can move smallest disk directly
		cout << "move disk from tower " << a << " to " << b << endl;
		}
	else {
			// first move all but last disk from tower a to tower c via b
		Hanoi (n-1, a, c, b);
		
			// then move one disk from a to b
		cout << "move disk from tower " << a << " to " << b << endl;
		
			// then move all disks from c back to b via a
		Hanoi (n-1, c, b, a);
		}
}

void test_Hanoi()
{
    Hanoi(3, 'a', 'b', 'c');
//    Hanoi(4, 'a', 'b', 'c');
//    Hanoi(5, 'a', 'b', 'c');
}



//	END of RECURSION

//    Accenture 2007
/*
      Imagine an array of n integers which contains every value from 1 to n in a random order, 
      except for one cell in the array, which has been maliciously set to zero.  
      Your task is to find the element in the array which has been zeroed, 
      and replace it with the value that used to be there.  
      Please write a function to do this in Java, C, C++, or C#. 
      What is the time complexity of your solution?

	IF entries are in sorted order, then use binary search for 0, subtract 1 from index returned.
	Complexity will be O(log(n)).
*/
void fix_array(int a[], int n)
{
     int i=0,  index=0, a1=1, d=1, actual_sum=0, sum=0;

     // 1. This is an arithmetic series with d=1 and first term a1=1.
     //    Find the sum=((2*a1+d*(n-1))/2)*n;
     //    This is a sum that should be if there is no memory corruption.

     sum=(((2*a1+d*(n-1))*n)/2);

     // 2. Now find the actual sum of corrupted array. Save the index of 0.
     for(i=0;i<n;i++)
     {
           if(a[i]==0) {
                index=i;    // index of 0.      
           }
           actual_sum+=a[i];
     }
     cout<<"sum = "<<sum <<" actual_sum= " << actual_sum << endl;

     int missed_value=sum-actual_sum;
     cout<<"missed_value = " << missed_value << " index = " << index <<endl;
     return;                                         
}     



//       Test of fix_array().
void test_fix_array()
{
    int i=0;
    const int SIZE=100;
    int a[SIZE];
    
    //  Initialize array
    for(;i<SIZE;i++)
    {
        a[i]=i+1;
    }
    cout<<"a[31]="<<a[31]<<endl;
    a[31]=0;  // Damage a value
    fix_array(a, SIZE);
    return;
}

//	BITWISE OPS

//  Miscellaneous interview questions
void test_misc() 
{
    char c=127;

    c=c+10;
    printf("%d\n" , c); // -119

    double a=5/10*2.0;
    printf("%f\n", a); // 0.000000
}

//  Generate truth table in reverse order.
/* On machines that have 8-bit bytes, a byte is conveniently represented as
   2 hexadecimal digits */ 
void bitwise()
{
    int num, i;

    for(i=0; i<5; i++)
    {
        num=i;
        while(num) {
            if(num & 1)
                cout<<"1";
            else
                cout<<"0";
            num>>=1;
        }
        cout<<endl;
    }
}

int areEqual(int a, int b)
{
    int result=a^b;
    return result?0:1;
    //	return (a^b) == 0; // equivalent of the above
}


/*  Print integer using only putchar(),	recursive version.
    This routine doesn't handle 0 or negative numbers! */
void PrintNum ( int Num )
{
	if ( Num == 0 )
		return;
	PrintNum ( Num / 10 );
	putchar ( '0'+ Num % 10 );
}

void test_PrintNum()
{
    PrintNum(10);   /* 10 is printed */
}


//#if 0 // @home  AAA
/*
  12/02/09, eSpeed
*/
void bitwise_ops1()
{ 
     char c=0xFF; /* -1 */
     int t=0xFF; /* 255 */
     printf("c = %d\n", c); /* -1 */
     printf("t = %#X = %d\n", t,t); /* 0xFF = 255 */ 
}


/*
  12/02/09, eSpeed
*/
/* On machines that have 8-bit bytes, a byte is conveniently represented as
   2 hexadecimal digits */ 
void bitwise_ops()
{
    char c=0xFF;   /* -1   */
    int t=0xFF; /* 255 */
    int t2=0xFFFF; /*  65535    */
    long value=65000;
    short s=t2;
     
    value &= t2;
    printf("c = %d\n", c); /* -1 */
    printf("t = %#X = %d\n", t,t); /* 0xFF = 255 */
    printf("t2 = %#X = %d\n", t2,t2); /* 65535    */
    printf("s=%d\n", s);
     // Is it an unsigned short? If yes, the value is printed.
    // Otherwise, difference between value and 65535 (FFFF).
    printf("value=%d\n", value); /* value=65000*/
    value=70000;
    value &= t2;
    printf("value=%d\n", value); /* value=4464 */
    
}
// #endif // @home  AAA
int isPowerOf2(int num)
{
	return (num>0) && ceil(log(num)/log(2))==floor(log(num)/log(2));
}

int is_PowerOf2(int n)
{
    return (n==1 || !(n & (n-1)));
    //		return (n==1 || (n & (n-1))==0);	// Works in Java
}



//	06.19.19
int isExactSquare2(int x)
{
	if(x<0) return 0;
	return ceil(sqrt(x)) == floor(sqrt(x));
}


//	10.28.19
int isExactCube(float n)
{       
    return ceil(cbrt(n)) == floor(cbrt(n));  // cbrt() stands for cubic root
}



//  Test for an overflow
bool WillOverflow_GOOD(unsigned int x, int add) {
  // This won't overflow because "x" can't be greater than UINT_MAX
  return (INT_MAX - x) < add;
}



/*  Returns 1 if the machine is little endian, 0 - if it's big endian. */
int endianness()
{
    int num=1;
    
    char *ptr=(char *)&num;
    return (*ptr);
}    

#if 0 // @home  AAA
/* Exercise 10, p 141, "A book on C", Kelley, Pohl  */
void ex10()
{
    char c=-1; /* -1 */
    signed char s=-1; /* -1 */
    unsigned char u=-1;  /* 255 */
    char minus_one=0xFF; /* -1 */
    printf("c=%d\ts=%d\tu=%d\n", c,s,u);
    printf("minus_one=%d\n", minus_one);
}    

#endif 

/* Packing and unpacking example */
/* Store in 2 chars a 0<number<10000. */
void test_binary()
{
    int b[]={1111, 1234, 2222, 4567, 3333, 4444, 5555, 7777, 8888, 9999};
    char c[3];
    int temp=0, i, p1=0, p2=0, x=0;    
    for(i=0; i<sizeof(b)/sizeof(b[0]); i++) {
        temp=0;
        x=0;
        c[0]=(b[i] / 256);
        c[1]=(b[i] % 256);
        c[2]='\0';

        if(c[1]>=0)
            x=c[1];
        else x=256+c[1];    
        temp=256*(c[0])+x;
        printf("b[%d] = %d = %d\n", i, b[i], temp);
    }

}    

/*  
    Multiply by 2 without *
    2<<(n-1) will do 2^n 
*/    
int mult_by2(int a)
{
	int b=a<<1;
	return b;
}

/*  
    Multiply by 7 without *
*/    
int mult_by7(int a)
{
	int b=(a<<3)-a;
	return b;
}

/* Remainder by 8 without % operator */
int rem8(int x)
{
    return x-8*(x>>3);
}    
    
/*
Given only putchar (no sprintf, itoa, etc.) 
Write a routine putlong that prints out an unsigned long in decimal. */
void putlong(unsigned long x)
{
    /* we know that 32 bits can have 10 digits. 2^32 = 4294967296 */
    unsigned long y, r;
    int found_1st_non_0=0;
    
    /* Handle 0 here */
    if(x == 0) {
        putchar('0');
        puts("\n");
        return;
    }
   
    for (y = 1000000000; y > 0; y /= 10) {
        r=x/y;
        if(r!=0 || found_1st_non_0!=0) {
            ++found_1st_non_0;
            putchar( r + '0');
        }
        x = x % y;
    }
    puts("\n");
}    

void test_putlong()
{
    int a[]={0, 10, 131, 131260, 148040}, i;
    
    for(i=0; i<sizeof(a)/sizeof(a[0]); i++)
        putlong(a[i]);
}
    
//  Morgan Stanley, 07/29/10
//  find a maximum of double x and 0 without if statement
double max(double x)
{
    return (x+abs(x))/2;
}     


//	Google question
void powersof_2()
{
    const int mil=1000000, bil=mil*1000;
    double p1=0, p2=0;
    
    p1=log(mil)/log(2); //  19.9316
    p2=log(bil)/log(2); //  29.9874

    cout<<"log2("<<mil<<") = "<<p1<<endl;
    cout<<"log2("<<bil<<") = "<<p2<<endl;
}


//	Swap 2 ints without 3rd parameter
//	Only swap technique is show in this method!
//	No actual swap is done here!
void swap1(int x, int y)
{
	x^=y^=x^=y;
}


//	Swap 2 ints without 3rd parameter
//	Only swap technique is show in this method!
//	No actual swap is done here!
void swap2(int a, int b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}

//	~x = -x -1  => -x = ~x+1
//	x+1= -~x
int add1(int n)
{
	return -~n;
}



//	Subtract 1 from a number n
int sub1(int n)
{
    return  ~-n;
}


//	Returns 1 if odd, 0 if even
int isOdd(int n)
{
	return n&1;
}



//	Turning on k-th bit of a number n
//	Bit numeration starts from 1!
int turnOnKthBit(int n, int k)
{
	return n | (1<<(k-1));
}



int turnOffKthBit(int n, int k)
{
	return n & ~(1<<(k-1));
}


int toggleKthBit(int n, int k)
{
	return n ^ (1<<(k-1));
}


int unsetRightMostBit(int n)
{
	return n & (n-1);
}



//	Find absolute value
int findAbsoluteValue(int n)
{
	int mask = n>>31;
	return (n+mask)^mask;
}



void ToLower()
{
    char ch;
    
    for(ch='A';ch<='Z';ch++)
        cout<<(char)(ch|' ');
    cout<<endl;
}



void ToUpper()
{
    char ch;
    
    for(ch='a';ch<='z';ch++)
        cout<<(char)(ch&'_');
    cout<<endl;
}



void InvertCase()
{
    
    char ch;
    
    //  To lower
    for(ch='A';ch<='Z';ch++)
        cout<<(char)(ch^' ');
    cout<<endl;    
  
    //  To Upper
    for(ch='a';ch<='z';ch++)
        cout<<(char)(ch^' ');
        
    cout<<endl;
}



void InvertCase2()
{
    char ch;
    
    //   To upper
    for(ch='a';ch<'z';ch++)
        cout<<(char)(ch+'A'-'a');
    cout<<endl;
    
    //  To lower
    for(ch='A';ch<'Z';ch++)
        cout<<(char)(ch-'A'+'a');
    cout<<endl;
}
//	END OF BITWISE OPS



//	SORTS
//  Bubble sort from Jones & Harrow book, p 547.
void bubble_sort(int arr[], int n)
{
	int i,swapped,temp;

	do {
		swapped=0;

		for(i=0;i<n-1;i++) {
			if(arr[i]>arr[i+1]) {
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
				swapped=1;
			}
		}
	} while(swapped);
}

void linear_sort(int *a, int size)
{
    int pass, cand, temp;

    for(pass=0; pass < size-1; pass++)
        for(cand=pass+1; cand < size; cand++)
            if(a[pass] > a[cand]) {
                temp=a[pass];
                a[pass]=a[cand];
                a[cand]=temp;
            }
    return;
}

void test_sorting()
{
    int data[]={8,23,6,5};
    int i=0;
    int size=sizeof(data)/sizeof(data[0]);

    linear_sort(data, size);
    for(i=0; i<size; i++)
        cout << data[i] << " ";
    cout << endl;
    return;    
}


//  Insertion sort: O(n^2)
void insert_sort(int data[], int no_elems)
{
	int tmp,j,i;

	for(i=1;i<no_elems;i++) {
		tmp=data[i];
		j=i-1;
		while( (data[j]>tmp) && (j>=0) ) {
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=tmp;
	}
}

//  Langsam, p.365
void insertion_sort(int *x, int n)
{
    int i,k,y;
    
    for(k=1; k<n; k++) {
        y=x[k];
        for(i=k-1; i>=0 && y<x[i]; i--)
            x[i+1]=x[i];
        x[i+1]=y;
    }
}    

int findmax(int a[], int size)
{
	int max=a[0], find=0;

	for(int i=1;i<size;i++)
		if(max<a[i]) {
			max=a[i];
			find=i;
		}
	return find;
}

// Max sort: O(n^2)
void maxsort(int a[],int size)
{
	if(size==1)
		return;
	else {
		int indmax=findmax(a,size);
		int temp=a[size-1];
		a[size-1]=a[indmax];
		a[indmax]=temp;
		maxsort(a,size-1);
	}
}

//  Selection sort: O(n^2)
void selection_sort(int a[], int n)
{
	int largepos,i,last;

	for(last=n-1; last>0; last--) {
		largepos=0;
		for(i=1; i<=last;i++) {
			if(a[i]>a[largepos])
				largepos=i;
			if(largepos!=last) {
				int temp=a[last];
				a[last]=a[largepos];
				a[largepos]=temp;
			}
		}
	}
}

// 	End of SORTS



int static_func1()
{
    static int a=0;
    a=a-1;
    return a;
}

int static_func(int x)
{
    return x++*++x; /* works as (x+1)^2 */
}

void test_static_func()
{
    int a=5;
    for(;a<8;a++)
        cout<<"static_func("<<a<<")="<<static_func(a)<<endl; // static_func(5)=36
//    cout<<static_func1()*static_func1()*static_func1()*static_func1()<<endl;
}

//  Euclid's Algorithm
int gcd(int a, int b) 
{ 
   return ( b == 0 ? a : gcd(b, a % b) ); 
}

/* Budd, "Data Structures in C++ using STL, p 55 */
//  Euclid's Algorithm
int gcd1(int m, int n)
{
    assert(n>0 && m>0);
    
    while(m!=n)
    {
        if(n>m)
            n=n-m;
        else
            m=m-n;
    }            
    return n;
}


// F-n that returns number of times called.
int f()
{
    static int num=0;
    ++num;
    return num;
}


//	STRING REVERSE

//  In place string reverse    
void reverse_in_place(char *src)
{
     int low=0, high=strlen(src) - 1;
     char temp;
     
     if(!src) return; /* empty string */
     
     while(low<high) 
     {
            temp=src[low];
            src[low]=src[high];
            src[high]=temp;                                                
            low++;
            high--;
     }
     return;            
}     



//    String reverse, from Jones & Harrow book, p 662.
void reverse(char *str, char *newstr)
{
     int k;
     
     k=strlen(str);
     if(k<=1)
             strcpy(newstr, str);
     else {
          reverse(str+1, newstr);
          newstr[k-1]=str[0];
          newstr[k]='\0';
     }
     return;
}          

//  Test of reverse()
//  test_reverse()
void test_reverse()
{
    char *src="abcdef123456";
    char revstr[strlen(src)+1];  // reversed src
    memset(revstr, 0, sizeof(revstr));
    reverse(src, revstr);
    cout<<revstr<<endl; 
}

//	END OF STRING REVERSE

//	String Library Functions


/*
  12/02/09, eSpeed; as of 05.08.12, works OK.
*/
int my_atoi(char *s)
{
    int sum=0, sign=1; // default is positive
    while(*s) {
        if(*s == '-') sign = -1;  // Should it be s[0] test only?
        else if(*s == '+') sign=1; // default is positive
        else 
            sum=(*s)-'0'+sum*10;
        s++;
    }
    return sum*sign;
}


//	10.7.19
double my_atod(char *s)
{
    int metDot=0, metPlus=0, metMinus=0, f10=1, sign=1, sum1=0;
    char DOT='.', PLUS='+', MINUS='-';
    double ONE=1.0D, ZERO=0.0D, sum2=0, result=ZERO;
    
    if(!s || *s=='\0') return ZERO;
    
    while(*s) {
        if(*s==DOT) ++metDot;
        else if(*s == MINUS) {
            ++metMinus;
            sign=-1;
        }
        else if(*s == PLUS) ++metPlus;
        else {
            if(metMinus==2 || metPlus==2 || metDot ==2) return ZERO;
            
            if(metDot == 0) {
                sum1 = *s - '0' + sum1*10;
            }
            else if(metDot ==1) {
                sum2=*s-'0'+sum2*10;
                f10*=10;
            }
        }
        s++;
    }
    result = sum1*ONE+(sum2*ONE)/f10;
    if(metMinus) {
        result*=sign;
    }
    return result;
}


//	10.7.19
double my_atod2(char *s)
{
    int metDot=0, metPlus=0, metMinus=0, f10=10, sign=1, sum1=0;
    char DOT='.', PLUS='+', MINUS='-';
    double ONE=1.0D, ZERO=0.0D, sum2=0, result=ZERO;
    
    if(!s || *s=='\0') return ZERO;
    
    while(*s) {
        if(*s==DOT) ++metDot;
        else if(*s == MINUS) {
            ++metMinus;
            sign=-1;
        }
        else if(*s == PLUS) ++metPlus;
        else {
            if(metMinus==2 || metPlus==2 || metDot ==2) return ZERO;
            
            if(metDot == 0) {
                sum1 = *s - '0' + sum1*10;
            }
            else if(metDot ==1) {
                sum2+= ((*s - '0')*ONE)/f10;
                f10*=10;
            }
        }
        s++;
    }
    result = sum1*ONE+sum2;
    if(metMinus) {
        result*=sign;
    }
    return result;
}



void test_my_atoi()
{
     #define NUM_TEST_CASES     3        
     char *src="159";  /* -123, +456, */
	 char *mySrc[NUM_TEST_CASES]={"159", "-123", "+456"};
	 /*
     int x=my_atoi(src);
     
     printf("%s = %d\n", src, x);
	 */
	 int i;

	 for(i=0; i<NUM_TEST_CASES; i++) {
		 cout<<mySrc[i]<<" = " << atoi(mySrc[i])<<endl;
	 }
}

 
/*
  12/02/09, eSpeed
*/
void my_strcpy(char *dest, char *src)
{ 
    while(*dest++=*src++);
}


char * my_strtok(char *s1, const char *s2)
{
    char *sbegin=NULL;
    char *send=NULL;
    static char * ssave="";
    size_t offset=0;
    
    sbegin=s1?s1:ssave;
    
    if(!sbegin) return NULL;
    
    offset=strspn(sbegin, s2);
    sbegin+=offset;
    
    if(*sbegin == '\0') {
        ssave="";
        return NULL;
    }        
    send=strpbrk(sbegin, s2);
    
    if(send && (*send != '\0'))
        *send++='\0';
        
    ssave=send;
    return sbegin;
}

void test_my_strtok()
{
    char src[]="A B";
    char *p=NULL;
    char *SPACE=" ";
    int num_tokens=0;
    
    p=my_strtok(src, SPACE);
    while(p) {
        num_tokens++;
        puts(p);
        p=my_strtok(NULL, SPACE);
    }        
    printf("\nTotal tokens handled = %d\n", num_tokens);
}



void test_flip()
{
    int n=1234;
    char str[256], dest[256];
    
    memset(str, 0, sizeof(str));
    memset(dest, 0, sizeof(dest));
    sprintf(str, "%d", n);
    reverse(str, dest);
    printf("n = %d\t reversed = %s\n", n, dest);
}    



/*
    10/22/10
    Test of min and max, works OK - don't get it yet.
    
    On some rare machines where branching is very expensive and no condition move instructions exist, 
    the above expression might be faster than the obvious approach, r = (x < y) ? x : y, 
    even though it involves two more instructions. (Typically, the obvious approach is best, though.) 
    It works because if x < y, then -(x < y) will be all ones, so r = y ^ (x ^ y) & ~0 = y ^ x ^ y = x. 
    Otherwise, if x >= y, then -(x < y) will be all zeros, so r = y ^ ((x ^ y) & 0) = y. 
    On some machines, evaluating (x < y) as 0 or 1 requires a branch instruction, so there may be no advantage. 
*/
void min_max()
{
    int x=3, y=2, r=0;
    
    /* Find min */
    r = y^((x^y) & -(x<y));
    printf("x = %d\ty = %d\t min(%d, %d) = %d\n", x,y,x,y,r);
    //  Under JDK 1.7 as per 05.15.12
    //  r=y^((x^y) & ((-1) * (x<y?1:0)));
    
    
    /* Find max */
    r = x^((x^y) & -(x<y));
    printf("x = %d\ty = %d\t max(%d, %d) = %d\n", x,y,x,y,r);
    
    //  Under JDK 1.7 as per 05.15.12
    //  r=x^((x^y) & ((-1) * (x<y?1:0)));
   
}


/*
October 2010, online test from Simplex Investments
Using %, /, +, *, how would you reverse any four-digit number in one statement?
For example, int n = 1234; int x = (*your code here* ); printf("%d\n", x); 
would print out 4321.

*/
void reverse_4_digit_number_in_1_line()
{
    int n=1234, rev;
    
    rev = (((n%1000)%100)%10)*1000 + ((((n%1000)%100))/10)*100+((n%1000)/100)*10 + n/1000;  /*  4321  */
    printf("n = %d\trev = %d\n", n, rev);   
}



/* October 2010, online test from Simplex Investments */
void problem2()
{
    unsigned short us = 6;
    unsigned short us1 = 7;
    unsigned short us3 = 8;
    
    printf("%d\n", us & 0x0);
    printf("%d\n", us | 0xFF );
    printf("%x\n", ( us & us1 ) | us3 );
    printf("%d\n", ( ( us << 2 ) & us1 ) | us3 );
}


/*
	The C library function void *bsearch(const void *key, 
										 const void *base, 
									 	 size_t nitems, 
										 size_t size, 
					 int (*compar)(const void *, const void *)) 
	function searches an array of nitems objects, 
	the initial member of which is pointed to by base, 
	for a member that matches the object pointed to, by key. 
	The size of each member of the array is specified by size.

	The contents of the array should be in ascending sorted 
	order according to the comparison function referenced by compar.
*/
/* Binary Search, O(log(n)). Added 05.01.12
    Jones & Harrow, p 571 */
int binarySearch(int *a, int size, int val)
{
    int mid, low=0, high=size-1;    
    
    while(low<=high) 
    {
        mid=(low+high)/2;
        if(a[mid] == val) return mid; /* Value is found! */
        else if(a[mid] > val) 
            high=mid-1;
        else 
            low=mid+1;
    }                        
    return -1; /* Value is NOT found */
}    


/*	02.08.17 */
int BinarySearch(int a[], int n, int x, bool searchFirst)
{
	int low=0, high=n-1, result=-1, mid=0;	

	while(low<=high) {
		mid=(low+high)/2;
		if(a[mid]==x) {
			result=mid;
			if(searchFirst) // search for first occurence
				high=mid-1; // go search left (lower indices)
			else // search for last occurence
				low=mid+1; // go search right

		}
		else if(x<a[mid]) high=mid-1;
		else low=mid+1;
	}
	return result;
}



/* 05.08.12., handles positive and negative numbers.*/
int atoi1(char *s) /*convert s to integer */
// char s[];
{
    int i, n, sign;
    for (i=0; s[i]==' '||s[i] == '\n' || s[i] == '\t'; i++)
    ;   /* skip whitespace */
    sign = 1;
    if (s[i] == '+' || s[i] == '-')  /* sign */
        sign = (s[i++] == '+') ? 1 : -1;
    for (n=0; s[i] >= '0' && s[i] <= '9'; i++)
        n = 10 * n + s[i] - '0';
    return (sign * n);
}


// Conversion to binary
//	0 is not handled as of 2.22.17
void convert2(int n)
{
    if(n>0) {
        convert2(n/2);
        cout<<n%2;
    }
}



// 	Conversion to hexadecimal
//	0 is not handled as of 2.23.17
void convert8(int n)
{
	if(n>0) {
		convert8(n/8);
		cout<<n%8;
	}
}



// Conversion to hexadecimal
//	0 is not handled as of 2.22.17
void convert16(int n)
{
    int rem=0;
    if(n>0) {
        convert16(n/16);
        rem=n%16;
        
        switch(rem) {
            case 10:
                cout<<"A";
                break;
            case 11:
                cout<<"B";
                break;
            case 12:
                cout<<"C";
                break;
            case 13:
                cout<<"D";
                break;
            case 14:
                cout<<"E";
                break;
            case 15:
                cout<<"F";
                break;
            default:
                cout<<rem;
                break;
        };
    }
}

//	07.05.13
//	sort() is in <algorithm>
int isPermutation()
{
	string s1("abcd"), s2("dbac");


	sort(s1.begin(), s1.end());		
	sort(s2.begin(), s2.end());		
	return strcmp(s1.data(), s2.data())==0?1:0;
}



//  Count number of divisors:  O(n^(1/2)) 
int count_divisors(int n)
{
    int i=1, result=0;
    if(n==1) return 1; // 1 has only 1 divisor!
    while(i*i < n) {
        if(n%i == 0) result+=2;
        ++i;
        if(i*i ==n) ++result;
    }
    return result;
}



//  Complexity:     O(n^(1/2))  Budd, p 67
int isPrime(int n)
{
    int i=2;
    while(i*i <=n) {
        if(n%i == 0) return 0;
        ++i;
    }
    return 1;
}



//  Complexity:     O(n^(1/2))
//  0 and 1 are NOT handled here!
void get_divisors(int n)
{
    vector<int> v;
    set<int> s;
    int i=1, result=0;
    
    if(n == 0 || n == 1) return;    //  For testing only, as of 12.11.14
   
    while(i*i < n) {
        if(n%i == 0) 
        {
             s.insert(i);
             s.insert(n/i);
             /*
             v.push_back(i);
             v.push_back(n/i);  */
        }
        ++i;
        if(i*i ==n)  {
            //v.push_back(i);
            s.insert(i);    // set keeps data in sorted order
        }
    }
    
    #if 0
    sort(v.begin(), v.end());
    //  print divisors
    cout<<n<<" has "<<v.size()<<" divisors: ";
    for(i=0;i<v.size();i++)
        cout<<v[i]<<" ";
        #endif
    
    cout<<n<<" has "<<s.size()<<" divisors: ";    
    std::set<int>::iterator it;
    for (it=s.begin(); it!=s.end(); ++it)
        std::cout << ' ' << *it;    
        
    cout<<endl;
//    return result;
}

//  03.27.15
int add(int a, int b)
{
    int sum = a^b; //   add without carrying
    int carry=(a&b)<<1;  // Carry, don't add
    
    if(b==0) return a;
    
    return add(sum, carry);
}



//	06.04.2020
//	0 is neither positive nor negative
int isSameSign2(int x, int y)
{
    // Since 0 has no sign, any number and 0 won't have same sign.
    if(x==0 && y==0) return 0;
    else if(x==0 || y==0) return 0;  
    else if(areEqual(x,y)) return true;
    return ((x^y)>0);
}


//	05.30.18
long swap_bits(long int n, int i, int j)
{
	if( ((n>>i)&1)!=  ((n>>j)&1))
   	{	
    	n^=(1L<<i)|(1L<<j);
   	}	
   	return n;
}



//	End of String Library Functions

// main() has only methods to be tested! 
int main(int argc, char**argv)
{
#if 0
    //   Test of fix_array().
    test_fix_array();

    //   Test of reverse()
    test_reverse();

    //  Test of sorting
    test_sorting();

    //  Test of bitwise()
    bitwise();

    test_Hanoi();
    test_PrintNum();
   

    test_static_func();
    
    if(endianness())
        cout<<"This is little endian machine!"<<endl;
    else         
        cout<<"This is big endian machine!"<<endl;
        
    test_my_atoi();           
    bitwise_ops();            
    powersof_2();
#endif

//    test_flip();    

//    cout<<my_atoi("+159")<<"\t"<<atoi1("+159");
//	test_my_atoi();
	InvertCase2();
    return 0;
}
