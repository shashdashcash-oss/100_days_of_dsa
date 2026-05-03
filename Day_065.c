// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO

#include <stdio.h>
#include <stdlib.h>

int hasCycle(int v, int parent, int *visited, int **adj, int *sizes) {
    visited[v] = 1;
    for (int i = 0; i < sizes[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            if (hasCycle(u, v, visited, adj, sizes)) return 1;
        } else if (u != parent) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int **adj = malloc(n * sizeof(int *));
    int *sizes = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &sizes[i]);
        adj[i] = malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int *visited = calloc(n, sizeof(int));
    int cycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycle(i, -1, visited, adj, sizes)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle) printf("YES");
    else printf("NO");

    return 0;
}// commit 65
// commit 65
