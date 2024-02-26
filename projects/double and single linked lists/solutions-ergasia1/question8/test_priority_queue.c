#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "acutest/acutest.h"
#include "priority_queue_module/PQInterface.h"

void test_priority_queue()
{
        int N = 2000;

        PQItem data[2000];

        srand(100);

        for (int i = 0; i < N; ++i)
        {
                data[i] = rand() % 1000;
        }

        PriorityQueuePtr queue = PriorityQueueCreate();

        for (int i = 0; i < N; ++i)
        {
                PriorityQueueInsert(data[i], queue);
        }

        for (int i = N - 1; i >= 0; --i)
        {
                data[i] = PriorityQueueRemove(queue);
        }
        
        for (int i = 0; i < N-1; ++i) {
                TEST_ASSERT(data[N] <= data[N+1]);
        }

        PriorityQueueDestroy(queue);
}

TEST_LIST = {
    {"test_priority_queue", test_priority_queue},
    {NULL, NULL} /* zeroed record marking the end of the list */
};
