// Problem Statement
// Using BFS or DFS, check if the entire graph is connected.

// Input Format
// n m
// edges

// Output Format
// CONNECTED
// NOT CONNECTED

// Sample Input
// 4 2
// 1 2
// 3 4

// Sample Output
// NOT CONNECTED

#include <stdio.h>
#include <stdlib.h>

int visited[1005];
int adj[1005][1005];
int n, m;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}// commit 77
// commit 77
