//  Bloomberg 2014

#include<iostream>
#define PLUS1(a) ((a)+1)
using namespace std;

class A{};
class B {
    public:
        void f(){}
};

class C{
    public:
        virtual void f(){}
};        

class D{
    public:
        virtual void f(){}
        double w;
};        

class E{
    public:
        virtual void f(){}
        virtual void g(){}
        double w;
};        
int main(int argc, char**argv)
{
    cout<<"A is empty class. sizeof(A) = "<< sizeof(A) <<" byte." <<endl;  // 1 byte
    cout<<"sizeof(B) = "<< sizeof(B)<<" byte." <<endl;  // 1 byte
    cout<<"sizeof(C) = "<< sizeof(C)<<" bytes." <<endl;  // 4 bytes
    cout<<"sizeof(D) = "<< sizeof(D)<<" bytes." <<endl;  // 16 bytes
    cout<<"sizeof(E) = "<< sizeof(E)<<" bytes." <<endl;  // 16 bytes
    
    int i=2;
    int j = 4*PLUS1(i*3);
    cout<<"j = "<<j<<endl;  // 28
    return 0;
}
