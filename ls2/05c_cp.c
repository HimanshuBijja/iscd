/*
 * Q5c: C program to emulate the Unix 'cp' command using system calls.
 *      Copies the contents of source file to destination file.
 *
 * COMPILE: gcc -o mycp 05c_cp.c
 * RUN:     ./mycp source.txt destination.txt
 *
 * SAMPLE INPUT:
 *   source.txt contents: "Hello, World!\n"
 *
 * EXPECTED OUTPUT:
 *   (no console output; destination.txt is created with the same content)
 *   destination.txt contents: "Hello, World!\n"
 */

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
    if (src == -1) return 1;

    dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest == -1) return 1;

    while ((n = read(src, buf, BUF_SIZE)) > 0)
        write(dest, buf, n);

    close(src);
    close(dest);

    return 0;
}
