#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    struct Edge edge[E];
};

int parent[V];

int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

void unionSet(int u, int v) {
    int uroot = find(u);
    int vroot = find(v);
    parent[uroot] = vroot;
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskalMST(struct Graph* graph) {
    struct Edge result[V];  
    int e = 0; 
    int i = 0;

    for (int v = 0; v < V; v++)
        parent[v] = v;

    qsort(graph->edge, E, sizeof(graph->edge[0]), compareEdges);

    while (e < V - 1 && i < E) {
        struct Edge next_edge = graph->edge[i++];

        int x = find(next_edge.src);
        int y = find(next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            unionSet(x, y);
        }
    }

    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}
