/*
 * Q15: C program that illustrates two processes communicating using a PIPE.
 *      Parent generates a random number (0-9), sends it to child via pipe.
 *      Child multiplies it by 4 and sends the result back to parent.
 *
 * COMPILE: gcc -o pipe_comm 15_pipe_communication.c
 * RUN:     ./pipe_comm
 *
 * SAMPLE INPUT:
 *   (no input required; parent generates a random number)
 *
 * EXPECTED OUTPUT (values depend on random number):
 *   Wrote 7          <- parent writes random number to pipe
 *   Received 7       <- child reads from pipe
 *   Wrote 28         <- child writes (7 * 4 = 28) back
 *   Result is 28     <- parent reads and prints the result
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int p1[2];
    int p2[2];
   
    if (pipe(p1) == -1) {
        return 1;
    }
    if (pipe(p2) == -1) {
        return 2;
    }
    int pid = fork();
    if (pid == -1) {
        return 3;
    }
   
    if (pid == 0) {
        // Child process
        close(p1[1]);
        close(p2[0]);
       
        int x;
        if (read(p1[0], &x, sizeof(int)) == -1) {
            return 3;
        }
        printf("Received %d\n", x);
       
        x *= 4;
       
        if (write(p2[1], &x, sizeof(int)) == -1) {
            return 4;
        }
        printf("Wrote %d\n", x);
        close(p1[0]);
        close(p2[1]);
    } else {
        // Parent process
        close(p1[0]);
        close(p2[1]);
       
        srand(time(NULL));
        int y = rand() % 10;
       
       
        if (write(p1[1], &y, sizeof(y)) == -1) {
            return 5;
        }
        printf("Wrote %d\n", y);
        if (read(p2[0], &y, sizeof(y)) == -1) {
            return 6;
        }
        printf("Result is %d\n", y);
       
        close(p1[1]);
        close(p2[0]);
        wait(NULL);
    }
   
    return 0;
}
