/*
 * Q9b: C program to create a hard link using the link() system call.
 *
 * COMPILE: gcc -o mylink 09b_link.c
 * RUN:     ./mylink source.txt hardlink.txt
 *
 * SAMPLE INPUT:
 *   argv[1] = source.txt  (must exist)
 *   argv[2] = hardlink.txt
 *
 * EXPECTED OUTPUT:
 *   Hard link created: hardlink.txt -> source.txt
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        // Check if the correct number of arguments is provided
        fprintf(stderr, "Usage: %s <source_file> <link_name>\n", argv[0]);
        return 1;
    }

    char *source_file = argv[1];
    char *link_name = argv[2];

    // Use the link system call to create a hard link
    if (link(source_file, link_name) == -1) {
        // If the link creation fails, print an error
        perror("Error creating link");
        return 1;
    }

    printf("Hard link created: %s -> %s\n", link_name, source_file);
    return 0;
}
