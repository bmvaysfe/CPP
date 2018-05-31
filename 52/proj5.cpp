//      CIS 2.85        Fall 98
//      Assignment #5.
//      Boris Vaysfeld
//      proj5.cpp 
//      Test driver.
#include<iostream>
#include<cstdlib>
#include<cassert> 
#include"proj5.h"
using namespace std;

int main()
{
	cout<<"Testing constructors"<<endl<<endl;
	cout<<"_____________________________________"<<endl<<endl;
	cout<<"Testing default constructor"<<endl;
	Solid R, *ptr;
	cout<<R;
	cout<<"_____________________________________"<<endl<<endl;

	Point A(-3,2,0), B(5,5,2.12);
	Color C(0.2, 0.4, 0.6);

	cout<<"Testing constructor that accepts 2 Points and 1 Color."<<endl<<endl;
	Solid D11(A,B,C), D12(B,A,C), D13(A,A,C);
	cout<<"This is D11"<<D11;
	cout<<"*********************************************************\n"<<endl;
	cout<<"This is D12"<<D12;
	cout<<"*********************************************************\n"<<endl;
	cout<<"This is D13"<<D13;
	cout<<"*********************************************************\n"<<endl;
	cout<<"_____________________________________"<<endl<<endl;

	cout<<"Testing constructor that accepts 2 Points and";
	cout<<" array of 6 Colors."<<endl<<endl;
	Color Zero(0,0,0), Four(0.4, 0.4, 0.4), Five(0.5, 0.5, 0.5);
	Color One(0.1, 0.1, 0.1), Two(0.2, 0.2, 0.2), Three(0.3, 0.3, 0.3);
	Color font[6];
	font[0]=Zero;
	font[1]=One;
	font[2]=Two;
	font[3]=Three;
	font[4]=Four;
	font[5]=Five;
	Solid D14(A,B,font);
	cout<<"This is D14"<<endl<<D14<<endl;
	cout<<"*********************************************************\n"<<endl;

	Solid D15(B,A,font), D16(A,A,font);
	cout<<"This is D15"<<endl<<D15<<endl;
	cout<<"*********************************************************\n"<<endl;
	cout<<"This is D16"<<endl<<D16<<endl;
	cout<<"*********************************************************\n"<<endl;
	cout<<"_____________________________________"<<endl<<endl;

	cout<<"Testing copy constructor"<<endl;
	ptr=new Solid(D11);
	assert(ptr);
	cout<<*ptr;

	cout<<"Now I delete ptr";
	delete ptr;
	cout<<", but D11 still exists."<<endl;
	cout<<"Here is D11"<<D11<<endl;
	cout<<"*********************************************************\n"<<endl;
	cout<<"Here is D11 again."<<D11<<endl;
	Solid RR(D11);
	cout<<"Solid RR is a copy of solid D11"<<endl;
	cout<<"Here is RR"<<RR<<endl;
	cout<<"_____________________________________"<<endl<<endl;

	cout<<"Testing assignment operator"<<endl<<endl;
	cout<<"This is solid R"<<R<<endl;
	R=D11;
	cout<<"Here is D11"<<D11<<endl;
	cout<<"Here is R"<<R<<endl;
	R=D12;
	cout<<"This is D12"<<D12;
	cout<<"Here is R"<<R<<endl;
	cout<<"_____________________________________"<<endl<<endl;

	cout<<"Testing rotation"<<endl;
	cout<<"_____________________________________"<<endl<<endl;
    int i;
	for(i=-10;i<10;i++) {
		cout<<"D14 before rotation"<<endl<<D14;
		R=D14+i;
		cout<<"\nRotated D14 is:"<<endl<<R;
		cout<<"***********************************************\n"<<endl;
	}
	cout<<"Testing intersection of solids"<<endl;
	cout<<"_____________________________________"<<endl<<endl;

	cout<<"Part #2. Lists and ListIterators."<<endl;
	cout<<"_____________________________________"<<endl<<endl;
	List<int> L;

	assert(L.isEmpty());
	L.print();	
	L.insertRear(-1);
	L.print();	
	for(i=1; i<10;i++) 
		L.insertFront(i);
	assert(!L.isEmpty());
	L.insertRear(131);
	L.print();
	cout<<endl<<"Removed from front "<<L.removeFront()<<endl;
	L.print();
	cout<<"Removed from rear "<<L.removeRear()<<endl;
	cout<<"After removal"<<endl;
	L.print();

	List <int> L1; 
	List <int> L2;
	List <int> L3;
	L1=L+10;
	L3=L1;
	cout<<"This is L"<<endl;
	L.print();
	cout<<"This is L1"<<endl;
	L1.print();
	L2=L1*25;
	cout<<"Finally:\n\n";
	cout<<"This is L"<<endl;
	L.print();
	cout<<"This is L1"<<endl;
	L1.print();
	cout<<"This is L2"<<endl;
	L2.print();
	cout<<"*************"<<endl;

	cout<<"-------------Iterator-traverse-of-L2-----------"<<endl;
	ListIterator<int> LI(L2);
	ListIterator<int> LI1(L1);

	int count=1;
	while(!LI.done()) {
		cout<<"Item #"<<count<<" is: ";
		cout<<LI()<<endl;
		count++;
		LI.next();
	}
	cout<<endl;
	count=1;
	cout<<"-------------Iterator-traverse-of-L1-----------"<<endl;
	while(!LI1.done()) {
		cout<<"Item #"<<count<<" is: ";
		cout<<LI1()<<endl;
		count++;
		LI1.next();
	}

	cout<<"\n\nNOW with Solids"<<endl;
	List <Solid> Q;
	Q.insertFront(D11);
	Q.insertRear(D12);
	Q.insertFront(D13);
	Q.insertRear(D14);
	Q.insertRear(D15);
	Q.insertFront(D16);
	Q.insertRear(R);
	Q.insertRear(RR);
	Q.insertFront(Q.removeRear());
	ListIterator <Solid> QI(Q);
	count=1;
    Solid mySolid;
	while(!QI.done()) {
		cout<<"Item #"<<count<<" is ";
        mySolid=QI();   //  03/10/08
//		cout<<QI()<<endl;   // This worked under Unix (CC, aCC compilers)
        cout<<mySolid<<endl; //  03/10/08
		count++;
		QI.next();
	}
	cout<<"************************"<<endl;
	List <Solid> K;
	K=Q+1;
	count=1;	
	ListIterator<Solid> T(K);
	while(!T.done()) {
		cout<<"Item #"<<count<<" is ";
        mySolid=T();    //  03/10/08
//		cout<<T()<<endl;  // This worked under Unix (CC, aCC compilers)
        cout<<mySolid<<endl;   //  03/10/08
		count++;
		T.next();
	}
	cout<<"************************"<<endl;

	count=1;
	List <Solid> K2;
	K2=Q*R;
	ListIterator<Solid> T1(K2);
	while(!T1.done()) {
		cout<<"Item #"<<count<<" is \n";
        mySolid=T1();  //  03/10/08
//		cout<<T1()<<endl;   // This worked under Unix (CC, aCC compilers)
        cout<<mySolid<<endl;  //  03/10/08
		count++;
		T1.next();
	}

	return EXIT_SUCCESS;
}
