// Problem: Deque (Double-Ended Queue)

// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

// Common Operations:
// 1. push_front(value): Insert an element at the front of the deque.
// 2. push_back(value): Insert an element at the rear of the deque.
// 3. pop_front(): Remove an element from the front of the deque.
// 4. pop_back(): Remove an element from the rear of the deque.
// 5. front(): Return the front element of the deque.
// 6. back(): Return the rear element of the deque.
// 7. empty(): Check whether the deque is empty.
// 8. size(): Return the number of elements in the deque.

// Additional Operations:
// - clear(): Remove all elements from the deque.
// - erase(): Remove one or more elements from the deque.
// - swap(): Swap contents of two deques.
// - emplace_front(): Insert an element at the front without copying.
// - emplace_back(): Insert an element at the rear without copying.
// - resize(): Change the size of the deque.
// - assign(): Replace elements with new values.
// - reverse(): Reverse the order of elements.
// - sort(): Sort the elements in ascending order.

// Time Complexity:
// - push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
// - clear, erase, resize, assign, reverse: O(n)
// - sort: O(n log n)

// Input:
// - Sequence of deque operations with values (if applicable)

// Output:
// - Results of operations such as front, back, size, or the final state of the deque after all operations

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

int dq[MAX];
int front = -1;
int rear = -1;

int empty() {
    return front == -1;
}

int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (empty()) {
        front = rear = MAX / 2;
        dq[front] = x;
    } else {
        front--;
        dq[front] = x;
    }
}

void push_back(int x) {
    if (empty()) {
        front = rear = MAX / 2;
        dq[rear] = x;
    } else {
        rear++;
        dq[rear] = x;
    }
}

void pop_front() {
    if (!empty()) {
        front++;
        if (front > rear) front = rear = -1;
    }
}

void pop_back() {
    if (!empty()) {
        rear--;
        if (front > rear) front = rear = -1;
    }
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            int x;
            scanf("%d", &x);
            push_front(x);
        }
        else if (strcmp(op, "push_back") == 0) {
            int x;
            scanf("%d", &x);
            push_back(x);
        }
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(op, "front") == 0) {
            if (!empty()) printf("%d\n", dq[front]);
        }
        else if (strcmp(op, "back") == 0) {
            if (!empty()) printf("%d\n", dq[rear]);
        }
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(op, "clear") == 0) {
            front = rear = -1;
        }
    }

    if (!empty()) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", dq[i]);
        }
    }

    return 0;
}// commit 38
// commit 38
