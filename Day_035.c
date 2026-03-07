// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements)
// - Second line: n space-separated integers

// Output:
// - Print queue elements from front to rear, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* q, int x) {
    Node* n = malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = n;
        return;
    }
    q->rear->next = n;
    q->rear = n;
}

void display(Queue* q) {
    Node* t = q->front;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
}

int main() {
    int n, x;
    scanf("%d", &n);

    Queue q;
    q.front = q.rear = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    display(&q);
    return 0;
}// commit 35
// commit 35
