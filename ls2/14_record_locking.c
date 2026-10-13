/*
 * Q14: C program to implement record locking using fcntl().
 *      Opens a file, applies a write lock on the first 100 bytes,
 *      sleeps for 5 seconds (simulating access), then releases the lock.
 *
 * COMPILE: gcc -o reclock 14_record_locking.c
 * RUN:     ./reclock
 *          (Run a second instance in another terminal while first is sleeping
 *           to observe the "already locked" message)
 *
 * SAMPLE INPUT:
 *   (no input required; operates on "record_file.txt" created automatically)
 *
 * EXPECTED OUTPUT (first instance):
 *   Record locked successfully.
 *   (waits 5 seconds)
 *   Record unlocked successfully.
 *
 * EXPECTED OUTPUT (second instance run concurrently):
 *   Record is already locked by another process.
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define FILENAME "record_file.txt"

int main() {
    int fd;
    struct flock lock;

    // Open the file
    fd = open(FILENAME, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Failed to open file");
        exit(1);
    }

    // Initialize the lock structure
    lock.l_type = F_WRLCK;  // Set the lock type to write lock
    lock.l_whence = SEEK_SET;  // Lock is from the beginning of the file
    lock.l_start = 0;   // Start of the file (you can set it to a specific record offset)
    lock.l_len = 100;   // Length of the record to lock (here locking 100 bytes)

    // Try to acquire the lock
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        if (errno == EACCES || errno == EAGAIN) {
            printf("Record is already locked by another process.\n");
        } else {
            perror("Failed to lock record");
        }
        close(fd);
        exit(1);
    }

    printf("Record locked successfully.\n");

    // Simulate file access (sleep for 5 seconds)
    sleep(5);

    // Release the lock
    lock.l_type = F_UNLCK;  // Change the lock type to unlock
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to unlock record");
        close(fd);
        exit(1);
    }

    printf("Record unlocked successfully.\n");

    // Close the file
    close(fd);

    return 0;
}
