// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

// Input:
// - First line: integer n (number of operations)
// - Next n lines: operation type and value (if applicable)
//   - 1 value: push value
//   - 2: pop
//   - 3: display

// Output:
// - For display: print stack elements from top to bottom
// - For pop: print popped element or 'Stack Underflow'

// Example:
// Input:
// 5
// 1 10
// 1 20
// 3
// 2
// 3

// Output:
// 20 10
// 20
// 10

#include <stdio.h>
#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int val;
            scanf("%d", &val);
            if (top < MAX - 1)
                stack[++top] = val;
        } 
        else if (op == 2) {
            if (top == -1)
                printf("Stack Underflow\n");
            else
                printf("%d\n", stack[top--]);
        } 
        else if (op == 3) {
            if (top == -1) {
                printf("\n");
            } else {
                for (int j = top; j >= 0; j--)
                    printf("%d ", stack[j]);
                printf("\n");
            }
        }
    }

    return 0;
}// commit 31
// commit 31
