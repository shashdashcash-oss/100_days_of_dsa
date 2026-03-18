// Problem: Level Order Traversal

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Queue {
    struct Node* arr[1000];
    int front, rear;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[++q->front];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void levelOrder(struct Node* root) {
    if (!root) return;
    struct Queue q;
    q.front = q.rear = -1;
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        struct Node* temp = dequeue(&q);
        printf("%d ", temp->data);
        if (temp->left) enqueue(&q, temp->left);
        if (temp->right) enqueue(&q, temp->right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0) return 0;

    int val;
    scanf("%d", &val);
    struct Node* root = newNode(val);

    struct Queue q;
    q.front = q.rear = -1;
    enqueue(&q, root);

    int count = 1;
    while (count < n) {
        struct Node* temp = dequeue(&q);

        scanf("%d", &val);
        count++;
        if (val != -1) {
            temp->left = newNode(val);
            enqueue(&q, temp->left);
        }

        if (count >= n) break;

        scanf("%d", &val);
        count++;
        if (val != -1) {
            temp->right = newNode(val);
            enqueue(&q, temp->right);
        }
    }

    levelOrder(root);
    return 0;
}// commit 46
// commit 46
