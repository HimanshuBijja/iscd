/*
 * Problem 5: Recursive descent parser for the grammar:
 *   S -> (L) | a
 *   L -> L, S | S
 *
 * Left recursion eliminated from L:
 *   L  -> S L'
 *   L' -> , S L' | epsilon
 *
 * Example:
 *   Input: (a,(a,a)) -> Accepted
 *   Input: (a,)      -> Rejected
 */

#include <stdio.h>

const char *p;

int S(void);
int L(void);

// S -> a | (L)
int S(void) {
    if (*p == 'a') {
        p++;
        return 1;
    }
    if (*p == '(') {
        p++;
        if (L() && *p == ')') {
            p++;
            return 1;
        }
    }
    return 0;
}

// L -> S (, S)*
int L(void) {
    if (!S()) return 0;
    while (*p == ',') {
        p++;
        if (!S()) return 0;
    }
    return 1;
}

int main() {
    char s[100];
    printf("Enter string: ");
    if (scanf("%99s", s) != 1) return 0;
    p = s;

    // Must parse S successfully and reach the end of the input string
    puts((S() && *p == '\0') ? "Accepted" : "Rejected");
    return 0;
}
