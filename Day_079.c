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

typedef struct Edge {
    int to, weight;
    struct Edge *next;
} Edge;

typedef struct {
    int vertex, dist;
} Node;

typedef struct {
    Node *arr;
    int size, capacity;
} MinHeap;

Edge **graph;
int *distanceArr;

MinHeap* createHeap(int capacity) {
    MinHeap *heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (Node*)malloc(capacity * sizeof(Node));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *heap, int vertex, int dist) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->arr = (Node*)realloc(heap->arr, heap->capacity * sizeof(Node));
    }
    int i = heap->size++;
    heap->arr[i].vertex = vertex;
    heap->arr[i].dist = dist;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap->arr[p].dist <= heap->arr[i].dist) break;
        swap(&heap->arr[p], &heap->arr[i]);
        i = p;
    }
}

Node pop(MinHeap *heap) {
    Node root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
        if (l < heap->size && heap->arr[l].dist < heap->arr[smallest].dist) smallest = l;
        if (r < heap->size && heap->arr[r].dist < heap->arr[smallest].dist) smallest = r;
        if (smallest == i) break;
        swap(&heap->arr[i], &heap->arr[smallest]);
        i = smallest;
    }
    return root;
}

int isEmpty(MinHeap *heap) {
    return heap->size == 0;
}

void addEdge(int u, int v, int w) {
    Edge *newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->to = v;
    newEdge->weight = w;
    newEdge->next = graph[u];
    graph[u] = newEdge;
}

void dijkstra(int n, int source) {
    for (int i = 1; i <= n; i++) distanceArr[i] = INT_MAX;
    distanceArr[source] = 0;

    MinHeap *heap = createHeap(n + 1);
    push(heap, source, 0);

    while (!isEmpty(heap)) {
        Node current = pop(heap);
        int u = current.vertex;
        int dist = current.dist;

        if (dist > distanceArr[u]) continue;

        Edge *temp = graph[u];
        while (temp) {
            int v = temp->to;
            int w = temp->weight;
            if (distanceArr[u] != INT_MAX && distanceArr[u] + w < distanceArr[v]) {
                distanceArr[v] = distanceArr[u] + w;
                push(heap, v, distanceArr[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (distanceArr[i] == INT_MAX) printf("-1");
        else printf("%d", distanceArr[i]);
        if (i < n) printf(" ");
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    graph = (Edge**)malloc((n + 1) * sizeof(Edge*));
    distanceArr = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) graph[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}// commit 79
// commit 79
