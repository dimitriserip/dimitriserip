#pragma once

typedef struct dnode DNode;
typedef struct dlist Dlist;


Dlist * double_linked_list_create();
void double_linked_list_destroy(Dlist * list);

DNode* double_linked_list_get_first_node(Dlist * list);
DNode* double_linked_list_get_last_node(Dlist * list);
int double_linked_list_get_value(DNode * node);

int double_linked_list_size(Dlist * list);
int double_linked_list_is_empty(Dlist * list);
int double_linked_list_get_first(Dlist * list);
int double_linked_list_get_last(Dlist * list);

DNode * double_linked_list_get_node(Dlist * list, int value);
DNode * double_linked_list_get_prev(DNode * node);
DNode * double_linked_list_get_next(DNode * node);

void double_linked_list_add_before(Dlist * list, DNode * node, int value);
void double_linked_list_add_after(Dlist * list, DNode * node, int value);
void double_linked_list_add_first(Dlist * list, int value);
void double_linked_list_add_last(Dlist * list, int value);
void double_linked_list_remove(Dlist * list, int value);
void double_linked_list_print(Dlist * list);





