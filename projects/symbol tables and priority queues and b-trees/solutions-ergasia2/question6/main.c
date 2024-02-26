#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "btree.h"
#include "item.h"

int main(int argc, char* argv[]) {
    int maxN = 20;
    Item item;

    Key data[1000];

    init();

    int x = count();

    printf("Total entries (before insert): %d \n", x);

    for (int N = 0; N < maxN; N++) {
        Key value = ITEMrand() % 1000;

        data[N] = value;

        if (search(value) != NULLitem) {
            continue;
        }

        printf("Inserting item with value: %d, items in structure: %d \n", value, count());

        item = value;

        insert(item);

        int n1 = count();

        if (n1 != N + 1) {
            printf("Insert failed: %d != %d \n", n1, N + 1);
            return 1;
        }
    }

    printf("Insert complete . \n");

    printf("Printing ... \n");

    sort(ITEMshow);
    printf("\n");

    for (int N = 0; N < maxN; N++) {
        Item item = search(data[N]);

        if (item == NULLitem) {
            printf("[ERROR] something went wrong, item with value %d was not found \n", item);
            exit(1);
        }
    }

    Item a = bselect(0);

    for (int N = 1; N < maxN; N++) {
        Item b = bselect(N);

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

        int d1 = count();

        printf("Deleting %d of %d: %d \n", N + 1, maxN, item);

        delete (item);

        int d2 = count();

        if (d2 != d1 - 1) {
            printf("[ERROR] something went wrong, delete item %d failed \n", item);
            printf("Before deletion: count: %d \n", d1);
            printf("After  deletion: count: %d \n", d2);
            exit(1);
        }
    }

    int y = count();

    printf("Total entries (after insert): %d \n", y);

    printf("%d keys\n", maxN);
    printf("%d distinct keys\n", count());

    return 0;
}
