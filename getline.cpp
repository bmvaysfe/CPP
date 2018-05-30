//  using streams to get getline()
// '\n' is a delimiter.

#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<typeinfo>

const char NEWLINE = '\n';  // Query delimiter
const int NUMERIC_FACTOR = 4; // used for buffer size
const int MAX_NUMBER_OF_QUERIES=4;
const int LAST_WRITTEN_QUERY_ID=10;  // ID of last written query
const int MAX_CANON=256;  // Add #include<limits.h> (in C file)or #include<climits> (in C++ file)
using namespace std;

int main(int argc, char**argv)
{
    char  *queryData[MAX_NUMBER_OF_QUERIES]={ 
                            "A B C D E 1 2 3 4 5 6 7 8 9 0;",
                            "F G H I J K L M N O 1 2 3 4 5 6 7 8 9 *;", 
                            "A;", 
                            "1;"
                            };
    char *queriesFileName="queries.txt";  // Use getenv() if needed
    char *Numeric_Query_ID="NumQuery.txt"; // Use getenv() if needed
    
    char src[NUMERIC_FACTOR*MAX_CANON+1]; // Total: 1024+1 bytes
    ofstream out;   //  Writing file stream
    ifstream in;  // Reading file stream
    int i, rc=0; 
    long last_ID=0;
    
    //  1. Open queries file for writing the queries
    out.open(queriesFileName, ios::app);
    
    //  2. Print query data in file
    for(i=0; i<MAX_NUMBER_OF_QUERIES; i++)
        out<<queryData[i]<<endl;
        
    //  3. Close queries file
    out.close();
    
    //  4. Open in stream for reading.
    in.open(queriesFileName, ios::in);

    //  5. Read data from file and print it
    while(in.good())
    {
        memset(src, 0, sizeof(src));
        //  in.getline(src, MAX_CANON, ';');  // in Version #1
        in.getline(src, MAX_CANON, NEWLINE);
        cout<<src<<endl;    // print queries
    }        
    
    //  6. Close in stream.
    in.close(); 
    
    
    
    //  7. Open stream to write queries numbers
    out.open(Numeric_Query_ID, ios::out);
    
    //  8. Write IDs of written queries in the stream
    for(i=0; i<LAST_WRITTEN_QUERY_ID; i++)
        out<<i+1<<endl;
        
    //  9. Close stream
    out.close();
    
    //  10. Open file with IDs of written Queries
    
    FILE *fp=fopen(Numeric_Query_ID, "r");
    if(!fp){
        cout<<"fopen() failed in "<<__FILE__<<" at line "<<__LINE__<<endl;
    }
    
    //  fseek() will put it at the right place since newline char at end
    //  is ignored (at least on my platform).
    //  - sign indicates that you're looking back from the very end of file.
    //
    //  If you plan to write just a number of last written query in file
    //  Numeric_Query_ID, you need read the only number from the very beginning 
    //  of this file. 
    //  From this point, I see 2 alternatives:
    //  1. Remove fseek() below, fscanf() will handle it.
    //  2. If you like system calls, use rc=fseek(fp, 0, SEEK_SET);
    rc=fseek(fp, -(sizeof(long)), SEEK_END);
    if(rc != 0) {
        cout<<"fseek() failed!"<<endl;
    }
    
    //  11. Get id of last written query and print it.
    fscanf(fp, "%ld", &last_ID);
    cout<<"ID of last written query is "<< last_ID<<endl;
 
    //  12. Close stream
    fclose(fp);
    return 0;
}
