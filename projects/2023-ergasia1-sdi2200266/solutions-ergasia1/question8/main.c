#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include "priority_queue_module/PQInterface.h"

void PriorityQueueSort(PQItem * data, int N) {
    PriorityQueuePtr queue = PriorityQueueCreate();    

    for (int i=0; i<N; ++i) {
         PriorityQueueInsert(data[i], queue);
    }

    for (int i=N-1; i>=0; --i) {
        data[i]=PriorityQueueRemove(queue);
    }

    PriorityQueueDestroy(queue);
}

int main(int argc, char * argv[]) {
    int N = 50;
    PQItem data[50];

    srand(100);

    for (int i = 0; i < N; ++i) {
        data[i] = rand() % 1000;
    }

    for (int i = 0; i < N; ++i) {
        printf("%d\t", data[i]);
    }
    printf("\n");

    PriorityQueueSort(data, N);

    for (int i = 0; i < N; ++i) {
        printf("%d\t", data[i]);
    }
    printf("\n");

    return 0;
}
