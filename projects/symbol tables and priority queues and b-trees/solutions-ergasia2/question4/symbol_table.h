#pragma once

#define NULLitem -1 /* NULLitem is a constant */

#include "item.h"

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))

typedef struct SymbolTable SymbolTable;
typedef int Key;

//
// Interface
//
SymbolTable* STinit();
int STcount(SymbolTable* table);
void STinsert(SymbolTable* table, Item);
Item STsearch(SymbolTable* table, Key);
void STdelete(SymbolTable* table, Item);
void STdeleteAll(SymbolTable* table, Item);
Item STselect(SymbolTable* table, int);
void STsort(SymbolTable* table, void (*visit)(Item));
