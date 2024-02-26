#pragma once

typedef struct SkipList SkipList;
typedef struct snode* link;

struct snode {
    int key;
    int value;
    link *forward;
};


SkipList* SkipListInit();
int SkipListInsert(SkipList *list, int key, int value);
link SkipListSearch(SkipList *list, int key);
int SkipListDelete(SkipList *list, int key);
void SkipListDisplay(SkipList* list) ;
void SkipListDump(SkipList *list);

SkipList* SkipListMerge(SkipList* list1, SkipList* list2);