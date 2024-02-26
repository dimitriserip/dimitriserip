#include <stdlib.h>
#include <string.h>
#include "acutest/acutest.h"
#include "evaluation_module/stack.h"
#include "evaluation_module/evaluation.h"

void test_stack() {
     int n = 1000;
     int x[1000];

     StackInitialize(n);
     
     srand(100);

     for (int i=0;i<n;i++) {
        x[i] = rand()%100;
        StackPush(x[i]);
     }

     for (int i=0;i<n;i++) {
        int value = StackPop();

        TEST_ASSERT(value == x[n-1-i]);
     }

     StackDestroy();
}

// void test_infix_to_postfix() { 
//    char * e = "(1+3)";

//    printInfixToPostfix(e);     
// }

void test_infix_to_postfix_with_return() { 
   char * e = "(1+3)";
   char * postfix = convertInfixToPostfix(e);

   TEST_ASSERT(strcmp(postfix, "13+") == 0);

   free(postfix);
}

void test_infix_evaluation_1() { 
   char * e = "(1+3)";
   char * postfix = convertInfixToPostfix(e);

   int value = evaluate(postfix);

   TEST_ASSERT(value == 4);
}

void test_infix_evaluation_2() { 
   char * e = "(9 + (5 + 3))";
   char * postfix = convertInfixToPostfix(e);

   int value = evaluate(postfix);

   TEST_ASSERT(value == 17);
}

TEST_LIST = {
    {"test_stack", test_stack},
   //  {"test_infix_to_postfix", test_infix_to_postfix},
    {"test_infix_to_postfix_with_return", test_infix_to_postfix_with_return},
    {"test_infix_evaluation_1", test_infix_evaluation_1},
    {"test_infix_evaluation_2", test_infix_evaluation_2},
    {NULL, NULL} /* zeroed record marking the end of the list */
};
