/*
 * Problem 6: Calculate FIRST function for grammar:
 *   E -> E+T | T
 *   T -> T*F | F
 *   F -> (E) | id (represented as 'i')
 *
 * Example:
 *   Productions:
 *     E=E+T (or E->E+T)
 *     E=T
 *     T=T*F
 *     T=F
 *     F=(E)
 *     F=i
 *   Output:
 *     FIRST(E) = { (, i }
 *     FIRST(F) = { (, i }
 *     FIRST(T) = { (, i }
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char lhs[20];
char rhs[20][20];
char first_set[26][30];

// Add terminal symbol c to FIRST(A) if not already present
int add_to_first(int A, char c) {
    if (strchr(first_set[A], c)) return 0;
    int len = strlen(first_set[A]);
    first_set[A][len] = c;
    first_set[A][len + 1] = '\0';
    return 1;
}

int main() {
    int n, i, changed = 1;
    char s[30], *q;

    printf("Number of productions: ");
    if (scanf("%d", &n) != 1) return 0;

    printf("Enter productions (e.g. E=E+T or E->E+T):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", s);
        lhs[i] = s[0];

        // Rectification: Robust extraction of RHS supporting both '->' and '='
        char *arrow = strstr(s, "->");
        char *equals = strchr(s, '=');
        if (arrow) {
            strcpy(rhs[i], arrow + 2);
        } else if (equals) {
            strcpy(rhs[i], equals + 1);
        } else {
            strcpy(rhs[i], s + 2);
        }
    }

    // Fixed-point iteration to compute FIRST sets
    while (changed) {
        changed = 0;
        for (i = 0; i < n; i++) {
            char c = rhs[i][0];
            if (!isupper(c)) {
                // If first symbol on RHS is a terminal, add it to FIRST(LHS)
                changed |= add_to_first(lhs[i] - 'A', c);
            } else {
                // If first symbol is non-terminal, add FIRST(c) to FIRST(LHS)
                for (q = first_set[c - 'A']; *q; q++) {
                    changed |= add_to_first(lhs[i] - 'A', *q);
                }
            }
        }
    }

    // Display computed FIRST sets
    for (i = 0; i < 26; i++) {
        if (first_set[i][0]) {
            printf("FIRST(%c) = { ", 'A' + i);
            for (q = first_set[i]; *q; q++) {
                printf("%c%s", *q, q[1] ? ", " : " ");
            }
            puts("}");
        }
    }
    return 0;
}
