#pragma once

#include <stdbool.h>

#include "PQTypes.h"

PriorityQueuePtr PriorityQueueCreate();
void PriorityQueueDestroy(PriorityQueuePtr queue);

bool PriorityQueueIsEmpty(PriorityQueuePtr queue);
bool PriorityQueueIsFull(PriorityQueuePtr queue);

void PriorityQueueInsert(PQItem, PriorityQueuePtr queue);
PQItem PriorityQueueRemove(PriorityQueuePtr queue);
