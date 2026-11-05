#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int src, dest, n;
    char buf[BUF_SIZE];

    if (argc != 3) {
        write(2, "Usage: cp <source> <destination>\n", 33);
        return 1;
    }

    src = open(argv[1], O_RDONLY);
    if (src == -1) {
        perror("Error opening source file");
        return 1;
    }

    dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest == -1) {
        perror("Error opening destination file");
        close(src);
        return 1;
    }

    while ((n = read(src, buf, BUF_SIZE)) > 0) {
        write(dest, buf, n);
    }

    close(src);
    close(dest);

    return 0;
}

/*
==================================================
HOW TO EXECUTE (STEP-BY-STEP):
Step 1: Open a terminal in the program folder:
        cd /path/to/LP
Step 2: Compile the C source code using gcc:
        gcc 05c_cp.c -o 05c_cp
Step 3: Run the executable providing source and destination filenames:
        ./05c_cp 07a_file1.txt copy_of_file1.txt
Step 4: Verify the destination file was created and contents match:
        cat copy_of_file1.txt

SAMPLE OUTPUT:
        apple
        banana
        orange
==================================================
*/
