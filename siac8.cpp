//  From SIAC C++ test, #8

#include<iostream>
using namespace std;

class Base
{
    public:
        void f() { cout<<"In Base::f()"<<endl; }
        virtual void g(int aX=1) { cout<<"Base::g() with aX="<<aX<<endl; }
};


class Derived1:virtual public Base
{    
    public:
        void f() { cout<<"In Derived1::f()"<<endl; }
};

class Derived2:virtual public Base
{    
    public:
        void h() { cout<<"In Derived1::h()"<<endl; }
};

class MyClass: public Derived1, public Derived2
{
    public:
        void f() { cout<<"In MyClass::f()"<<endl; }
};

class D: public Base
{
    public:
        virtual void g(int aX=2){ cout<<"D::g() with aX="<<aX<<endl; }
};


int main(int argc, char**argv)
{

    Base *bptr=new D;
    D* dptr=(D*)bptr;
    MyClass obj;
    
    bptr->g();  // points to Base in D but runs D::g() with aX=1;
    dptr->g();  // points to D in D,  C-cast brokes vtable???
    obj.f();


    D* d1=new D;
    d1->g();
    
    
    Base* b1=new D;
    d1->g();
    
    cout<<"Part #2!"<<endl;
    
    dynamic_cast<D*>(b1)->g();  // runs D::g() with aX=2 properly.
    dynamic_cast<Base*>(b1)->g();  // runs Base::g() with aX=1 properly.
    delete bptr;
    delete d1;
    delete b1;
            
    return 0;
}

// Default argument is NOT determined at run-time;
// it's done at compile-time and is based on the 
// type of  object through which function is being invoked, 
// i.e. Base*. 
// Function of D with Base class default parameters will run.

/*

D::g() with aX=1
D::g() with aX=2
In MyClass::f()

Part #2!
D::g() with aX=2
D::g() with aX=2
D::g() with aX=2
Base::g() with aX=1

*/
