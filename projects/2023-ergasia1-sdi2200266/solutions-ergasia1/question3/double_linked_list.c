#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "double_linked_list.h"

struct dnode {
    int data;
    DNode *next;
    DNode *previous;
};

struct dlist {
    DNode *first;
    DNode *last;
    int count;
};

Dlist * double_linked_list_create() {
    Dlist * list =  (Dlist *) malloc(sizeof(Dlist));
    list->first = NULL;
    list->last = NULL;
    list->count = 0;
    return list;
}

void double_linked_list_destroy(Dlist * list) {
    if (list != NULL) {
        DNode * current = list->first;
        DNode * next = NULL;

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


DNode* double_linked_list_get_first_node(Dlist * list) {
    if (list != NULL) {
        return list->first;
    } else {
        return NULL;
    }
}

DNode* double_linked_list_get_last_node(Dlist * list) {
    if (list != NULL) {
        return list->last;
    } else {
        return NULL;
    }
}

int double_linked_list_get_value(DNode * node) {
    if (node != NULL) { 
        return node->data;
    } else {
        return -1;
    }
}

int double_linked_list_size(Dlist * list) {
    if (list != NULL) {
        return list->count;
    } else {
        return -1;
    }
}

int double_linked_list_is_empty(Dlist * list) {
    if (list != NULL) {
        return list->count == 0;
    } else {
        return -1;
    }
}

int double_linked_list_get_first(Dlist * list) {
    if (list != NULL) {
        return list->first->data;
    } else {
        return -1;
    }
}

int double_linked_list_get_last(Dlist * list){
    if (list != NULL) {
        return list->last->data;
    } else {
        return -1;
    }
}

DNode * double_linked_list_get_node(Dlist * list, int value){
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

DNode * double_linked_list_get_prev(DNode * node){
    if (node != NULL) {
        return node->previous;
    } else {
        return NULL;
    }
}

DNode * double_linked_list_get_next(DNode * node) {
    if (node != NULL) {
        return node->next;
    } else {
        return NULL;
    }
}

void double_linked_list_add_before(Dlist * list, DNode * current, int value) {
    if (list != NULL && current != NULL) {
        if  (current == list->first) {
            double_linked_list_add_first(list, value);
        } else {
            DNode * node = (DNode *) malloc(sizeof(DNode));
            
            node->data = value;
            node->next = current;
            node->previous = current->previous;

            current->previous->next = node;
            current->previous = node;
            
            list->count++;
        }
    }
}

void double_linked_list_add_after(Dlist * list, DNode * current, int value) {
    if (list != NULL && current != NULL) {
        if  (current == list->last) {
            double_linked_list_add_last(list, value);
        } else {
            DNode * node = (DNode *) malloc(sizeof(DNode));
            
            node->data = value;
            node->next = current->next;
            node->previous = current;

            current->next->previous = node;
            current->next = node;
            
            list->count++;
        }
    }
}

void double_linked_list_add_first(Dlist * list, int value) {
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

void double_linked_list_add_last(Dlist * list, int value) {
    if (list != NULL) {
        DNode * node = (DNode *) malloc(sizeof(DNode));
        node->data = value;
        node->next = NULL;
        node->previous = list->last;

        if (list->first == NULL)  {    
            double_linked_list_add_first(list, value);
        } else {
            list->last->next = node;
            list->last = node;

            list->count++; 
        }
    }
}

void double_linked_list_remove(Dlist * list, int value) {
    if (list != NULL) {
        DNode * temp  = double_linked_list_get_node(list, value);
        if (temp == NULL) {
            return;
        }

        if (temp == list->first) {
            temp->next->previous = NULL;
            list->first = temp->next; 
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

void double_linked_list_print(Dlist * list) {
    DNode * temp = list->first;
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}


int max(int x, int y) {
    if (x<y ) {
        return y;
    } else {
        return x;
    }
}

int double_linked_list_find_max_recursive(DNode * node){
    if (node == NULL) {
        return 0;
    } else {
        if (node->next) {
            return max(node->data, double_linked_list_find_max_recursive(node->next));
        } else {
            return node->data;
        }
    }

}

int double_linked_list_find_max(Dlist * list){
    if (list == NULL) {
        return 0;
    }

    if (list->count == 0) {
        return 0;
    }

    return double_linked_list_find_max_recursive(list->first);  
}
