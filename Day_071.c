// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define DELETED -2

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int h = hash(key, m);
    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;
        if (table[idx] == EMPTY || table[idx] == DELETED) {
            table[idx] = key;
            return;
        }
    }
}

void search(int table[], int m, int key) {
    int h = hash(key, m);
    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;
        if (table[idx] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }
        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }
    }
    printf("NOT FOUND\n");
}

void deleteKey(int table[], int m, int key) {
    int h = hash(key, m);
    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;
        if (table[idx] == EMPTY) {
            return;
        }
        if (table[idx] == key) {
            table[idx] = DELETED;
            return;
        }
    }
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(table, m, key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(table, m, key);
        } else if (strcmp(op, "DELETE") == 0) {
            deleteKey(table, m, key);
        }
    }

    return 0;
}// commit 71
// commit 71
