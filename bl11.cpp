//  Bloomberg phone screen 06.15.11

#include<iostream>
using namespace std;

class Base {
    public:
        virtual void clear()=0;
        Base () { 
            cout<<"Base::Base()"<<endl;  
//            test();
         }
       // virtual 
        ~Base() { 
            cout<<"Base::~Base()"<<endl;  
//            clear();  // cannot call pure virtual f-n 
         }
//         void test() { cout<<"Base::test()"<<endl; }
};

class Derived: public Base {
    public:
        Derived() { cout<<"Derived::Derived()"<<endl; }
        ~Derived() { cout<<"Derived::~Derived()"<<endl; }
        virtual void clear(){ ; }
};        

void f()
{
    cout<<"\nIn f()"<<endl;
    Derived d;
    cout<<"Leaving f()\n"<<endl;
}            

class A {};
class B {};

class C: public A, public B
{
};

//  if &c is &b 
bool is(B& b, C &c)
{
#if 0
//    cout<<"is()"<<endl;
    cout<<"Arg1 is "<<typeid(b).name()<<"\t Arg2 is "<<typeid(c).name()<<endl;
//    if(typeid(b) == typeid(C&)) return false;   
    if( &b == &c || typeid(&c) != typeid(A&) )
        return true;
    else 
        return false;        
#endif
    try {
        B b1 = dynamic_cast<b>c;
    }
    catch(...)
    {
        cout<<"Cast failed..."<<endl;
        return false;
    }        
    return true;





}    


    
int main(int argc, char**argv)
{
#if 0    
    cout<<typeid(Derived *).name()<<endl;   // P7Derived
    cout<<typeid(Derived &).name()<<endl;   // 7Derived

    if(typeid(Derived *) == typeid(Derived &))
        cout<<"typeid(Derived *) == typeid(Derived &)"<<endl;
    else 
        cout<<"typeid(Derived *) != typeid(Derived &)"<<endl;        

    f();
#endif
    
    // 
    cout<<"\nTest of Abstract Class"<<endl;
    Base *bp=new Derived;  // Base() is called 1st, Derived() is called 2nd.
//    cout<<typeid(bp).name()<<endl;   // P4Base
//    Derived d;
      
    if(typeid(bp)==typeid(Base *)) cout<<"bp is Base*"<<endl;
    if(bp) {
        delete bp;    // ~Derived() is called if ~Base() is virtual;
                      //~Base() destructor is called
        bp=0;
    }   

#if 0         
    
    cout<<"typeid(bp).name() = "<<typeid(bp).name()<<endl;  // P4Base, i.e. Base*
//    cout<<"typeid(*bp).name() ="<<typeid(*bp).name()<<endl;   // Compiles OK, but terminated by Runtime
    cout<<"END of Test of Abstract Class\n"<<endl;
    
    //  Test of is()
    cout<<"Test of is()"<<endl;
    A a;
    A *pA = &a;
//    A& ar=&a;
    B b;
    B *pB=&b;
    C c;
    C *pC = &c;
    cout<<"typeid(pC).name() = "<<typeid(pC).name()<<endl;
    if(typeid(pC) == typeid(C*)) {
        cout<<"typeid(pC) == typeid(C*)"<<endl;
    }        
    cout<<"typeid(*pC).name() = "<<typeid(*pC).name()<<endl;
    if(typeid(*pC) == typeid(C)) {
        cout<<"typeid(*pC) == typeid(C)"<<endl;
    }
    
    if(typeid(C) == typeid(A))
        cout<<"typeid(C) == typeid(A)"<<endl;
    else
        cout<<"typeid(C) != typeid(A)"<<endl;        
        
    if(typeid(c) == typeid(b))
        cout<<"typeid(c) == typeid(b)"<<endl;
    else
        cout<<"typeid(c) != typeid(b)"<<endl;    
                
    //  Test dynamic cast as cross cast from B* to A*, no cross cast is allowed.
//    cout<<typeid(dynamic_cast<A*>(pB).name())<<endl;
    
//    cout<<"is(&a, &b)="<<is(&a, &b)<<endl;

    //  Test of is()
    cout<<"Test of is()"<<endl;
    test_is();
    
#endif    
    Derived d;
    return 0;
}
