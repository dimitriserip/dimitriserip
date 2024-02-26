
#include <stdio.h>
#include <stdlib.h>

#include "solve.h"

int main(int argc, char** argv) {
    int nrid = 20;
    int nst = 4;
    int data[] = {8, 32, 14, 14, 6, 7, 25, 43, 12, 9, 1, 28, 27, 25, 33, 38, 42, 27, 14, 44};
    

    //    printf("Type the number of people: ");
    //    scanf("%d", &nrid);
    //
    //    printf("Type the number of stops: ");
    //    scanf("%d", &nst);
    //
    //    dests = malloc(sizeof (int)*nrid);
    //    
    //    for (int i=0;i<nrid;i++) {
    //        printf("Type the floor of person %d: ", i+1);
    //        scanf("%d", &dests[i]);
    //    }

    int cost = solve(nrid, nst, data);

    printf("Cost is: %d \n", cost);

//    free(dests);

    return 0;
}

