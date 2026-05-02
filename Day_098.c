// Day 98 - Question 1: Merge Overlapping Intervals
// Topic: Intervals / Sorting / Greedy
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compare(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval intervals[n];
    for(int i = 0; i < n; i++)
        scanf("%d %d", &intervals[i].start, &intervals[i].end);

    qsort(intervals, n, sizeof(Interval), compare);

    Interval result[n];
    int idx = 0;
    result[idx] = intervals[0];

    for(int i = 1; i < n; i++) {
        if(intervals[i].start <= result[idx].end) {
            // Overlapping: extend end if needed
            if(intervals[i].end > result[idx].end)
                result[idx].end = intervals[i].end;
        } else {
            // Non-overlapping: start new interval
            idx++;
            result[idx] = intervals[i];
        }
    }

    for(int i = 0; i <= idx; i++)
        printf("[%d,%d] ", result[i].start, result[i].end);

    return 0;
}
