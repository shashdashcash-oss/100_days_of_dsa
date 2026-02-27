// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node *head1 = NULL, *tail1 = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* node = createNode(val);
        if (!head1) head1 = tail1 = node;
        else {
            tail1->next = node;
            tail1 = node;
        }
    }

    scanf("%d", &m);

    struct Node *head2 = NULL, *tail2 = NULL;
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        struct Node* node = createNode(val);
        if (!head2) head2 = tail2 = node;
        else {
            tail2->next = node;
            tail2 = node;
        }
    }

    struct Node* p1 = head1;
    while (p1) {
        struct Node* p2 = head2;
        while (p2) {
            if (p1->data == p2->data) {
                printf("%d\n", p1->data);
                return 0;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    printf("No Intersection\n");
    return 0;
}// commit 27
// commit 27
