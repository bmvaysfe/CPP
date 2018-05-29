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

void print_digits(int n){
	int a[6] = {0}, i=0;
	printf("%d = ", n);
	a[0] = n/100000;
	a[1] = ((n%100000)/10000);
	a[2] = (((n%100000)%10000)/1000);
	a[3] = ((((n%100000)%10000)%1000))/100;
	a[4] = ((((n%100000)%10000)%1000)%100)/10;
	a[5] = n%10;
	for(i=0;i<6;i++) {
		printf("%d", a[i]);
	}
	puts("\n\n");
}

int count_sums()
{
	int count=0, n=100000;
	
	for(;n<1000000;n++) {
		if( (n/100000 + 
		     ((n%100000)/10000) + (((n%100000)%10000)/1000)) == 
		     (((((n%100000)%10000)%1000))/100) + 
			 (((((n%100000)%10000)%1000)%100)/10)+ n%10)
		     ++count;		     
	}
	return count;  //	50412
}
  
int main(int argc, char**argv)
{
	#if 0
	char *p="abc"   ;
	cout<<*p<<endl; // 	a
	cout<<(*p+1)<<endl;	//	98
	cout<<((*p)+1)<<endl;	// 98
    cout<<(p+1)<<endl;	//	bc
    
    cout<<"\n\nTesting C-style printing"<<endl;

    //	Testing C-style printing
    printf("%c\n", *p); // a
    printf("%c\n", *p+1); // b
    printf("%c\n", ((*p)+1)); // b
	printf("%s\n", p+1); //bc
   	puts(p); // abc
   	#endif
   	
   	print_digits(123456);
   	int x = count_sums();
   	cout<<"Total x = "<<x<<endl;
   	
    return 0;
}
