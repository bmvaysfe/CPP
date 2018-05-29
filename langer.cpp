//  See more: http://www.sgi.com/tech/stl/List.html

//  Examples from Angelika Langer presentation
//  Start: 08.01.01 
#include<iostream>
#include<vector>
#include<list>
using namespace std;
const int SIZE=10;
int main()
{
    
    int a[SIZE];
    int i;
    vector<int> v;
    list<int> theList;
    list<int>::iterator Iter =  theList.begin();
    
    for(i=0; i<SIZE; i++) {
        a[i]=i;
        v.push_back(a[i]);
    }        
    
    //  Copy vector content into list
//    copy(v.begin(), v.end(), theList);
    
//    copy(theList.begin(), v.begin(), v.end());  // doesn't compile
    if(theList.empty()) cout<<"List is empty!"<<endl;
    
    cout<<"\nThis is a vector"<<endl;
    
    //  Print vector content 
    for(i=0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }        
    
    //  Insert data from vector to list
    //	Update from slides 41-43
   	list<int>::iterator li=theList.begin();
    for(i=0; i<v.size(); i++) {
        li = theList.insert(li, v[i]);
        ++li;  // if iterator is not updated, acts like front inserter and data are in reverse order from 9 to 0.
    }
    //	End of update
   
   
    cout<<"\n\nList after insertion from vector"<<endl;
	cout<<theList.size()<<" items in list."<<endl;
    //  Print list content 
    list<int>::iterator Iter2=theList.begin();
    while(Iter2!=theList.end()) {
        cout<<*Iter2<<" ";
        ++Iter2;
    }    
    
    cout<<"\n\nList @ END\n"<<endl;
//    theList.remove(1);  //   remove().
    cout<<"\n\n"<<endl;
    
    return 0;    
}    
