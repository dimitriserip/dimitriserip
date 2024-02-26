#pragma once

typedef struct Item {
    int am;
    char firstname[100];
    char lastname[100];
} Item;

Item ITEMrand();
int ITEMscan(Item*);
void ITEMshow(Item);