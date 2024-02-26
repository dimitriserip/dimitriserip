#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "symbol_table.h"

typedef struct STnode {
    Item item;
    struct STnode* l;
    struct STnode* r;
    int N;
} STnode;

struct SymbolTable {
    STnode* head;
};

static STnode* z = NULL;

STnode* NEW(Item item, STnode* l, STnode* r, int N);
Item searchR(STnode* h, Key v);
STnode* insertR(STnode* h, Item item);
void sortR(STnode* h, void (*visit)(Item));
STnode* rotR(STnode* h);
STnode* rotL(STnode* h);
Item selectR(STnode* h, int k);
STnode* joinLR(STnode* a, STnode* b);
STnode* deleteR(STnode* h, Key v);

STnode* NEW(Item item, STnode* l, STnode* r, int N) {
    STnode* x = malloc(sizeof *x);
    x->item = item;
    x->l = l;
    x->r = r;
    x->N = N;
    return x;
}
//------------------------------------
//          Implementation
//------------------------------------

SymbolTable* STinit() {
    SymbolTable* table = malloc(sizeof(SymbolTable));

    if (z == NULL) {
        z = NEW(NULLitem, NULL, NULL, 0);
    }

    table->head = z;

    return table;
}

int STcount(SymbolTable* table) {
    if (table != NULL) {
        return table->head->N;
    } else {
        return 0;
    }
}

void STinsert(SymbolTable* table, Item item) {
    if (table == NULL) {
        return;
    }

    table->head = insertR(table->head, item);
}

Item STsearch(SymbolTable* table, Key v) {
    return searchR(table->head, v);
}

void fixN(STnode* h) {
    if (h == NULL || h == z) {
        return;
    }

    if (h->l == z && h->r == z) {
        h->N = 1;
        return;
    }

    if (h->l != z) {
        fixN(h->l);
    }
    if (h->r != z) {
        fixN(h->r);
    }

    h->N = h->l->N + h->r->N + 1;
}

void traverseFixN(STnode* h) {
    if (h == z) {
        return;
    }

    traverseFixN(h->l);
    traverseFixN(h->r);
    fixN(h);
}

void STdelete(SymbolTable* table, Key v) {
    table->head = deleteR(table->head, v);

    // fix N
    traverseFixN(table->head);
}

void STdeleteAll(SymbolTable* table, Item) {
    // TODO
}

Item STselect(SymbolTable* table, int k) {
    return selectR(table->head, k);
}

void STsort(SymbolTable* table, void (*visit)(Item)) {
    sortR(table->head, visit);
}

//------------------------------------
//               Helpers
//------------------------------------

Item searchR(STnode* h, Key v) {
    Key t = key(h->item);
    if (h == z)
        return NULLitem;
    if eq (v, t)
        return h->item;
    if less (v, t)
        return searchR(h->l, v);
    else
        return searchR(h->r, v);
}

STnode* insertR(STnode* h, Item item) {
    Key v = key(item), t = key(h->item);

    if (h == z) {
        return NEW(item, z, z, 1);
    }

    if less (v, t) {
        h->N++;
        h->l = insertR(h->l, item);
    } else {
        h->N++;
        h->r = insertR(h->r, item);
    }
    return h;
}

void sortR(STnode* h, void (*visit)(Item)) {
    if (h == z) {
        return;
    }

    sortR(h->l, visit);
    visit(h->item);
    sortR(h->r, visit);
}

STnode* partR(STnode* h, int k);

/* code for rotations */

STnode* rotR(STnode* h) {
    STnode* x = h->l;
    h->l = x->r;
    x->r = h;

    return x;
}

STnode* rotL(STnode* h) {
    STnode* x = h->r;
    h->r = x->l;
    x->l = h;

    return x;
}

Item selectR(STnode* h, int k) {
    int t = h->l->N;
    if (h == z)
        return NULLitem;
    if (t > k)
        return selectR(h->l, k);
    if (t < k)
        return selectR(h->r, k - t - 1);
    return h->item;
}

STnode* partR(STnode* h, int k) {
    int t = h->l->N;

    if (t > k) {
        h->l = partR(h->l, k);
        h = rotR(h);
    }
    if (t < k) {
        h->r = partR(h->r, k - t - 1);
        h = rotL(h);
    }

    return h;
}

/* code for deleting a key from a BST */

STnode* joinLR(STnode* a, STnode* b) {
    if (b == z)
        return a;

    b = partR(b, 0);
    b->l = a;
    return b;
}

STnode* deleteR(STnode* h, Key v) {
    STnode* x;
    Key t = key(h->item);

    if (h == z) {
        return z;
    }

    if (less(v, t)) {
        h->l = deleteR(h->l, v);
    }

    if (less(t, v)) {
        h->r = deleteR(h->r, v);
    }

    if (eq(v, t)) {
        x = h;
        h = joinLR(h->l, h->r);
        free(x);
    }
    return h;
}

int count_how_many_times_a_number_appears(STnode* root, int num) {
    if (root == NULL) {
        return 0;
    }
    if (root->item == num) {
        return 1 + count_how_many_times_a_number_appears(root->l, num) + count_how_many_times_a_number_appears(root->r, num);
    } else if (root->item > num) {
        return count_how_many_times_a_number_appears(root->l, num);
    } else {
        return count_how_many_times_a_number_appears(root->r, num);
    }
}
/* code for the main program */
