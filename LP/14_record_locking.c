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
    lock.l_type = F_WRLCK;     // Set the lock type to write lock
    lock.l_whence = SEEK_SET;  // Lock is from the beginning of the file
    lock.l_start = 0;          // Start of the file (specific record offset)
    lock.l_len = 100;          // Length of the record to lock (100 bytes)

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
    lock.l_type = F_UNLCK;     // Change the lock type to unlock
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

/*
==================================================
HOW TO EXECUTE (STEP-BY-STEP):
Step 1: Open a terminal in the program folder:
        cd /path/to/LP
Step 2: Compile using gcc:
        gcc 14_record_locking.c -o 14_record_locking
Step 3: Run the program:
        ./14_record_locking
        (To test concurrency, run `./14_record_locking` in a second terminal while the first is sleeping)

SAMPLE OUTPUT:
Terminal 1:
        Record locked successfully.
        (sleeps for 5 seconds)
        Record unlocked successfully.

Terminal 2 (concurrent execution while Terminal 1 holds lock):
        Record is already locked by another process.
==================================================
*/
