/*
 * Q12: C program that illustrates creating, writing to, and reading from a message queue.
 *
 * COMPILE: gcc -o msgq 12_message_queue.c
 * RUN:     ./msgq
 *
 * SAMPLE INPUT (interactive):
 *   Enter message type (positive integer): 1
 *   Enter message text: HelloWorld
 *
 * EXPECTED OUTPUT:
 *   Message Queue Created with ID: 0
 *   Enter message type (positive integer): 1
 *   Enter message text: HelloWorld
 *   Message Sent: HelloWorld
 *   Message Received: HelloWorld
 *   Message Queue Removed
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define the structure for the message queue
struct msgbuf {
    long mtype;      // Message type (must be a positive integer)
    char mtext[100]; // Message text (content)
};

int main() {
    int msqid;          // Message queue ID
    int len, ret;       // Length of the message and return values
    struct msgbuf msgsend = {0, "\0"}, msgrecv; // Message buffers for sending and receiving
    
    // Step 1: Create a message queue (with key 1234)
    msqid = msgget((key_t)1234, IPC_CREAT | 0666);  // Create the message queue with read-write permissions for all users
    if (msqid == -1) {
        perror("msgget:");
        exit(1);
    }
    printf("Message Queue Created with ID: %d\n", msqid);

    // Step 2: Write a message to the message queue
    printf("Enter message type (positive integer): ");
    if (scanf("%ld", &msgsend.mtype) != 1) {
        fprintf(stderr, "Invalid message type input.\n");
        exit(1);
    }

    printf("Enter message text: ");
    if (scanf("%s", msgsend.mtext) != 1) {
        fprintf(stderr, "Invalid message text input.\n");
        exit(1);
    }

    len = strlen(msgsend.mtext);  // Calculate the length of the message text
    ret = msgsnd(msqid, &msgsend, len, 0);  // Send the message to the queue
    if (ret == -1) {
        perror("msgsnd:");
        exit(1);
    }
    printf("Message Sent: %s\n", msgsend.mtext);

    // Step 3: Read the message from the message queue
    ret = msgrcv(msqid, &msgrecv, sizeof(msgrecv.mtext), msgsend.mtype, 0);  // Receive the message with the same type
    if (ret == -1) {
        perror("msgrcv:");
        exit(1);
    }

    printf("Message Received: %s\n", msgrecv.mtext);

    // Step 4: Clean up by removing the message queue (optional)
    ret = msgctl(msqid, IPC_RMID, NULL);  // Remove the message queue
    if (ret == -1) {
        perror("msgctl:");
        exit(1);
    }
    printf("Message Queue Removed\n");

    return 0;
}
