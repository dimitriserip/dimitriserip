/* This code is from Chapter 4 of the book "Algorithms in C" by Robert Sedgewick. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evaluation_module/stack.h"
#include "evaluation_module/evaluation.h"

int main(int argc, char *argv[]) {    
    char * e[] = { "(1+4)", "(9 + (5 + 3))", "(5 * 2)", "(5*2)", "(5-2)", "(5 + (3 - 2))"};
    int N = sizeof(e)/sizeof(char*);

    for (int i=0;i<N;i++) {
        char * postfix = convertInfixToPostfix(e[i]);

        printf("[%d] Infix   is: %s \n", i+1, e[i]);
        printf("[%d] Postfix is: %s \n", i+1, postfix);
        printf("[%d] Value   is: %d \n", i+1, evaluate(postfix));

        free(postfix);

        printf("\n'");
    }

    return 0;
}
