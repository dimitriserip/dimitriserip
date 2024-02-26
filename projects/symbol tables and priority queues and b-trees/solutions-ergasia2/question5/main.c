#include "PQ.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int capacityA = 10;
    int capacityB = 20;
    PriorityQueue* queueA = Initialize(capacityA);
    PriorityQueue* queueB = Initialize(capacityB);

    if (Empty(queueA)) {
        printf("Queue A is empty (correct)\n");
    }

    if (Empty(queueB)) {
        printf("Queue B is empty (correct)\n");
    }

    for (int i = 0; i < capacityA + 3; i++) {
        if (Full(queueA)) {
            printf("Queue A is full (expected) \n");
        }

        Insert(queueA, rand() % 1000);
    }

    PrintPriorityQueue(queueA);

    for (int i = 0; i < capacityB + 3; i++) {
        if (Full(queueB)) {
            printf("Queue B is full (expected) \n");
        }

        Insert(queueB, rand() % 1000);
    }

    PrintPriorityQueue(queueB);

    int temp = 10000;

    printf("---------------------------- Queue A extract sequence \n");

    while (!Empty(queueA)) {
        int i = Remove(queueA);
        if (i > temp) {
            printf("Something went wrong (not expected ) \n");
        } else {
            printf("%d \n", i);
            temp = i;
        }
    }

    temp = 10000;

    printf("---------------------------- Queue B extract sequence  \n");

    while (!Empty(queueB)) {
        int i = Remove(queueB);
        if (i > temp) {
            printf("Something went wrong (not expected ) \n");
        } else {
            printf("%d \n", i);
            temp = i;
        }
    }

    if (Empty(queueA)) {
        printf("Queue A is empty (correct)\n");
    } else {
        printf("Queue A is not empty (error)\n");
    }

    if (Empty(queueB)) {
        printf("Queue B is empty (correct)\n");
    } else {
        printf("Queue B is not empty (error)\n");
    }

    Destroy(queueA);
    Destroy(queueB);

    return 0;
}
