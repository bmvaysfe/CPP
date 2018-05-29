/* algorithm that would find out whether single linked list has any loops */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node
{  
    void * data;  
    struct Node * pNext;
};
typedef struct Node Node;

/*  Floyd Algorithm */
/* O(n)             */
int hasLoop(Node *startNode)
{
    Node *slowNode=startNode;
    Node *fastNode1=startNode;
    Node *fastNode2=startNode;

    while(slowNode&&(fastNode1=fastNode2->pNext)&& (fastNode2=fastNode1->pNext))
    {
        if (slowNode == fastNode1 || slowNode == fastNode2) 
            return 1; /* loop found */
        slowNode = slowNode->pNext;
    }
    return 0; /* no loops */
}

int main()
{
    Node list[4];
    Node *head=&list[0];
    int loopFlag=0;

    list[0].pNext=&list[1];
    list[1].pNext=&list[2];
    list[2].pNext=&list[3];
    list[3].pNext=&list[1];  /* last node points to 2nd Node */
    
    loopFlag=hasLoop(head);
    printf("List %s loop\n", loopFlag==1?"has":"has no");
    return 0;
}
