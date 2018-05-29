#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
struct A{};
class B{};
class C
{
    int *p;
};

class D
{
    int &p;
};

const int ROWS=3;
const int COLUMNS=4;

void f(int m[][COLUMNS]) /* Pass dimensions! */
{
    printf("In f(): sizeof(m)=%u bytes\n", sizeof(m)); /* 4 bytes */
}

void test_sizes()
{
typedef struct 
{
    char x;
    int y;
} FOO;

FOO bar;

cout<<"sizeof(FOO) = "<<sizeof(FOO)<<endl;
cout<<"sizeof(bar) = "<<sizeof(bar)<<endl;

}   
    
class K {
    public:
        K(){}
        ~K(){}
    	virtual void go();
    	virtual void go1();
};


class Base
{
    public:
        Base(){}
        ~Base(){}
        void go();
    private:
        char c;
        short s;
        int i;
        long l;
};
        
struct CC
{
      char c;
      char *pc;
};
            
int main()
{
    int a[ROWS][COLUMNS]={0};
    printf("Size of some fundamental data types\n\n");
    printf("char: %3u byte\n", sizeof(char));
    printf("short: %3u bytes\n", sizeof(short));
    printf("int: %3u bytes\n", sizeof(int));
    printf("long: %3u bytes\n", sizeof(long));
    printf("unsigned: %3u bytes\n", sizeof(unsigned));
    printf("unsigned long: %3u bytes\n", sizeof(unsigned long));
    printf("float: %3u bytes\n", sizeof(float));
    printf("double: %3u bytes\n", sizeof(double));
    printf("long double: %3u bytes\n", sizeof(long double)); // 12
    printf("size of an empty structure is %3u bytes\n", sizeof(struct A)); // 1
    printf("size of an empty class is %3u bytes\n", sizeof(B)); // 1
    printf("size of an class with ptr is %3u bytes\n", sizeof(C));  // 4
    printf("size of an class with reference is %3u bytes\n", sizeof(D)); //4
    printf("sizeof(void *)=%u bytes\n", sizeof(void *)); /* 4 bytes */
    
    /* size of matrix */
    printf("sizeof(a)=%u bytes\n", sizeof(a)); /* 48 bytes=ROWS*COLUMNS*sizeof(int) */
    f(a);
    std::cout<<"sizeof(std::vector<int>)="<<sizeof(std::vector<int>)<<std::endl; //12 bytes
    std::cout<<"sizeof(std::vector<std::string>)="<<sizeof(std::vector<std::string>)<<std::endl; //12 bytes
    
    // post-increment
    int i = 4; 
    i = ( i++) + (i++); 

    std::cout<<"( i++) + (i++) = "<<i<<std::endl; // 10
    
    i=4;    // reset
    i = ( i++) * (i++); // 16?
    std::cout<<"( i++) * (i++) = "<<i<<std::endl;
    B b;
    
    test_sizes();
	std::cout<<"sizeof(K)="<<sizeof(K)<<std::endl;  // 4
	std::cout<<"sizeof(Base)="<<sizeof(Base)<<std::endl;  // 12
	std::cout<<"sizeof(CC)="<<sizeof(CC)<<std::endl;  //   8
	
	vector<int> VI;
	std::cout<<"sizeof(VI) = "<<sizeof(VI)<<" size = "<<VI.size()<<" capacity = "<<VI.capacity()<<endl;
	VI.push_back(260);
	std::cout<<"sizeof(VI) = "<<sizeof(VI)<<" size = "<<VI.size()<<" capacity = "<<VI.capacity()<<endl;
	
    return 0;
}
