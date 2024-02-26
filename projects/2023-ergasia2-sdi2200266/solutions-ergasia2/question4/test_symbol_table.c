#include "acutest/acutest.h"
#include "symbol_table.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void test_symbol_table_create() {
    int data[1000];
    SymbolTable* table = STinit();

    for (int i = 0; i < 1000; i++) {
        data[i] = rand();
    }

    TEST_ASSERT(STcount(table) == 0);

    for (int i = 0; i < 1000; i++) {
        STinsert(table, data[i]);
    }

    TEST_ASSERT(STcount(table) == 1000);
}

void test_symbol_table_search() {
    int data[1000];
    SymbolTable* table = STinit();

    for (int i = 0; i < 1000; i++) {
        data[i] = rand();
    }

    TEST_ASSERT(STcount(table) == 0);

    for (int i = 0; i < 1000; i++) {
        STinsert(table, data[i]);
    }

    TEST_ASSERT(STcount(table) == 1000);

    for (int i = 0; i < 1000; i++) {
        Item a = STsearch(table, data[i]);
        TEST_ASSERT(a == data[i]);
    }
}

void test_symbol_table_delete_all() {
    SymbolTable* table = STinit();
    int data[10] = {5, 7, 3, 8, 4, 4, 4, 5, 1, 2};

    for (int i = 0; i < 10; i++) {
        STinsert(table, data[i]);
    }

    printf("Before delete: \n");

    STsort(table, ITEMshow);

    printf("\n");

    TEST_ASSERT(STcount(table) == 10);

    printf("After delete: \n");

    STdeleteAll(table, 4);

    STsort(table, ITEMshow);

    printf("\n");

    TEST_ASSERT(STcount(table) == 7);
}

TEST_LIST = {
    {"test_symbol_table_create", test_symbol_table_create},
    {"test_symbol_table_search", test_symbol_table_search},
    {"test_symbol_table_delete_all", test_symbol_table_delete_all},
    {NULL, NULL} /* zeroed record marking the end of the list */
};