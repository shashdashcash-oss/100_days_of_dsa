// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int **adj = (int **)malloc(V * sizeof(int *));
    int *count = (int *)calloc(V, sizeof(int));
    int *indegree = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int *)malloc(V * sizeof(int));
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][count[u]++] = v;
        indegree[v]++;
    }

    int *queue = (int *)malloc(V * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int *topo = (int *)malloc(V * sizeof(int));
    int idx = 0;

    while (front < rear) {
        int node = queue[front++];
        topo[idx++] = node;

        for (int i = 0; i < count[node]; i++) {
            int next = adj[node][i];
            indegree[next]--;
            if (indegree[next] == 0) {
                queue[rear++] = next;
            }
        }
    }

    if (idx != V) {
        printf("Cycle detected\n");
    } else {
        for (int i = 0; i < V; i++) {
            printf("%d ", topo[i]);
        }
    }

    for (int i = 0; i < V; i++) {
        free(adj[i]);
    }
    free(adj);
    free(count);
    free(indegree);
    free(queue);
    free(topo);

    return 0;
}// commit 68
// commit 68
