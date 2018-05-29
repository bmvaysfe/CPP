// SIAC C++ test #4

#include<iostream>
using namespace std;

class B
{
    public:
        virtual void foo() { cout<<"In B::foo()"<<endl; }
        virtual void bar(int x=5) { cout<<"In B::bar()"<<endl; }
};

class D:public B 
{        
    public:
        virtual void foo() { cout<<"In D::foo()"<<endl; }
        virtual void bar() { cout<<"In D::bar()"<<endl; }
};

int main(int argc, char**argv)
{
    B b;
    D d;
    B* pB=&d;
    
    b.foo();
    pB->foo();
    pB->bar();  // D::bar() is hidden , bar() in D has different signature
                //void bar(void); COMPILE-BINDING is here.
                // IF bar() at line 10 has signature void bar(), 
                //output will be In D::bar().
    d.bar();
    (*pB).foo();
    return 0;
}

// Default argument is NOT determined at run-time;
// it's done at compile-time and is based on the 
// type of  object through which function is being invoked, 
// i.e. B* . 
// Function of D with Base class default parameters will run.


/* Output:
    
In B::foo()
In D::foo()
In B::bar()
In D::bar()
In D::foo()


*/    
