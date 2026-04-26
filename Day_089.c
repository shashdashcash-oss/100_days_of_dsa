// Day 89 - Question 1: Allocate Minimum Pages
// Topic: Binary Search / Load Balancing
#include <stdio.h>

int isFeasible(int pages[], int n, int m, int maxPages) {
    int students = 1;
    int currentSum = 0;

    for(int i = 0; i < n; i++) {
        if(currentSum + pages[i] > maxPages) {
            students++;
            currentSum = pages[i];

            if(students > m)
                return 0;
        } else {
            currentSum += pages[i];
        }
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int pages[n];
    int low = 0, high = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
        if(pages[i] > low)
            low = pages[i];
        high += pages[i];
    }

    if(n < m) {
        printf("-1");
        return 0;
    }

    int ans = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(isFeasible(pages, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}
