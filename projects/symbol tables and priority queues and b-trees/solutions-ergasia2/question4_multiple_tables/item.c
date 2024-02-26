#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item.h"

Item ITEMrand(void) {
    char* names[] = {"Bob", "Tom", "Eva", "Mairy", "Joe", "Alice"};
    char* surnames[] = {"Bob", "Mot", "Ave", "Yriam", "Eoj", "Ecila"};
    int n = rand() % 6;
    int m = rand() % 6;

    Item item;
    item.am = rand() % 10000;
    strcpy(item.firstname, names[n]);
    strcpy(item.lastname, surnames[m]);

    return item;
}

int ITEMscan(Item* x) {
    return scanf("%d %s %s", &(x->am), x->firstname, x->lastname);
}

void ITEMshow(Item x) {
    printf("%5d %s %s \n", x.am, x.firstname, x.lastname);
}
