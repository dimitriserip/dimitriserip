#include "PQ.h"
#include "acutest/acutest.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// cant visualize the test
void test_PQinsert() {
    PriorityQueue* PQ = Initialize(20);

    int counter = 0;

    srand(100);

    for (int k = 0; k < 20; k++) {
        int i = rand() % 1000;
        Insert(PQ, i);
        printf("%d\n", i);
        counter++;
    }

    PrintPriorityQueue(PQ);

    printf("The PriorityQueue has %d items in it\n", counter);
}

// checked if insert works before
void test_PQ_empty_and_full() {
    PriorityQueue* PQ = Initialize(20);

    TEST_ASSERT(Empty(PQ) == 0);

    for (int j = 0; j < 10; j++) {
        Insert(j, PQ);
    }

    TEST_ASSERT(Full(PQ) == GetCapacity(PQ));
}

void test_PQ_remove() {
    PriorityQueue* PQ = Initialize(20);

    Insert(PQ, 1);
    Remove(PQ);

    TEST_ASSERT(Empty(PQ) == 0);
}

TEST_LIST = {
    {"test_PQ_empty_and_full", test_PQ_empty_and_full},
    {"test_PQ_remove", test_PQ_remove},
    {NULL, NULL}};