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
static int options[] = {0};
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
  
void hm_partition(unsigned int nvtxs, unsigned int nhedges, int *hewt, int *vtw, int *eind, int *eptr, int *part, int kway, int passes, long seed)
{
    // printf("This is the wrapper for the HMETIS call\n");
    int edgecut;

    HMETIS_PartRecursive(nvtxs, nhedges, vtw, eptr, eind, hewt, kway, passes, options, part, &edgecut);

}