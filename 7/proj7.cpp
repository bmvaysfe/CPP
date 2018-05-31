//	CIS 22	Spring 98
//	Assignment #7.
//	Priority Queue Using templates.
//	Boris Vaysfeld
//	proj7.cpp
//	Test driver



#include<iostream>
#include<cassert>
#include<cstdlib>
#include"proj7.h"

int main()
{
	PQ <int> p;

	assert(p.isempty());
	std::cout<<"Priority Queue for integers"<<std::endl;
	p.insert(0);
	p.print();
	p.insert(4);
	p.print();
	p.insert(-5);
	p.print();
	p.insert(2);
	p.print();
	p.insert(-2);
	p.print();
	p.insert(-2);
	p.print();
	p.insert(-3);
	p.print();
	p.insert(1);
	p.print();
	p.insert(3);
	p.print();
	std::cout<<"Min is "<<p.remove_min()<<std::endl;
	std::cout<<"Max is "<<p.remove_max()<<std::endl;
	p.insert(-1);
	p.print();
	p.insert(-100);
	p.print();
	p.insert(-100);
	p.print();
	p.insert(-1);
	p.print();
	int x=p.remove_min();
	while(!p.isempty()) {
		int y=p.remove_min();
		assert(x<=y);
		x=y;
	}
	assert(p.isempty());

	PQ<double> ttt;	
	assert(ttt.isempty());
	std::cout<<"\n\n\nPriority Queue for doubles"<<std::endl;
	ttt.insert(2.50);
	ttt.insert(3.14);
	ttt.insert(0);
	ttt.insert(-123.45);
	ttt.insert(-450.22);
	ttt.insert(2.75);
	ttt.insert(3.14);
	ttt.print();
	std::cout<<"Min is "<<ttt.remove_min()<<std::endl;
	std::cout<<"Max is "<<ttt.remove_max()<<std::endl;
	ttt.print();
	double xx=ttt.remove_max();
	while(!ttt.isempty()) {
		double yy=ttt.remove_max();
		assert(xx>=yy);
		xx=yy;
	}
	assert(ttt.isempty());

	PQ <Card> deck;
	Card mk,mt(diamond,7),mg(club, 12), bv(club,7), rt(club,2), tr(diamond,2);
	
	assert(deck.isempty());
	std::cout<<"\n\n\nPriority Queue for Cards"<<std::endl;
	deck.insert(mk);
	deck.insert(mt);
	deck.insert(mg);
	deck.insert(bv);
	deck.insert(rt);
	deck.insert(tr);	
	deck.print();	
	std::cout<<"Min is "<<deck.remove_min()<<std::endl<<std::endl;
	std::cout<<"Max is "<<deck.remove_max()<<std::endl<<std::endl;
	Card dd=deck.remove_max();
	std::cout<<"First removed card is "<<dd<<std::endl<<std::endl;
	while(!deck.isempty()) {
		Card dp=deck.remove_max();
		std::cout<<"Removed card is "<<dd<<std::endl<<std::endl;
		assert(dd>=dp);
		dd=dp;
	}
	assert(deck.isempty());
	return 0;
}
