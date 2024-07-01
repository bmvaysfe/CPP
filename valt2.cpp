//	BST2.cpp
// Valkyrie Trading Test

/******************************************************************************
Write a program that will do the following:

1) Read three lines from standard in. The first two lines are a single integer,
   two nodes in a binary search tree. The third line is a whitespace-delimited
   list of integers. Example:

     4
     2
     8 7 13 6 2 5 1 9 11 3 4 10

2) It will then construct a binary search tree, in order, from the integers in
   line 3.

3) Further, it will calculate and show the distance between the nodes in line
   1 and 2, or print "not found".

Note:
     - Feel free to use a text editor or IDE of your choice to do this instead.
     - If you do, simply just copy-paste your code here when you're done.
******************************************************************************/

// This is C++11 code; To compile, run the following command from shell
// prompt:  g++ -std=c++11 -o BST2.exe BST2.cpp

/  Assumptions made:
/*
	1. Empty tree doesn't contain any values by definition, so they cannot be found.
	2. No duplicates in this binary search tree. Values to be found are NOT EQUAL.
	3. The nodes from val1 to val2 have to be printed. If both values val2 and val2
	   are in the tree, 2 scenarios are possible:
	   a) they are on same side of the tree
	   b) they are on different sides of the tree
	   c) one of the values can be a root
	4. Distance is calculated as number of iterations from val1 to val2.
	5. No limitations or constrains for debugging messages left for clarify.
*/	
void BSTree::calculate_and_show_distance(int val1, int val2) // 05.09.18
{
	int dist=0, leftData=0, rightData=0, caData=0;  // distance
	
	//	1. Is tree empty?
    if(isEmpty()) {
    	cout<<"The tree is empty! Values " <<val1<<" and "<<val2<<" are not found!"<<endl;
    	exit(0);
    }
    
    //	2. Are the values val1 and val2 in the tree?
    TNode* n1 = find_value(val1);
    if(!n1) {
    	cout<<"Value " <<val1<<" is not found!"<<endl;
    	exit(0);
    }
    
	TNode* n2 = find_value(val2);
    if(!n2) {
    	cout<<"Value " <<val2<<" is not found!"<<endl;
    	exit(0);
    }
    
    //	3. Start calculating distance and print it.
    //	3A. What side of the root are the values?
    TNode *t = root;
    bool is_n1_on_left = covers(t->getLeft(), n1);
    cout<<"is_n1_on_left = "<< is_n1_on_left<<endl;
    
    t = root;
    bool is_n2_on_left = covers(t->getLeft(), n2);
    cout<<"is_n2_on_left = " << is_n2_on_left<<endl;
    
    t = root;
//    cout<<"root = "<<root->getData()<<"  = "<<t->getData()<<endl;
    TNode* ca = commonAncestor(t, n1, n2);
//    if(ca  == root) cout<<"Nodes are on different sides!"<<endl;
    unordered_set<int> ht;  // store printed values to prevent double print   
 
    //	Nodes are on same side
    if(is_n1_on_left == is_n2_on_left)
    {	
    	TNode *child = is_n1_on_left?t->getLeft():t->getRight();
		cout<<"Nodes are on same side"<<endl;
    
    	TNode* ca = commonAncestor(child, n1, n2);
    	t=ca;
    	
    	caData = ca->getData();
    	leftData = val1<caData?val1:val2;
		rightData = val2>caData?val2:val1;

	
				
		cout<<"caData = "<<caData<<" leftData = "<<leftData<<"\trightData = "<<rightData<<endl;
    	bool isPrinted=false;	    	     	    	
		
		// Print data from common ancestor to left , starting from common ancestor
    	cout<<"Common Ancestor "<<t->getData()<<" "<<endl;  // print common ancestor
	   	
    
    	cout<<leftData<<" ";  // print left data here
    	ht.insert(leftData);
    	
    	while(t && t->getData()!= leftData) {
    	//	cout<<t->getData()<<" ";  // print 
    	
    		if(ht.find(t->getData())== ht.end()) { //value not found, print it and then insert
    			cout<<t->getData()<<" ";  // print 
    			ht.insert(t->getData());
    		}
    		
    		if(t->getData() > leftData)
				t=t->getLeft();
			else t=t->getRight();
			++dist;
	
			// Check if rightData is reached
			if(t->getData()==rightData) {
			//	cout<<"\nfound right data "<<rightData<<endl;
			//	cout<<rightData<<endl;
			
				if(ht.find(t->getData())== ht.end()) { //value not found, print it and then insert
	    			cout<<t->getData()<<" ";  // print 
	    			ht.insert(t->getData());
	    		}
				cout<<"\nDistance between "<< val1 <<" and "<<val2<<" is "<<dist<<endl<<endl;
			
				return;
			}
		}
				
		t=ca; // get back to common ancestor
		
		//	Print data from common ancestor to right , (starting from common ancestor)
    	while(t && t->getData()!= rightData) {
    		if(ht.find(t->getData())== ht.end()) { //value not found, print it and then insert
    			cout<<t->getData()<<" ";  // print 
    			ht.insert(t->getData());
    		}
    		else {} // value found! Don't print again
    		if(t->getData() > rightData)
				t=t->getLeft();
			else t=t->getRight();
			++dist;
		}
		
		
		if(ht.find(rightData)==ht.end()) {
			cout<<rightData<<endl;  // print right data
			ht.insert(rightData);
		}	
	}	
	else {
		cout<<"Nodes are on different side of the root!"<<endl;
		leftData = val1<=root->getData()?val1:val2;
		rightData = val2>root->getData()?val2:val1;
		cout<<"leftData = "<<leftData<<"\trightData = "<<rightData<<endl;
		
		// A. Print root.
		t=root;
		cout<<"Root is "<<t->getData()<<"\n";
		
		cout<<leftData<<" ";  // print left data here
		ht.insert(leftData);
		
		// B. Print data from root to left value (leftData)
		while(t && t->getData()!= leftData) 
		{    	  	
    		if(ht.find(t->getData())== ht.end()) { //value not found, print it and then insert
    			cout<<t->getData()<<" ";  // print 
    			ht.insert(t->getData());
    		}
    		else {} // value found! Don't print again
    			
    		if(t->getData() > leftData)
				t=t->getLeft();
			else t=t->getRight();
			++dist;
		}
		
		// C. Print data from root to right value (rightData)
		t=root;
		
    	while(t && t->getData()!= rightData) {
    	//	cout<<t->getData()<<" ";  // print 
    		if(ht.find(t->getData())== ht.end()) { //value not found, print it and then insert
    			cout<<t->getData()<<" ";  // print 
    			ht.insert(t->getData());
    		}
    		else {} // value found! Don't print again
    		
    		if(t->getData() > rightData)
				t=t->getLeft();
			else t=t->getRight();
			++dist;
		}
		cout<<rightData<<endl;  // print right data
	}
     cout<<"Distance between "<< val1 <<" and "<<val2<<" is "<<dist<<endl<<endl;
}



//	Find value in the tree, return 0 if it is not found
TNode* BSTree::find_value(int x) // 05.09.18
{
	// 1. Is it an empty tree?
	if(isEmpty()) {
    	cout<<"The tree is empty! Value " <<x<<" is not found!"<<endl;
    	exit(0);
    }
    
    TNode* t = root;
    
	// 2. Is is a root value?
	if(x==t->getData()) return t;
	
	// 3. Find out what side of tree is it and start search this side only.
	while(t && t->getData()!= x) {
		if(t->getData() > x)
			t=t->getLeft();
		else t=t->getRight();
	}
	
	if(t) {
		cout<<"Found: "<<t->getData()<<endl;
		return t;
	}
		
	//	Value is not found
	return 0;
}

main()
{

    // Test only, works OK
//#if 0    
	theTree.calculate_and_show_distance(4,  6);
	theTree.calculate_and_show_distance(7,  4);
	theTree.calculate_and_show_distance(1,  4);
	theTree.calculate_and_show_distance(10,  13);
	
	// values are at different branches of tree
    theTree.calculate_and_show_distance(6,  10); // 05.09.18
//#endif    
}
