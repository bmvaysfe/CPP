//	CIS 2.85	Fall 98
//	Assignment #5.
//	Boris Vaysfeld
//	test5.inl


#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include"proj5.h"

using namespace std;

//      This function prints information about the Color in a neat manner.
ostream& operator<<(ostream& os, Color& C)
{
	os<<"red="<<C.red<<"   green="<<C.green<<"   blue="<<C.blue<<endl;
	return os;
}



//      This function prints information about the Point in a neat manner.
ostream& operator<<(ostream& os,Point& P)
{
	os<<"("<<P.x<<","<<P.y<<","<<P.z<<")";
	return os;
}



//      This function prints information about the Solid in a neat manner.
ostream& operator<<(ostream& os,Solid &T)
{
	os<<endl<<"Solid "<<"["<<T.LL<<","<<T.UR<<"]"<<endl;
	for(int i=0;i<6;i++)
		os<<"face["<<i<<"] is "<<T.face[i];
	os<<endl;
	return os;
}



Color::Color(float r, float g, float b)
{
	red=r;
	green=g;
	blue=b;
	assert(red>=0 && red<=1);
	assert(green>=0 && green<=1);
	assert(blue>=0 && blue<=1);
}



//	Default constructor.
//	Solid is formed by the two points (0,0,0) and (1,1,1).
//	Color of each face of the solid is white.
Solid::Solid()
{
	Point zero, one(1,1,1);

	LL=zero;
	UR=one;
	face=new Color[6];
	assert(face);
}



//	Solid destructor.
Solid::~Solid()
{
	delete []face;
}



//	Point A-low point of the solid.
//	A has coordinates lowx, lowy, lowz.
//	Point B-upper point corner of the solid.
//	B has coordinates hix, hiy, hiz.
//	C-Color of each face of the solid.
//	face[0] is parallel to the y-z plane with x value lowx.
//	face[1] is parallel to the x-z plane with y value lowy.
//	face[2] is parallel to the y-z plane with x value hix.
//	face[3] is parallel to the x-z plane with y value hiy.
//	face[4] is parallel to the x-y plane with z value lowz.
//	face[5] is parallel to the x-y plane with z value hiz.
//	If points are not arranged properly, the solid [(0,0,0),(1,1,1)]
//	is created, the color of each face will be white.	
Solid::Solid(Point A,Point B,Color C)
{
	face=new Color[6];
	assert(face);

	//	Points A and B are arranged properly.	
	if(A.getX()<=B.getX() && A.getY()<=B.getY() && A.getZ()<=B.getZ()) {
		LL=A;
		UR=B;
		for(int i=0;i<6;i++)
			face[i]=C;
	}

	//	Points are not arranged properly.
	else {
		cout<<"Points "<< A<<" and "<< B<<endl;
		cout<<"do not constitute a valid solid."<<endl;
		cout<<"The white solid [(0,0,0),(1,1,1)] is created."<<endl<<endl;
		Point zero, one(1,1,1);
		LL=zero;
		UR=one;
	}
}



//	Point A-low point of the solid.
//	A has coordinates lowx, lowy, lowz.
//	Point B-upper point corner of the solid.
//	B has coordinates hix, hiy, hiz.
//	C[]-array of Colors.
//	There are 6 faces to the solid.
//	face[0] is parallel to the y-z plane with x value lowx.
//	face[1] is parallel to the x-z plane with y value lowy.
//	face[2] is parallel to the y-z plane with x value hix.
//	face[3] is parallel to the x-z plane with y value hiy.
//	face[4] is parallel to the x-y plane with z value lowz.
//	face[5] is parallel to the x-y plane with z value hiz.
//	If points are not arranged properly, the solid [(0,0,0),(1,1,1)]
//	is created, the color of each face will be white.	
Solid::Solid(Point A,Point B,Color C[])
{
	face=new Color[6];
	assert(face);

	//	Points A and B are arranged properly.	
	if(A.getX()<=B.getX() && A.getY()<=B.getY() && A.getZ()<=B.getZ()) {
		LL=A;
		UR=B;
		for(int i=0;i<6;i++)
			face[i]=C[i];
	}

	//	Points are not arranged properly.
	else {
		cout<<"Points "<< A<<" and "<< B<<endl;
		cout<<"do not constitute a valid solid."<<endl;
		cout<<"The white solid [(0,0,0),(1,1,1)] is created."<<endl<<endl;
		Point zero, one(1,1,1);
		LL=zero;
		UR=one;
	}
}



//	Copy constructor for Solid.
Solid::Solid (const Solid& T)
{
	LL=T.LL;
	UR=T.UR;
	face=new Color[6];
	assert(face);
	for(int i=0;i<6;i++)
		face[i]=T.face[i];
}



//	Overloaded assignment operator for Solid.
Solid& Solid::operator=(const Solid& T)
{
	if(this!=&T) {
		LL=T.LL;
		UR=T.UR;
		delete []face;
		face=new Color[6];
		assert(face);
		for(int i=0;i<6;i++)
			face[i]=T.face[i];
	}
	return *this;
} 



