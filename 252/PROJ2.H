//	Boris Vaysfeld
//	CIS 25	Fall 99
//	Assignment #2.
//	proj2.h



#ifndef	PROJ2_H
#define PROJ2_H


const int TRUE=1;
const int FALSE=0;
const int PROCESS_CREATION_TIME=0;
const int TOTAL_NUMBER_OF_PROCESSES=12;

const int TIME_QUANTUM=7;

const char TIME_TO_EXIT='E';
const char INSTRUCTION='I';
const int NONE=0;

//	States of the process.
const int STATE_UNKNOWN=-1;
const int STATE_NEW=1;
const int STATE_READY=2;
const int STATE_RUNNING=3;
const int STATE_TERMINATED=4;


class Process {
	public:
		Process();	//	Default constructor

		int isDone();
		void create_this_process(int, int);
		void print_info_about_this_process();
		void change_process_state(int);
		void run();
		void terminate();
		void adjust_status();

	private:
		int process_id;		//	Process Id
		int process_length;	//	Process duration
		int total_number_of_instructions_to_run;
		int number_of_executed_instructions;
		int total_waiting_time;	//	Total waiting time
		int new_state;		//	New state of the process
		int previous_state;	//	Previous state of the process
		int time_of_creation;	//	Time when process was created
		int process_life;	//	Life time of process
		int last_execution_time;//	Last time of removal from ready queue
};



class Node {
       public:
               Node(); //      Default constructor

	       Process getData()const;
           Node *getNext()const;
	       void setData(Process);
           void setNext(Node *);

       private:
	       Process data;
           Node *next;
};



class Queue {
       public:
           Queue();
           ~Queue();

           Node *getFront()const { return front; }
	       void insert(Process);
	       Process remove();
           int isEmpty()const;

       private:
           Node *front;
	       Node *rear;
};



class CPU {
	public:
		CPU() { free=TRUE; time_quantum=TIME_QUANTUM; }

		int isFree();
		void addProcess(Process);

	private:
		int free;
		int time_quantum;
		Process ProcessRunByCPU;
};

#endif
