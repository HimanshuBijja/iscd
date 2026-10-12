/*
 * Problem 4: Implement a lexical analyzer using C.
 * Identifies: Keywords, Identifiers, Numbers, Operators, Symbols.
 * Example:
 *   Input: int x = 10 + y;
 *   Output:
 *     int      Keyword
 *     x        Identifier
 *     =        Operator
 *     10       Number
 *     +        Operator
 *     y        Identifier
 *     ;        Symbol
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_keyword(const char *t) {
    const char *kw[] = {"int", "float", "char", "void", "if", "else", "while", "for", "return"};
    int count = sizeof(kw) / sizeof(kw[0]);
    for (int i = 0; i < count; i++) {
        if (strcmp(t, kw[i]) == 0) return 1;
    }
    return 0;
}

int main() {
    char s[200], t[50];
    int i = 0, j;

    printf("Enter code: ");
    if (!fgets(s, sizeof(s), stdin)) return 0;

    while (s[i]) {
        // Skip whitespace and newline characters
        if (isspace(s[i])) {
            i++;
            continue;
        }

        j = 0;
        // Identifier or Keyword
        if (isalpha(s[i]) || s[i] == '_') {
            while (isalnum(s[i]) || s[i] == '_') {
                if (j < 49) t[j++] = s[i];
                i++;
            }
            t[j] = '\0';
            printf("%s\t%s\n", t, is_keyword(t) ? "Keyword" : "Identifier");
        }
        // Number literal
        else if (isdigit(s[i])) {
            while (isdigit(s[i])) {
                if (j < 49) t[j++] = s[i];
                i++;
            }
            t[j] = '\0';
            printf("%s\tNumber\n", t);
        }
        // Operator or other Symbol
        else {
            printf("%c\t%s\n", s[i], strchr("+-*/=<>%", s[i]) ? "Operator" : "Symbol");
            i++;
        }
    }
    return 0;
}
