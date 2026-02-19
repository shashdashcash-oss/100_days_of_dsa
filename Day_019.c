// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

// Example:
// Input:
// 5
// 1 60 -10 70 -80

// Output:
// -10 1

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp);

    int l = 0, r = n - 1;
    int min_sum = arr[l] + arr[r];
    int a = arr[l], b = arr[r];

    while(l < r) {
        int sum = arr[l] + arr[r];
        if(abs(sum) < abs(min_sum)) {
            min_sum = sum;
            a = arr[l];
            b = arr[r];
        }
        if(sum < 0)
            l++;
        else
            r--;
    }

    printf("%d %d", a, b);
    return 0;
}
// commit 19
// commit 19
