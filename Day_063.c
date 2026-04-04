// Problem: Perform DFS starting from a given source vertex using recursion.

// Input:
// - n
// - adjacency list
// - starting vertex s

// Output:
// - DFS traversal order

#include <stdio.h>

int n;

void dfs(int v, int visited[], int adj[n][n]) {
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i < n; i++) {
        if(adj[v][i] && !visited[i]) {
            dfs(i, visited, adj);
        }
    }
}

int main() {
    scanf("%d", &n);
    int adj[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    int s;
    scanf("%d", &s);
    int visited[n];
    for(int i = 0; i < n; i++) visited[i] = 0;
    dfs(s, visited, adj);
    return 0;
}// commit 63
// commit 63
