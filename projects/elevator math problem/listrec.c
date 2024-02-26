

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "solve.h"

#include "fw.h"
#include "nfl.h"

int M(int i, int j, const int nrid, const int * dests) {
    if (i == 0) {
        return fw(0, INT_MAX, nrid, dests);
    } else {
        int min = -1;
//        int min_k = -1;

        for (int k = 0; k <= j; k++) {
            int t0 = M(i - 1, k, nrid, dests);
            int t1 = fw(k, INT_MAX, nrid, dests);
            int t2 = fw(k, j, nrid, dests);
            int t3 = fw(j, INT_MAX, nrid, dests);
            int cost = t0 - t1 + t2 + t3;
            if (min == -1 || cost < min) {
                min = cost;
//                min_k = k;
            }
        }

        if (min == -1) {
            exit(1);
        }
        //        data[i-1] = min_k;
        return min;
    }
}

int solve(int nrid, int nst, int * dests) {
    int nfl = find_nfl(nrid, dests);

    printf("nfl = %d \n", nfl);

    int min = -1;

    for (int k = 0; k <= nfl; k++) {
        int cost = M(nst, k, nrid, dests);
        if (min == -1 || cost < min) {
            min = cost;
        }
    }

    int cost = min;

    //    printf("Last floor: %d \n", min_k);
    //    
    //    for (int i=0;i<nst;i++) {
    //        printf("Stop %d : %d \n", i, data[i]);
    //    }
    //    

    printf("----------------\n");
    printf("      Results\n");
    printf("----------------\n");

    printf("nrid: %d \n", nrid);
    printf("nst : %d \n", nst);
    printf("plan: ");

    for (int i = 0; i < nrid; i++) {
        printf("%3d ", dests[i]);
    }
    printf("\n");

    return min;
}
