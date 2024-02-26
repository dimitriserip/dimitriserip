/* This code is from Chapter 4 of the book "Algorithms in C" by Robert Sedgewick. */

#include <stdlib.h>
#include "stack.h"

static Item *s;
static int N;

void StackInitialize(int maxN) {
  s = malloc(maxN * sizeof(Item));
  N = 0;
}

int StackEmpty() {
  return N == 0;
}

void StackPush(Item item) {
  s[N++] = item;
}

Item StackPop() {
  return s[--N];
}

void StackDestroy() {
  free(s);
  N = 0;
  s = NULL;
}