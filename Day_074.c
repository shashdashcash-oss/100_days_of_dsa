// Problem Statement
// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

// Input Format
// First line contains an integer n representing number of votes.
// Second line contains n space-separated strings representing candidate names.

// Output Format
// Print the name of the winning candidate followed by the number of votes received.

// Sample Input
// 13
// john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

// Sample Output
// john 4

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char names[n][101];
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    qsort(names, n, sizeof(names[0]), cmp);

    int maxCount = 0, count = 1;
    char winner[101];
    strcpy(winner, names[0]);

    for (int i = 1; i < n; i++) {
        if (strcmp(names[i], names[i - 1]) == 0) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                strcpy(winner, names[i - 1]);
            }
            count = 1;
        }
    }

    if (count > maxCount) {
        maxCount = count;
        strcpy(winner, names[n - 1]);
    }

    printf("%s %d", winner, maxCount);

    return 0;
}// commit 74
// commit 74
