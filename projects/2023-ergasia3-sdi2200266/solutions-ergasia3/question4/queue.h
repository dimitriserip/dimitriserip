#pragma once

#include <stdbool.h>

typedef struct dlist Queue;

Queue * queue_create();
void queue_destroy(Queue * queue);

void queue_enqueue(Queue* queue, void * value);
void * queue_dequeue(Queue* queue);

bool queue_is_empty(Queue * queue);
