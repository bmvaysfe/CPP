//	CIS 2.85	Fall 98
//	Assignment #5.
//	Boris Vaysfeld
//	proj5.h

#ifndef PROJ5_H
#define PROJ5_H

#include<cstdlib>
#include<cassert>
using namespace std;
class Color {
	friend ostream& operator<<(ostream&,Color&);
	public:
		Color() { red=1; green=1; blue=1; }
		explicit Color(float,float,float);
		float RED() const { return red; }
		float GREEN() const { return green; }
		float BLUE() const { return blue; }
		
	private:
		float red;
		float green;
		float blue;
};


class Point {
	friend ostream& operator<<(ostream&,Point&);
	public:
		Point() { x=0; y=0; z=0; }
		explicit Point(float xx, float yy, float zz) { x=xx; y=yy; z=zz; }
		float getX() const { return x; }
		float getY() const { return y; }
		float getZ() const { return z; }
		
	private:
		float x;
		float y;
		float z;	
};


class Solid {
	friend ostream& operator<<(ostream&, Solid&);
	public:
		Solid();
		~Solid();	
		explicit Solid(Point,Point,Color);
		explicit Solid(Point,Point,Color *);
		Solid(const Solid&);	
		Solid& operator=(const Solid&);
		Solid operator+(int);
		Solid operator*( Solid&);
		Point getLL() const { return LL; }
		Point getUR() const { return UR; }
		
	private:
		Point LL;
		Point UR;
		Color *face;
};


template <class Type>
class Item {
	public:
		Item();
		explicit Item(Type x):data(x),next(0){}
		void setData(Type x) {data=x;}
		void setNext(Item<Type> *p) { next=p; }
		Type getData() const { return data; }
		Item<Type> *getNext() const { return next; }

	private:
		Type data;
		Item<Type> *next;
};

template <class Type> class ListIterator;

template <class Type>
class List {
	friend class ListIterator <Type>;
	public:
		List();
		~List();
		void insertFront(Type);
		void insertRear(Type);
		Type removeFront();
		Type removeRear();
		void print();
		int isEmpty() const { return (front==0); }
		List<Type> & operator+(int);
		List<Type> & operator*(int);
		List<Type> & operator*(Solid&);
		List<Type> & operator=(const List<Type> &);

	private:
		Item<Type> *front;
		Item<Type> *rear;
};



template <class Type>
class ListIterator {
	public:
		explicit ListIterator(List<Type> &l);
		int done() const { return (current==0); }
		Type operator()();
		void next() { assert(current); current=current->getNext(); }

	private:
		Item <Type> *current;
};

#include"test5.inl"

#endif
