/*
 * Q10: C program to emulate the Unix 'ls -l' command.
 *      Displays inode number and filename for each entry in a directory.
 *
 * COMPILE: gcc -o myls 10_ls_l.c
 * RUN:     ./myls /home/user
 *          (or) ./myls .
 *
 * SAMPLE INPUT:
 *   argv[1] = /tmp  (any valid directory)
 *
 * EXPECTED OUTPUT:
 *   (inode)    (filename)
 *    131073 .
 *    131074 ..
 *    131075 file1.txt
 *    131076 file2.txt
 */

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
