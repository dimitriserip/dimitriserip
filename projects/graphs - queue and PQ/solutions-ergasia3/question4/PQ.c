#include "PQ.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PriorityQueue {
    int Count;
    int Capacity;
    PQItem* ItemArray;
};

// QUEUEInit
PriorityQueue* PriorityQueueInitialize(int maxN) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->Count = 0;
    pq->Capacity = maxN;
    pq->ItemArray = malloc(sizeof(PQItem) * (maxN + 1));
    return pq;
}

void PriorityQueueDestroy(PriorityQueue* pq) {
    free(pq->ItemArray);
    free(pq);
}

// QUEUEEmpty
int PriorityQueueEmpty(PriorityQueue* PQ) {
    return (PQ->Count == 0);
}

int PriorityQueueFull(PriorityQueue* PQ) {
    return (PQ->Count == PQ->Capacity);
}

// QUEUEPut
void PriorityQueueInsert(PriorityQueue* PQ, PQItem Item) {
    int ChildLoc;
    int ParentLoc;

    if (PriorityQueueFull(PQ)) {
        return;
    }

    (PQ->Count)++;
    ChildLoc = PQ->Count;
    ParentLoc = ChildLoc / 2;
    
    while (ParentLoc != 0) {
        if (Item->weight >= PQ->ItemArray[ParentLoc]->weight) {
            PQ->ItemArray[ChildLoc] = Item;
            return;
        } else {
            PQ->ItemArray[ChildLoc] = PQ->ItemArray[ParentLoc];
            ChildLoc = ParentLoc;
            ParentLoc = ParentLoc / 2;
        }
    }
    PQ->ItemArray[ChildLoc] = Item;
}

// QUEUEGet
PQItem PriorityQueueRemove(PriorityQueue* PQ) {
    int CurrentLoc;
    int ChildLoc;
    PQItem ItemToPlace;
    PQItem ItemToReturn;

    if (PriorityQueueEmpty(PQ)) {
        return 0;
    }

    ItemToReturn = PQ->ItemArray[1];
    ItemToPlace = PQ->ItemArray[PQ->Count];
    (PQ->Count)--;
    CurrentLoc = 1;
    ChildLoc = 2 * CurrentLoc;

    while (ChildLoc <= PQ->Count) {
        if (ChildLoc < PQ->Count) {
            if (PQ->ItemArray[ChildLoc + 1]->weight <= PQ->ItemArray[ChildLoc]->weight) {
                ChildLoc++;
            }
        }
        if (PQ->ItemArray[ChildLoc]->weight >= ItemToPlace->weight) {
            PQ->ItemArray[CurrentLoc] = ItemToPlace;
            return (ItemToReturn);
        } else {
            PQ->ItemArray[CurrentLoc] = PQ->ItemArray[ChildLoc];
            CurrentLoc = ChildLoc;
            ChildLoc = 2 * CurrentLoc;
        }
    }
    PQ->ItemArray[CurrentLoc] = ItemToPlace;

    return (ItemToReturn);
}

void PrintPriorityQueue(PriorityQueue* PQ) {
    int x = PQ->Count;

    for (int i = 0; i <= x; i++) {
        printf("%d -> %d (%d) \n", PQ->ItemArray[i]->startpoint, PQ->ItemArray[i]->endpoint, PQ->ItemArray[i]->weight);
    }
    printf("\n");
}

int PriorityQueueGetCapacity(PriorityQueue* PQ) {
    return PQ->Capacity;
}