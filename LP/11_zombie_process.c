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

/*
==================================================
HOW TO EXECUTE (STEP-BY-STEP):
Step 1: Open terminal and navigate to the directory:
        cd /path/to/LP
Step 2: Compile using gcc:
        gcc 11_zombie_process.c -o 11_zombie_process
Step 3: Run the program:
        ./11_zombie_process &
Step 4: While the parent sleeps (during the 10 seconds), check the zombie status in terminal:
        ps -el | grep 'Z'
        (or: ps aux | grep -i defunct)

SAMPLE OUTPUT:
        Child process (PID: 12345) is exiting...
        Parent process (PID: 12344) is waiting...
        (During 10-second sleep, ps shows 12345 with state 'Z' or '<defunct>')
        Parent process (PID: 12344) exiting...
==================================================
*/
