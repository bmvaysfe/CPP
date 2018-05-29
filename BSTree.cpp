//	BSTree.cpp

#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<queue>

using namespace std;

class TNode
{
	public:
        TNode()
    	{
    		data=0;
    		left=0;
    		right=0;
    	}
    
    	TNode(int x)
    	{
    		data=x;
    		left=0;
    		right=0;
    	}
    
    	TNode* getLeft()
    	{
    		return left;
    	}
    
    	void setLeft(TNode* left_node)
    	{
    		left=left_node;
    	}
    
    	void setRight(TNode* right_node)
    	{
    		right=right_node;
    	}
    
    	TNode* getRight()
    	{
    		return right;
    	}
    
    	void setData(int x)
    	{
    		data=x;
    	}
    
    	int getData()
    	{
    		return data;
    	}

	private:
        int data;
	   	TNode* left;
		TNode* right;
};



class BSTree 
{
	public:
		BSTree():root(0){}	
		BSTree(const BSTree&);
		BSTree& operator=(const BSTree&);
		~BSTree();

		int isEmpty() const { return root==0; }
		void insertLeft(TNode* node, int x);
		void insertRight(TNode* node, int x);
		void insert(int x);
		void InOrderTraverse() const;
		void PreOrderTraverse() const;
		void PostOrderTraverse() const;
		void InOrderTraverse_Iterative() const; // 04.07.14
		void PreOrderTraverse_Iterative() const; // 04.07.14
		void PostOrderTraverse_Iterative() const;  // 04.07.14
		int ipl() const;
		int countNodes() const;
		int countLeaves() const;
		int depth() const;
		int getHeight() const;  //  01.19.15
		int isBalanced() const; //  01.19.15
		void print_binary_tree_level_order() const; //  05.04.15
		void print_tree_perimeter(); const//	10.22.15

	private:
		TNode* root;

		void intrav(TNode* t) const;
		void pretrav(TNode* t) const;
		void posttrav(TNode* t) const;
		void InOrderTraverse_Iterative(TNode* t) const; // 04.07.14
		void PreOrderTraverse_Iterative(TNode *t) const;  // 04.07.14
		void PostOrderTraverse_Iterative(TNode *) const;  // 04.07.14
		int ipl(TNode* t, int d) const;
		int countNodes(TNode* t) const;
		int countLeaves(TNode* t) const;
		int depth(TNode* t) const;
		void destroy(TNode* t);
		void makeRoot(int x);
		int getHeight(TNode *) const;  //  01.19.15
		int isBalanced(TNode *) const; //  01.19.15
		bool covers(TNode *root, TNode *p) const; //    02.05.15
		TNode* commonAncestorHelper(TNode *root, TNode *p, TNode *q) const; //  02.09.15
		TNode* commonAncestor(TNode *root, TNode *p, TNode *q) const;   //  02.09.15
		void print_binary_tree_level_order(TNode *t) const; //  05.04.15
		void _print_tree_perimeter();  const//	10.22.15
		void print_leaves(TNode*); 	const //	10.22.15
};



//	Copy constructor
BSTree::BSTree(const BSTree& tree)
{
	#if 0
	if(tree.isEmpty()) {
		//	log ?
	}
	#endif
	
	queue<TNode*>q;
	q.push(tree.root);
	
	while(!q.empty()) {
		TNode *current = q.front();
		insert(current->getData());
		
		if(current->getLeft())
			q.push(current->getLeft());
		
		if(current->getRight())		
			q.push(current->getRight());	
		q.pop();			
	}
}



//	Assignment operator
BSTree& BSTree::operator=(const BSTree& tree)
{
	//	what if tree is empty?
	
	if(this != &tree) {
		destroy(root);
		
		queue<TNode*>q;
		q.push(tree.root);
		
		//	Traverse tree and insert
		while(!q.empty()) {
			TNode *current = q.front();
			insert(current->getData());
			
			if(current->getLeft())
				q.push(current->getLeft());
			
			if(current->getRight())		
				q.push(current->getRight());	
			q.pop();			
		}
	}
	return *this;
}



BSTree::~BSTree()
{
	destroy(root);
	root=0;
}



void BSTree::insertLeft(TNode* node, int x)
{
	TNode* n=new TNode(x);
	node->setLeft(n);
}

void BSTree::insertRight(TNode* node, int x)
{
	TNode* n=new TNode(x);
	node->setRight(n);
}

