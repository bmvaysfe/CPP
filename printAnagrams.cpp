//	printAnagrams.cpp
//  Version with Hash Map using unordered_map container

/*
	 Write me a program that accepts a block of text (English words), 
	 and outputs the groups of words that are anagrams of each other. 
	 For example, "apt", "tap" and "pat" are anagrams of each other.
*/

/*
	My assumptions are that block of text is a line read from a file
	or stdin. Words are separated by spaces, all words are lower case 
	for simplicity. The code below doesn't read it from file, but it's easy to do.
*/


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map> // for unordered_map C++ 11 implementation
using namespace std;

void parse_line(vector<string>&vs, string input, string dlmtr) 
{
	string token;
	
	//	Validation
	if(input.empty() || dlmtr.empty())	return;

	
	size_t start=0, end;
	
	while( (end=input.find(dlmtr, start)) != string::npos)
	{
		
		token=input.substr(start, end-start);
		vs.push_back(token);
		start=end+1;  //	for whitespace		
	}
	
	//	Last token
	token=input.substr(start);
	vs.push_back(token);
}


//	04.01.26
//	Version with Hash Map using unordered_map container.
//	The retrieval time from hash map is O(1)
void printAnagrams3(string src)
{
	string SPACE = " ";
	string tmpString, tmpValue;
	vector<string> vs;
	
	parse_line(vs, src, SPACE);
	cout<<"\n"<<__FUNCTION__<<"()"<<endl;
	cout<<"Version with Hash Map using unordered_map container\n"<<endl;
	cout<<"Source string: "<<src<<endl;
	
	vector<string>sortedAns;
	
//	unordered_set<string> sortedKeys;
	unordered_map<string, string> sortedAnagrams;
	
	string sortedKey;
	int i=0;
	for(i=0;i<vs.size();i++) {
		sortedKey.assign(vs[i]);  // assign original value
		sort(sortedKey.begin(), sortedKey.end());  // sort original value, it will be the key in hashtable and map.
		
		tmpValue = sortedAnagrams[sortedKey];
		tmpValue.append(" ");
		tmpValue.append(vs[i]);
			
		//	 Append a value
		sortedAnagrams[sortedKey] = tmpValue;  // Possibly make it shorter?
		tmpValue.clear();				
		
	}
	
	//	traverse the updated map
	unordered_map<string, string>::iterator m_it2 = sortedAnagrams.begin();
	cout<<"\nResulting Hash Map"<<endl; 
    while(m_it2!=sortedAnagrams.end())
    {    
        cout<<m_it2->second<<endl;    
        ++m_it2;
    } 
}



int main(int argc, char**argv)
{

	string src = "abd def pat tap apt dab bad fed efd deaf fead";  // test string
	printAnagrams3(src);
	return 0;
}