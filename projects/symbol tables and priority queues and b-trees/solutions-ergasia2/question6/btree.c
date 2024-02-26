#include <stdio.h>
#include <stdlib.h>

#include "btree.h"
#include "item.h"

#define M 4

typedef struct t24* link;

struct t24 {
    Tree24* parent;
    Item items[3];
    Tree24* children[4];
    //    entry b[M];
    int count;
    //    int N[4];
};

link split(link h);

static link head;
static int H, N;

link NEW() {
    link x = malloc(sizeof *x);
    x->parent = NULL;
    x->count = 0;
    return x;
}

void init(int maxN) {
    head = NEW();
    H = 0;
    N = 0;
}

int count() {
    return N;
}

Item searchR(link h, Key v, int H) {
    if (h == NULL) {
        return NULLitem;
    }
    for (int j = 0; j < h->count; j++) {
        if (eq(v, key(h->items[j]))) {
            return h->items[j];
        } else {
            if ((j + 1 == h->count) || less(v, key(h->items[j + 1]))) {
                return searchR(h->children[j], v, H - 1);
            }
        }
    }

    return NULLitem;
}

Item search(Key v) {
    return searchR(head, v, H);
}

link insertR(link h, Item item, int H) {
    int i, j;
    Key v = key(item);
    link u;
    Key key = v;
    Item current = item;

    for (j = 0; j < h->count; j++) {
        if (less(v, key(h->items[j]))) {
            break;
        }
    }

    for (j = 0; j < h->count; j++) {
        if ((j + 1 == h->count) || less(v, key(h->items[j + 1]))) {
            u = insertR(h->children[j++], item, H - 1);

            if (u == NULL) {
                return NULL;
            }

            key = key(u->items[0]);
            break;
        }
    }

    for (i = (h->count)++; i > j; i--) {
        h->items[i] = h->items[i - 1];
    }

    h->items[j] = current;

    if (h->count < M)
        return NULL;
    else
        return split(h);
}

void insert(Item item) {
    link t, u = insertR(head, item, H);
    N++;

    if (u == NULL) {
        return;
    }
    t = NEW();
    t->count = 2;
    t->items[0] = head->items[0];
    t->children[0] = head;
    t->items[1] = u->items[0];
    t->children[1] = u;

    head = t;
    H++;
}

link split(link h) {
    int j;
    link t = NEW();
    for (j = 0; j < M / 2; j++) {
        t->items[j] = h->items[M / 2 + j];
    }
    t->children[j] = h->children[M / 2 + j];
    h->count = M / 2;
    t->count = M / 2;

    return t;
}

void delete(Item x) {
    // unsupported
    printf("delete not supported \n");
    exit(1);
}

Item bselect(int) {
    printf("select not supported \n");
    exit(1);
}

void sortR(link h, void (*visit)(Item)) {
    //    if (h != NULL) {
    //        for (int j = 0; j < h->count - 1; j++) {
    //            // sortR(h->b[j].ref.next, visit);
    //            visit(h->b[j].ref.item);
    //        }
    //    }
}

void sort(void (*visit)(Item)) {
    //    if (N == 0) {
    //        printf("Tree is empty \n");
    //        return;
    //    }
    //
    //    sortR(head, visit);
}