// find Solids intersection
Solid Solid::operator*(Solid&T) 
{
	float lx, ly, rx, ry;
        Solid ZERO;

	cout<<"Attempts to find the intersection of solid ";
	cout<<endl<<*this<<"and solid "<<endl;
	cout<<T<<endl;

	lx=(T.getLL().getX()>=LL.getX())?T.getLL().getX():LL.getX();
	ly=(T.getLL().getY()>=LL.getY())?T.getLL().getY():LL.getY();

	rx=(T.getUR().getX()<=UR.getX())?T.getUR().getX():UR.getX();
	ry=(T.getUR().getY()<=UR.getY())?T.getUR().getY():UR.getY();

	//	Solids don't intersect
	if(rx<lx || ry<ly) {
		cout<<"No intersection. White Solid [(0,0,0),(1,1,1)]";
		cout<<" is returned"<<endl;
		return ZERO;
	}
	else { 
		float lz, rz;
		if(LL.getZ()>=T.LL.getZ()) 
			lz=LL.getZ();
		else
			lz=T.LL.getZ();

		if(UR.getZ()<=T.UR.getZ())
			rz=UR.getZ();
		else
			rz=T.UR.getZ();
		
		if(lz>rz) {	
			cout<<"No intersection. White Solid [(0,0,0),(1,1,1)]";
			cout<<" is returned"<<endl;
			return ZERO;
		}
		Point L(lx,ly,lz);
		Point R(rx,ry,rz);
		Color font[6];	
/*
	//	Setting color of the intersecting solid.
	float nr=(font.RED()+T.font.RED())/2;
	float ng=(font.GREEN()+T.font.GREEN())/2;
	float nb=(font.BLUE()+T.font.BLUE())/2;
	Color N(nr,ng,nb);
*/
		Solid F(L,R,font);
		return F;
	}	
}




//	This function rotates solid  90 degrees in the x-y plane around 
//	a line  parallel to the z axis through the center of the solid    
//	as many tim es as the absolute value of the integer x.
//	If x>0, the rotation is clockwise.
//	If x<0, the rotation is counter-clockwise.
//	If x==0, no rotation because rotate solid 0 times is impossible.
//	Solid obtained by rotation is returned.
//	face[0] is parallel to the y-z plane with x value lowx.
//	face[1] is parallel to the x-z plane with y value lowy.
//	face[2] is parallel to the y-z plane with x value hix.
//	face[3] is parallel to the x-z plane with y value hiy.
//	face[4] is parallel to the x-y plane with z value lowz.
//	face[5] is parallel to the x-y plane with z value hiz.
Solid Solid::operator+(int x) 
{
	//	No rotation
	if(x==0) {
		cout<<"\nRotation 0 times of "<<endl<<*this<<"is impossible!\n";
		Solid T;
		T=*this;
		return T;
	}
    int j;
	Color temp, old[6];

	//	Save old colors.
	for(j=0;j<6;j++)
		old[j]=face[j];

	//	Clockwise rotation.
	if(x>0) {
		cout<<"This is clockwise rotation."<<endl;		
		cout<<"Solid is rotated "<<abs(x)<<" times."<<endl;		
		if( (abs(x)%4)==1) {
			temp=face[0];
			face[0]=face[1];
			face[1]=face[2];
			face[2]=face[3];
			face[3]=temp;
		}		

		if( (abs(x)%4)==2) {
			temp=face[0];
			face[0]=face[2];
			face[2]=temp;
			temp=face[1];
			face[1]=face[3];
			face[3]=temp;
		}

		if( (abs(x)%4)==3) {
			temp=face[0];
			face[0]=face[3];
			face[3]=face[2];
			face[2]=face[1];
			face[1]=temp;
		}
	}


	//	Counter-clockwise rotation.
	if(x<0) {
		cout<<"This is counter-clockwise rotation."<<endl;		
		cout<<"Solid is rotated "<<abs(x)<<" times."<<endl;		
		
		if( (abs(x)%4)==1) {
			temp=face[0];
			face[0]=face[3];
			face[3]=face[2];
			face[2]=face[1];
			face[1]=temp;
		}

		if( (abs(x)%4)==2) {
			temp=face[0];
			face[0]=face[2];
			face[2]=temp;
			temp=face[1];
			face[1]=face[3];
			face[3]=temp;
		}

		if( (abs(x)%4)==3) {
			temp=face[0];
			face[0]=face[1];
			face[1]=face[2];
			face[2]=face[3];
			face[3]=temp;
		}
	}	
	
	if( (abs(x)%2)==1) {

		//	Coordinates of the center of the projection
		//      of solid in x-y plane.
		float cx, cy;

		//	Coordinates of the lower left corner of the solid
		//	obtained by the rotation of the projection of original
		//	 solid	around its center 90 degrees in x-y plane.
		float llX, llY;

		//	Coordinates of the upper right corner of the solid
		//	obtained by the rotation of the original solid projection
		//	in x-y	plane around its center 90 degrees.
		float urX, urY;


		float midX, midY;

		//	Find the center of the solid projection in x-y plane.
		cx=(LL.getX()+UR.getX())/2;
		cy=(LL.getY()+UR.getY())/2;

		midX=fabs((UR.getX()-LL.getX())/2);
		midY=fabs((UR.getY()-LL.getY())/2);

		llX=cx-midY;
		llY=cy-midX;
		Point newLL(llX,llY,LL.getZ());

		urX=cx+midY;
		urY=cy+midX;
		Point newUR(urX,urY,UR.getZ());
		Solid R(newLL,newUR,face);
		//	Restore original colors of original solid.
		for(j=0;j<6;j++)
			face[j]=old[j];

		return R;

	}
	else {
		Solid RR(LL,UR,face);
		//	Restore original colors of original solid.
		for(j=0;j<6;j++)
			face[j]=old[j];

		return RR;
	}
}


