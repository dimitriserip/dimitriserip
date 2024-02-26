#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#include "single_linked_list.h"

SingleLinkedList * SingleLinkedListCreate() {
    SingleLinkedList *  collection = (SingleLinkedList * ) malloc(sizeof(SingleLinkedList));
    collection->first = NULL;
    collection->counter = 0;
    return collection;
}

void SingleLinkedListDestroy(SingleLinkedList *collection) {   
   SingleLinkedListNode * current = collection->first;
   SingleLinkedListNode * next = NULL;

   while (current != NULL) {
       next = current->next;
       free(current);
       current = next;
   }   
   collection->first = NULL; 
   collection->counter = 0;

   free(collection);
}

bool SingleLinkedListInsertFirst(SingleLinkedList *collection, int value) {
    // 1. create node
    SingleLinkedListNode * node = (SingleLinkedListNode *) malloc(sizeof(SingleLinkedListNode));
    
    // 2. initialize node values
    node->value = value;
    node->next = collection->first;
    
    // 3. update pointers on collection
    collection->first = node;
    
    // 4. update counter    
    collection->counter++;   
    
    return 0;
}

bool SingleLinkedListInsertLast(SingleLinkedList *collection, int value) {
    //1. create node
    SingleLinkedListNode * node = (SingleLinkedListNode * ) malloc(sizeof(SingleLinkedListNode));
    node->value = value;
    node->next = NULL;
    
    if (collection->first == NULL)  {    
        SingleLinkedListInsertFirst(collection, value);
    } else {
        SingleLinkedListNode * temp = collection->first;

        //2. diasxizw lista mexri prin ton teleutaio kombo
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = node;

        //4. update counter
        collection->counter++; 
    }
    
    return 0;
}

int SingleLinkedListFindByIndex(SingleLinkedList collection, int index) {
    if (index < collection.counter) {
        SingleLinkedListNode * temp = collection.first;

        for (int i=0;i<index;i++) {
            temp=temp->next;
        }

        return temp->value;
    } else {
        return -1;
    }
}

int SingleLinkedListFindByValue(SingleLinkedList *collection, int value) {
    int index=-1;
    
    SingleLinkedListNode * temp;
    temp = collection->first;
    
        while(temp->next != NULL){
          temp = temp->next;
          index++;
          
          if(temp->value == value){
              break;     
          }else continue; 
        }    
    
    return index;
}    

void SingleLinkedListPrint(SingleLinkedList collection) {
    SingleLinkedListNode * temp = collection.first;
    
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp=temp->next;
    }
    printf("\n");
}


int SingleLinkedListRemoveFirst(SingleLinkedList *collection) {
    if (collection == NULL) {
        return 0;
    }

    if (collection->counter == 0) {
        return 0;
    }
    
    SingleLinkedListNode * temp;
    temp = collection->first;
    collection->first = temp->next; 
           
    int value = temp->value;
    free(temp);

    collection->counter--;
    return value;
}

int SingleLinkedListRemoveLast(SingleLinkedList *collection) {
    int value = -1;
    SingleLinkedListNode * temp = collection->first;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    value = temp->value;
    free(temp);
    
    collection->counter--;

    return value;
}


int SingleLinkedListLength(SingleLinkedList collection) {
    return collection.counter;
}


void SingleLinkedListSort(SingleLinkedList *collection){
    if (collection == NULL || collection->counter <= 1) {
        return;
    }

    SingleLinkedListNode * current = collection->first ;

    while (current != NULL) {
        SingleLinkedListNode * next = current->next;

        if (next == NULL) {
            break;
        }

        // printf("Current :  %d \n", current->value);
        // printf("Next    :  %d \n", next->value);

        if (current->value <= next->value) {
            current = current->next;
            continue;
        }

        current->next = next->next;

        if (next->value <= collection->first->value) {
            next->next = collection->first;
            collection->first = next;
        } else {
            SingleLinkedListNode * current2 = collection->first;
            while (current2->next->value < next->value) {
                current2 = current2->next;
            }

            next->next = current2->next;
            current2->next = next;
        }

        // SingleLinkedListPrint(*collection);
    }
}

SingleLinkedListNode * SingleLinkedListGetFirstNode(SingleLinkedList *collection) {
    if (collection) {
        return collection->first;
    } else {
        return NULL;
    }
}

int SingleLinkedListGetValue(SingleLinkedListNode * node) {
    if (node) {
        return node->value;
    } else {
        return 0;
    }
}

SingleLinkedListNode * SingleLinkedListNextNode(SingleLinkedListNode *node) {
    if (node) {
        return node->next;
    } else {
        return NULL;
    }
}

SingleLinkedListNode * SingleLinkedListInsertBefore(SingleLinkedList *collection,SingleLinkedListNode * node){
    SingleLinkedListNode * temp;
    SingleLinkedListNode * node_before_temp = collection->first;
    temp = node_before_temp->next;

    while(temp != NULL){
        if(temp = node){
            SingleLinkedListNode * new_node = malloc(sizeof(SingleLinkedListNode));
            node_before_temp->next = new_node;
            new_node->next = temp;
        }else{
            node_before_temp = temp;
            temp = temp->next;
        }
    }
}

SingleLinkedList * SingleLinkedListSortMerge(SingleLinkedList *l1, SingleLinkedList *l2) {    
    SingleLinkedList * combined_list = SingleLinkedListCreate();
    SingleLinkedListNode * temp = combined_list->first;

 
    SingleLinkedListSort(l1);
    SingleLinkedListSort(l2);

   
   

    if (l1 == NULL && l2 == NULL) {
        return combined_list;
    }

    if (l1 == NULL) {
        SingleLinkedListNode * temp = l2->first;
        while (temp != NULL) {
            int value = temp->value;
            SingleLinkedListInsertLast(combined_list, value);
            temp= temp->next;
        }

        return combined_list;
    }


    if (l2 == NULL) {
        SingleLinkedListNode * temp = l1->first;
        while (temp != NULL) {
            int value = temp->value;
            SingleLinkedListInsertLast(combined_list, value);
            temp= temp->next;
        }

        return combined_list;
    }


    SingleLinkedListNode * current1 = l1->first;
    SingleLinkedListNode * current2 = l2->first;

    while (1){
        if (current1 == NULL && current2 == NULL) {
            return combined_list;
        }

        if (current1 != NULL && current2 == NULL) {
            int value = current1->value;
            current1 = current1->next;
            SingleLinkedListInsertLast(combined_list, value);
            continue;
        }

        if (current1 == NULL && current2 != NULL) {
            int value = current2->value;
            current2 = current2->next;
            SingleLinkedListInsertLast(combined_list, value);
            continue;
        }

        if (current1->value <= current2->value){
            int value = current1->value;
            current1 = current1->next;
            SingleLinkedListInsertLast(combined_list, value);
            continue;
        } else {
            int value = current2->value;
            current2 = current2->next;
            SingleLinkedListInsertLast(combined_list, value);
            continue;
        }
    }
  
}