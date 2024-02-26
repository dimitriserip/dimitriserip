#pragma once

#include "item.h"

#define key(I) (I.am)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))

#define less_key(A, B) ((A) < (B))
#define eq_key(A, B) (!less_key(A, B) && !less_key(B, A))

#define is_null(I) (I.am == -1)
typedef struct SymbolTable SymbolTable;
typedef int Key;

//
// Interface
//
SymbolTable* STinit();
int STcount(SymbolTable* table);
void STinsert(SymbolTable* table, Item);
Item STsearch(SymbolTable* table, Key);
void STdelete(SymbolTable* table, Key);
void STdeleteAll(SymbolTable* table, Key);
Item STselect(SymbolTable* table, Key);
void STsort(SymbolTable* table, void (*visit)(Item));