void BSTree::insert(int x)
{
	TNode* t;
	TNode* q=0;

	if(isEmpty())
	{
		makeRoot(x);
		return;
	}

	t=root;
	while((t!=0) && (x != t->getData()))
	{
		q=t;
		if(x < t->getData())
			t=t->getLeft();
		else 
			t=t->getRight();
	}

	if(t!=0)
		return; // Value is inserted in tree ALREADY
	else {
		if(x<q->getData())
			insertLeft(q, x);
		else
			insertRight(q,x);
	}
}

void BSTree::InOrderTraverse() const
{
	intrav(root);
}

void BSTree::PreOrderTraverse() const
{
	pretrav(root);
}

void BSTree::PostOrderTraverse() const
{
	posttrav(root);
}

//	Internal path length
//	Root has the depth of 0.
//	01/23/08
int BSTree::ipl() const
{
	return ipl(root->getLeft(), 0)+ipl(root->getRight(), 0);
}

//	Count nodes
int BSTree::countNodes() const
{
	return countNodes(root);
}


	//	Count leaves
int BSTree::countLeaves() const
{
	return countLeaves(root);
}


//	Depth of tree
int BSTree::depth() const
{
	return max(depth(root->getLeft()), 
               depth(root->getRight())); // root has depth 0
}



//	Left, Root, Right
void BSTree::intrav(TNode* t) const
{
	if(t==0)
		return;

	intrav(t->getLeft());
	cout<<t->getData()<<" ";
	intrav(t->getRight());
}



//	Root, Left, Right
void BSTree::pretrav(TNode* t) const
{
	if(t==0)
		return;

	cout<<t->getData()<<" ";
	pretrav(t->getLeft());
	pretrav(t->getRight());
}

//	Left, Right, Root
void BSTree::posttrav(TNode* t) const
{
	if(t==0)
		return;

	posttrav(t->getLeft());
	posttrav(t->getRight());
	cout<<t->getData()<<" ";
}



//	Internal path length
int BSTree::ipl(TNode* t, int d) const
{
	if(t==0)
		return 0;

	return 1+d+ipl(t->getRight(), d+1)+ipl(t->getLeft(), d+1);
}

int BSTree::countNodes(TNode* t) const
{
	if(t==0)
		return 0;
	return 1+countNodes(t->getLeft())+countNodes(t->getRight());
}

int BSTree::countLeaves(TNode* t) const
{
	if(t==0)
		return 0;
	if(t->getLeft()==0 && t->getRight()==0)
		return 1;
	return countLeaves(t->getLeft())+countLeaves(t->getRight());
}

int BSTree::depth(TNode* t) const
{
	if(t==0)
		return 0;
	return max(depth(t->getLeft()), depth(t->getRight()))+1;
}



void BSTree::destroy(TNode* t)
{
	if(t!=0) {
		destroy(t->getLeft());
		destroy(t->getRight());
		delete t;
	}
}


void BSTree::makeRoot(int x)
{
	root=new TNode(x);
}




#if 0
/**
         * Internal method to remove from a subtree.
         * x is the item to remove.
         * t is the node that roots the tree.
         * Set the new root.
         */
template <class Comparable>
        void BinarySearchTree<Comparable>::
        remove( const Comparable & x, BinaryNode<Comparable> * & t ) const
        {
            if( t == NULL )
                return;   // Item not found; do nothing
            if( x < t->element )
                remove( x, t->left );
            else if( t->element < x )
                remove( x, t->right );
            else if( t->left != NULL && t->right != NULL ) // Two children
            {
                t->element = findMin( t->right )->element;
                remove( t->element, t->right );
            }
            else
            {
                BinaryNode<Comparable> *oldNode = t;
                t = ( t->left != NULL ) ? t->left : t->right;
                delete oldNode;
            }
        }

#endif 


void BSTree::InOrderTraverse_Iterative() const
{
    InOrderTraverse_Iterative(root);  
}



void BSTree::InOrderTraverse_Iterative(TNode* t) const
{
    cout<<"\n\nIn BSTree::InOrderTraverse_Iterative(TNode* t)"<<endl;
    stack <TNode *> s;
    int isDone=0;
    
    if(!t) return;
    
    while(!isDone )
    {
        if(t) {
            s.push(t);
            t=t->getLeft();
        }
        else {
            if(!s.empty()) {
                t=s.top();
                s.pop();
                cout<<t->getData()<<" ";
                t=t->getRight();
            }
            else isDone=1;  
        }
    }
}



