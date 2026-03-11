// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
// - Print -1 if operation cannot be performed

// Example:
// Input:
// 6
// insert 40
// insert 10
// insert 30
// peek
// extractMin
// peek

// Output:
// 10
// 10
// 30

#include <stdio.h>
#include <string.h>

int heap[100000];
int size = 0;

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void heapifyUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]>heap[i]){
            swap(&heap[p],&heap[i]);
            i=p;
        }else break;
    }
}

void heapifyDown(int i){
    while(1){
        int l=2*i+1;
        int r=2*i+2;
        int s=i;

        if(l<size && heap[l]<heap[s]) s=l;
        if(r<size && heap[r]<heap[s]) s=r;

        if(s!=i){
            swap(&heap[s],&heap[i]);
            i=s;
        }else break;
    }
}

void insert(int x){
    heap[size]=x;
    heapifyUp(size);
    size++;
}

int extractMin(){
    if(size==0) return -1;
    int m=heap[0];
    heap[0]=heap[size-1];
    size--;
    heapifyDown(0);
    return m;
}

int peek(){
    if(size==0) return -1;
    return heap[0];
}

int main(){
    int n,x;
    char op[20];
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%s",op);
        if(strcmp(op,"insert")==0){
            scanf("%d",&x);
            insert(x);
        }else if(strcmp(op,"extractMin")==0){
            printf("%d\n",extractMin());
        }else if(strcmp(op,"peek")==0){
            printf("%d\n",peek());
        }
    }
    return 0;
}// commit 39
// commit 39
