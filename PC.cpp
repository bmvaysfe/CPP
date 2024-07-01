//	Permutation from "Programming Interviews Exposed", p97
//	Combination from "Programming Interviews Exposed", p99
//
//
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

	

void doPermute(char *in, string *out, bool*used, int length, int level)
{
	if(level == length) {
        cout<<*out<<endl;
		return;
	}

	for(int i=0; i<length; i++) 
	{
		if(used[i]) continue;

        (*out)+=in[i];
		used[i]=true;
		doPermute(in, out, used, length, level+1);
		used[i]=false;
        out->erase(out->length()-1);
	}
}


void permute(string str)
{
	int length=str.length();
	bool *used = new bool[length];
	memset(used, false, length);
	string *out = new string; 
	char *in = const_cast<char*>(str.c_str());
	
	doPermute(in, out, used, length, 0);
	
}



void doCombine(char *instr, string *outstr, int length, int level, int start)
{

	for(int i=start; i<length;i++) 
	{
		(*outstr)+=instr[i];
        cout<<*outstr<<endl;
        
		if(i<length-1) {
			doCombine(instr, outstr, length, level+1, i+1);
		}
		outstr->erase(outstr->length()-1);
	}
}


void combine(string str)
{
	int length=str.length();
	char *instr=const_cast<char*>(str.c_str());  
	string *outstr = new string;
	doCombine(instr, outstr, length, 0, 0);
}
	

int main(int argc, char**argv)
{
	string str="123"; // Gives 3! permutations

	//	Test Permutation
	permute(str);

	//	Test combination
	combine(str);
}

