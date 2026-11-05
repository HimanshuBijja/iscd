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

/*
==================================================
HOW TO EXECUTE (STEP-BY-STEP):
Step 1: Open a terminal in the program folder:
        cd /path/to/LP
Step 2: Compile using gcc:
        gcc 09a_rename.c -o 09a_rename
Step 3: Create a test file:
        touch old.txt
Step 4: Run the program with old and new names:
        ./09a_rename old.txt new.txt

SAMPLE OUTPUT:
        File renamed successfully: old.txt -> new.txt
==================================================
*/
