//      Boris Vaysfeld
//      CIS 25  Fall 99
//      Assignment #2.
//	    test2.cpp


#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include"proj2.h"

using namespace std;

//	Default constructor for class Process.
Process::Process()
{
	//	All processes are created at PROCESS_CREATION_TIME=0
	//	At the moment they are created, their attributes are
	//	unknown, except time of their creation. Processes will
	//	be initialized in create_all_processes function.

	process_id=STATE_UNKNOWN;
	process_length=STATE_UNKNOWN;
	new_state=STATE_UNKNOWN;
	previous_state=STATE_UNKNOWN;
	time_of_creation=PROCESS_CREATION_TIME;
	process_life=time_of_creation;
	total_number_of_instructions_to_run=STATE_UNKNOWN;
    number_of_executed_instructions=STATE_UNKNOWN;
	total_waiting_time=STATE_UNKNOWN;
	last_execution_time=STATE_UNKNOWN;
}



//	This function initializes process id, length, state, and time left
//	at the point of creation.
void Process::create_this_process(int id, int length)
{
	process_id=id;
	process_length=length;
	new_state=STATE_NEW;
	total_number_of_instructions_to_run=length;
    number_of_executed_instructions=NONE;
	total_waiting_time=NONE;
	last_execution_time=NONE;
	return;
}



//	This function prints information about the process in a neat format.
void Process::print_info_about_this_process()
{
	extern int CurrentTime;

	cout<<CurrentTime<<"\t";
	cout<<process_id<<"\t";
	cout<<number_of_executed_instructions<<"\t";

	//	Calculate total life time of process.
	process_life=CurrentTime-time_of_creation;
	cout<<process_life<<"\t";

	//	CPU Time is a number of executed instructions.
	cout<<number_of_executed_instructions<<"\t";

	//	Waiting time.
	cout<<total_waiting_time<<"\t";

	//	States of the process.	
	switch (previous_state) {

		case STATE_UNKNOWN:
			cout<<"Unknown\t";
			break;

		case STATE_NEW:
			cout<<"New\t";
			break;

		case STATE_READY:
			cout<<"Ready\t";
			break;

		case STATE_RUNNING:
			cout<<"Running\t";
			break;

		case STATE_TERMINATED:
			cout<<"Terminated";
			break;
	};
	cout<<"\t";
	switch (new_state) {

		case STATE_NEW:
			cout<<"New\t";
			break;

		case STATE_READY:
			cout<<"Ready\t";
			break;

		case STATE_RUNNING:
			cout<<"Running\t";
			break;

		case STATE_TERMINATED:
			cout<<"Terminated";
			break;
	};
	cout<<endl;
	return;
}



//	This function checks whether process completed its execution or not.
//	If process completed its execution, returns 1.
//	Otherwise, 0 is returned.
int Process::isDone()
{
	return ( (--process_length) < 1);
}



//	This function will change process' state.
void Process::change_process_state(int state)
{
	previous_state=new_state;
	new_state=state;
	return;
}



//	Put process into Running state.
void Process::run()
{
	extern int CurrentTime;

	change_process_state(STATE_RUNNING);

	int wait=CurrentTime-last_execution_time-number_of_executed_instructions;
	//	This happens when time slice expires and process
	//	completes execution, waiting time must be adjusted.	
	if(wait<0)
		wait+=TIME_QUANTUM;
	total_waiting_time+=wait;
	last_execution_time=CurrentTime;
	print_info_about_this_process();
	return;
}



//	Terminates process execution.
void Process::terminate()
{
	extern int CurrentTime;

	change_process_state(STATE_TERMINATED);
	number_of_executed_instructions=total_number_of_instructions_to_run;
	print_info_about_this_process();
	return;
}



//	Adjusts status of process if execution is not completed.
void Process::adjust_status()
{
	number_of_executed_instructions+=TIME_QUANTUM;
	return;
}



//     Default constructor
Node::Node()
{
	next = 0;
}



//	Returns data in a node.
Process Node::getData()const
{
	return data;
}



//	Returns pointer to next node.
Node *Node::getNext()const
{
	return next;
}



//	Sets value of a data member of a node to Process x.
void Node::setData(Process x)
{
	data = x;
	return;
}



//	Sets pointer to next node to n.
void Node::setNext(Node *n)
{
	next = n;
	return;
}



//     Default constructor for Queue.
Queue::Queue()
{
	front = 0;
    rear = 0;
}



//	Inserts process into Queue.
//	Process state is changed from New to Ready.
void Queue::insert(Process ProcessToInsert)
{
	Node *node = new Node;

	assert(node);
	ProcessToInsert.change_process_state(STATE_READY);
	ProcessToInsert.print_info_about_this_process();
	node->setData(ProcessToInsert);
	if (!rear)
		front= node;
	else
		rear->setNext(node);
	rear = node;
	return;
}



//	Removes process from queue.
Process Queue::remove()
{
	assert(!isEmpty());
	Node *node = front;
	Process ProcessToRemove = front->getData();
	front = front->getNext();
	if (!front)
		rear = 0;
	delete node;
	return ProcessToRemove;
}



//	Checks if Queue is empty.
//	Returns 1 if empty.
//	Otherwise, 0 is returned.
int Queue::isEmpty()const
{
	return (front==0 && rear==0);
}



//	Iterative destructor for Queue.
Queue::~Queue()
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



//	Checks if CPU is free.
//	Returns 1 if free.
//	Otherwise, 0 is returned.
int CPU::isFree()
{
	extern	Queue ReadyQueue;
	extern int CurrentTime;
	extern int number_of_executed_processes;

	if(free)
		return TRUE;
	 
	//	Process completed its execution.
	if(ProcessRunByCPU.isDone()) { 
		free=TRUE;
		ProcessRunByCPU.terminate();
		number_of_executed_processes++;
	}
	else if((--time_quantum)<1) {
		ProcessRunByCPU.adjust_status();
		ReadyQueue.insert(ProcessRunByCPU);
		free=TRUE;
	}
	return free;
}



//	Adds process to CPU.
void CPU::addProcess(Process ProcessToAdd)
{
	ProcessRunByCPU=ProcessToAdd;
	ProcessRunByCPU.run();
	free=FALSE;
	time_quantum=TIME_QUANTUM;
	return;
}
