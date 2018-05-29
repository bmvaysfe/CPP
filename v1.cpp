#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char**argv)
{
    int data[]={5,4,3,0, 131, 260, 183, 117, 5, 4, 2, 8718, 9430, 3, 1418, 5};
    vector<int> v;
    int i;
    
    vector <int>::iterator Iter1;
    pair < vector <int> :: iterator , vector <int> :: iterator > Result1, Result2, Result3;

    for(i=0; i<sizeof(data)/sizeof(data[0]); i++)
             v.push_back(data[i]);
             
    cout<<"Vector has "<<v.size()<<" elements.\n"<<endl;
    cout<<"Vector has max_size() = "<<v.max_size()<<endl;
    cout<<"v.capacity()-v.size() = "<<v.capacity()-v.size()<<endl;
    
    //  Sort array
    sort(v.begin(), v.end());
    
    //  print sorted vector
    for(i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
        
    cout<<endl<<endl;
 
    Result1 = equal_range ( v.begin ( ) , v.end ( ) , 5 );

    cout << "The lower_bound in v1 for the element with a value of 5 is: "
        << *Result1.first << "." << endl;
    cout << "The upper_bound in v1 for the element with a value of 5 is: "
        << *Result1.second << "." << endl;
    cout<<endl<<endl;
    
    // Find the equal range, i.e. how many elements are equal  
    cout <<"5 is found in vector "<< Result1.second - Result1.first 
         << " times."<<endl;      
    cout<<endl<<endl;         
             
    // test for uniq
    unique (v.begin(), v.end());       
     
    vector <int>::iterator iMax= max_element ( v.begin ( ) , v.end ( ) ); 

    cout<<"Max element = "<<*iMax<<endl;
    cout<<"Position of max element from front is "<<iMax-v.begin()<<endl; 
    cout<<"Position of max element from end is "<<v.end()-iMax<<endl; 
    cout<<endl<<endl;
    
    //              Remove duplicates after max el-t.
    v.erase(iMax+1, v.end());
    
    //  Remove 117
    vector <int>::iterator new_end;
    new_end = remove ( v.begin( ), v.end( ), 117 );
    
    //  print vector
    for(i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl<<endl;    
    
    cout<<"vector has "<<v.size()<<" elements.\n"<<endl; 
   
    vector <int>::iterator srch;
    
    srch=find(v.begin(), v.end(), 8448);
    if(srch==v.end()) cout<<"8448 is not here!\n"<<endl;
    
    //  Find and Remove 4 from vector
    srch=find(v.begin(), v.end(), 4);
    while(srch!=v.end()) {
        v.erase(srch);
        srch=find(v.begin(), v.end(), 4);
    }
    
    //  print vector
    cout<<"Vector now:"<<endl;
    for(i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n\nv.capacity() = " << v.capacity()<<endl;    //    16 
    cout<<"v.size() = " << v.size()<<endl;    // 11
    cout<<"v.capacity()-v.size() = " << v.capacity()-v.size()<<endl;    // 5
    cout<<endl<<endl;
    
    //  Multiplication of 2 vectors via array subscription
    vector<int> v1, v2;
    for(i=0; i<5; i++) {
        v1.push_back(i+1);
        v2.push_back(i+5);
    }        
    
    cout<<"Multiplication of 2 vectors via array subscription. v1 is below"
        <<endl;
    for(i=0; i<v1.size(); i++) {
        v1[i]*=v2[i];
        cout<<"v1["<<i<<"] = " << v1[i]<<endl;  // v1 is: 5,12,21,32,45
    }        
    
    
    //  Same task as above via iterators.
    

    vector<double> vd1, vd2; // same size
    
    //  Set up vectors here
    for(i=0; i<5; i++) {
        vd1.push_back((i+1)*1.0); // 1,2,3,4,5
        vd2.push_back((i+5)*1.0); // 5,6,7,8,9
    }        
    
    //  Multiply each element of v1 by corresponding element of v2
    vector<double>::iterator it1, it2;
    it1=vd1.begin();
    it2=vd2.begin();
    i=0;
    
    while(i++ != vd1.size())
    {
    	(*it1)*=(*it2);
    	++it1;
    	++it2;
    }
    
    //  Print results here
    cout<<"\nVector of DOUBLES #1"<<endl;
    for(i=0; i<vd1.size(); i++) {
        cout<<"vd1["<<i<<"] = " << vd1[i]<<endl; // vd1 is: 5,12,21,32,45
    }        
//#if 0     
    
//    The code snippet above can be re-written as following:
    
    vector<double>::iterator it=vd2.begin();
    
    //  Reset and fill vectors here
    vd1.clear();
    vd2.clear();
    
    for(i=0; i<5; i++) {
        vd1.push_back((i+1)*1.0); // 1,2,3,4,5
        vd2.push_back((i+5)*1.0); // 5,6,7,8,9
    }     
    
    i=0;
    while(i!= vd1.size())
    {
    	vd1[i]*=*it;
    	++it;
    	++i;
    }
    
    //  Print results here
    cout<<"\nVector of DOUBLES #2"<<endl;
    for(i=0; i<vd1.size(); i++) {
        cout<<"vd1["<<i<<"] = " << vd1[i]<<endl;  // vd1 is: 5,12,21,32,45
    }        
/*    
    In vector, 2 actions - sizeof() calculation+setting pointer at required element.
    Only 1 action needed for iterator to be updated.
*/

   
//#endif     
    
    //  count()
    vector<int>::iterator::difference_type result;
    result = count(v.begin(), v.end(), 260);
    cout << "\nThe number of 260s in v is: " << result << ".\n" << endl;

    
    //  count_if()
    
    
    //  
    // Using for_each to multiply each element by a Factor
    // for_each ( v1.begin ( ) , v1.end ( ) , MultValue<int> ( -2 ) );

    
    vector<int> vi;
    cout<<"Capacity of v1 is "<<vi.capacity()-vi.size()<<endl<<endl;    // 0 since vector is empty
    return 0;
}
