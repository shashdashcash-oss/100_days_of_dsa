// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include <stdio.h>
#include <stdlib.h>

int **adj;
int *visited;
int *recStack;

int dfs(int node, int V) {
    if (!visited[node]) {
        visited[node] = 1;
        recStack[node] = 1;

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                if (!visited[i] && dfs(i, V))
                    return 1;
                else if (recStack[i])
                    return 1;
            }
        }
    }
    recStack[node] = 0;
    return 0;
}

int main() {
    int V;
    scanf("%d", &V);

    adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        adj[i] = (int *)malloc(V * sizeof(int));
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    visited = (int *)calloc(V, sizeof(int));
    recStack = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (dfs(i, V)) {
            printf("YES");
            return 0;
        }
    }

    printf("NO");
    return 0;
}// commit 66
// commit 66
