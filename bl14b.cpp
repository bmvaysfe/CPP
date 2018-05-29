//  Reference tests

#include<iostream>
using namespace std;

  
int main(int argc, char**argv)
{
    int i=12;
    int &r=i;
    r+=r/4;
    int *p = &r;
    *p+=r;
    cout<<"i = "<<i<<"\tr = "<<r<<endl; // 30 30
   
    
    return 0;
}
