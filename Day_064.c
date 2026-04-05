// Problem: Perform BFS from a given source using queue.

// Input:
// - n
// - adjacency list
// - source s

// Output:
// - BFS traversal order

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int **adj = (int **)malloc(n * sizeof(int *));
    int *sizes = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &sizes[i]);
        adj[i] = (int *)malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int s;
    scanf("%d", &s);

    int *visited = (int *)calloc(n, sizeof(int));
    int *queue = (int *)malloc(n * sizeof(int));

    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < sizes[node]; i++) {
            int v = adj[node][i];
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    return 0;
}// commit 64
// commit 64
