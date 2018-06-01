//      Boris Vaysfeld
//      CIS 25  Fall 99
//      Assignment #2.
//	    proj2.cpp



#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
#include<limits.h>
#include"proj2.h"

#ifndef MAX_CANON
    #define MAX_CANON 512
#endif
using namespace std;

CPU TheCPU;	//	CPU
Queue ReadyQueue;	//	Ready Queue
Process	*PCB;
int CurrentTime=0;	//      Current time in milliseconds.
int number_of_executed_processes=0;   //      Number of executed processes. 
	
void create_all_processes(Process *);
void execute_process();

int main()
{
	//	Initially CPU is free.
	assert(TheCPU.isFree());
	
	//	Initially ReadyQueue is empty.
	assert(ReadyQueue.isEmpty());

	//	Allocate memory for an array of processes.
	PCB=new Process[TOTAL_NUMBER_OF_PROCESSES];
	assert(PCB);	//	Check if allocation was successful.
	
	cout<<"Time\tId\tPC\tLife\tCPUtime\tWait\tPrev State\tNew State";
        cout<<endl<<endl;
	
	//	Create all processes.
	create_all_processes(PCB);

	//	Insert processes into ReadyQueue.
	//	Processes change state from New to Ready.
	for(int i=0; i<TOTAL_NUMBER_OF_PROCESSES;i++) 
		ReadyQueue.insert(PCB[i]);

	//	CPU is always working, always waits for process to run.
	//	CPU takes processes from ready queue one at a time.
	//	Then CPU becomes busy while it executes some process.
	//	After process is executed, it becomes free again.
	//	It will execute processes until there are processes in ready queue.
	while(1) {
		if(TheCPU.isFree()) {
			if(!ReadyQueue.isEmpty()) {
				execute_process();
			}
			else
				break;
		}
		CurrentTime++;
	}

	//	Now, all processes should be executed.
	//	CPU must be free.
	assert(TheCPU.isFree());

	//	ReadyQueue must be empty after all processes are executed.
	assert(ReadyQueue.isEmpty());

	//	Check number of executed processes here.
	assert(number_of_executed_processes==TOTAL_NUMBER_OF_PROCESSES);

	//	Now, clean up allocated memory...
	delete []PCB;

	cout<<"\nAll "<<number_of_executed_processes<<" processes run ";
	cout<<CurrentTime<<" ms."<<endl;

	return EXIT_SUCCESS;
}



//	This function will create all processes.
void create_all_processes(Process *PCB)
{

	int *id;
	int *instructions;
	ifstream in;

	//	Open memory input file for reading.
	in.open("memory", ios::in);	

	char *temp;
	char data;
	
	//	Create an array to hold id of the processes.
	id=new int[TOTAL_NUMBER_OF_PROCESSES];
	assert(id);

	//	Create an array to hold number of instructions of the processes.
	instructions=new int[TOTAL_NUMBER_OF_PROCESSES];
	assert(instructions);

	//	Create temporary buffer to store input.
	temp=new char[MAX_CANON];
	assert(temp);
    memset(temp, 0, sizeof(temp)); 

	int TOTAL_PROCESSES=0;
	int i=0, number_of_instructions=0, tempid=1, j=0, n=0;
	while(in>>data) {
		if(data != TIME_TO_EXIT) {
			if(isalpha(data) && data==INSTRUCTION)
				number_of_instructions++;
			if(isdigit(data))
				tempid++;
			temp[j]=data;
			j++;
		}
		else {
			TOTAL_PROCESSES++;
			temp[j]='\0';
			char *ttt=new char[tempid+1];
			assert(ttt);
            memset(ttt, 0, sizeof(ttt)); 
			for(n=0;n<tempid;n++)
				ttt[n]=temp[n];
			ttt[tempid-1]='\0';
			id[i]=atoi(ttt);
			instructions[i]=number_of_instructions+1;
            memset(temp, 0, sizeof(temp)); 
			j=0;
			number_of_instructions=0;
			tempid=1;
			i++;
			delete []ttt;
		}
	}
	in.close();	//	Close input file.
	delete []temp;	//	Delete temporary buffer.

	assert(TOTAL_PROCESSES==TOTAL_NUMBER_OF_PROCESSES);

	//	Now, create all processes.	
	for(i=0;i<TOTAL_NUMBER_OF_PROCESSES;i++) {
		PCB[i].create_this_process(id[i], instructions[i]);
	}

	//	Clean up allocated memory.
	delete []id;
	delete []instructions;
	return;
}



//	This function will execute process.
void execute_process()
{
	Process ProcessToExecute=ReadyQueue.remove();
	TheCPU.addProcess(ProcessToExecute);
	return;
}
