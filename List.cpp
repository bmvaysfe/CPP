//	List.cpp

#include<iostream>
#include<stack>
#include<cstring>
#include<cassert>
using namespace std;
class Node {
	public:
		Node();	//	Default constructor

		int getData()const;
		Node *getNext() const;
		void setData(int x);
		void setNext(Node *n);

	private:
		int data;
		Node *next;
};

class List {
	friend class ListIterator;
	public:
		List();
		~List();
	
       	List(const List&);
      	List & operator=(const List&);
		void insert(int x);
		int isEmpty() const;
		void print() const;
    	Node *getMthFromRear(int mth)const;  
    	Node *getMiddle() const;
    	void deleteMthFromRear(int);   // Added 05.07.14
    	void print_reverse()const; // Added 05.06.10
    	int count()const; // Added 05.06.10
    	int count_rec()const; // Added 05.06.10
    	void print_rec()const; // Added 07.21.10
    	void reverse();   // Added 09.18.11
        int isPalindrome(); // Start 06.27.13	
        void clear();
	private:
		Node *front;
		Node *rear;
		void print_reverse(Node *)const;  // Added 05.06.10
		int count_rec(Node *)const; // Added 05.06.10
		void print_rec(Node *)const;  // Added 07.21.10
		void reverse(Node **);    // Added 09.18.11
		void reverse_recursively(Node*p); //	Added 02.16.17
};


class ListIterator {
	public:
		explicit ListIterator(List &l);
		int done() const { return (current==0); }
		int operator()()const;
		void next()  { assert(current); current=current->getNext(); }

	private:
		Node *current;
};



#if 0  	// Since Node has an int as a data, this won't compile;
		// Should work OK in this list as a template implementation
void test_palindrome_string()
{
    char *str[3]= { static_cast<char*>("abcdcba"), 
					static_cast<char*>("abccba"), 
					static_cast<char*>("123456") };
    int i, j=0;
    List l1;
    for(i=0; i<3; i++)
    {
        for(j=0;j<strlen(str[i]);j++)
        {
            l1.insert(str[i][j]);
        }
        cout<<str[i]<<" is "<<l1.isPalindrome()<<endl;
        l1.clear();
    }

}


void test_palindrome_int()
{
	int i, j=0;
	int a[]={1,2,3,4,5,6}
    List l1;
    for(i=0; i<sizeof(a)/sizeof(a[0]); i++)
    {
        
            l1.insert(a[i]);
    }
    cout<<str[i]<<" is "<<l1.isPalindrome()<<endl;
    l1.clear();
    
}
#endif  // doesn't comlile @ BlodShed 5.11 as of 02.16.17
int main()
{
     int i, mthFromEnd=3, count=0, cntr=0;
     List theList;
    
     for(i=0;i<11;i++)
         theList.insert(i);
     theList.print();   
     
     //	find 3rd element from back
     Node *mth=theList.getMthFromRear(mthFromEnd);
     cout<<"Element #"<<mthFromEnd<<" from end is: "<<mth->getData()<<endl;
     
     // Get middle element
     Node *middle=theList.getMiddle();
     cout<<"Middle node has "<<middle->getData()<<endl;
     
     cout<<"\nList in REVERSE Order:"<<endl;
     theList.print_reverse();
     
     count=theList.count();
     cout<<"\n\nThere are "<<count<<" nodes in list."<<endl;
     
     cntr=theList.count();
     cout<<"There are "<<cntr<<" nodes in list."<<endl;
     theList.print_rec();
     
     cout<<"\n\nTest Print"<<endl;
     theList.print_rec();
     cout<<endl;
   
     cout<<"\nReversed List"<<endl;
     theList.reverse();
     theList.print_rec();
     
     cout<<"\n\nList Printed in Reverse Order"<<endl;
     theList.print_reverse();
     cout<<endl;
     
     theList.insert(131);
     theList.insert(260);
     theList.insert(8448);
     cout<<"\n\nTest Print"<<endl;
     theList.print_rec();
     cout<<endl;
    
//     test_palindrome();

     cout<<"************************"<<endl;

	count=0;
	
	ListIterator T1(theList);
	while(!T1.done()) {
		cout<<"Item #"<<count<<" is ";
		cout<<T1()<<endl;   // This worked under Unix (CC, aCC compilers)
		++count;
		T1.next();
	}
     
     
     
     return 0;                   
}


//	Default constructor
Node::Node()
{
	next = 0;
}

int Node::getData() const
{
	return data;
}

Node *Node::getNext() const
{
	return next;
}

void Node::setData(int x)
{
	data = x;
}

void Node::setNext(Node *np)
{
	next = np;
}

List::List()
{
  	front = 0;
    rear = 0;
}

//	#if 0
List::List(const List&myList)
{
	if(!myList.isEmpty()) {
		Node *p = myList.front;
		
		while(p) {
			insert(p->getData());
			p=p->getNext();
		}
	}
	else {
		cout<<"List::List(const List&myList) - source list is empty!"<<endl;
	}
}



List & List::operator=(const List&myList)
{
	if(this != &myList) {
		if(!isEmpty()) {
			clear();
		}
		if(!myList.isEmpty()) {
			Node *p = myList.front;
		
			while(p) {
				insert(p->getData());
				p=p->getNext();
			}
		}
		else {
			cout<<"List::operator=(const List&myList) - source list is empty!"<<endl;
		}
	}
	return *this;
}
// #endif

