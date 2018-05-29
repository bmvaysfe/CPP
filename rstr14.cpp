//	C++ 14 @ ideone.com
//	Line 9 requires C++ 11 support. BloodShed 5.11 doesn't provide it.
#include <iostream>
#include <typeinfo>
#include <string>
#include <cstring>
using namespace std;

int main() 
{
	auto x = R"( * Can you assist me? * )"; // lenght=24, sizeof=8
	char *p;
	const	char *cp="CP";
	
	std::cout << x;
	cout<<typeid(x).name()<<endl;  // x is const char *
	cout<<typeid(p).name()<<endl;
	cout<<typeid(cp).name()<<endl;
	
	//	Raw string and Unicode
	auto str = R"delimiter(The String Data \ Stuff " )delimiter";
	auto str1 = u8R"XXX(I'm a "raw UTF-8" string.)XXX"; // strlen(str1)=25 sizeof(str1)=4
	auto str2 = uR"*(This is a "raw UTF-16" string.)*";
	auto str3 = UR"(This is a "raw UTF-32" string.)";
	cout<<str<<endl;
	cout<<str1<<endl;
	//	problems with printing of str2 and str3 on ideone.com
	return 0;
}


/*
* Can you assist me? * PKc
Pc
PKc
PKc
The String Data \ Stuff " 
4
25




*/