template <class Type>
Item<Type>::Item()
{
	next=NULL;
}



template <class Type>
List<Type>::List()
{
	front=NULL;
	rear=NULL;
}



template <class Type>
List<Type>::~List()
{
	Item<Type> *p;
	Item<Type> *q;
	p=front;
	while(p) {
		q=p;
		p=p->getNext();
		delete q;
	}
	front=NULL;
	rear=NULL;
}



//	Insert an item in front of the list.
template <class Type>
void List<Type>::insertFront(Type x) 
{
	Item<Type> *np;

	np=new Item<Type> (x);
	assert(np);
	np->setNext(front);
	if(isEmpty()) 
		rear=np;
	front=np;
}



//	Appends an item to the end of the list.
template <class Type>
void List<Type>::insertRear(Type x)
{
	Item <Type> *np;

	np=new Item<Type> (x);
	assert(np);
	if(isEmpty())
		front=np;
	else
		rear->setNext(np);
	rear=np;
}


template <class Type>
void List<Type>::print()
{
	if(isEmpty())
		cout<<endl<<"List is empty!"<<endl;
	else {
		cout<<endl<<"*************************************"<<endl<<endl;
		cout<<"Printed list:"<<endl<<endl;
		Item<Type> *p;
		p=front;
		while(p) {
			cout<<p->getData()<<endl;
			p=p->getNext();
		}
		cout<<endl;
		cout<<endl<<"*************************************"<<endl<<endl;
	}
	return;
}

		
template <class Type>
Type List<Type>::removeFront()
{
	Item<Type> *p;

	p=front;
	Type x=p->getData();
	front=p->getNext();
	if(front==NULL)
		rear=NULL;
	delete p;
	return x;
}


template <class Type>
Type List<Type>::removeRear()
{
	Item <Type> *p;
	Item <Type> *q;
	
	assert(!isEmpty());
	p=front;
	while(p->getNext()) {
		q=p;
		p=p->getNext();	
	}
	if(q==NULL)
		return removeFront();
	else {
		assert(q);
		Item <Type> *t;
		t=q->getNext();
		assert(t);
		q->setNext(t->getNext());
		rear=q;
		Type x=t->getData();
		delete t;
		return x;
	}
}



template <class Type>
List<Type>& List<Type>::operator+(int x)
{
	if(!isEmpty()) {
		Item <Type>*p;
		p=front;
		while(p) {
			p->setData((p->getData())+x);
			p=p->getNext();
		}
	}
	return *this;
}



template <class Type>
List<Type>& List<Type>::operator*(int x)
{
	if(!isEmpty()) {
		Item <Type> *p;
		p=front;
		while(p) {
			p->setData((p->getData())*x);
			p=p->getNext();
		}
	}
	return *this;
}



template <class Type>
List<Type>& List<Type>::operator*( Solid& T)
{
	Item <Type> *p;
	Solid d,I;
	p=front;
	if(!isEmpty()) {
		while(p) {
			d=p->getData();
			I=d*T;
			p->setData(I);
			p=p->getNext();
		}
	}
	return *this;
}



template <class Type>
List<Type>& List<Type>::operator=(const List<Type> &T)
{
	if(this!=&T && !T.isEmpty()) {
		Item<Type> *p;
		Item<Type> *q;
		p=front;
		while(p) {
			q=p;
			p=p->getNext();
			delete q;
		}
		front=NULL;
		rear=NULL;
	
		p=T.front;
		insertFront(p->getData());	//	1st Item
		p=p->getNext();
		while(p) {
			insertRear(p->getData());
			p=p->getNext();
		}
	}
	return *this;
}

template <class Type>
Type ListIterator<Type>::operator()()
{
	assert(current);
	return current->getData();
}

template <class Type>
ListIterator<Type>::ListIterator(List<Type> &l)
{
	current=l.front;
}
