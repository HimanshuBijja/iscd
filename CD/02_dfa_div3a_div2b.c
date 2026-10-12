/*
 * Problem 2: Implement DFA that accepts all strings of a's and b's where:
 *   - Number of a's is divisible by 3
 *   - Number of b's is divisible by 2
 * Example:
 *   Input: aaabb -> Accepted
 *   Input: aab   -> Rejected
 */

#include <stdio.h>

int main() {
    char s[100];
    int a = 0, b = 0, i;

    printf("Enter string: ");
    if (scanf("%99s", s) != 1) return 0;

    for (i = 0; s[i]; i++) {
        if (s[i] == 'a')      a = (a + 1) % 3;
        else if (s[i] == 'b') b = (b + 1) % 2;
        else {
            puts("Invalid");
            return 0;
        }
    }

    // Both counts must be 0 modulo their divisor
    puts((a == 0 && b == 0) ? "Accepted" : "Rejected");
    return 0;
}
