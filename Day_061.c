// Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
// The graph may be directed or undirected.

// Input:
// - n (vertices)
// - m (edges)
// - m pairs (u, v)

// Output:
// - n x n adjacency matrix

#include <stdio.h>

int main() {
    int n, m, u, v, i, j, directed;
    scanf("%d %d", &n, &m);
    scanf("%d", &directed);

    int adj[n][n];

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            adj[i][j] = 0;

    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        if(!directed)
            adj[v][u] = 1;
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    return 0;
}// commit 61
// commit 61