void BSTree::PreOrderTraverse_Iterative() const
{
    PreOrderTraverse_Iterative(root);  
}



void BSTree::PreOrderTraverse_Iterative(TNode *t) const
{
    cout<<"\n\nIn BSTree::PreOrderTraverse_Iterative(TNode* t)"<<endl;
    stack <TNode *> s;
    
    if(!t) return;
    
    //  1. Push root on stack
    s.push(t);
    
    /*  2. Pop all items one by one. Do following for every popped item:
           a) print it
           b) push its right child
           c) push its left child
        Note that right child is pushed first so that left is processed first */
    while(!s.empty())
    {
        t=s.top();
        s.pop();
        cout<<t->getData()<<" ";
        if(t->getRight())
            s.push(t->getRight());
        if(t->getLeft())            
            s.push(t->getLeft());
    }
}


void BSTree::PostOrderTraverse_Iterative() const
{
    PostOrderTraverse_Iterative(root);  
}



void BSTree::PostOrderTraverse_Iterative(TNode *t) const
{
    cout<<"\n\nIn BSTree::PostOrderTraverse_Iterative(TNode* t)"<<endl;
    stack <TNode *> s;
    
    if(!t) return;
    
    do
    {
        // 1. Move to leftmost node
        while (t)
        {
            // 2. Push root's right child and then root to stack.
            if (t->getRight())
                s.push(t->getRight());
            s.push(t);
 
            // 3. Set root as root's left child 
            t = t->getLeft();
        }
 
        // Pop an item from stack and set it as root   
        t = s.top();
        s.pop();
        
        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before root
        TNode *p;
        if(!s.empty()) {
            p = s.top();
        }
        if (t&& t->getRight() && p == t->getRight())
        {
            if(!s.empty()) {
                s.pop();  // remove right child from stack 
            }
            s.push(t);  // push root back to stack
            t = t->getRight(); // change root so that the right
                                // child is processed next
        }
        else  // Else print root's data and set root as NULL
        {
	    cout<< t->getData() <<" ";
            t = 0;
        }
    } while (!s.empty());
}



int BSTree::getHeight() const //  01.19.15
{
    return getHeight(root);
}



int BSTree::getHeight(TNode *t) const //  01.19.15
{
    if(!t) return 0; // Base case
    return max(getHeight(t->getLeft()), getHeight(t->getRight()))+1;
}



int BSTree::isBalanced() const //  01.19.15
{
    return isBalanced(root);
}



int BSTree::isBalanced(TNode *t) const //  01.19.15
{
	if(!t) return 1;
    int heightDiff = getHeight(t->getLeft()) - getHeight(t->getRight());
    if(abs(heightDiff) > 1) return 0;
    else {
        return isBalanced(t->getLeft()) && isBalanced(t->getRight());
    }   
}



//  02.09.15
//  Returns true if p is a descendent of root
bool BSTree::covers(TNode *root, TNode *p) const
{
    if(!root) return false;
    if(root == p) return true;
    return covers(root->getLeft(),p) || covers(root->getRight(), p);
}



//  02.09.15
TNode* BSTree::commonAncestorHelper(TNode *root, TNode *p, TNode *q) const
{
    if(!root) return 0;
    if(root == p || root == q) return root;
    
    bool is_p_on_left = covers(root->getLeft(), p);
    bool is_q_on_left = covers(root->getLeft(), q);
    
    //  If p and q are on different sides, return root
    if(is_p_on_left != is_q_on_left) return root;
    
    //  Else, they're on the same side. Traverse this side
    TNode * child_side = is_p_on_left?root->getLeft():root->getRight();
    return commonAncestorHelper(child_side, p, q);
}



//  02.09.15
TNode* BSTree::commonAncestor(TNode* root, TNode* p, TNode* q) const
{
    //  Error check
    if(!covers(root, p) || !covers(root, q))    return 0;
    
    return commonAncestorHelper(root, p, q);
}



void BSTree::print_binary_tree_level_order() const //  05.04.15
{
    print_binary_tree_level_order(root);
}



