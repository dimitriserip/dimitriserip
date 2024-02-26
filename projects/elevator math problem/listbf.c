

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "solve.h"

#include "fw.h"
#include "nfl.h"

static int * best_stops = NULL;
static int best_nst = 0;
static int best_cost = INT_MAX;

static int brute_force_cost(int nst, int * stops, const int nrid, const int * dests ) {
    int result = 0;
    
    for (int i=0;i<nrid;i++) {
        int min_distance = INT_MAX;
        
        for (int j=0;j<nst;j++) {
            int distance = abs(dests[i] - stops[j]);
            if (distance < min_distance) {
                min_distance = distance;
            }
        }
        
        if (dests[i] < min_distance) {
            min_distance = dests[i];
        }
        
        result = result + min_distance;
    }
    
    return result;
}


static void fill_array(int index, int nst, int * stops, const int nfl, const int nrid, const int * dests) {
    if (index == nst) {
        int cost = brute_force_cost(nst, stops, nrid, dests);
        
        if (cost < best_cost) {
            best_cost = cost;
            best_nst = nst;
            memcpy(best_stops, stops, sizeof(int)*nst);
        }
    } else {
        int start_from;
        
        if (index == 0) {
            start_from = 0;
        } else {
            start_from = stops[index-1];
        }
        
        for (int i=start_from;i<=nfl;i++) {
            
            stops[index] = i;
            
            bool skip =false;
            
            for (int ii=0;ii<index;ii++) {
                if (stops[ii] == stops[index]){
                    skip = true;
                    break;
                }               
            }
            
            if (skip) {
                continue;
            }

            fill_array(index+1, nst, stops, nfl, nrid, dests);
        }
    }        
}


static int M(int nst, const int nfl, const int nrid, const int * dests) {
    int * stops = malloc(sizeof(int)*nfl);    
    
    for (int i=0;i<nfl;i++) {
        stops[i] = -1;
    }

    fill_array(0, nst, stops, nfl, nrid, dests);
       
    free(stops);
        
    return 0;
}

int solve(int nrid, int nst, int * dests) {
    int nfl = find_nfl(nrid, dests);
    
    printf("nfl = %d \n", nfl);
        
    best_nst = 0;
    best_cost = INT_MAX;
    
    best_stops = malloc(sizeof(int)*nst);
    
    for (int k = 0; k <= nst; k++) {
        M(k, nfl, nrid, dests);        
    }

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
    
    
    printf("stops: ");

    for (int i = 0; i < best_nst; i++) {
        printf("%3d ", best_stops[i]);
    }
    printf("\n");
    
    if (best_stops != NULL) {
        free(best_stops);
    }
    

    return best_cost;
}
