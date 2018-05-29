// Virtual Friend Function Idiom Example

#include<iostream>
using namespace std;

class Base
{
    friend ostream& operator<<(ostream& o, const Base &b);
    public:
        Base(){}
        ~Base(){}
        
    protected:
        virtual void printOn(ostream &o)const;
};        



ostream& operator<<(ostream& o, const Base &b)
{
    b.printOn(o);
    return o;
}

void Base::printOn(ostream &o)const
{
    o<<"Base::printOn()"<<endl;
}

class Derived:public Base
{
    public:
        Derived(){}
        ~Derived(){}
        
    protected:
        virtual void printOn(ostream &o)const;        
};

void Derived::printOn(ostream &o)const
{
    Base::printOn(o); // print base class info
    o<<"Derived::printOn()"<<endl;
}
            
int main(int argc, char**argv)
{
    Base b;
    Derived d;
    
    cout<<b<<endl;
    cout<<d<<endl;
    
    return 0;
}

/* Output:
    
    Base::printOn()
    
    Base::printOn()
    Derived::printOn()
*/    
