//	stack.c
//	06.22.25

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

struct Stack{
	int size;
	NODE *head;
};
typedef struct Stack STACK;

void initStack(STACK *s)
{
	s->size = 0;
	s->head = NULL;
}

int isEmpty(STACK *s)
{
	if(!s) return 1;
	if(s && !s->head) return 1;
	return 0;
	
}

void destroyStack(STACK*s)
{
	NODE *p = s->head;
	NODE *q=NULL;

	if(isEmpty(s))	return;
	
	while(p) {
		q=p;
		p=p->next;
		free(q);
		q=NULL;
		--(s->size);
		puts("Deleted item");
	}
	s=NULL;
}

void push(STACK *s, int x)
{
	NODE *n = (NODE*)malloc(sizeof(NODE));
	assert(n);
	n->data = x;
	if(!s->head) { // First node
		n->next = NULL;
		s->head = n;
	}
	else {
		n->next = s->head;
		s->head = n;
	}
	++(s->size);
}


int pop(STACK *s)
{
	int x=0;
	NODE *n=NULL;
	
	if(isEmpty(s)) {
		puts("Cannot pop an empty stack!");
		abort(); // C++ STL stack.pop() also calls abort() if empty stack is popped.
	}
	else {
		x =s->head->data;
		n = s->head;
		s->head = s->head->next;
		free(n);
		n=NULL;
		--(s->size);
	}
	return x;
}

int main(int argc, char**argv)
{
	STACK s; // You can also assign s={0}; to initialize it, but only once.
	int x=0;
	initStack(&s);
	if(!isEmpty(&s))
		puts("Stack is NOT empty");
	else
		puts("Stack is empty");

	push(&s,0);
	push(&s,1);
	push(&s,2);
	printf("Stack has %d items.\n", s.size);
	x=pop(&s);
	printf("Popped: %d. Stack has %d items left.\n", x, s.size);
	
	while(!isEmpty(&s)) {
		x=pop(&s);
		printf("Popped: %d. Stack has %d items left.\n", x, s.size);
	}
	assert(isEmpty(&s)); // Stack is empty now.
	
	x = 0;
	while(TEST_STRING[x]) {
		push(&s,TEST_STRING[x]);
		++x;
	}
	printf("%d items in source string. Stack has %d items.\n", strlen(TEST_STRING), s.size);
	while(!isEmpty(&s)) {
		x=pop(&s);
		printf("Popped: %c. Stack has %d items left.\n", x, s.size);
	}
	assert(isEmpty(&s)); // Stack is empty now.
	destroyStack(&s);
    return 0;
}
