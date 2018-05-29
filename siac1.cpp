//  SIAC C++ test, #5

#include<iostream>
using namespace std;

class B {
    public:
        virtual void foo();
        virtual void bar()=0;
};

class D: public B {
    public:
        void bar();
    protected:
        void foo();
};                
        
int main(int argc, char**argv)
{
//    B b;  // Cannot instantiate an abstract class.
    D d;
    
    return 0;
}
