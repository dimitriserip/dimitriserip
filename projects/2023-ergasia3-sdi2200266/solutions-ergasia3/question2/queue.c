#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

typedef struct dnode DNode;

struct dnode {
    void * data;
    struct dnode* next;
    struct dnode* previous;
};

struct dlist {
    struct dnode* first;
    struct dnode* last;
    int count;
};

Queue* queue_create() {
    Queue* list = (Queue*)malloc(sizeof(Queue));
    list->first = NULL;
    list->last = NULL;
    list->count = 0;
    return list;
}

void queue_destroy(Queue* list) {
    if (list != NULL) {
        DNode* current = list->first;
        DNode* next = NULL;

        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
        list->first = NULL;
        list->last = NULL;
        list->count = 0;

        free(list);
    }
}

void queue_add_first(Queue * list, void * value) {
    if (list != NULL) {
        DNode * node = (DNode *) malloc(sizeof(DNode));
        node->data = value;
        node->next = list->first;
        node->previous = NULL;

        if (list->first != NULL) {
            list->first->previous = node;
        } else {
            list->last = node;
        }
        
        list->first = node;
        
        list->count++;   
    }
}

void queue_add_last(Queue * list, void * value) {
    if (list != NULL) {
        DNode * node = (DNode *) malloc(sizeof(DNode));
        node->data = value;
        node->next = NULL;
        node->previous = list->last;

        if (list->first == NULL)  {    
            queue_add_first(list, value);
            free(node);
        } else {
            list->last->next = node;
            node->previous = list->last;
            list->last = node;

            list->count++; 
        }
    }
}


// Enqueue an element at the rear of the queue
void queue_enqueue(Queue* list, void * value) {
    if (list != NULL) {
        queue_add_last(list, value);
    }
}

bool queue_is_empty(Queue * list) {
    if (list != NULL) {
        return list->count == 0;
    } else {
        return false;
    }
}

void * queue_get_first(Queue * list) {
    if (list != NULL) {
        return list->first->data;
    } else {
        return NULL;
    }
}

DNode * queue_get_node(Queue * list, void * value){
    if (list != NULL) {
        DNode * temp = list->first;
        
        while (temp != NULL){
            if (temp->data == value){
                break;     
            } else {
                temp=temp->next;
                continue; 
            }
        }    
        
        return temp;
    } else {
        return NULL;
    }
}

void queue_remove(Queue * list, void * value) {
    if (list != NULL) {
        DNode * temp  = queue_get_node(list, value);
        if (temp == NULL) {
            return;
        }

        if (temp == list->first) {
            if (temp->next) {
                temp->next->previous = NULL;
            }
            list->first = temp->next; 
            if (list->first) {
                list->first->previous = NULL;
            }
            free(temp);           
        } else if (temp == list->last) {
            list->last->previous->next = NULL;
            list->last = list->last->previous;
            free(temp);
        } else {
            DNode * prev = temp->previous;
            DNode * next = temp->next;
            prev->next = next;
            next->previous = prev;
            free(temp);            
        }

        list->count--;
    }
}

// Dequeue an element from the front of the queue
void * queue_dequeue(Queue* list) {
    if (list != NULL && !queue_is_empty(list)) {
        void * value = queue_get_first(list);
        queue_remove(list, value);
        return value;
    }
    return NULL; // Or any other sentinel value indicating failure
}