int List::isEmpty() const
{
	return (front==0 && rear==0);
}


void List::clear()
{
    Node *np = front, *nq;
	while (np) {
		nq = np;
		np = np->getNext();
		delete nq;
	}
    front = 0;
    rear = 0;
}

List::~List()
{
	Node *np = front, *nq;
	while (np) {
		nq = np;
		np = np->getNext();
		delete nq;
	}
   front = 0;
   rear = 0;
}

void List::insert(int d)
{
	Node *node = new Node;

	assert(node);
	node->setData(d);
	if (!rear)
		front= node;
	else
		rear->setNext(node);
	rear = node;
}

void List::print() const
{
	if(isEmpty())
		cout<<"The list is empty!"<<endl;
	else {
		Node *p=front;

		while(p) {
			cout<<p->getData()<<"   ";
			p=p->getNext();
		}
	}
	cout<<endl;
}

Node* List::getMthFromRear(int mth) const
{
    if(isEmpty()) {
     		cout<<"The list is empty!"<<endl;
			return 0;
  	} 			 
  		
    if(mth<=0) {
		 cout<<"mth="<<mth<<endl;
		 return 0;
  	} 			            

	Node *current=front;
	Node *Mth=current;

	int i;
			
	for(i=0; i<mth && current; i++) {
			 current=current->getNext();
	}

    if(!current)
                  return 0;
                  
	while(current) {
	   current=current->getNext();
	   Mth=Mth->getNext();
    }
    return Mth;                  
}

//  12.18.08, OpenLink
Node * List::getMiddle() const
{
    if(isEmpty()) {
        cout<<"The list is empty!"<<endl;
        return 0;
    }
    
    Node *p1=front;
    Node *p2=front;
    
    while(p2)
    {
        p1=p1->getNext();
        p2=p2->getNext();
#if 0        
        if(!p2) break;
        else p2=p2->getNext();  
#endif        
        if(p2) p2=p2->getNext();  // 05.06.10, more elegant than 2 lines above.
    }        
    return p1;
}    



void List::deleteMthFromRear(int m)
{
    if(isEmpty() || m<=0) return;
    
    Node *p = getMthFromRear(m);
    if(!p) return;
    
    Node *q = front;
    Node *c=front;
    while(c!=p) {
        q=c;
        c=c->getNext();
    }        
    
    q->setNext(p->getNext());
    if(p==front) front=p->getNext();
    
    delete p;
    
}    




void List::print_reverse() const// Added 05.06.10
{
    Node *pHead=front;
    if(!isEmpty())
        print_reverse(pHead);
}    

//  Print list in REVERSE order
void List::print_reverse(Node *n) const // Added 05.06.10
{ 
    if(n) {
        print_reverse(n->getNext());
        cout<<n->getData()<<"   ";
    }
}        

int List::count() const// Added 05.06.10
{
    int cnt=0;
    
    if(isEmpty()) return 0;
    Node *np=front;
    while(np) {
        cnt++;
        np=np->getNext();
    }        
    return cnt;
}        

int List::count_rec() const  // Added 05.06.10
{
    return count_rec(front);
}

int List::count_rec(Node *n) const   // Added 05.06.10
{    
    if(!n) return 0;
    return 1+count_rec(n->getNext());
}    

void List::print_rec() const // Added 07.21.10
{
    Node *head=front;
    print_rec(head);
}

//  Print list recursively
void List::print_rec(Node *t) const// Added 07.21.10    
{
    if(t) {
        cout<<t->getData()<< " ";
        print_rec(t->getNext());
    }
}


void List::reverse()    // Added 09.18.11
{
//    Node *head=front;
    rear=front;
    if(!isEmpty())
        reverse(&front);  
    //    reverse_recursively(front);
    cout<<"List::reverse(): rear->getData()="<<rear->getData()<<endl;
    cout<<"List::reverse(): front->getData()="<<front->getData()<<endl;
//    front=head;
}    

void List::reverse(Node **head)    // Added 09.18.11
{
    Node *temp1=*head;
    Node *temp2=0;
    Node *temp3=0;
    
    while(temp1)
    {
        *head=temp1;
        temp2=temp1->getNext();
        temp1->setNext(temp3);
        temp3=temp1;
        temp1=temp2;
    }        
}        


//	02.16.17
void List::reverse_recursively(Node*p)
{
    if(p->getNext()==NULL) {
        front=p;
        return;
    }
    reverse_recursively(p->getNext());
    Node *q=p->getNext();
    q->setNext(p);
    p->setNext(NULL);
}    



int List::isPalindrome()
{
	Node *p1=front;
	Node *p2= getMiddle();
    stack<int> theStack;
	while(p2) {

		if(p1->getData() != p2->getData())
			return 0; 
		p1=p1->getNext();
		theStack.push(p2->getData()); // Push data on stack after middle node
		p2=p2->getNext();
	}

	while(!theStack.empty()) {
		int x = theStack.top();
		theStack.pop();
		if(x!= p1->getData()) return 0;
		p1=p1->getNext();
	}

	return 1;
}


//	template <class Type>
int ListIterator::operator()() const
{
	assert(current);
	return current->getData();
}

//	template <class Type>
ListIterator::ListIterator(List &l)
{
	current=l.front;
}
