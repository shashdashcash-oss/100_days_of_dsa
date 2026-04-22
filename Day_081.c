// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.

// Input Format
// n m
// u v w
// source

// Output Format
// Distances to all vertices.

// Sample Input
// 5 6
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 5 1
// 1

// Sample Output
// 0 2 3 9 6

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int to, wt;
    struct Node *next;
} Node;

typedef struct {
    int v, dist;
} HeapNode;

HeapNode heap[200005];
int heapSize = 0;

void push(int v, int dist) {
    heap[++heapSize].v = v;
    heap[heapSize].dist = dist;
    int i = heapSize;
    while (i > 1 && heap[i].dist < heap[i / 2].dist) {
        HeapNode temp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = temp;
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode root = heap[1];
    heap[1] = heap[heapSize--];
    int i = 1;
    while (1) {
        int left = 2 * i, right = 2 * i + 1, smallest = i;
        if (left <= heapSize && heap[left].dist < heap[smallest].dist) smallest = left;
        if (right <= heapSize && heap[right].dist < heap[smallest].dist) smallest = right;
        if (smallest == i) break;
        HeapNode temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        i = smallest;
    }
    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node **adj = (Node **)calloc(n + 1, sizeof(Node *));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        Node *a = (Node *)malloc(sizeof(Node));
        a->to = v;
        a->wt = w;
        a->next = adj[u];
        adj[u] = a;

        Node *b = (Node *)malloc(sizeof(Node));
        b->to = u;
        b->wt = w;
        b->next = adj[v];
        adj[v] = b;
    }

    int source;
    scanf("%d", &source);

    int *dist = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[source] = 0;

    push(source, 0);

    while (heapSize > 0) {
        HeapNode cur = pop();
        int u = cur.v;
        int d = cur.dist;

        if (d > dist[u]) continue;

        Node *temp = adj[u];
        while (temp) {
            int v = temp->to;
            int w = temp->wt;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("-1");
        else printf("%d", dist[i]);
        if (i < n) printf(" ");
    }

    return 0;
}// commit 81
// commit 81
