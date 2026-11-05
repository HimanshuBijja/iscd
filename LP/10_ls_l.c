#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char **argv) {
    DIR *dirop;
    struct dirent *dired;

    // Check if the correct number of arguments is provided
    if (argc != 2) {
        printf("Invalid number of arguments. Usage: %s <directory_name>\n", argv[0]);
        exit(1); // Exit if the number of arguments is incorrect
    }

    // Try to open the directory specified in the argument
    if ((dirop = opendir(argv[1])) == NULL) {
        printf("Cannot open directory %s\n", argv[1]);
        exit(1); // Exit if the directory cannot be opened
    }

    // Read and print directory entries
    while ((dired = readdir(dirop)) != NULL) {
        // Print inode number and filename
        printf("%10lu %s\n", dired->d_ino, dired->d_name);
    }

    // Close the directory stream
    closedir(dirop);
    
    return 0;
}

/*
==================================================
HOW TO EXECUTE (STEP-BY-STEP):
Step 1: Open a terminal in the program folder:
        cd /path/to/LP
Step 2: Compile using gcc:
        gcc 10_ls_l.c -o 10_ls_l
Step 3: Run providing directory path as argument:
        ./10_ls_l .

SAMPLE OUTPUT:
       1234567 .
       1234568 ..
       1234569 01_basic_linux_commands.md
       1234570 02_lines_between.sh
       1234571 10_ls_l.c
==================================================
*/
