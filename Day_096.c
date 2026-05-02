// Day 96 - Question 1: Counting Inversions in Array
// Topic: Inversions / Merge Sort / Divide and Conquer
#include <stdio.h>
#include <stdlib.h>

long long mergeCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long inv_count = 0;

    while(i <= mid - 1 && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // All remaining elements in left half form inversions with arr[j]
            inv_count += (mid - i);
        }
    }

    while(i <= mid - 1) temp[k++] = arr[i++];
    while(j <= right)   temp[k++] = arr[j++];

    for(i = left; i <= right; i++) arr[i] = temp[i];

    return inv_count;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if(right > left) {
        int mid = (left + right) / 2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += mergeCount(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int* temp = (int*)malloc(n * sizeof(int));
    long long result = mergeSort(arr, temp, 0, n - 1);
    printf("Inversion Count: %lld", result);

    free(temp);
    return 0;
}
