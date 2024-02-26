
#include "nfl.h"


int find_nfl(int nrid, int * dests) {
    int nfl = 0;
    
    for (int i=0;i<nrid;i++) {
        if (dests[i] > nfl) {
            nfl = dests[i];
        }
    }
    
    return nfl;
}
