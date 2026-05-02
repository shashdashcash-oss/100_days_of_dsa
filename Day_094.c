// Day 94 - Question 1: Counting Sort Implementation
// Topic: Counting Sort / Relative Ordering / Custom Sorting
#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max) max = arr[i];

    int* count = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) count[arr[i]]++;
    for(int i = 1; i <= max; i++) count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for(int i = 0; i < n; i++) arr[i] = output[i];

    free(count);
    free(output);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
