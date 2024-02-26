#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "symbol_table.h"

int main(int argc, char* argv[]) {
    int maxN = 1000;
    Item item;
    SymbolTable* table = STinit();
    Item data[1000];

    int x = STcount(table);

    printf("Total entries (before insert): %d \n", x);

    for (int N = 0; N < maxN; N++) {
        Item student = ITEMrand();

        data[N] = student;

        Item result = STsearch(table, key(student));

        // if (!is_null(result)) {
        //     continue;
        // }

        printf("Inserting student with values: %d %s %s, items in structure: %d \n", student.am, student.firstname, student.lastname, STcount(table));

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
        Item result = STsearch(table, key(data[N]));

        if (is_null(result)) {
            printf("[ERROR] something went wrong, item at %d %s %s was not foound \n", data[N].am, data[N].firstname, data[N].lastname);
            exit(1);
        }
    }

    Item a = STselect(table, 0);

    for (int N = 1; N < maxN; N++) {
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

    for (int N = 0; N < maxN; N++) {
        Item item = data[N];

        int d1 = STcount(table);

        printf("Deleting %d of %d: %d %s %s \n", N + 1, maxN, item.am, item.firstname, item.lastname);

        STdelete(table, key(item));

        int d2 = STcount(table);

        if (d2 != d1 - 1) {
            printf("[ERROR] something went wrong, delete item %d %s %s failed \n", item.am, item.firstname, item.lastname);
            printf("Before deletion: count: %d \n", d1);
            printf("After  deletion: count: %d \n", d2);
            exit(1);
        }
    }

    int y = STcount(table);

    printf("Total entries (after insert): %d \n", y);

    printf("%d keys\n", maxN);
    printf("%d distinct keys\n", STcount(table));

    return 0;
}
