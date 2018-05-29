#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<cmath>
#include<cassert>  // for assert()
#include<set>
#include<cstdio>
using namespace std;

class Fraction
{
	public:
		int num;
		int denom;
		
		Fraction(int n=0, int d=1) {
			num=n;
			denom=d;
		}
		
		~Fraction(){}
		
		void print()
		{
			cout<<num<<"/"<<denom;
		}
		
		Fraction operator+(const Fraction &A)
		{
		//	cout<<"operator+"<<endl;
			int nn = num*A.denom+denom*A.num;
			int denn = denom*A.denom;
			int cd=gcd(nn, denn);
		//	cout<<"operator+"<<"cd = "<<cd<<endl;
	
			return Fraction(nn/cd, denn/cd);
		}

	private:
		
		
		int gcd1(int m, int n)
		{
		    assert(n>0 && m>0);
		    
		    while(m!=n)
		    {
		        if(n>m)
		            n-=m;
		        else
		            m-=n;
		    }            
		    return n;
		}
		
		int gcd(int a, int b)
		{
			return b==0?a:gcd(b, a%b);
		}
		
};
  
int main(int argc, char**argv)
{
   	Fraction f12(1,2), f14(1,4);
   	
   	
   	f12.print();
   	cout<<endl;
   	f14.print();
   	cout<<endl;
   	Fraction f34=f12+f14;
 //  	f34.reduce();
   	f34.print();
   	
   	
    
    return 0;
}
