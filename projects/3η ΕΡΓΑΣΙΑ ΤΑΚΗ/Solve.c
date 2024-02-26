
#include <stdio.h>
#include <stdlib.h>

#include "solve.h"

void test1() {
    int nrid = 5;
    int nst = 2;
    int data[] = {11, 2, 7, 13, 7};
    int correct = 4;

    int cost = solve(nrid, nst, data);

    if (cost != correct) {
        printf("%%TEST_FAILED%% time=0 testname=test1 (Solve) message=error message sample\n");

        printf("WRONG RESULT: %d \n", cost);
    } else {
        printf("CORRECT RESULT: %d \n", cost);
    }
}

void test2() {
    int nrid = 7;
    int nst = 3;
    int data[] = {8, 10, 3, 8, 12, 6, 5};
    int correct = 5;

    int cost = solve(nrid, nst, data);

    if (cost != correct) {
        printf("%%TEST_FAILED%% time=0 testname=test2 (Solve) message=error message sample\n");

        printf("WRONG RESULT: %d  , correct: %d \n", cost, correct);
    } else {
        printf("CORRECT RESULT: %d \n", cost);
    }
}

void test3() {
    int nrid = 6;
    int nst = 4;
    int data[] = {5, 3, 3, 5, 5, 3};
    int correct = 0;

    int cost = solve(nrid, nst, data);

    if (cost != correct) {
        printf("%%TEST_FAILED%% time=0 testname=test3 (Solve) message=error message sample\n");

        printf("WRONG RESULT: %d  , correct: %d \n", cost, correct);
    } else {
        printf("CORRECT RESULT: %d \n", cost);
    }
}

void test4() {
    int nrid = 5;
    int nst = 0;
    int data[] = {1, 2, 3, 4, 5};
    int correct = 15;

    int cost = solve(nrid, nst, data);

    if (cost != correct) {
        printf("%%TEST_FAILED%% time=0 testname=test4 (Solve) message=error message sample\n");

        printf("WRONG RESULT: %d  , correct: %d \n", cost, correct);
    } else {
        printf("CORRECT RESULT: %d \n", cost);
    }
}

void test5() {
    int nrid = 20;
    int nst = 4;
    int data[] = {8, 32, 14, 14, 6, 7, 25, 43, 12, 9, 1, 28, 27, 25, 33, 38, 42, 27, 14, 44};
    int correct = 30;

    int cost = solve(nrid, nst, data);

    if (cost != correct) {
        printf("%%TEST_FAILED%% time=0 testname=test5 (Solve) message=error message sample\n");

        printf("WRONG RESULT: %d  , correct: %d \n", cost, correct);        
    } else {
        printf("CORRECT RESULT: %d \n", cost);
    }
}

void test6() {
    int nrid = 20;
    int nst = 5;
    int data[] = {8, 32, 14, 14, 6, 7, 25, 43, 12, 9, 1, 28, 27, 25, 33, 38, 42, 27, 14, 44};
    int correct = 20;

    int cost = solve(nrid, nst, data);

    if (cost != correct) {
        printf("%%TEST_FAILED%% time=0 testname=test6 (Solve) message=error message sample\n");

        printf("WRONG RESULT: %d  , correct: %d \n", cost, correct);
    } else {
        printf("CORRECT RESULT: %d \n", cost);
    }
}

void test7() {
    int nrid = 20;
    int nst = 6;
    int data[] = {8, 32, 14, 14, 6, 7, 25, 43, 12, 9, 1, 28, 27, 25, 33, 38, 42, 27, 14, 44};
    int correct = 15;

    int cost = solve(nrid, nst, data);

    if (cost != correct) {
        printf("%%TEST_FAILED%% time=0 testname=test7 (Solve) message=error message sample\n");

        printf("WRONG RESULT: %d  , correct: %d \n", cost, correct);
    } else {
        printf("CORRECT RESULT: %d \n", cost);
    }
}

void test8() {
    int nrid = 25;
    int nst = 7;
    int data[] = {1, 2, 2, 3, 5, 6, 6, 8, 10, 13, 15, 15, 16, 17, 18, 18, 18, 20, 22, 25, 30, 38, 49, 55, 62};
    int correct = 35;

    int cost = solve(nrid, nst, data);

    if (cost != correct) {
        printf("%%TEST_FAILED%% time=0 testname=test8 (Solve) message=error message sample\n");

        printf("WRONG RESULT: %d  , correct: %d \n", cost, correct);
    } else {
        printf("CORRECT RESULT: %d \n", cost);
    }
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% Solve\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (Solve)\n");
    test1();
    printf("%%TEST_FINISHED%% time=0 test1 (Solve) \n");

    printf("%%TEST_STARTED%% test2 (Solve)\n");
    test2();
    printf("%%TEST_FINISHED%% time=0 test2 (Solve) \n");

    printf("%%TEST_STARTED%% test3 (Solve)\n");
    test3();
    printf("%%TEST_FINISHED%% time=0 test3 (Solve) \n");

    printf("%%TEST_STARTED%% test4 (Solve)\n");
    test4();
    printf("%%TEST_FINISHED%% time=0 test4 (Solve) \n");
    
    printf("%%TEST_STARTED%% test5 (Solve)\n");
    test5();
    printf("%%TEST_FINISHED%% time=0 test5 (Solve) \n");
    
    printf("%%TEST_STARTED%% test6 (Solve)\n");
    test6();
    printf("%%TEST_FINISHED%% time=0 test6 (Solve) \n");
    
    printf("%%TEST_STARTED%% test7 (Solve)\n");
    test7();
    printf("%%TEST_FINISHED%% time=0 test7 (Solve) \n");
    
    printf("%%TEST_STARTED%% test8 (Solve)\n");
    test8();
    printf("%%TEST_FINISHED%% time=0 test8 (Solve) \n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
