/* This is the file PQImplementation.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "PQInterface.h"
#include "PQTypes.h"

typedef struct PQListNode PQListNode;
typedef struct PQListNode* PQListNodePtr;
typedef struct PriorityQueue PriorityQueue;

struct PQListNode {
   PQItem NodeItem;
   PQListNodePtr next;
};

struct PriorityQueue {
   int Count;
   PQListNodePtr first;
};

PriorityQueuePtr PriorityQueueCreate() {
   PriorityQueuePtr pqueue = (PriorityQueuePtr)malloc(sizeof(struct PriorityQueue));
   
   pqueue->Count=0;
   pqueue->first = NULL;
   
   return pqueue;
}

void PriorityQueueDestroy(PriorityQueuePtr queue) {
   PQListNodePtr temp = queue->first;

   while (temp != NULL) {
      PQListNodePtr next = temp->next;
      free(temp);
      temp = next;
   }

   free(queue);
}

bool PriorityQueueIsEmpty(PriorityQueuePtr PQ) {
   return PQ->Count == 0;
}

bool PriorityQueueIsFull(PriorityQueuePtr PQ) {
   return false;
}

PQListNodePtr SortedInsert(PQItem Item, PQListNodePtr P) {
   PQListNodePtr N;

   if ((P==NULL)||(Item >=P->NodeItem)){
      N=(PQListNode *)malloc(sizeof(PQListNode));
      N->NodeItem=Item;
      N->next=P;
      return(N);
   } else {
      P->next=SortedInsert(Item, P->next);
      return(P);
   }
}


void PriorityQueueInsert(PQItem Item, PriorityQueuePtr PQ) {
   if (!PriorityQueueIsFull(PQ)){
     PQ->Count++;
     PQ->first=SortedInsert(Item, PQ->first);
   }
}

PQItem PriorityQueueRemove(PriorityQueuePtr PQ) { 
   PQItem temp;

   if (!PriorityQueueIsEmpty(PQ)) {

     temp = PQ->first->NodeItem;
     PQ->first = PQ->first->next;
     PQ->Count--;

     return(temp);
   }
}
