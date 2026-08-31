//	Hash Table Problems



#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<cmath>
#include<cassert>  // for assert()
#include<set>
#include<map>
#include<cstdio>
#include<utility>  // for std::pair
#include<unordered_set> // for Hash Table C++ 11 implementation
#include<unordered_map> // for unordered_map C++ 11 implementation
#include<typeinfo>
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
	
	//	Iterate through hash table, for illustrative purposes only
   	cout<<"\n\nIterate through hash table, for illustrative purposes only"<<endl;
 
   	for ( auto it = comp.begin(); it != comp.end(); ++it )
    	std::cout << " " << *it;
  	std::cout << std::endl;
   	
	return false;
}



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






/*
	 Write me a program that accepts a block of text (English words), 
	 and outputs the groups of words that are anagrams of each other. 
	 For example, “apt”, “tap” and “pat” are anagrams of each other.
*/

/*
	My assumptions are that block of text is a line read from a file
	or stdin. Words are separated by spaces, all words are lower case 
	for simplicity.
*/
//	In printAnagram() the retrieval time from the map is O(log(n)).
void printAnagrams(string src)
{
	string SPACE = " ";
	string tmpString, tmpValue;
	vector<string> vs;
	
	parse_line(vs, src, SPACE);
	cout<<__FUNCTION__<<"()"<<endl;
	cout<<"Version with Hash Table and Map\n"<<endl;
	cout<<"Source string: "<<src<<endl;
	vector<string>sortedAns;
	
	unordered_set<string> sortedKeys;
	map<string, string> sortedAnagrams;
	
	string sortedKey;
	int i=0;
	for(i=0;i<vs.size();i++) {
		sortedKey.assign(vs[i]);  // assign original value
		sort(sortedKey.begin(), sortedKey.end());  // sort original value, it will be the key in hashtable and map.
	
		// Insert sorted key into hash table if entry is not present
		if(sortedKeys.find(sortedKey)==sortedKeys.end()) { 
			sortedKeys.insert(sortedKey);  // insert into hash table
			
			// insert into map
			tmpString.assign(vs[i]); // store original value
			pair<string,string>mypair(sortedKey, tmpString.data());
		
			sortedAnagrams.insert(mypair);	
			tmpString.clear();
		}
		else {
			// Update entry in map
			// Entry found, update list of anagrams for sorted key by appending original value to value string
			map<string, string>::iterator m_it;
			m_it = sortedAnagrams.find(sortedKey);
			pair<string,string> entry = *m_it;
			
			tmpValue.assign(entry.second);
			tmpValue.append(" ");
			tmpValue.append(vs[i]);
		
			//	 remove old value, insert aupdated 
			sortedAnagrams.erase(m_it);
			
			pair<string, string> updatedEntry(sortedKey, tmpValue);
		//	entry.second.assign(tmpValue);
			sortedAnagrams.insert(updatedEntry);
		//	sortedAnagrams.insert(pair<string, string>(sortedKey, tmpValue));
		
		}		
	} // end for
	
	
	//	traverse the updated map
	map<string, string>::iterator m_it2 = sortedAnagrams.begin();
	cout<<"\nResulting Map"<<endl;  
    while(m_it2!=sortedAnagrams.end())
    {    
        cout<<m_it2->second<<endl;    
        ++m_it2;
    } 
}


/*

	Write a program that that accepts an array of integers, 
	and prints out the distinct pairs of these integers that sum to 7. 
	For example, if the input is [1, 2, 3, 4, 5, 6], 
	the output could be (1,6), (2, 5), (3, 4), 
	or (6,1), (5, 2), (4,3). Different combinations of the same pair of numbers e.g, 
	(1, 6) and (6, 1) are not distinct. In this case, you should only print 
	(1, 6) or (6, 1) but not both of them.

*/
void printPairs(int *a, int size, int sum)
{
	unordered_set<int>comp; // complements
	int i=0;
	for(i=0; i<size;i++)
	{
		if(comp.find(a[i])!=comp.end())
		{
			// Print pair
			cout<<"{"<<a[i]<<","<<sum - a[i]<<"}"<<endl;
		}	
		comp.insert(sum-a[i]);  
	}
}



//	O(n)
void removeDuplicatesFromVector()
{
	vector<int>v = {0,1,-1,3, 0, 12, 3, -1, 131, 260, 6172, 1};
	queue<int>q;
	unordered_set<int> ht; // hash table
	
	auto it=v.begin();
	auto end=v.end();
	
	while(it!=end) {
		// item is not in hash table, insert it
		if(ht.find(*it)==ht.end())  {
			ht.insert(*it);
			q.push(*it);
		}
		++it;
	}
	
	//	Clear vector
	v.clear();
	
	//	Insert values from queue
	while(!q.empty()) {
		v.push_back(q.front());
		q.pop();
	}
	
	cout<<"Vector has "<<v.size()<<" items"<<endl;
	auto it1=v.begin();
	auto end1=v.end();
	while(it1!=end1) {
		cout<<*it1<<" ";
		++it1;
	}
	cout<<"\nDone"<<endl;
}

