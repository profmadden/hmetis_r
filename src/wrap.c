#include <stdio.h>

void HMETIS_PartRecursive();


static int eptr[] = {0, 2, 6, 9, 12};
static int eind[] = {0, 2, 0, 1, 3, 4, 3, 4, 6, 2, 5, 6};
static int vwgts[] = {1, 1, 1, 1, 1, 1, 1};
static int hewgts[] = {1, 1, 1, 1};

// nruns CType OType Vcycle not-used start-with-part randomseed debuglevel
// nruns=zero means default values
// start-with-part=1 means use starting positions
//    if there are starting positions, those with 0 or 1 are fixed,
//    while -1 indicates free-to-move
// Options:
// 0 -- set to 1 for non-default behavior
// 1 -- number of runs
// 2 -- scheme for ctype
// 3 -- scheme for otype
// 4 -- vcycle
// 5 -- not used
// 6 -- not used
// 7 -- random seed
// 8 -- debug flags
static int options[] = {
    1, // Not defaults
    1, // 1 run
    1, // ctype Hybrid First Choice HFC
    1, // Otype minimixe hyperedge cut    
    1, // Vcycle only on the best run
    0, // not used
    0, // not used,
    0, // random seed
    0  // debug
};
static int part[] = {-1, -1, -1, -1, -1, -1, -1};



void hm_hello() {
    printf("Hello, world from the hMetis partitioning wrapper\n");
    int edgecut;
    
    HMETIS_PartRecursive(7, 4, vwgts, eptr, eind, hewgts, 2, 10, options, part, &edgecut);
    
    printf("Partition edge cut %d\n", edgecut);
    for (int i = 0; i < 7; ++i)
    {
        printf("Vertex %d partition %d\n", i, part[i]);
    }
}
  
void hm_partition(unsigned int nvtxs, unsigned int nhedges, int *hewt, int *vtw, int *eind, int *eptr,
    int *part, int kway, int passes, long seed, int imbalance)
{
    // printf("This is the wrapper for the HMETIS call\n");
    int edgecut;
    options[1] = passes;
    options[7] = seed;
    HMETIS_PartRecursive(nvtxs, nhedges, vtw, eptr, eind, hewt, kway, imbalance, options, part, &edgecut);

}