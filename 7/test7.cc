//	CIS 22	Spring 98
//	Assignment #7.
//	Priority Queue Using Templates.
//	Boris Vaysfeld
//	test7.cpp
//	Methods for proj7.cpp



#include <cassert>
#include <cstdlib>
#include <iostream>
#include "proj7.h"
using namespace std;
//	Default constructor: ace of spades
Card::Card()
{
	r=14;
	s=spade;
}



//	Initialize a card with given values
Card::Card(int sv, int rv)
{
	r=rv;
	s=sv;
}



int operator <( Card tm, Card tn)
{
	return tm.comprank(tn);	
}



int operator >= ( Card tm, Card tn)
{
	if( tm.rank() >= tn.rank() )
		return 1;
	return 0;
}



std::ostream& operator << (std::ostream& ttt, Card m)
{
	switch (m.rank()) {
		case 11:
			ttt<<"J";
			break;
		case 12:
			ttt<<"Q";
			break;
		case 13:
			ttt<<"K";
			break;
		case 14:
			ttt<<"A";
			break;
		default:
			ttt<<m.rank();
	}

	switch(m.suit()) {
		case club:
			ttt<<"C\t";
			break;
		case diamond:
			ttt<<"D\t";
			break;
		case heart:
			ttt<<"H\t";
			break;
		case spade:
			ttt<<"S\t";
			break;
	}
	return ttt;
}



//	print card rank and suit
void Card::print()
{
	switch (rank()) {
		case 11:
			std::cout<<"J";
			break;
		case 12:
			std::cout<<"Q";
			break;
		case 13:
			std::cout<<"K";
			break;
		case 14:
			std::cout<<"A";
			break;
		default:
			std::cout<<rank();
	}

	switch(suit()) {
		case club:
			std::cout<<"C\t";
			break;
		case diamond:
			std::cout<<"D\t";
			break;
		case heart:
			std::cout<<"H\t";
			break;
		case spade:
			std::cout<<"S\t";
			break;
	}
	std::cout<<std::endl;
}



//	Returns true if suits of 2 cards are the same
int Card::compsuit(Card c)
{
	return (s==c.suit());
}



// Compares ranks of 2 cards 
int Card::comprank(Card bv)
{
	if( (rank()-bv.rank()) <0 )
		return 1;
	return 0;
} 



// methods for class Dnode
template <typename Type>
Dnode<Type>::Dnode()
{
	left = 0;
	right = 0;
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
int PQ<Type>::isempty()
{
	return d.isempty();
}



template <typename Type>
Type PQ<Type>::remove_max()
{
	return d.removelast();
}



template <typename Type>
Type PQ<Type>::remove_min()
{
	return d.removefirst();
}



template <typename Type>
void PQ<Type>::print()
{
	d.print();
}



template <typename Type>
void PQ<Type>::insert(Type x)
{
	d.insert(x);
}
		
