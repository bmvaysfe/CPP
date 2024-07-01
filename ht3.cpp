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

#include<unordered_set> // for Hash Table C++ 11 implementation
using namespace std;

void HashTableIteration_Buckets()
{
	std::unordered_set<std::string> myset =
  {"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune"};

  std::cout << "myset contains:";
  for ( auto it = myset.begin(); it != myset.end(); ++it )
    std::cout << " " << *it;
  std::cout << std::endl;

  std::cout << "myset's buckets contain:\n";
  for ( unsigned i = 0; i < myset.bucket_count(); ++i) {
    std::cout << "bucket #" << i << " contains:";
    for ( auto local_it = myset.begin(i); local_it!= myset.end(i); ++local_it )
      std::cout << " " << *local_it;
    std::cout << std::endl;
  }
}



void a_not_b_b_not_a(int *a, int size_of_a, int *b, int size_of_b)
{
	int i=0;
	
	unordered_set<int> ht_a;  // Hash table of elements of array a
	unordered_set<int> ht_b;  // Hash table of elements of array b
	
	// 1. Put elements of array a in hash table ht_a
	for(i=0;i<size_of_a;i++) {
		ht_a.insert(a[i]);
	}
	
	// 2. Put elements of array b in hash table ht_b
	for(i=0;i<size_of_b;i++) {
		ht_b.insert(b[i]);
	}
	
	vector<int> a_not_b;
	
	//	3. What elements are in a and not in b?
	for(i=0; i<size_of_a; i++) {
		if(ht_b.find(a[i])== ht_b.end())  // Element a[i] is not in array b
			a_not_b.push_back(a[i]);
	}
	
	//	4. Print a_not_b - elements that are in a and not in b
	if(!a_not_b.empty()) {
		cout<<"a_not_b is not empty and has "<<a_not_b.size()<<" items"<<endl;
		// print content here
		
		for(i=0;i<a_not_b.size();i++) 
			cout<<a_not_b[i]<<" ";
		cout<<"\n\n***\n\n"<<endl;
	}
	
	vector<int> b_not_a;
	//	5. What elements are in b and not in a?
	for(i=0; i<size_of_b; i++) {
		if(ht_a.find(b[i])== ht_a.end())  // Element b[i] is not in array a
			b_not_a.push_back(b[i]);
	}
	
	
	//	6. Print b_not_a - elements that are in b and not in a
	if(!b_not_a.empty()) {
		cout<<"b_not_a is not empty and has "<<b_not_a.size()<<" items"<<endl;
		// print content here
		
		for(i=0;i<b_not_a.size();i++) 
			cout<<b_not_a[i]<<" ";
		cout<<"\n\n***\n\n"<<endl;
	}
}




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
	
	If line has n words in it, total complexity will be O(nlog(n)).
*/
void printAnagrams(string src)
{
	string SPACE = " ";
	string tmpString, tmpValue;
	vector<string> vs;
	
	parse_line(vs, src, SPACE);
	cout<<src<<endl;
	
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
		#if 0
			map<string, string>::iterator m_it;
			m_it = sortedAnagrams.find(sortedKey);
			pair<string,string> entry = *m_it;
			
			tmpValue.assign(entry.second);
			tmpValue.append(" ");
			tmpValue.append(vs[i]);
		
			//	 remove old value, insert an updated 
			sortedAnagrams.erase(m_it);
			
			pair<string, string> updatedEntry(sortedKey, tmpValue);
		//	entry.second.assign(tmpValue);
			sortedAnagrams.insert(updatedEntry);
		//	sortedAnagrams.insert(pair<string, string>(sortedKey, tmpValue));
		#endif
			sortedAnagrams[sortedKey]+=SPACE+vs[i];  //	update entry
			
		}		
	} // end for
	
	
	//	traverse the updated map
	map<string, string>::iterator m_it2 = sortedAnagrams.begin();
	 
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


//	O(n) - no external storage
void removeDuplicates()
{

	vector<int> v={1,1,1,2,3,5,-1, 0, 0, -2, 0, -5, 5};
	cout<<"Vector has "<<v.size()<<" items."<<endl;
   	unordered_set<int> ht;
   
   int i=0;
   auto it=v.begin();
   while(i<v.size()) {
       auto it=v.begin();
       // Insert item im hash table
       if(ht.find( *(it+i)) == ht.end()) {
           ht.insert(*(it+i));
         //  ++i;
       }
       else {
           cout<<"Duplicate found "<<*(it+i)<<endl;
           // Remove duplicate here
           v.erase(it+i);
           --i;
       }
       if(i<0) { 
           i=-1;
       }
       ++i;
   }
   cout<<"AAA Vector has "<<v.size()<<" items."<<endl;
   cout<<"Here is cleaned vector"<<endl;
   for(i=0;i<v.size();++i)
        cout<<v[i]<<" ";
    cout<<"\n\nDone"<<endl;
}    

// O(n)
void removeDuplicatesFromVector()
{
	vector<int>v = {0,1,-1,3, 0, 12, 3, -1, 131, 260, 6172, 1};
	queue<int>q;
	unordered_set<int> ht; // hash table
	
	auto it=v.begin();
	auto end=v.end();
	
	while(it!=end) {
		// If item is not in hash table, insert it
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


int main(int argc, char**argv)
{

	string src = "abd def pat tap apt dab bad fed efd deaf fead";  // test string
	printAnagrams(src);
	
#if 0	
	int a[]={1,2,3,4,5,6};
	int sum=7;
	cout<<"\n\nPrinting pairs that sum to "<<sum<<endl;
	printPairs(a, sizeof(a)/sizeof(a[0]), sum);   
#endif	
//	removeDuplicatesFromVector();
	return 0;
}