void BSTree::print_binary_tree_level_order(TNode *t) const //  05.04.15
{
    if(!t) return;
    
    queue<TNode*>q;
    
    q.push(t);
    int count=q.size();
    while(!q.empty()) {
        TNode *current = q.front();
        cout<<current->getData()<<" ";
        if(current->getLeft())
            q.push(current->getLeft());
        if(current->getRight())
            q.push(current->getRight());
        q.pop();
        
        //  use --count or count--
        if(count == 0) {
            cout<<endl;
            count = q.size();
        }
    }
}


// #endif


void  BSTree::print_tree_perimeter() const//	10.22.15
{
	_print_tree_perimeter(); //	10.22.15
}

void BSTree::_print_tree_perimeter() const //	10.22.15
{
	if(isEmpty()) return;
	
	TNode* t=root;
	
	//	1. Print root
	cout<<t->getData()<<" ";
	
	//	2. Print left branch except leaves
	t=t->getLeft();
	while(t) {
		if( (!t->getLeft()) && (!t->getRight()))  // check if no leaf here?
		{
			//	print only iff it's not a leaf
			cout<<t->getData()<<" ";
			if(t->getLeft())
				t=t->getLeft();
			else
				t=t->getRight();
		}
	}
	
	
	
	//	3. Print right branch except leaves
	t=root->getRight();
	while(t) { 
		if( (!t->getLeft()) && (!t->getRight()))
		{
			//	print only iff it's not a leaf
			cout<<t->getData()<<" ";
			if(t->getRight())
				t=t->getRight();
			else
				t=t->getLeft();
		}
	}
	
	
	//	4. Print here leaves only
	print_leaves(root->getLeft());
	print_leaves(root->getRight());
}



//	10.22.15
void BSTree::print_leaves(TNode*t) const
{
	if(!t) return;
	if((!t->getLeft()) && (!t->getRight())) {
		cout<<t->getData()<<" ";
	}
	
	print_leaves(t->getLeft());
	print_leaves(t->getRight());
}





int main()
{

	int data[]={50, 30, 70, 20, 40, 60, 80};
	int i=0, totalNodes=0, totalLeaves=0, theDepth=0, valToFind=83;
    int array_size;
    
	BSTree theTree;
	assert(theTree.isEmpty());
	array_size=sizeof(data)/sizeof(data[0]);
	for(i=0; i<array_size; i++)
	{
		theTree.insert(data[i]);
	}

	//	Inorder Traverse: Left, Root, Right
	cout<<"Inorder Traverse"<<endl;
	theTree.InOrderTraverse();

	cout<<endl;

	//	Preorder Traverse: Root, Left, Right
	cout<<"Preorder Traverse"<<endl;
	theTree.PreOrderTraverse();

	cout<<endl;

	//	Postorder Traverse: Left, Right, Root
	cout<<"Postorder Traverse"<<endl;
	theTree.PostOrderTraverse();
	
	//	Internal path length
	int iplen=theTree.ipl();
	cout<<"\n\nInternal Path Length = "<<iplen<<endl;

	//	New data
	int data2[]={15,24,32,48,55,64,72,93};
    array_size=sizeof(data2)/sizeof(data2[0]);
	for(i=0; i<array_size; i++)
	{
		theTree.insert(data2[i]);
	}

	//	Internal path length
	iplen=theTree.ipl();
	cout<<"\n\nInternal Path Length = "<<iplen<<endl;

	// Count nodes
	totalNodes=theTree.countNodes();
	cout<<"Total: "<<totalNodes<<" nodes"<<endl;

	// Count leaves
	totalLeaves=theTree.countLeaves();	
	cout<<"Total: "<<totalLeaves<<" leaves"<<endl;


	theTree.insert(95);

	//	Test of tree depth
	theDepth=theTree.depth();
	cout<<"Depth of tree: "<<theDepth<<endl;

	BSTree tree2;
	assert(tree2.isEmpty());
	int data3[]={50, 60, 30, 70, 72, 83, 64 };
    array_size=sizeof(data3)/sizeof(data3[0]);
	for(i=0; i<array_size;i++) 
	{
		tree2.insert(data3[i]);
	}
	theDepth=tree2.depth();
    cout<<"Depth of tree2: "<<theDepth<<endl;
    
    //  Clean up
    theTree.~BSTree();
    tree2.~BSTree();

    assert(theTree.isEmpty());
    assert(tree2.isEmpty());
	return 0;
}
