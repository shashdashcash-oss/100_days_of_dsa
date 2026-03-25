// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct QNode {
    Node* node;
    int hd;
} QNode;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node* root = newNode(arr[0]);
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        Node* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void verticalOrder(Node* root) {
    if (!root) return;

    QNode* queue = (QNode*)malloc(1000 * sizeof(QNode));
    int front = 0, rear = 0;

    int map[2000][100];
    int count[2000] = {0};
    int offset = 1000;

    queue[rear++] = (QNode){root, 0};

    int min = 0, max = 0;

    while (front < rear) {
        QNode temp = queue[front++];
        Node* curr = temp.node;
        int hd = temp.hd;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        map[hd + offset][count[hd + offset]++] = curr->data;

        if (curr->left)
            queue[rear++] = (QNode){curr->left, hd - 1};
        if (curr->right)
            queue[rear++] = (QNode){curr->right, hd + 1};
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i + offset]; j++) {
            printf("%d ", map[i + offset][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}

// commit 53
// commit 53
