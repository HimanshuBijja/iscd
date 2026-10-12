/*
 * Problem 3: Implement DFA accepting strings not ending with "00" over input {0, 1}.
 * Example:
 *   Input: 101  -> Accepted
 *   Input: 1100 -> Rejected
 */

#include <stdio.h>

int main() {
    char s[100];
    int st = 0, i;

    printf("Enter string: ");
    if (scanf("%99s", s) != 1) return 0;

    for (i = 0; s[i]; i++) {
        if (s[i] == '1') {
            st = 0;
        } else if (s[i] == '0') {
            st = (st < 2) ? st + 1 : 2;
        } else {
            puts("Invalid");
            return 0;
        }
    }

    // State 2 means the string ends with "00"
    puts((st != 2) ? "Accepted" : "Rejected");
    return 0;
}
