#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int edges[MAX][MAX];
    int numVertices;
} Graph;

void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            g->edges[i][j] = 0;
}

void addEdge(Graph *g, int u, int v) {
    g->edges[u][v] = 1;
}

void dfs(Graph *g, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < g->numVertices; i++) {
        if (g->edges[v][i] && !visited[i]) {
            dfs(g, i, visited);
        }
    }
}

// Example usage
int main() {
    Graph g;
    initGraph(&g, 5);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);

    int visited[MAX] = {0};
    printf("Depth First Search starting from vertex 0:\n");
    dfs(&g, 0, visited);
    return 0;
}
