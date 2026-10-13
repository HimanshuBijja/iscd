/*
 * Q11: C program to demonstrate a zombie process.
 *      The child exits immediately but the parent sleeps without calling wait(),
 *      causing the child to become a zombie for 10 seconds.
 *
 * COMPILE: gcc -o zombie 11_zombie_process.c
 * RUN:     ./zombie
 *
 * SAMPLE INPUT:
 *   (no input required)
 *
 * EXPECTED OUTPUT:
 *   Child process (PID: 12346) is exiting...
 *   Parent process (PID: 12345) is waiting...
 *   (after 10 seconds)
 *   Parent process (PID: 12345) exiting...
 *
 * NOTE: During the 10-second sleep, run 'ps aux | grep Z' in another terminal
 *       to observe the child process in zombie (Z) state.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // If fork() fails
        perror("Fork failed");
        return 1;
    } 
    else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) is exiting...\n", getpid());
        _exit(0);  // Child exits without the parent collecting the exit status
    }
    else {
        // Parent process
        printf("Parent process (PID: %d) is waiting...\n", getpid());
        // Parent does not call wait() immediately, so the child becomes a zombie
        sleep(10);  // Sleep for 10 seconds to allow the child to become a zombie
        printf("Parent process (PID: %d) exiting...\n", getpid());
    }

    return 0;
}
