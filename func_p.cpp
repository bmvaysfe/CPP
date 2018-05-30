//  Function pointers    

#include <iostream>

using namespace std;

float Plus(float a, float b)
{
    return a+b;
}


float Minus(float a, float b)
{
    return a-b;
}


float Mult(float a, float b)
{
    return a*b;
}

float Div(float a, float b)
{
    return a/b;
}

typedef float (*FP)(float, float);  // FP - type
int main()
{
    float a=2, b=5;
    FP vtable[4]={Plus, Minus, Mult, Div};  //  Table 
    int i;

    for(i=0; i<4; i++)
        cout<<vtable[i](a, b)<<endl;
    FP f2=vtable[0];
    float res=f2(a,b);
    cout<<res<<endl;

    FP f3=&Minus;
    res=f3(a,b);
    cout<<res<<endl;
    return 0;
}
