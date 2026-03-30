// Problem Statement:
// Construct a binary tree from given preorder and inorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains preorder traversal
// - Third line contains inorder traversal

// Output Format:
// - Print postorder traversal of constructed tree

// Example:
// Input:
// 5
// 1 2 4 5 3
// 4 2 5 1 3

// Output:
// 4 5 2 3 1

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int map[100005];

struct Node* build(int preorder[], int ps, int pe, int inorder[], int is, int ie){
    if(ps > pe || is > ie) return NULL;

    struct Node* root = newNode(preorder[ps]);

    int inIndex = map[root->val];
    int leftSize = inIndex - is;

    root->left = build(preorder, ps+1, ps+leftSize, inorder, is, inIndex-1);
    root->right = build(preorder, ps+leftSize+1, pe, inorder, inIndex+1, ie);

    return root;
}

void postorder(struct Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main(){
    int n;
    scanf("%d",&n);

    int preorder[n], inorder[n];

    for(int i=0;i<n;i++) scanf("%d",&preorder[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&inorder[i]);
        map[inorder[i]] = i;
    }

    struct Node* root = build(preorder,0,n-1,inorder,0,n-1);

    postorder(root);

    return 0;
}// commit 58
// commit 58
