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

void parse_in_C(char *src, char *delimiter)
{
	char *pToken=0;
	
	pToken = strtok(src, delimiter);
	while(pToken) {
		cout<<pToken<<endl;
		pToken = strtok(NULL, delimiter);	
	}
}
 
 

void parse_CPP(string input, string dlmtr) 
{
	string token;
	cout<<__FUNCTION__<<endl;
	cout<<input<<endl;
	
	//	Validation
	if(input.empty() || dlmtr.empty())	return;
//	int start=0, end=0, len=0, i=0; 
	
	size_t start=0, end;
	
	while( (end=input.find(dlmtr, start)) != string::npos)
	{
		
		token=input.substr(start, end-start);
		cout<<token<<endl;
		start=end+1;  //	for whitespace		
	}
	
	//	Last token
	token=input.substr(start);
	cout<<token<<endl;
	
	
	
	
}




	 
int main(int argc, char**argv)
{
   	char src[10]="A B C";
   	char src2[10]="A:B:C";
   	char delimiter[2]=" ";
    char delimiter2[2]=":";
    
//    parse_in_C(src, delimiter);
//    parse_in_C(src2, delimiter2);
    
      
    parse_CPP(src, delimiter);
    parse_CPP(src2, delimiter2);
    return 0;
}
