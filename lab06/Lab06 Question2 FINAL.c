#include "graph.h"

int count_isolated(Graph* g) {
    int count = 0;

    for (int i = 0; i < MAX_NODES; i++) {
        int isolated = 1;

        for (int j = 0; j < MAX_NODES; j++) {
            if (g->adj[i][j] == 1) {
                isolated = 0;
                break;
            }
        }

        if (isolated == 1) {
            count++;
        }
    }

    return count;
}