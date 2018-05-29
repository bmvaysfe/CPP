//  vect.cpp
//  Test of some vector APIs

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric> // for accumulate()
using namespace std;

int main()
{
    vector <int> v;
    int a[] = { -1, -2, 3, 4,6,7,9, 5 ,131,1712, 167, 2140, 8448, 412, 260, 95};
    int i, array_size=sizeof(a)/sizeof(a[0]), sum=0;
    
    
    cout<< "Empty vector has size "<<v.size()<<endl;
    cout<< "Empty vector has capacity "<<v.capacity()<<endl;
        
    for(i=0; i<array_size; i++)
        v.push_back(a[i]);
      
    cout<< "After insertion vector has size "<<v.size()<<endl;
    cout<< "After insertion vector has capacity "<<v.capacity()<<endl;    

#if 0        
    //  Traverse as an array   
    for(i=0; i<array_size; i++)
        cout<<"v["<<i<<"] = "<<v[i]<<endl;
#endif        
    
    
    //  Sort array
    sort(v.begin(), v.end());
    
    //  Traverse sorted vector using iterator
    vector <int> :: iterator it;
    for(it=v.begin(); it!=v.end(); it++) {
        cout<<*it<<endl;
        sum+=(*it);
    }        
    cout<<"sum = "<<sum<<endl;
    
    //  Find 95
    it = find(v.begin(), v.end(), 95);
    cout << *it<<endl;
    cout<<v.end() - it << endl;

    //   Find 0
    it = find(v.begin(), v.end(), 0);
/*    cout << v.end() == (it)<<endl;
     if(it == 0)
        cout << "0 is not in vector!"<<endl;
        */
        
    //  Find the sum
    sum = accumulate(v.begin(), v.end(), 0);
    cout<<"sum = "<<sum<<endl;
            
    return 0;
}

