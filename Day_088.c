// Day 88 - Question 1: Aggressive Cows Problem
// Topic: Binary Search / Distance Optimization
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int stalls[], int n, int k, int minDist) {
    int count = 1;
    int lastPos = stalls[0];

    for(int i = 1; i < n; i++) {
        if(stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
        }

        if(count >= k)
            return 1;
    }

    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &stalls[i]);

    qsort(stalls, n, sizeof(int), compare);

    int low = 1, high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(canPlace(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d", ans);

    return 0;
}
