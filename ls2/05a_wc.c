/*
 * Q5a: C program to emulate the Unix 'wc' command.
 *      Counts lines, words, and characters in a file.
 *
 * COMPILE: gcc -o wc 05a_wc.c
 * RUN:     ./wc 08a_file1.txt
 *          (or) ./wc anyfile.txt
 *
 * SAMPLE INPUT (08a_file1.txt):
 *   hi
 *   how r u
 *   this
 *   is
 *   hello
 *   bajj
 *   dfdf
 *   hhhh
 *   rrrr
 *   ttt
 *
 * EXPECTED OUTPUT:
 *   10 10 47 08a_file1.txt
 *   (lines words chars filename)
 */

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *file;
    int c, lines = 0, words = 0, chars = 0;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    while ((c = fgetc(file)) != EOF) {
        chars++;
        if (c == '\n') {
            lines++;
        }
        if (isspace(c)) {
               words++;
               }
    }
    fclose(file);
    printf("%d %d %d %s\n", lines, words, chars, argv[1]);
    return 0;
}
