#include<iostream>
using namespace std;
class A
{
      int x;
      public:
             A(){x=0;}
      friend void B::dump();
};
             
class B
{
      public:
             B(){}
      void dump(){cout<<A.x<<endl;}
      
};
     // void B::dump(){cout<<A.x<<endl;}       
class C:public B
{
      public:
             C(){}     
};
      
      
      
      
      
      




int main(int argc, char**argv)
{
    C c;
    c.dump();
    return 0;
}
