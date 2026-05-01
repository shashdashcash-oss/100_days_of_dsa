// Day 90 - Question 1: Painter Partition Problem
// Topic: Binary Search on Answer
#include <stdio.h>

int isFeasible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentSum = 0;

    for(int i = 0; i < n; i++) {
        if(currentSum + boards[i] > maxTime) {
            painters++;
            currentSum = boards[i];

            if(painters > k)
                return 0;
        } else {
            currentSum += boards[i];
        }
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int low = 0, high = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if(boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    int ans = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(isFeasible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}
