#include <stdio.h>

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n; 


void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}


void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    push(v);
}

void topologicalSort() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    int e, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort();

    return 0;
}
