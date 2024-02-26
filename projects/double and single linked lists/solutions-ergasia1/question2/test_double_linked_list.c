#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#include "acutest/acutest.h"
#include "double_linked_list.h"

void test_double_linked_list_create(){
    Dlist * list = double_linked_list_create();

    TEST_CHECK( double_linked_list_get_first_node(list) == NULL );
    TEST_CHECK( double_linked_list_get_last_node(list) == NULL );
    TEST_CHECK( double_linked_list_size(list) == 0 );

    double_linked_list_destroy(list);
}

void test_double_linked_list_empty() {
    Dlist * list = double_linked_list_create();

    TEST_CHECK( double_linked_list_is_empty(list) == 1 );

    for (int i=0;i<10;i++) {
        double_linked_list_add_first(list, i);
    }

    TEST_CHECK( double_linked_list_is_empty(list) == 0 );

    double_linked_list_destroy(list);
}

void test_double_linked_list_size() {
    Dlist * list = double_linked_list_create();

    for (int i=0;i<10;i++) {
        double_linked_list_add_first(list, i);
        TEST_CHECK( double_linked_list_size(list) == 1+i );
    }

    double_linked_list_destroy(list);
}

void test_double_linked_list_get_first(){
    Dlist * list  = double_linked_list_create();

    double_linked_list_add_first(list,10);

    TEST_CHECK( double_linked_list_get_first(list) == 10 );

    double_linked_list_destroy(list);
}

void test_double_linked_list_get_last(){
    Dlist * list  = double_linked_list_create();

    double_linked_list_add_last(list,10);

    TEST_CHECK( double_linked_list_get_last(list) == 10 );

    double_linked_list_destroy(list);

}

void test_double_linked_list_get_node(){
    Dlist * list  = double_linked_list_create();

    int x[100];

    srand(100);

    for (int i=0;i<100;i++) {
        x[i] = rand();
    }

    for (int i=0;i<100;i++) {
        if (i% 2 == 0) {
            double_linked_list_add_first(list,x[i]);
        } else {
            double_linked_list_add_last(list,x[i]);
        }
    }

    for (int i=0;i<100;i++) {
        DNode * current = double_linked_list_get_node(list, x[i]);
        int data = double_linked_list_get_value(current);

        TEST_CHECK( data == x[i] );
    }

    double_linked_list_destroy(list);
}

void test_double_linked_list_get_prev(){
    Dlist * list  = double_linked_list_create();

    double_linked_list_add_first(list,10);
    double_linked_list_add_first(list,20);

    DNode * current = double_linked_list_get_node(list, 10);
    DNode * previous = double_linked_list_get_prev(current);

    int data = double_linked_list_get_value(previous);
      
    TEST_CHECK( data == 20 );

    double_linked_list_destroy(list);

}

void test_double_linked_list_get_next(){
    Dlist * list  = double_linked_list_create();
    double_linked_list_add_first(list,10);
    double_linked_list_add_first(list,20);


    DNode * current = double_linked_list_get_next(double_linked_list_get_node(list, 20));
    int data = double_linked_list_get_value(current);
      
    TEST_CHECK( data == 10 );

    double_linked_list_destroy(list);

}

void test_double_linked_list_add_before(){
    Dlist * list  = double_linked_list_create();
    double_linked_list_add_first(list,10);
    double_linked_list_add_first(list,20);
    double_linked_list_add_before(list,double_linked_list_get_node(list,20),30);

    TEST_CHECK (double_linked_list_get_first(list) == 30);

    double_linked_list_destroy(list);
}

void test_double_linked_list_add_after() {
    Dlist * list  = double_linked_list_create();
    double_linked_list_add_first(list,10);
    double_linked_list_add_first(list,20);
    double_linked_list_add_after(list,double_linked_list_get_node(list,20),30);

    TEST_CHECK(double_linked_list_get_last(list)== 10);

    double_linked_list_destroy(list);
}

void test_double_linked_list_add_first(){
    Dlist * list  = double_linked_list_create();
    double_linked_list_add_first(list,10);

    TEST_CHECK( double_linked_list_get_first(list) == 10 );


    double_linked_list_destroy(list);
}

