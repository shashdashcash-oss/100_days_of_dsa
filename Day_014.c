// Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

// Input:
// - First line: integer n representing number of rows and columns
// - Next n lines: n integers each representing the matrix elements

// Output:
// - Print "Identity Matrix" if the matrix satisfies the condition
// - Otherwise, print "Not an Identity Matrix"

// Example:
// Input:
// 3
// 1 0 0
// 0 1 0
// 0 0 1

// Output:
// Identity Matrix

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                if(a[i][j] != 1) {
                    printf("Not an Identity Matrix");
                    return 0;
                }
            } else {
                if(a[i][j] != 0) {
                    printf("Not an Identity Matrix");
                    return 0;
                }
            }
        }
    }

    printf("Identity Matrix");

    return 0;
}
// commit 14
// commit 14
