// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int *q = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    scanf("%d", &m);

    int front = 0, rear = n - 1;

    front = (front + m) % n;

    int count = n;
    int i = front;

    for(int k = 0; k < count; k++) {
        printf("%d ", q[i]);
        i = (i + 1) % n;
    }

    free(q);
    return 0;
}// commit 36
// commit 36
