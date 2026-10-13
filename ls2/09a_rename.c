/*
 * Q9a: C program to implement the Unix 'rename' command using the rename() system call.
 *
 * COMPILE: gcc -o myrename 09a_rename.c
 * RUN:     ./myrename oldname.txt newname.txt
 *
 * SAMPLE INPUT:
 *   argv[1] = oldname.txt  (must exist)
 *   argv[2] = newname.txt
 *
 * EXPECTED OUTPUT:
 *   File renamed successfully: oldname.txt -> newname.txt
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if correct number of arguments is provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <old_name> <new_name>\n", argv[0]);
        return 1;
    }

    // Rename the file using the rename() system call
    if (rename(argv[1], argv[2]) == 0) {
        printf("File renamed successfully: %s -> %s\n", argv[1], argv[2]);
    } else {
        perror("Error renaming file");
        return 1;
    }

    return 0;
}
