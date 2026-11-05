#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char ch;

    // Check if at least one file name is provided
    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return 1;
    }

    // Loop through each file provided in the command line
    for (int i = 1; i < argc; i++) {
        file = fopen(argv[i], "r");  // Open the file in read mode

        if (file == NULL) {
            perror("Error opening file");
            continue;  // Move to the next file
        }

        // Read the file character by character and print it to the console
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);  // Print the character to stdout
        }

        fclose(file);  // Close the file after reading
        printf("\n");   // Print a newline after each file's content
    }

    return 0;
}

/*
==================================================
HOW TO EXECUTE (STEP-BY-STEP):
Step 1: Open a terminal in the program folder:
        cd /path/to/LP
Step 2: Compile the C source code using gcc:
        gcc 05b_cat.c -o 05b_cat
Step 3: Run the executable with one or more files as arguments:
        ./05b_cat 07a_file1.txt

SAMPLE OUTPUT:
        apple
        banana
        orange
==================================================
*/
