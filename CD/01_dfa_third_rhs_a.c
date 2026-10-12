/*
 * Problem 1: Implement DFA that accepts all strings of a's and b's where the 3rd symbol from RHS is always 'a'.
 * Example:
 *   Input: abb  -> Accepted
 *   Input: bab  -> Rejected
 */

#include <stdio.h>

int main() {
    char s[100];
    int st = 0, i;

    printf("Enter string: ");
    if (scanf("%99s", s) != 1) return 0;

    for (i = 0; s[i]; i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            puts("Invalid");
            return 0;
        }
        // Shift window and record whether character is 'a'
        st = ((st << 1) | (s[i] == 'a')) & 7;
    }

    // Check if 3rd bit from right (value 4) is set
    puts((st & 4) ? "Accepted" : "Rejected");
    return 0;
}
