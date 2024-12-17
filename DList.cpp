//	DList.cpp
//	Some double linked list interview questions.

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<cmath>
#include<cassert>  // for assert()
#include<set>
#include<cstdio>
using namespace std;



template <class Type>
class Dnode {
	public:
		Dnode();
		Dnode(Type x);
		Type getinfo() { return info; }
		Dnode<Type> *getleft() { return left; }
		Dnode<Type> *getright() { return right; }
		void setinfo(Type x) { info=x; }
		void setleft(Dnode<Type> *n) { left=n; }
		void setright(Dnode<Type> *n) { right=n; }
	private:
		Type info;
		Dnode<Type> *left;
		Dnode<Type> *right;
};


template <class Type>
class Dlist {
	public:
		Dlist();
		~Dlist();
		Dnode<Type> *firstnode() { return leftend; }
		Dnode<Type> *lastnode() { return rightend; }
		void insertfirst(Type x);
		void insertlast(Type x);
		void insertright(Type x, Dnode<Type> *p);
		void insertleft(Type x, Dnode<Type> *p);
		Type removefirst();
		Type removelast();
		Type removeright(Dnode<Type> *p);
		Type removeleft(Dnode<Type> *p);
		Type remove(Dnode<Type> *p);
		int isempty();
		void print();
		void insert(Type);
		void reverse() {_reverse();}
	private:
		void _reverse();
		Dnode<Type> *leftend;
		Dnode<Type> *rightend;
};




  
int main(int argc, char**argv)
{
   	Dlist<int>dl;
   	
   	int i=0;
   	
   	for(;i<5;i++) {
   		dl.insert(i);
    }
   	dl.reverse();
    dl.print();
    dl.insert(5);
    dl.print();
    
    dl.reverse();
    dl.print();
    return 0;
}





template <typename Type>
Dnode<Type>::Dnode(Type x)
{
	info = x;
	left = 0;
	right = 0;
}



// methods for class Dlist

template <typename Type>
Dlist<Type>::Dlist()
{
	leftend = 0;
	rightend = 0;
}



template <typename Type>
void Dlist<Type>::insertfirst(Type x)
{
	Dnode<Type> *p;
	p = new Dnode<Type> (x);
	assert(p);
	p->setright(leftend);
	if (leftend)
		leftend->setleft(p);
	else
		rightend = p;
	leftend = p;

}



template <typename Type>
void Dlist<Type>::insertlast(Type x)
{
	Dnode<Type> *p;
	p = new Dnode<Type> (x);
	assert(p);
	p->setleft(rightend);
	if (rightend)
		rightend->setright(p);
	else
		leftend = p;
	rightend = p;
}



template <typename Type>
void Dlist<Type>::insertleft(Type x, Dnode<Type> *p)
{
	Dnode <Type> *q;
	Dnode <Type> *r;

	assert (p);
	q = new Dnode<Type>(x);
	assert (q);
	r = p->getleft();
	p->setleft(q);
	q->setleft(r);
	q->setright(p);
	if (r)
		r->setright(q);
	else
		leftend = q;
}



template <typename Type>
void Dlist<Type>::insertright(Type x, Dnode<Type> *p)
{
	Dnode <Type> *q;
	Dnode <Type> *r;

	assert (p);
	q = new Dnode<Type>(x);
	assert (q);
	r = p->getright();
	p->setright(q);
	q->setright(r);
	q->setleft(p);
	if (r)
		r->setleft(q);
	else
		rightend = q;
}



template <typename Type>
Type Dlist<Type>::removefirst()
{
	Dnode<Type> *p;
	Type x;

	assert(!isempty());

	p = leftend;
	x = p->getinfo();
	leftend = p->getright();
	if (leftend)
		leftend->setleft(0);
	else
		rightend = 0;

	delete p;
	return x;
}



template <typename Type>
Type Dlist<Type>::removelast()
{
	Dnode<Type> *p;
	Type x;

	assert(!isempty());

	p = rightend;
	x = p->getinfo();
	rightend = p->getleft();
	if (rightend)
		rightend->setright(0);
	else
		leftend = 0;

	delete p;
	return x;
}



template <typename Type>
Type Dlist<Type>::removeleft(Dnode<Type> *p)
{
	Type x;
	Dnode <Type> *q;
	Dnode <Type> *r;

	assert(p);
	q = p->getleft();
	assert(q);
	r = q->getleft();
	x = q->getinfo();
	p->setleft(r);
	if (r)
		r->setright(p);
	else
		leftend = p;

	delete q;
	return x;
}



template <typename Type>
Type Dlist<Type>::removeright(Dnode<Type> *p)
{
	Type x;
	Dnode <Type> *q;
	Dnode <Type> *r;

	assert(p);
	q = p->getright();
	assert(q);
	r = q->getright();
	x = q->getinfo();
	p->setright(r);
	if (r)
		r->setleft(p);
	else
		rightend = p;

	delete q;
	return x;
}



template <typename Type>
Type Dlist<Type>::remove(Dnode<Type> *p)
{
	Dnode <Type> *q;
	Dnode <Type> *r;
	Type x;

	assert(p);
	x = p->getinfo();

	q = p->getleft();
	r = p->getright();

	if (q)
		q->setright(r);
	else
		leftend = r;

	if (r)
		r->setleft(q);
	else
		rightend = q;

	delete (p);
	return x;
}



template <typename Type>
int Dlist<Type>::isempty()
{
	return (leftend == 0);
}



template <typename Type>
void Dlist<Type>::print()
{
	Dnode<Type> *p;

	p = leftend;
	while (p){
		std::cout << p-> getinfo()<<' ';
		p = p->getright();
	}
	std::cout<<std::endl;
}



template<typename Type>
Dlist< Type >::~Dlist()
{
	Dnode <Type> *q;
	Dnode <Type> *p;

	p = leftend;
	while (p) {
		q = p;
		p = p->getright();
		delete q;
	}
}



template <typename Type>
void Dlist<Type>::insert(Type x)
{
	if(isempty())
		insertfirst(x);
	else {
		Dnode <Type> *q=0;
		Dnode <Type> *p;
		p=q;
		p=firstnode();	
		while(p && p->getinfo()<x) {
			q=p;
			p=p->getright();
		}
		if(q)
			insertright(x,q);
		else
			insertleft(x,p);
	}
}


template <typename Type>
void Dlist<Type>::_reverse()
{
	if(isempty()) return;
	
	Dnode<Type> *temp=0;
	Dnode<Type> *current=leftend; // point to head

	while (current)
    {
       temp = current->getleft();	// save left node
       current->setleft(current->getright());	//	point left to right
       current->setright(temp);          //	set right to saved left node    
       current = current->getleft();	//	get right via left
    }      
      
     /* Before changing head, check for the cases like empty 
        list and list with only one node */
        
    if(temp) {
	    leftend = temp->getleft();
	}
}
