/*  Google interview problem from youtube.com 
 *  C++11
find if a collection has 2 numbers whose sum=8
[1,2,3,4] sum = 8 NO
[1,2,4,4] sum = 8 YES

*/


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

#include<unordered_set> // for Hash Table C++ 11 implementation
using namespace std;




// O(n)
bool HasPairWithSum(const vector<int>data, int sum)
{

	unordered_set<int>comp; // complements

	for(int value:data) {
		if(comp.find(value)!=comp.end())
			return true;
		comp.insert(sum-value);  // Should it be emplace()?
	}
	return false;
}


void f1()
{
	unordered_set<int>ht2;
	
	int a[]={0,1,2,-1, 8, 5, 256, -1};
    int i=0;
    
    for(i=0;i<sizeof(a)/sizeof(a[0]);i++) {
    	if(ht2.find(a[i])==ht2.end()) {
    		// value is not in table
    		ht2.insert(a[i]);
    	}
    	else {
    		cout<<"Value "<<a[i]<<" is in table already"<<endl;
    	}
	}
	cout<<"Table has "<<ht2.size()<<" items."<<endl;
}

void f2()
{
	
}

  
int main(int argc, char**argv)
{
   /*
   	int data1[] = {1,2,3,9};
   	int data2[] = {1,2,4,4};
   	int test_sum = 8;
   	int i=0;
   	vector<int> v;
   	
   	for(i=0;i<sizeof(data1)/sizeof(data1[0]);i++) {
   		v.push_back(data1[i]);
   	}
   	
   	if(HasPairWithSum(v, test_sum)) cout<<"Yes"<<endl;
   	else cout<<"NO"<<endl;
   	
   	// Clear vector
   	v.clear();
   	
   	// Load another data set in vector v
   	for(i=0;i<sizeof(data2)/sizeof(data2[0]);i++) {
   		v.push_back(data2[i]);
   	}
   	
   	if(HasPairWithSum(v, test_sum)) cout<<"Yes"<<endl;
   	else cout<<"NO"<<endl;
   	
   	// Clear vector
   	v.clear();
    */
    f1();
    return 0;
}

