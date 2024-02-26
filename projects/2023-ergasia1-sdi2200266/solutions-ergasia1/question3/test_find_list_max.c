#include <stdlib.h>
#include <limits.h>
#include "double_linked_list.h"
#include "acutest/acutest.h"

void test_find_list_max(){
        Dlist * list = double_linked_list_create();

        srand(100);

        int x[100];
        int max = -1;

        for (int i=0;i<100;i++) {
                x[i] = rand();
                if (x[i] > max) {
                        x[i] = max;
                }

                double_linked_list_add_last(list, x[i]);
                
        }

        TEST_CHECK( double_linked_list_find_max(list) == max);

        double_linked_list_destroy(list); 
}

TEST_LIST = {
        { "test_find_list_max", test_find_list_max  },
        { NULL, NULL } /* zeroed record marking the end of the list */
};
