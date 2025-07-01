//	queue.c
//	07.01.25
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<math.h>
#include<ctype.h>
#include<wchar.h>

#define TEST_STRING "Charles Babbage"

struct Node {
	int data;
	struct Node *next;
};
typedef struct Node NODE;

struct Queue{
	int size;
	NODE *head;
	NODE *tail;
};
typedef struct Queue QUEUE;

void initQueue(QUEUE *q)
{
	q->size = 0;
	q->head = NULL;
	q->tail = NULL;
}

int isEmpty(QUEUE *q)
{
	if(!q) return 1;
	if(q && !q->head && !q->tail) return 1;
	return 0;
}

void destroyQueue(QUEUE*q)
{
	NODE *p = q->head;
	NODE *qq=NULL;
	
	if(isEmpty(q)) return;
	
	while(p) {
		qq=p;
		p=p->next;
		free(qq);
		qq=NULL;
		--(q->size);
		puts("Deleted item");
	}
	q=NULL;
}

void push(QUEUE *q, int x)
{
	NODE *n = (NODE*)malloc(sizeof(NODE));
	assert(n);
	n->data = x;
	n->next = NULL;
	if(!q->head) { // First node		
		q->head = n;
		q->tail = n;  // Head and tail are the same for the first node.
	}
	else {
		q->tail->next = n;
		q->tail = n;
	}
	++(q->size);
}


int pop(QUEUE *q)
{
	int x=0;
	NODE *n=NULL;
	
	if(isEmpty(q)) {
		puts("Cannot pop an empty queue!");
		abort(); // C++ STL queue.pop() also calls abort() if empty queue is popped.
	}
	else {
		x =q->head->data;
		n = q->head;
		q->head = q->head->next;
		free(n);
		n=NULL;
		--(q->size);
		if(q->size == 1) { // Last node is the only left.
			q->tail = q->head;
		}
		if(q->size == 0) {	// Queue is empty now.
			q->head = NULL;
			q->tail = NULL;			
		}
	}
	return x;
}

int main(int argc, char**argv)
{
	QUEUE q; // You can also assign s={0}; to initialize it, but only once.
	int x=0;
	initQueue(&q);
	if(!isEmpty(&q))
		puts("Queue is NOT empty");
	else
		puts("Queue is empty");

	push(&q,0);
	push(&q,1);
	push(&q,2);
	printf("Queue has %d items.\n", q.size);
	x=pop(&q);
	printf("Popped: %d. Queue has %d items left.\n", x, q.size);
	
	while(!isEmpty(&q)) {
		x=pop(&q);
		printf("Popped: %d. Queue has %d items left.\n", x, q.size);
	}
	assert(isEmpty(&q)); // Queue is empty now.

	x = 0;
	while(TEST_STRING[x]) {
		push(&q,TEST_STRING[x]);
		++x;
	}
	printf("%d items in source string. Queue has %d items.\n", (int)strlen(TEST_STRING), q.size);
	while(!isEmpty(&q)) {
		x=pop(&q);
		printf("Popped: %c. Queue has %d items left.\n", x, q.size);
	}
	assert(isEmpty(&q)); // Queue is empty now.
	destroyQueue(&q);
    return 0;
}
