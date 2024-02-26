#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct SingleLinkedListNode {
    int value;
    struct SingleLinkedListNode  * next;
} SingleLinkedListNode;

typedef struct SingleLinkedList {
    SingleLinkedListNode * first;
    int counter;
} SingleLinkedList;


SingleLinkedList * SingleLinkedListCreate();

void SingleLinkedListDestroy(SingleLinkedList *collection);

bool SingleLinkedListInsertFirst(SingleLinkedList *collection, int value);

bool SingleLinkedListInsertLast(SingleLinkedList *collection, int value);

int SingleLinkedListRemoveFirst(SingleLinkedList *collection);

int SingleLinkedListRemoveLast(SingleLinkedList *collection);

int SingleLinkedListFindByIndex(SingleLinkedList collection, int index) ;

int SingleLinkedListFindByValue(SingleLinkedList *collection, int value);

void SingleLinkedListPrint(SingleLinkedList collection); 

int SingleLinkedListLength(SingleLinkedList collection);

void SingleLinkedListSort(SingleLinkedList *collection);

SingleLinkedListNode * SingleLinkedListGetFirstNode(SingleLinkedList *collection);
SingleLinkedListNode * SingleLinkedListNextNode(SingleLinkedListNode *node);

int SingleLinkedListGetValue(SingleLinkedListNode * node);

SingleLinkedListNode * SingleLinkedListInsertBefore(SingleLinkedList *collection,SingleLinkedListNode * node);