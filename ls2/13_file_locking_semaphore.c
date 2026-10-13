/*
 * Q13: C program that illustrates file locking using semaphores.
 *      Creates a semaphore, locks it (simulating file lock), sleeps 3 seconds,
 *      then unlocks and removes the semaphore.
 *
 * COMPILE: gcc -o semlok 13_file_locking_semaphore.c
 * RUN:     ./semlok
 *
 * SAMPLE INPUT:
 *   (no input required)
 *
 * EXPECTED OUTPUT:
 *   File locked.
 *   (waits 3 seconds)
 *   File unlocked.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

// Semaphore union for operations
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

#define SEM_KEY 1234  // Semaphore key

// Locking function using semaphore
void lock_file(int semid) {
    struct sembuf sb = {0, -1, 0};  // P (wait) operation
    if (semop(semid, &sb, 1) == -1) {
        perror("semop - lock");
        exit(1);
    }
    printf("File locked.\n");
}

// Unlocking function using semaphore
void unlock_file(int semid) {
    struct sembuf sb = {0, 1, 0};   // V (signal) operation
    if (semop(semid, &sb, 1) == -1) {
        perror("semop - unlock");
        exit(1);
    }
    printf("File unlocked.\n");
}

int main() {
    int semid;
    union semun sem_union;

    // Create or get the semaphore set
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize the semaphore to 1 (unlocked)
    sem_union.val = 1;
    if (semctl(semid, 0, SETVAL, sem_union) == -1) {
        perror("semctl");
        exit(1);
    }

    // Lock and unlock the file (simulated by print and sleep)
    lock_file(semid);
    sleep(3);  // Simulate file access
    unlock_file(semid);

    // Clean up semaphore
    if (semctl(semid, 0, IPC_RMID, sem_union) == -1) {
        perror("semctl - IPC_RMID");
        exit(1);
    }

    return 0;
}
