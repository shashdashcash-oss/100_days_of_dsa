// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = x;
    n->next = top;
    top = n;
}

int pop() {
    struct node* t = top;
    int x = t->data;
    top = top->next;
    free(t);
    return x;
}

int main() {
    char exp[100];
    int i = 0;

    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0') {
        if (exp[i] >= '0' && exp[i] <= '9') {
            push(exp[i] - '0');
        } 
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            int b = pop();
            int a = pop();
            int r;

            if (exp[i] == '+') r = a + b;
            if (exp[i] == '-') r = a - b;
            if (exp[i] == '*') r = a * b;
            if (exp[i] == '/') r = a / b;

            push(r);
        }
        i++;
    }

    printf("%d", pop());
}// commit 34
// commit 34
