#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "acutest/acutest.h"
#include "single_linked_list.h"

void test_left_null(){    
    SingleLinkedList * list = SingleLinkedListCreate();

    srand(100);

    int x[100];

    for (int i=0;i<100;i++) {
        x[i] = rand()%1000;

        SingleLinkedListInsertFirst(list, x[i]);
            
    }

    SingleLinkedList * l1 = NULL;
    SingleLinkedList * l2 = list;
    
    SingleLinkedList * l3 = SingleLinkedListSortMerge(l1, l2);

    TEST_ASSERT(l3 != list);

    int n1 = SingleLinkedListLength(*l3);
    int n2 = SingleLinkedListLength(*list);

    TEST_ASSERT(n1 == n2);
    
    int L = SingleLinkedListLength(*l3);

    for (int i=0;i<L;i++) {
        int v1 = SingleLinkedListRemoveFirst(l3);
        int v2 = SingleLinkedListRemoveFirst(list);

        TEST_ASSERT(v1 == v2);
    }

    SingleLinkedListDestroy(list);
}

void test_right_null(){    
    SingleLinkedList * list = SingleLinkedListCreate();

    srand(100);

    int x[100];

    for (int i=0;i<100;i++) {
        x[i] = rand()%1000;

        SingleLinkedListInsertFirst(list, x[i]);
            
    }

    SingleLinkedList * l1 = list;
    SingleLinkedList * l2 = NULL;
    
    SingleLinkedList * l3 = SingleLinkedListSortMerge(l1, l2);

    TEST_ASSERT(l3 != list);

    int n1 = SingleLinkedListLength(*l3);
    int n2 = SingleLinkedListLength(*list);

    TEST_ASSERT(n1 == n2);
    
    int L = SingleLinkedListLength(*l3);

    for (int i=0;i<L;i++) {
        int v1 = SingleLinkedListRemoveFirst(l3);
        int v2 = SingleLinkedListRemoveFirst(list);

        TEST_ASSERT(v1 == v2);
    }

    SingleLinkedListDestroy(list);
}

void test_both_null(){    
    SingleLinkedList * l1 = NULL;
    SingleLinkedList * l2 = NULL;
    
    SingleLinkedList * l3 = SingleLinkedListSortMerge(l1, l2);

    int L = SingleLinkedListLength(*l3);

    TEST_ASSERT(L == 0);

}

void test_sort_merge(){    
    SingleLinkedList * lists[2] = { SingleLinkedListCreate(), SingleLinkedListCreate() };

    int n[2] = { 50, 100};

    for (int i=0;i<2;i++) {
        for (int j=0;j<n[i];j++) {
            SingleLinkedListInsertFirst(lists[i], rand()%1000);
        }
    }
    
    SingleLinkedList * result = SingleLinkedListSortMerge(lists[0], lists[1]);

    TEST_ASSERT(result != lists[0]);
    TEST_ASSERT(result != lists[1]);

    
    int n1 = SingleLinkedListLength(*lists[0]);
    int n2 = SingleLinkedListLength(*lists[1]);
    int n3 = SingleLinkedListLength(*result);

    TEST_ASSERT(n3 == n1 + n2);
    
   
    SingleLinkedListNode * current = NULL; 
    SingleLinkedListNode * next = NULL;

    for (current = SingleLinkedListGetFirstNode(result); current != NULL; current = next) {
        if (!next) {
            break;
        }

        int currentValue = SingleLinkedListGetValue(current);
        int nextValue = SingleLinkedListGetValue(next);

        TEST_ASSERT(currentValue < nextValue);
    }
   
    SingleLinkedListDestroy(lists[0]);
    SingleLinkedListDestroy(lists[1]);
    SingleLinkedListDestroy(result);
}


TEST_LIST = {      
        { "test_left_null", test_left_null  },
        { "test_right_null", test_right_null  },
        { "test_both_null", test_both_null  },
        { "test_sort_merge", test_sort_merge  },
        { NULL, NULL } /* zeroed record marking the end of the list */
};
