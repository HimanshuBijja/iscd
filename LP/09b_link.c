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

/*
==================================================
HOW TO EXECUTE (STEP-BY-STEP):
Step 1: Open a terminal in the program folder:
        cd /path/to/LP
Step 2: Compile using gcc:
        gcc 09b_link.c -o 09b_link
Step 3: Run with existing source file and new link name:
        ./09b_link 08a_file1.txt hardlink_file1.txt
Step 4: Verify inode numbers are identical:
        ls -i 08a_file1.txt hardlink_file1.txt

SAMPLE OUTPUT:
        Hard link created: hardlink_file1.txt -> 08a_file1.txt
==================================================
*/
