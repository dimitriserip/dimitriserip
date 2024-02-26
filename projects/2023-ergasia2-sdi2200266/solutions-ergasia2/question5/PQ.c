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
PriorityQueue* Initialize(int maxN) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->Count = 0;
    pq->Capacity = maxN;
    pq->ItemArray = malloc(sizeof(PQItem) * (maxN + 1));
    return pq;
}

void Destroy(PriorityQueue* pq) {
    free(pq->ItemArray);
    free(pq);
}

// QUEUEEmpty
int Empty(PriorityQueue* PQ) {
    return (PQ->Count == 0);
}

int Full(PriorityQueue* PQ) {
    return (PQ->Count == PQ->Capacity);
}

// QUEUEPut
void Insert(PriorityQueue* PQ, PQItem Item) {
    int ChildLoc;
    int ParentLoc;

    if (Full(PQ)) {
        return;
    }

    (PQ->Count)++;
    ChildLoc = PQ->Count;
    ParentLoc = ChildLoc / 2;
    while (ParentLoc != 0) {
        if (Item <= PQ->ItemArray[ParentLoc]) {
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
PQItem Remove(PriorityQueue* PQ) {
    int CurrentLoc;
    int ChildLoc;
    PQItem ItemToPlace;
    PQItem ItemToReturn;

    if (Empty(PQ)) {
        return 0;
    }

    ItemToReturn = PQ->ItemArray[1];
    ItemToPlace = PQ->ItemArray[PQ->Count];
    (PQ->Count)--;
    CurrentLoc = 1;
    ChildLoc = 2 * CurrentLoc;

    while (ChildLoc <= PQ->Count) {
        if (ChildLoc < PQ->Count) {
            if (PQ->ItemArray[ChildLoc + 1] > PQ->ItemArray[ChildLoc]) {
                ChildLoc++;
            }
        }
        if (PQ->ItemArray[ChildLoc] <= ItemToPlace) {
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
        printf("%d ", PQ->ItemArray[i]);
    }
    printf("\n");
}

int GetCapacity(PriorityQueue* PQ) {
    return PQ->Capacity;
}