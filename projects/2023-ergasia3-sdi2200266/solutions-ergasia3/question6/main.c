#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "skip_list.h"

int main() {
    srand(1000); // Initialize the random number generator

    int x1[10] = {5, 20, 12, 76, 18, 2, 95, 25, 56, 62};
    int x2[10] = {41, 5, 11, 39, 25, 61, 93, 82, 17, 9};

    SkipList * list1 = SkipListInit();
    SkipList * list2 = SkipListInit();

    printf("Insert:--------------------\n");

    for (int i = 0; i < sizeof (x1) / sizeof (x1[0]); i++) {
        SkipListInsert(list1, x1[i], x1[i]);
        SkipListDisplay(list1);
    }
    
    SkipListDump(list1);

    for (int i = 0; i < sizeof (x2) / sizeof (x2[0]); i++) {
        SkipListInsert(list2, x2[i], x2[i]);
        SkipListDisplay(list2);
    }
    
    SkipListDump(list2);


    printf("Search:--------------------\n");
    
    int search_x1[6] = {5, 21, 12, 77, 18, 21};

    for (int i = 0; i < 6; i++) {
        link x = SkipListSearch(list1, search_x1[i]);
        
        if (x) {
            printf("key = %d, value = %d\n", search_x1[i], x->value);
        } else {
            printf("key = %d, not found\n", search_x1[i]);
        }
    }

    printf("Delete:--------------------\n");
    
    SkipListDelete(list1, 5);
    SkipListDisplay(list1);
    
    SkipListDelete(list1, 2);
    SkipListDisplay(list1);

//    printf("%d\n", list1->size);

    printf("-------------------------------\n");
    printf("             List 1: \n");
    printf("-------------------------------\n");
    
    SkipListDisplay(list1);
    
    printf("-------------------------------\n");
    printf("              List 2: \n");
    printf("-------------------------------\n");
    
    SkipListDisplay(list2);
    
    
    printf("-------------------------------\n");
    printf("     List 3 = list1 + list2 : \n");
    printf("-------------------------------\n");
    
    SkipList* list3 = SkipListMerge(list1, list2);
    
    SkipListDisplay(list3);
    
    for (int i = 0; i < sizeof (x1) / sizeof (x1[0]); i++) {
        int value  = x1[i];
        
        if (value == 2) {            
            continue; // deleted from previous steps
        }
                
        link x = SkipListSearch(list3, value);
        
        if (x) {
            printf("key = %d, value = %d\n", value, x->value);
        } else {
            printf("key = %d, not found - merge failed !!!\n", value);
            return -1;
        }
    }   
    

    for (int i = 0; i < sizeof (x2) / sizeof (x2[0]); i++) {
        int value  = x2[i];
        
        if (value == 2) {            
            continue; // deleted from previous steps
        }
                
        link x = SkipListSearch(list3, value);
        
        if (x) {
            printf("key = %d, value = %d\n", value, x->value);
        } else {
            printf("key = %d, not found - merge failed\n", value);
            return -1;
        }
    }
    printf("The end. \n");
    
    
    
    return 0;
}

