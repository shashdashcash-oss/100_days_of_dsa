// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n;
int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = v;
}

int main() {
    int edges, u, v;
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}// commit 67
// commit 67
