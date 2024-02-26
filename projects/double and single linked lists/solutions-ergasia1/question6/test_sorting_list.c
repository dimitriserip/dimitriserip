#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "acutest/acutest.h"
#include "single_linked_list.h"

void test_sorting_list(){    
    SingleLinkedList * list = SingleLinkedListCreate();

    srand(100);

    int N = 2000;
    int max = 100;

    for(int i=0; i<N; i++){
        int value = rand()%1000;
        SingleLinkedListInsertFirst(list,value);
    }

    // SingleLinkedListPrint(*list);
    // printf("\n");

    SingleLinkedListSort(list);

    // SingleLinkedListPrint(*list);
    // printf("\n");

    SingleLinkedListNode * current = NULL; 
    SingleLinkedListNode * next = NULL;

    for (current = SingleLinkedListGetFirstNode(list); current != NULL; current = next) {
        if (!next) {
            break;
        }

        int currentValue = SingleLinkedListGetValue(current);
        int nextValue = SingleLinkedListGetValue(next);

        TEST_ASSERT(currentValue < nextValue);
    }
   

    SingleLinkedListDestroy(list);
}


TEST_LIST = {      
        { "test_sorting_list", test_sorting_list  },
        { NULL, NULL } /* zeroed record marking the end of the list */
};
