#pragma once

#include "item.h"
#define NULLitem -1

typedef struct t24 Tree24;
typedef int Key;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))

void init();
int count();
void insert(Item);
Item search(Key);
void delete(Item);
Item bselect(int);
void sort(void (*visit)(Item));