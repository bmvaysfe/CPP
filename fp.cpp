//  fp.cpp


#include "FileProcessor.h"
const int MAX_NUMBER_OF_QUERIES=4;
const int NUMERIC_FACTOR = 4; // used for buffer size
//const int MAX_CANON=256;  // Add #include<limits.h> (in C file)or #include<climits> (in C++ file)
const int LAST_WRITTEN_QUERY_ID=10;  // ID of last written query
using namespace std;

int main(int argc, char**argv)
{
    int i=0;
    string str;
    char *queriesFileName="queries.txt";  // Use getenv() if needed
    char *Numeric_Query_ID="NumQuery.txt"; // Use getenv() if needed   
    char src[NUMERIC_FACTOR*MAX_CANON+1]; // Total: 1024+1 bytes
    char  *queryData[MAX_NUMBER_OF_QUERIES]={ 
                            "A B C D E 1 2 3 4 5 6 7 8 9 0;",
                            "F G H I J K L M N O 1 2 3 4 5 6 7 8 9 *;", 
                            "A;", 
                            "1;"
                            };
    const char *pQuery;
                                
    // 1. Open stream for writing                         
    FileProcessor out(queriesFileName, WRITE_MODE); 
    
    //  2. Print query data in file
    for(i=0; i<MAX_NUMBER_OF_QUERIES; i++) {
        str.assign(queryData[i]);  //  set str
        out.write(str); //<<endl;
        str.clear();  // clear buffer
    }
    
    //  3. Close queries file
    out.closeStream(WRITE_MODE);
    
    //  4. Open stream for reading
    FileProcessor in(queriesFileName, READ_MODE); 
    
    cout<<"READING QUERIES DATA"<<endl;
    
    //  5. Read Queries from file and print them
    for(i=0; i<MAX_NUMBER_OF_QUERIES; i++) {
        pQuery = in.read();
        cout<<pQuery<<endl;
    }
    
    //  6. Close queries file
    in.closeStream(READ_MODE);
    
    //  7. Dumping queries IDs into Numquery.txt
    //     Open stream to write queries numbers
    ofstream ids;
    ids.open(Numeric_Query_ID, ios::out);
    
    //  8. Write IDs of written queries in the stream
    for(i=0; i<LAST_WRITTEN_QUERY_ID; i++)
        ids<<i+1<<endl;
        
    //  9. Close stream
    ids.close();
    
    //  10. Open stream to read file and print contents
//    FileProcessor in2(Numeric_Query_ID, READ_MODE); 
    ifstream in3;
    in3.open(Numeric_Query_ID, ios::in);
    int pos=0;
    
    in3.seekg(0, ios::end);
    pos=in3.tellg();
    cout<<"pos = "<<pos<<endl;
    
    for(i=0; i<LAST_WRITTEN_QUERY_ID; i++) {
        
        
        
    }
    in3.close();
//    in2.closeStream(READ_MODE);
    return 0;
}

//  End of fp.cpp
