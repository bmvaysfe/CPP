//	CIS 22	Spring 98
//	Assignment #7.
//	Priority Queue Using templates.
//	Boris Vaysfeld
//	proj7.h
//	Header file.



#include<iostream>

#ifndef PROJ7_H
#define PROJ7_H

enum {club,diamond,heart,spade};

class Card {

	friend int operator <( Card tm, Card tn);
	friend int operator >= ( Card tm, Card tn);
	friend std::ostream& operator << (std::ostream& ttt, Card m);

	public:	//constructors

		Card();		// initialize Card with default values

		Card(int,int);	// initialize Card with given values
		
		int comprank(Card);
		int compsuit(Card);
		int rank(){return r;}	//return card rank
		int suit(){return s;}	//return card suit
		void print();		//print the card rank and suit
	
	private:
		int r;	// rank of a card
		int s;	// suit of a card
};

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
	private:
		Dnode<Type> *leftend;
		Dnode<Type> *rightend;
};


template <class Type>
class PQ {
	public:
		PQ():d(){}
		int isempty();
		void insert(Type);
		Type remove_max();
		Type remove_min();
		void print();

	private:
		Dlist<Type> d;
};
#include "test7.cc"

#endif
