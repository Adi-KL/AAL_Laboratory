#include <stdio.h>
#include <limits.h>

int tsp(int graph[N][N], int visited[], int currPos, int n, int count, int cost, int *ans) {
    if (count == n && graph[currPos][0]) {
        if (cost + graph[currPos][0] < *ans)
            *ans = cost + graph[currPos][0];
        return *ans;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i]) {
            visited[i] = 1;
            tsp(graph, visited, i, n, count + 1, cost + graph[currPos][i], ans);
            visited[i] = 0; // backtrack
        }
    }
    return *ans;
}

int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 20, 30, 25},
        {20, 30, 15, 35},
        {25, 45, 30, 10}
    };
    };

    int visited[N];
    for (int i = 0; i < N; i++)
        visited[i] = 0;

    visited[0] = 1; 
    int ans = INT_MAX;

    ans = tsp(graph, visited, 0, N, 1, 0, &ans);

    printf("Minimum cost of traveling salesman path: %d\n", ans);

    return 0;
}
