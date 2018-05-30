//  tail.cpp
//  Implements Unix tail utility without default parameters.
//  This version doesn't handle stdin case.

#include<iostream>
#include<fstream>
#include<queue>
#include<string>
#include<cstdlib>
using namespace std;

  
int main(int argc, char**argv)
{
    string line;
    queue<string>q;
    int i=0, count=0, size=0, number_of_tail_lines=atoi(argv[1])*(-1);
    
    //	1. Check for proper number of arguments here
	if(argc != 3) {
		cout<<"Improper number of arguments! Usage: tail -number file_name\n"<<endl;
		exit(1);
	}
    
    if(number_of_tail_lines==0) {
        cout<<"Number of lines to tail cannot be 0."<<endl;
        exit(1);
	}
	
    ifstream in(argv[2]);  // Reading file stream
    
    if (in.good())
    {
        while ( getline (in,line) )
        {
//          cout << line << '\n';
          q.push(line);
          
        }
        in.close();
    }
    size=q.size();
    cout<<"Queue has "<<size<<" items."<<endl;
    int start=0; // line to start print from
    if(size>number_of_tail_lines)
        start=size-number_of_tail_lines;
    else  start=0;
          
    cout<<"start = "<<start<<endl;   
        
    //  Drain queue 
    while(!q.empty()) {
        line=q.front();
        q.pop();
        if(count>=start) {
            cout<<line<<endl;
        }
        ++count;
    }
    
    
    
    
    
    
    
    return 0;
}
