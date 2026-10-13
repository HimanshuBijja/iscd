/*
 * Q5b: C program to emulate the Unix 'cat' command.
 *      Reads and prints the contents of one or more files.
 *
 * COMPILE: gcc -o mycat 05b_cat.c
 * RUN:     ./mycat 08a_file1.txt
 *          ./mycat file1.txt file2.txt   (multiple files)
 *
 * SAMPLE INPUT (08a_file1.txt):
 *   hi
 *   how r u
 *   this
 *
 * EXPECTED OUTPUT:
 *   hi
 *   how r u
 *   this
 *   (followed by a blank line after each file)
 */

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
