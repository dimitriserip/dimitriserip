#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#include "skip_list.h"

#define SKIPLIST_MAX_LEVEL 10

int max(int x, int y) {
    if (x < y) {
        return y;
    } else {
        return x;
    }
}

typedef struct SkipList {
    int level;
    int size;
    link header;
} SkipList;

link createNode(int value, int key, int level) {
    link newNode = (link) malloc(sizeof (struct snode));
    newNode->value = value;
    newNode->key = key;
    newNode->forward = (link*) malloc(sizeof (link) * (level + 1));
    for (int i = 0; i <= level; i++) {
        newNode->forward[i] = NULL;
    }
    return newNode;
}

// Create skip-list

SkipList *SkipListInit() {
    SkipList *list = (SkipList *) malloc(sizeof (SkipList));
    link header = createNode(0, INT_MAX, SKIPLIST_MAX_LEVEL);
    list->header = header;

    list->level = 0;
    list->size = 0;

    return list;
}

// Pick a random level

static int rand_level() {
    int level = 0;
    // We generate a new j-link node with probability 1/2^j
    while (rand() < RAND_MAX / 2 && level < SKIPLIST_MAX_LEVEL)
        level++;
    return level;
}

// Insert a Node into skip-list

int SkipListInsert(SkipList *list, int key, int value) {
    link update[SKIPLIST_MAX_LEVEL + 1];
    link current = list->header;
    int i, level;
    // This is the way we scan through a skip list
    // For each level (descending order)
    for (i = list->level; i >= 0; i--) {
        // We find the closer key which is less than the key we search 
        while (current->forward[i] != NULL && current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }
    current = current->forward[0];

    if (current != NULL && key == current->key) {
        // if the key already exists just replace the value
        current->value = value;

    } else {
        level = rand_level(); // take the random level
        printf("Random level= %d\n", level);
        if (level > list->level) {
            for (i = list->level + 1; i <= level; i++) {
                update[i] = list->header;
            }
            list->level = level;
        }
        current = createNode(value, key, level);
        list->size++;
        for (i = 0; i <= level; i++) {
            current->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = current;
        }
    }
    return 0;
}

// search skip-list

link SkipListSearch(SkipList *list, int key) {
    // printf("Search: %d\n", key);
    link x = list->header;
    int i;
    int steps = 0;
    for (i = list->level; i >= 0; i--) {

        while (x->forward[i] != NULL && x->forward[i]->key <= key) {
            x = x->forward[i];
            steps++;

            if (x != NULL && x->key == key) {
                // printf("Steps: %d\n", steps);
                return x;
            }
        }
        steps++;
    }
    return NULL;
}

static void skiplist_node_free(link x) {
    if (x) {
        free(x->forward);
        free(x);
    }
}

// Delete a node from skip list

int SkipListDelete(SkipList *list, int key) {
    int i;
    link update[SKIPLIST_MAX_LEVEL + 1];
    link x = list->header;
    for (i = list->level; i >= 0; i--) {
        while (x->forward[i] != NULL && x->forward[i]->key < key)
            x = x->forward[i];
        update[i] = x;
    }

    x = x->forward[0];

    if (x != NULL && x->key == key) {
        for (i = 0; i <= list->level; i++) {
            if (update[i]->forward[i] != x)
                break;
            update[i]->forward[i] = x->forward[i];
        }
        skiplist_node_free(x);
        list->size--;
        return 0;
    }
    return 1;
}

void SkipListDump(SkipList *list) {
    link x = list->header;

    while (x && x->forward[0] != NULL) {
        printf("%d[%d]->", x->forward[0]->key, x->forward[0]->value);
        x = x->forward[0];
    }
    printf("NIL\n");
}

// Display the Skip List / Level format

void SkipListDisplay(SkipList* list) {
    printf("Skip List:\n");

    for (int i = 0; i <= list->level; i++) {
        link current = list->header->forward[i];
        printf("Level %d: ", i);
        while (current != NULL) {
            printf("(%d, %d) ", current->key, current->value);
            current = current->forward[i];
        }
        printf("\n");
    }
}

SkipList* SkipListMerge(SkipList* list1, SkipList* list2) {
    link update[SKIPLIST_MAX_LEVEL] = {0};

    bool unflipped = true;

    SkipList * list = SkipListInit();
    list->level = max(list1->level, list2->level);

    for (int i = 0; i <= list->level; i++) {
        update[i] = list->header;
    }

    while (list1->header->forward[0] != NULL && list2->header->forward[0] != NULL) {
        int key1 = list1->header->forward[0]->key;
        int key2 = list2->header->forward[0]->key;

        if (key1 > key2) {
            SkipList* temp = list1;
            list1 = list2;
            list2 = temp;

            int keytemp = key1;
            key1 = key2;
            key2 = keytemp;

            unflipped = !unflipped;
        }

        int lvl = 0;

        do {
            update[lvl]->forward[lvl] = list1->header->forward[lvl];
            lvl++;
        } while (lvl <= list->level && list1->header->forward[lvl] != NULL && list1->header->forward[lvl]->key > key2);

        lvl--;

        link x = list1->header->forward[lvl];

        for (int i = lvl; i >= 0; i--) {
            while (x->forward[i] != NULL && x->forward[i]->key <= key2) {
                x = x->forward[i];
            }

            update[i] = x;

            list1->header->forward[i] = x->forward[i];
        }

        if (key2 == x->key) {
            if (unflipped) {
                x->value = list2->header->forward[0]->value;
            }

            link y = list2->header->forward[0];
            
            for (int i = 0; i <= list->level && y->forward[i] != NULL; i++) {
                list2->header->forward[i] = y->forward[i];
            }
        }
    }

    SkipList * leftOver = NULL;

    if (list2->header->forward[0] == NULL) {
        leftOver = list1;
    } else {
        leftOver = list2;
    }

    for (int i = 0; i <= leftOver->level; i++) {
        update[i]->forward[i] = leftOver->header->forward[i];
    }

    for (int i = leftOver->level + 1; i <= list->level; i++) {
        update[i]->forward[i] = NULL;
    }

    while (list->header->forward[list->level] == NULL && list->level > 0) {
        list->level--;
    }

    return list;
}


