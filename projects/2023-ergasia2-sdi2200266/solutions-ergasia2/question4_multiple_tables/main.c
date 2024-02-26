#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "symbol_table.h"

int main(int argc, char* argv[]) {
    int maxN = 1000;
    Item item;
    SymbolTable* table1 = STinit();
    SymbolTable* table2 = STinit();
    Item data[1000];
    SymbolTable* table = NULL;

    printf("Total entries (before insert) in first table: %d \n", STcount(table1));
    printf("Total entries (before insert) in second table: %d \n", STcount(table2));

    for (int N = 0, table_id = 0; N < maxN; N++) {
        Item student = ITEMrand();

        data[N] = student;

        if (N % 2 == 0) {
            table = table1;
            table_id = 1;
        } else {
            table = table2;
            table_id = 2;
        }

        Item result = STsearch(table, key(student));

        // if (!is_null(result)) {
        //     continue;
        // }

        printf("Inserting student with values: %d %s %s to table %d, items in structure: %d \n", student.am, student.firstname, student.lastname, table_id, STcount(table));

        int x1 = STcount(table);

        STinsert(table, student);

        int x2 = STcount(table);

        if (x2 != x1 + 1) {
            printf("Insert failed \n");
            return 1;
        }
    }

    STsort(table, ITEMshow);
    printf("\n");

    for (int N = 0; N < maxN; N++) {
        if (N % 2 == 0) {
            table = table1;
        } else {
            table = table2;
        }

        Item result = STsearch(table, key(data[N]));

        if (is_null(result)) {
            printf("[ERROR] something went wrong, item at %d %s %s was not foound \n", data[N].am, data[N].firstname, data[N].lastname);
            exit(1);
        }
    }

    for (int N = 1; N < maxN; N++) {
        if (N % 2 == 0) {
            table = table1;
        } else {
            table = table2;
        }

        Item a = STselect(table, 0);

        if (N >= STcount(table)) {
            continue;
        }
        Item b = STselect(table, N);

        if (key(b) < key(a)) {
            printf("[ERROR} something went wrong with select \n]");
            exit(1);
        } else {
            a = b;
        }
    }

    printf("Select seems ok \n");

    for (int N = 0, table_id = 0; N < maxN; N++) {
        if (N % 2 == 0) {
            table = table1;
            table_id = 1;
        } else {
            table = table2;
            table_id = 2;
        }

        Item item = data[N];

        int d1 = STcount(table);

        printf("Deleting %d of %d from table %d: %d %s %s \n", N + 1, maxN, table_id, item.am, item.firstname, item.lastname);

        STdelete(table, key(item));

        int d2 = STcount(table);

        if (d2 != d1 - 1) {
            printf("[ERROR] something went wrong, delete item %d %s %s failed \n", item.am, item.firstname, item.lastname);
            printf("Before deletion: count: %d \n", d1);
            printf("After  deletion: count: %d \n", d2);
            exit(1);
        }
    }

    printf("Total entries (after insert) in table1: %d \n", STcount(table1));
    printf("Total entries (after insert) in table2: %d \n", STcount(table2));

    printf("%d keys\n", maxN);
    printf("%d distinct keys in table 1\n", STcount(table1));
    printf("%d distinct keys in table 2\n", STcount(table2));

    return 0;
}
