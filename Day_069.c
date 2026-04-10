// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int to, weight;
    struct Edge *next;
} Edge;

typedef struct {
    int node, dist;
} HeapNode;

typedef struct {
    HeapNode *arr;
    int size, capacity;
} MinHeap;

Edge *createEdge(int to, int weight) {
    Edge *e = (Edge *)malloc(sizeof(Edge));
    e->to = to;
    e->weight = weight;
    e->next = NULL;
    return e;
}

MinHeap *createHeap(int capacity) {
    MinHeap *h = (MinHeap *)malloc(sizeof(MinHeap));
    h->arr = (HeapNode *)malloc(capacity * sizeof(HeapNode));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(HeapNode *a, HeapNode *b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap *h, int idx) {
    while (idx > 0) {
        int p = (idx - 1) / 2;
        if (h->arr[p].dist <= h->arr[idx].dist) break;
        swap(&h->arr[p], &h->arr[idx]);
        idx = p;
    }
}

void heapifyDown(MinHeap *h, int idx) {
    while (1) {
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;
        int s = idx;

        if (l < h->size && h->arr[l].dist < h->arr[s].dist) s = l;
        if (r < h->size && h->arr[r].dist < h->arr[s].dist) s = r;

        if (s == idx) break;

        swap(&h->arr[idx], &h->arr[s]);
        idx = s;
    }
}

void push(MinHeap *h, int node, int dist) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->arr = (HeapNode *)realloc(h->arr, h->capacity * sizeof(HeapNode));
    }
    h->arr[h->size].node = node;
    h->arr[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

HeapNode pop(MinHeap *h) {
    HeapNode root = h->arr[0];
    h->size--;
    h->arr[0] = h->arr[h->size];
    heapifyDown(h, 0);
    return root;
}

int isEmpty(MinHeap *h) {
    return h->size == 0;
}

void dijkstra(Edge **graph, int V, int src) {
    int *dist = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    MinHeap *pq = createHeap(V);
    push(pq, src, 0);

    while (!isEmpty(pq)) {
        HeapNode cur = pop(pq);
        int u = cur.node;
        int d = cur.dist;

        if (d > dist[u]) continue;

        Edge *temp = graph[u];
        while (temp) {
            int v = temp->to;
            int w = temp->weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(pq, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    free(dist);
    free(pq->arr);
    free(pq);
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    Edge **graph = (Edge **)malloc(V * sizeof(Edge *));
    for (int i = 0; i < V; i++) graph[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        Edge *e1 = createEdge(v, w);
        e1->next = graph[u];
        graph[u] = e1;

        Edge *e2 = createEdge(u, w);
        e2->next = graph[v];
        graph[v] = e2;
    }

    int src;
    scanf("%d", &src);

    dijkstra(graph, V, src);

    for (int i = 0; i < V; i++) {
        Edge *temp = graph[i];
        while (temp) {
            Edge *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph);

    return 0;
}// commit 69
// commit 69
