// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20

#include <stdio.h>
#include <string.h>

int pq[1000];
int size = 0;

void insert(int x){
    int i = size++;
    pq[i] = x;
    while(i > 0){
        int p = (i - 1) / 2;
        if(pq[p] <= pq[i]) break;
        int t = pq[p];
        pq[p] = pq[i];
        pq[i] = t;
        i = p;
    }
}

int delete(){
    if(size == 0) return -1;
    int root = pq[0];
    pq[0] = pq[--size];
    int i = 0;
    while(1){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int s = i;
        if(l < size && pq[l] < pq[s]) s = l;
        if(r < size && pq[r] < pq[s]) s = r;
        if(s == i) break;
        int t = pq[i];
        pq[i] = pq[s];
        pq[s] = t;
        i = s;
    }
    return root;
}

int peek(){
    if(size == 0) return -1;
    return pq[0];
}

int main(){
    int n,x;
    char op[10];
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%s",op);

        if(strcmp(op,"insert")==0){
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"delete")==0){
            printf("%d\n",delete());
        }
        else if(strcmp(op,"peek")==0){
            printf("%d\n",peek());
        }
    }
}// commit 37
// commit 37
