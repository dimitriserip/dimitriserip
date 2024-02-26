#include <stdio.h>
#include <stdlib.h>

#include "single_linked_list.h"

int main(int argc, char * argv) {
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