#pragma once

#include "WeightedUndirectedGraph.h"

typedef Edge* PQItem;

typedef struct PriorityQueue PriorityQueue;
typedef struct PriorityQueue* PQPointer;

PriorityQueue* PriorityQueueInitialize(int maxN);
void PriorityQueueDestroy(PriorityQueue*);
int PriorityQueueEmpty(PriorityQueue*);
int PriorityQueueFull(PriorityQueue*);
void PriorityQueueInsert(PriorityQueue*, PQItem);
PQItem PriorityQueueRemove(PriorityQueue*);
void PrintPriorityQueue(PriorityQueue* PQ);

int PriorityQueueGetCapacity(PriorityQueue* PQ);

// typedef PriorityQueue *PQPointer;
// PQPointer QUEUEinit(int maxN);
// int QUEUEempty(PQPointer);
// void QUEUEput(PQPointer, Item);
// Item QUEUEget(PQPointer);
