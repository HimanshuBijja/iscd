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

/*
==================================================
HOW TO EXECUTE (STEP-BY-STEP):
Step 1: Open a terminal in the program folder:
        cd /path/to/LP
Step 2: Compile the C source code using gcc:
        gcc 05a_wc.c -o 05a_wc
Step 3: Run the compiled executable with a text file as argument:
        ./05a_wc 08a_file1.txt

SAMPLE OUTPUT:
        10 10 49 08a_file1.txt
        (Prints: lines words characters filename)
==================================================
*/
