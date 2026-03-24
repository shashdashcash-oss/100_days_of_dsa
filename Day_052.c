// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7
// 4 5

// Output:
// 2

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;
    Node* root = createNode(arr[0]);
    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        Node* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    free(queue);
    return root;
}

Node* lca(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int a, b;
    scanf("%d %d", &a, &b);

    Node* root = buildTree(arr, n);
    Node* res = lca(root, a, b);
    if (res) printf("%d\n", res->data);

    free(arr);
    return 0;
}// commit 52
// commit 52
