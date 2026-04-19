// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

#include <stdio.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[n + 1][n + 1];
    int visited[n + 1];
    int minEdge[n + 1];

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        minEdge[i] = INT_MAX;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (graph[u][v] == 0 || w < graph[u][v]) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    minEdge[1] = 0;
    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || minEdge[j] < minEdge[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalWeight += minEdge[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < minEdge[v]) {
                minEdge[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}// commit 78
// commit 78