void test_double_linked_list_add_last(){
    Dlist * list  = double_linked_list_create();
    double_linked_list_add_first(list,20);
    double_linked_list_add_first(list,30);
    double_linked_list_add_first(list,40);
    double_linked_list_add_first(list,10);

    TEST_CHECK( double_linked_list_get_last(list) == 20 );

    double_linked_list_destroy(list);
}

void test_double_linked_list_remove(){

}
//?????????????????????????????????
void test_double_linked_list_print(){
    Dlist * list  = double_linked_list_create();
    test_double_linked_list_add_first(list,20);

    

    double_linked_list_destroy(list);
}

// void test_stack_push_peek(void){
//     Stack *s = stack_init();

//     s = stack_push(s,2);

//     TEST_CHECK( stack_size(s) == 1  && stack_peek(s) == 2);

//     s = stack_push(s,4);
//     s = stack_push(s,6);
//     s = stack_push(s,8);

//     TEST_CHECK( stack_size(s) == 4 && stack_peek(s) == 8);

//     stack_destroy(s);
// }

// void test_stack_pop(void){
//     Stack *s = stack_init();

//     s = stack_push(s,2);
//     s = stack_push(s,4);
//     s = stack_push(s,6);
//     s = stack_push(s,8);

//     int elem = stack_pop(s);
//     TEST_CHECK( stack_size(s) == 3 && elem == 8);
//     elem = stack_pop(s);
//     TEST_CHECK( stack_size(s) == 2 && elem == 6);
//     elem = stack_pop(s);
//     TEST_CHECK( stack_size(s) == 1 && elem == 4);
//     elem = stack_pop(s);
//     TEST_CHECK( stack_size(s) == 0 && elem == 2);
//     elem = stack_pop(s);
//     TEST_CHECK( stack_size(s) == 0 && elem == INT_MIN);

//     stack_destroy(s);
// }

// void test_stack_merge(void){
//     Stack *s1 = stack_init();
//     s1 = stack_push(s1,1);
//     s1 = stack_push(s1,2);
//     s1 = stack_push(s1,3);

//     Stack *s2 = stack_init();
//     s2 = stack_push(s2,4);
//     s2 = stack_push(s2,5);
//     s2 = stack_push(s2,6);

//     Stack *s = stack_merge(s1,s2);

//     int elem = stack_pop(s);
//     TEST_CHECK( stack_size(s) == 5 && elem == 6);
//     elem = stack_pop(s);
//     TEST_CHECK( stack_size(s) == 4 && elem == 5);
//     elem = stack_pop(s);
//     TEST_CHECK( stack_size(s) == 3 && elem == 4);
//     elem = stack_pop(s);
//     TEST_CHECK( stack_size(s) == 2 && elem == 3);
//     elem = stack_pop(s);
//     TEST_CHECK( stack_size(s) == 1 && elem == 2);
//     elem = stack_pop(s);
//     TEST_CHECK( stack_size(s) == 0 && elem == 1);

//     stack_destroy(s);
// }

TEST_LIST = {
        { "test_double_linked_list_create", test_double_linked_list_create  },
        { "test_double_linked_list_empty", test_double_linked_list_empty  },
        { "test_double_linked_list_size", test_double_linked_list_size  },
        { "test_double_linked_list_get_first", test_double_linked_list_get_first  },
        { "test_double_linked_list_get_last", test_double_linked_list_get_last  },
        { "test_double_linked_list_get_node", test_double_linked_list_get_node  },
        { "test_double_linked_list_get_prev", test_double_linked_list_get_prev  },
        { "test_double_linked_list_get_next", test_double_linked_list_get_next  },
        { "test_double_linked_list_add_before", test_double_linked_list_add_before  },
        { "test_double_linked_list_add_after", test_double_linked_list_add_after  },
        { "test_double_linked_list_add_first", test_double_linked_list_add_first  },
        { "test_double_linked_list_add_last", test_double_linked_list_add_last  },
        { "test_double_linked_list_remove", test_double_linked_list_remove  },
        { "test_double_linked_list_print", test_double_linked_list_print  },
        { NULL, NULL } /* zeroed record marking the end of the list */
};
