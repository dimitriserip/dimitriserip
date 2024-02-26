#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "symbol_table.h"

int main(int argc, char* argv[]) {
    int maxN = 1000;
    Item item;
    SymbolTable* table = STinit();
    Key data[1000];

    int x = STcount(table);

    printf("Total entries (before insert): %d \n", x);

    for (int N = 0; N < maxN; N++) {
        Key value = ITEMrand();

        data[N] = value;

        if (STsearch(table, value) != NULLitem) {
            continue;
        }

        key(item) = value;

        printf("Inserting item with value: %d, items in structure: %d \n", value, STcount(table));

        STinsert(table, item);

        if (STcount(table) != N + 1) {
            printf("Insert failed \n");
            return 1;
        }
    }

    STsort(table, ITEMshow);
    printf("\n");

    for (int N = 0; N < maxN; N++) {
        Item item = STsearch(table, data[N]);

        if (item == NULLitem) {
            printf("[ERROR] something went wrong, item at %d was not foound \n", item);
            exit(1);
        }
    }

    Item a = STselect(table, 0);

    for (int N = 1; N < maxN; N++) {
        Item b = STselect(table, N);

        if (b < a) {
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

        printf("Deleting %d of %d: %d \n", N + 1, maxN, item);

        STdelete(table, item);

        int d2 = STcount(table);

        if (d2 != d1 - 1) {
            printf("[ERROR] something went wrong, delete item %d failed \n", item);
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
