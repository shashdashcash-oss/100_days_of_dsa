// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

// Input:
// - Single line: a lowercase string containing only alphabetic characters (no spaces)

// Output:
// - Print the transformed code name after applying the mirror operation

// Example:
// Input:
// hello

// Output:
// olleh

// Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored

#include <stdio.h>
#include <string.h>

void reverse(char s[], int l, int r) {
    if (l >= r)
        return;
    char t = s[l];
    s[l] = s[r];
    s[r] = t;
    reverse(s, l + 1, r - 1);
}

int main() {
    char s[1000];
    scanf("%s", s);
    reverse(s, 0, strlen(s) - 1);
    printf("%s", s);
    return 0;
}
// commit 9
// commit 9
