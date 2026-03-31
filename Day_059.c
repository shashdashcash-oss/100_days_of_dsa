// Problem Statement:
// Construct a binary tree from given inorder and postorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains inorder traversal
// - Third line contains postorder traversal

// Output Format:
// - Print preorder traversal of constructed tree

// Example:
// Input:
// 5
// 4 2 5 1 3
// 4 5 2 3 1

// Output:
// 1 2 4 5 3

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    int curr = postorder[*postIndex];
    (*postIndex)--;

    Node* node = newNode(curr);

    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, curr);

    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

void preorder(Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int *inorder = (int*)malloc(n * sizeof(int));
    int *postorder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;
    Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    free(inorder);
    free(postorder);

    return 0;
}// commit 59
// commit 59
