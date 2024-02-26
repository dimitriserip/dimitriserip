
#include <stdlib.h>
#include <limits.h>

#include "fw.h"


int fw(int a, int b, const int nrid, const int * dests) {
    int cost = 0;
    
    for (int i=0;i<nrid;i++) {
        int d = dests[i];
        
        if (d > a && d <= b) {
            int x = abs(d-a);
            int y = abs(d-b);        
            
            if (b == INT_MAX || x < y) {
                cost = cost + x;
            } else {
                cost = cost + y;
            }
        }        
    }
    
    return cost;
}
