#include <map>
#include <string>
#include<iostream>
#include<utility>
#include<typeinfo>
#include<unordered_set>
using namespace std;
/*
Which of the following functions should you use to return whether or not 
each of these keys exists in the map?
--------------------------------------------------------------------
*/
bool is_in_map_0(std::map<std::string, std::string> &map,
                 const std::string &name)
{
    return !map[name].empty();
}

/*
bool is_in_map_1(const std::map<std::string, std::string> &map,
                 const std::string &name)
{
    return !map[name].empty();
}
*/
bool is_in_map_2(const std::map<std::string, std::string> &map,
                 const std::string &name)
{
    return map.find(name) != map.end();
}

bool is_in_map_3(const std::map<std::string, std::string> &map,
                 const std::string &name)
{
    return map.find(name) == map.end();
}



void test_map_iterator()
{
    map<char, int> m;
    int i;
    char key='A';
    pair<char, int> myPair;
    
    //  1.  Insertion
    for(i=0;i<26;i++)
    {
        pair<char, int> thePair(key, i+1);
        m.insert(thePair);
        ++key;
    }
    
    if(!m.empty()) {
        cout<<"Map has "<<m.size()<<" items."<<endl;
    }
    else {
        cout<<"Map has "<<m.size()<<" items."<<endl;
    }
    
    //  2. Traverse and print
    map<char, int>::iterator m_it=m.begin();
    
    while(m_it!=m.end())
    {
//        cout<<m_it->first<<" "<<m_it->second<<endl;
        myPair=*m_it;
        cout<<myPair.first<<" "<<myPair.second<<endl;
        ++m_it;
    }
    
    //  Clear contents
    m.clear();
    
    if(!m.empty()) {
        cout<<"\nMap has "<<m.size()<<" items."<<endl;
    }
    else {
        cout<<"\nMap has "<<m.size()<<" items."<<endl;
    }
    
}
        
void test_bracket_operator()
{
	map<string,string> m;
    string add(" CAB");
    m["ABC"]="ABC";
    cout<<m.size()<<" items in map"<<endl;
    m["ABC"]+=add;
    map<string, string>::iterator m_it=m.begin();
    pair<string, string> myPair;
    while(m_it!= m.end()) {
        myPair = *m_it;
        cout<<myPair.first<<" | "<<myPair.second<<endl;
        ++m_it;
    }
}


/*
	How would you design a class that behaves similar 
	to a Java Map <Date,Object> except that get() returns 
	the mapped value for not only an exact match but 
	also for the latest Date in the Map
*/
void test_map()
{
	map<char, int> m;
	m['a']=1;
	m['b']=0;
	m['c']=1;
	m['d']=-1;
	m['e']=1;
	cout<<"map has "<<m.size()<<" items"<<endl;
	int key=1;
	auto it1=m.find(key);
	
	
	auto Begin = m.begin();
	auto End=m.end();
	auto it=Begin;
	multimap<int, char>m2; // inverted m1: values of m1 are keys in m2
	
	//	Traverse source map m and insert its contents into multimap m2
	//	where key of source map m is the value in m2
	while(it!=End) {
		cout<<"Inserting into multimap "<<it->second<<" "<<it->first<<endl;
		pair<int, char> p(it->second, it->first);
		m2.insert(p);
		++it;
	}
	cout<<"Miltimap has "<<m2.size()<<" items"<<endl;
	
	auto ret = m2.equal_range(key);  // find 1
//	cout<<ret->first<<" "<<ret->second<<endl;
	
	//	Add here to look for max value of m2 - it's key in m
	for (auto  it1=ret.first; it1!=ret.second; ++it1)
      std::cout << ' ' << it1->second<<endl;
      // complexity O(log(n))
}

void test_map2()
{
	pair<char, int>p('A',1);
	map<char, int>m;
	
	cout<<"Map has "<<m.size()<<" items"<<endl;
	pair<char,int> p2('Z', -1);
	pair<char, int>pa[]={p,p2};
//	pair<char, int>paq[2]={ (<'a',0>), (<'b',-1>)};
	m['A']=1;
    m['B']=3;
    cout<<"Map has "<<m.size()<<" items"<<endl;
    ++m['A'];  // Now 'A' has 2
    auto it=m.begin();
    auto END=m.end();
    while(it!=END) {
        cout<<it->first<<"\t"<<it->second<<endl;
        ++it;
    }
}

/*
Given two lists Aand B, and B is an anagram of A. B is an anagram of A means B
is made by randomizing the order of the elements in A.
We want to find an index mapping P, from A to B. A mapping P[i] = j means the
ith element in A appears in B at index j.
These lists A and B may contain duplicates. If there are multiple answers,
output any of them.
For example, given
A = [12, 28, 46, 32, 50]
B = [50, 12, 32, 46, 28]
We should return
[1, 4, 3, 2, 0]
as P[0] = 1 because the 0th element of A appears at B[1], and P[1] = 4 because
the 1st element of A appears at B[4], and so on.
Note:
A, B have equal lengths in range [1, 100].
A[i], B[i] are integers in range [0, 10^5].


*/
void AnagramMappings()
{
    int A[] = {12, 28, 46, 32, 50};
    int B[] = {50, 12, 32, 46, 28};
    unordered_set<int>ht;
    map<int,int>mB;
    int sizeA=sizeof(A)/sizeof(int);
    int sizeB=sizeof(B)/sizeof(int);
    cout<<"sizeA = "<<sizeA<<"\tsizeB = "<<sizeB<<endl;
    int i=0, pos=0;
    //  1. put B items in hash table and store items with index in map
    for(i=0;i<sizeB;++i) {
        ht.insert(B[i]);
        pair<int, int> pb(B[i], i);
        mB.insert(pb);
    }
    
    //  traverse A, check its items in hash table
    for(i=0;i<sizeA;++i) {
        if(ht.find(A[i])!=ht.end()) { // item is found, retrieve index
        
        //  Store pos in vector or other collection to return
            pos=mB[A[i]];
            cout<<"Found "<<A[i]<<" in B in position: "<<pos<<endl;
            
            //	Optionally: put pos in vector, return vector
        }
    }       
}




int main()
{
#if 0    
    std::map<std::string, std::string> map;

    map["Bugs Bunny"] = "What's up, doc?";
    map["itsop2"]  = "hyperterminal";
    map["Elmer Fudd"] = "That kwazy wabbit!";
    map["Pinky"]      = "What are we going to do tonight, Brain?";
    map["atrium9"]="main terminal";
    map["atrium2"]="abandoned";
    map["Silent Bob"] = "";
    
    map[""]="12345";
    map[""]="3.14";
/*
    Budd, p 402
    if(map1.find(4) != map1.end) ...

*/
//  Find returns *pair; which has 2 members first and second.
    std::cout<<(map.find("Pinky"))->second<<std::endl;
    std::cout<<typeid((map.find("Pinky"))).name()<<std::endl;
    
    if(map.find("itsop1") == map.end()) std::cout<<"itsop1 is NOT there!"<<std::endl;
    
    std::map<std::string, std::string>::iterator  p=map.find("atrium9");
    std::cout<<p->first<<" "<<p->second<<std::endl;
    
    p=map.find("");
    std::cout<<p->first<<" "<<p->second<<std::endl; // print both values of the pair
#endif

//    test_map_iterator();
    test_map();
    return 0;
}    
