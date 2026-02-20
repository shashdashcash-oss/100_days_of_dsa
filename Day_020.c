// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the count of subarrays having sum zero

// Example:
// Input:
// 6
// 1 -1 2 -2 3 -3

// Output:
// 6

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long *arr = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    long long *prefix = (long long *)malloc((n + 1) * sizeof(long long));
    prefix[0] = 0;

    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + arr[i - 1];

    qsort(prefix, n + 1, sizeof(long long), cmp);

    long long count = 0;
    long long freq = 1;

    for (int i = 1; i <= n; i++) {
        if (prefix[i] == prefix[i - 1]) {
            freq++;
        } else {
            count += (freq * (freq - 1)) / 2;
            freq = 1;
        }
    }

    count += (freq * (freq - 1)) / 2;

    printf("%lld", count);

    free(arr);
    free(prefix);

    return 0;
}
// commit 20
// commit 20
