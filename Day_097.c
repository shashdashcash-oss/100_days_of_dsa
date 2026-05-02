// Day 97 - Question 1: Meeting Rooms Scheduling
// Topic: Intervals / Priority Queue / Greedy
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

int compare(const void* a, const void* b) {
    return ((Meeting*)a)->start - ((Meeting*)b)->start;
}

void swap(int* heap, int i, int j) {
    int temp = heap[i]; heap[i] = heap[j]; heap[j] = temp;
}

void heapifyUp(int* heap, int index) {
    while(index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(heap, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int* heap, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1, right = 2 * index + 2;
    if(left  < size && heap[left]  < heap[smallest]) smallest = left;
    if(right < size && heap[right] < heap[smallest]) smallest = right;
    if(smallest != index) {
        swap(heap, index, smallest);
        heapifyDown(heap, size, smallest);
    }
}

int minMeetingRooms(Meeting meetings[], int n) {
    if(n == 0) return 0;

    qsort(meetings, n, sizeof(Meeting), compare);

    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;

    heap[heapSize++] = meetings[0].end;

    for(int i = 1; i < n; i++) {
        if(heap[0] <= meetings[i].start) {
            heap[0] = meetings[i].end;
            heapifyDown(heap, heapSize, 0);
        } else {
            heap[heapSize] = meetings[i].end;
            heapifyUp(heap, heapSize);
            heapSize++;
        }
    }

    int result = heapSize;
    free(heap);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting meetings[n];
    for(int i = 0; i < n; i++)
        scanf("%d %d", &meetings[i].start, &meetings[i].end);

    printf("%d", minMeetingRooms(meetings, n));

    return 0;
}