//  03.25.26
//	This function does the same work as printAnagrams(). The only difference is unordered_map is used here
//	to make the retrieval time O(1). In printAnagram() the retrieval time from the map is O(log(n)).
void printAnagrams2(string src)
{
	string SPACE = " ";
	string tmpString, tmpValue;
	vector<string> vs;
	
	parse_line(vs, src, SPACE);
	cout<<src<<endl;
	
	vector<string>sortedAns;
	
	unordered_set<string> sortedKeys;
	unordered_map<string, string> sortedAnagrams;
	
	string sortedKey;
	int i=0;
	for(i=0;i<vs.size();i++) {
		sortedKey.assign(vs[i]);  // assign original value
		sort(sortedKey.begin(), sortedKey.end());  // sort original value, it will be the key in hashtable and map.
	
		// Insert sorted key into hash table if entry is not present
		if(sortedKeys.find(sortedKey)==sortedKeys.end()) { 
			sortedKeys.insert(sortedKey);  // insert into hash table
			
			// insert into map
			tmpString.assign(vs[i]); // store original value								
			sortedAnagrams[sortedKey]= tmpString;
			tmpString.clear();
		}
		else {
			// Update entry in map
			// Entry found, update list of anagrams for sorted key by appending original value to value string
		
			tmpValue = sortedAnagrams[sortedKey];
			tmpValue.append(" ");
			tmpValue.append(vs[i]);
			
			//	 remove old value, insert aupdated 
			sortedAnagrams[sortedKey] = tmpValue;
			tmpValue.clear();				
		}		
	} // end for
	

	//	traverse the updated map
	unordered_map<string, string>::iterator m_it2 = sortedAnagrams.begin();
	 
    while(m_it2!=sortedAnagrams.end())
    {    
        cout<<m_it2->second<<endl;    
        ++m_it2;
    } 
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
	cout<<"\n\n"<<__FUNCTION__<<"()"<<endl;
	cout<<"Version with Hash Map using unordered_map container\n"<<endl;
	cout<<"Source string: "<<src<<endl;
	
	vector<string>sortedAns;
	
	unordered_set<string> sortedKeys;
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

//	Given 2 strings, return common characters in both.
void get_common_characters_from_2_strings(string A, string B)
{
	string both;
	unordered_set<char> htc;
	int i=0;
	int length_A=A.length();
	int length_B=B.length();
	
	if(length_A ==0 || length_B==0) {
		cout<<"Both strings ["<<A<<"] and B["<<B<<"] have NO common characters."<<endl;
		return;
	}		
	//	Insert characters of string A into hash table
	while(i<length_A) {
		htc.insert(A[i]);
		++i;
	}
	
	//	Traverse B string and check hash table content: if character is there, add it to string both.
	i=0;
	while(i<length_B) {
		if(htc.find(B[i])!=htc.end()) {
			both+=B[i];
		}
		++i;
	}
	if(both.length()==0) // empty string
		cout<<"Both strings ["<<A<<"] and B["<<B<<"] have NO common characters."<<endl;
	else
		cout<<"Both strings ["<<A<<"] and B["<<B<<"] have common characters: "<<both<<endl;
}



//	08.17.26
//	Find numbers in array and their indices that add to a given sum.
void hasPairIndexWithSum(const vector<int>data, int sum)
{
	unordered_map<int,int>comp; // complements
	int i=0; // index of current element
	const int ComplementIndex = -1;

	for(int value:data) {
		auto RC = comp.find(value);
		if(RC == comp.end()) { // Value is NOT found
			pair<int,int> tmp = make_pair(value,i);
			comp.insert(tmp);
		
			//	Fill complement value - if it exists, 
			//	it will be encountered later during iteration.
			//	Index of complement is -1 to distinguish from values inserted before. 
			pair<int,int> tmp2 = make_pair(sum - value,ComplementIndex);
			comp.insert(tmp2);
		}	
		else { // Found complement entry which is = value at index i
		//	Retrieve sum - value at this point
			auto tmp3 = comp.find(sum-value);
			cout<<"Found AAA value = "<<tmp3->first<<" at position "<<tmp3->second<<endl;
			cout<<"Found BBB value = "<<value<<" at position "<<i<<endl<<endl;
		}
		++i; // increment index, go to next element
	}
}


int main(int argc, char**argv)
{
#if 0
	string src = "abd def pat tap apt dab bad fed efd deaf fead";  // test string
	printAnagrams(src);
	printAnagrams3(src);

	int a[]={1,2,3,4,5,6};
	int sum=7;
	cout<<"\n\nPrinting pairs that sum to "<<sum<<endl;
	printPairs(a, sizeof(a)/sizeof(a[0]), sum);   

	removeDuplicatesFromVector();
		
	string A="abcdef", B="efgha", AA="", BB="asdfs", A2="1234", B2="xcvb";
	get_common_characters_from_2_strings(A,B);
	get_common_characters_from_2_strings(AA,BB);
	get_common_characters_from_2_strings(A2,B2);
#endif

	int a[]={1,2,3,4,5,6};
	int sum=7, size = sizeof(a)/sizeof(a[0]);
	int i=0;
	vector<int>data;
	for(;i<size;++i)
		data.push_back(a[i]);

	hasPairIndexWithSum(data, sum);
	return 0;
}
