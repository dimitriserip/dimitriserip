#pragma once

typedef int PQItem;

typedef struct PriorityQueue PriorityQueue;
typedef struct PriorityQueue* PQPointer;

PriorityQueue* Initialize(int maxN);
void Destroy(PriorityQueue*);
int Empty(PriorityQueue*);
int Full(PriorityQueue*);
void Insert(PriorityQueue*, PQItem);
PQItem Remove(PriorityQueue*);
void PrintPriorityQueue(PriorityQueue* PQ);

int GetCapacity(PriorityQueue* PQ);

// typedef PriorityQueue *PQPointer;
// PQPointer QUEUEinit(int maxN);
// int QUEUEempty(PQPointer);
// void QUEUEput(PQPointer, Item);
// Item QUEUEget(PQPointer);
