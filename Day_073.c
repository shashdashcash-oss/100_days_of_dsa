// Problem Statement
// Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

// Input Format
// A single string s.

// Output Format
// Print the first non-repeating character or '$' if none exists.

// Sample Input
// geeksforgeeks

// Sample Output
// f

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};
    scanf("%s", s);

    for(int i = 0; s[i]; i++)
        freq[s[i] - 'a']++;

    for(int i = 0; s[i]; i++) {
        if(freq[s[i] - 'a'] == 1) {
            printf("%c", s[i]);
            return 0;
        }
    }

    printf("$");
    return 0;
}// commit 73
// commit 73
