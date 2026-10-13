MID-1  LP LAB RECORD
===========================

# 5a. C Program – wc (Word Count)

**COMPILE:**
```
gcc -o wc 05a_wc.c
```
**RUN:**
```
./wc 08a_file1.txt
```
**SAMPLE INPUT (08a_file1.txt):**
```
hi
how r u
this
is
hello
bajj
dfdf
hhhh
rrrr
ttt
```
**EXPECTED OUTPUT:**
```
10 10 47 08a_file1.txt
(lines words chars filename)
```

**Program:**
```c
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *file;
    int c, lines = 0, words = 0, chars = 0;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    while ((c = fgetc(file)) != EOF) {
        chars++;
        if (c == '\n') {
            lines++;
        }
        if (isspace(c)) {
               words++;
               }
    }
    fclose(file);
    printf("%d %d %d %s\n", lines, words, chars, argv[1]);
    return 0;
}
```

---

# 5b. C Program – cat (Concatenate & Display)

**COMPILE:**
```
gcc -o mycat 05b_cat.c
```
**RUN:**
```
./mycat 08a_file1.txt
./mycat file1.txt file2.txt   (multiple files)
```
**SAMPLE INPUT (08a_file1.txt):**
```
hi
how r u
this
```
**EXPECTED OUTPUT:**
```
hi
how r u
this

(followed by a blank line after each file)
```

**Program (File1.c):**
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char ch;

    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        file = fopen(argv[i], "r");

        if (file == NULL) {
            perror("Error opening file");
            continue;
        }

        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }

        fclose(file);
        printf("\n");
    }

    return 0;
}
```

---

# 5c. C Program – cp (Copy File)

**COMPILE:**
```
gcc -o mycp 05c_cp.c
```
**RUN:**
```
./mycp source.txt destination.txt
```
**SAMPLE INPUT:**
```
source.txt contents: "Hello, World!\n"
```
**EXPECTED OUTPUT:**
```
(no console output; destination.txt is created with the same content)
destination.txt contents: "Hello, World!\n"
```

**Program:**
```c
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
```

---

# 9a. C Program – rename (System Call)

**COMPILE:**
```
gcc -o myrename 09a_rename.c
```
**RUN:**
```
./myrename oldname.txt newname.txt
```
**SAMPLE INPUT:**
```
argv[1] = oldname.txt  (must exist)
argv[2] = newname.txt
```
**EXPECTED OUTPUT:**
```
File renamed successfully: oldname.txt -> newname.txt
```

**Program:**
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <old_name> <new_name>\n", argv[0]);
        return 1;
    }

    if (rename(argv[1], argv[2]) == 0) {
        printf("File renamed successfully: %s -> %s\n", argv[1], argv[2]);
    } else {
        perror("Error renaming file");
        return 1;
    }

    return 0;
}
```

---

# 9b. C Program – link (Hard Link System Call)

**COMPILE:**
```
gcc -o mylink 09b_link.c
```
**RUN:**
```
./mylink source.txt hardlink.txt
```
**SAMPLE INPUT:**
```
argv[1] = source.txt  (must exist)
argv[2] = hardlink.txt
```
**EXPECTED OUTPUT:**
```
Hard link created: hardlink.txt -> source.txt
```

**Program:**
```c
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <link_name>\n", argv[0]);
        return 1;
    }

    char *source_file = argv[1];
    char *link_name = argv[2];

    if (link(source_file, link_name) == -1) {
        perror("Error creating link");
        return 1;
    }

    printf("Hard link created: %s -> %s\n", link_name, source_file);
    return 0;
}
```

---

# 10. C Program – ls -l (Emulate Unix ls)

**COMPILE:**
```
gcc -o myls 10_ls_l.c
```
**RUN:**
```
./myls /home/user
./myls .
```
**SAMPLE INPUT:**
```
argv[1] = /tmp  (any valid directory)
```
**EXPECTED OUTPUT:**
```
(inode)    (filename)
    131073 .
    131074 ..
    131075 file1.txt
    131076 file2.txt
```

**Program:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char **argv) {
    DIR *dirop;
    struct dirent *dired;

    if (argc != 2) {
        printf("Invalid number of arguments. Usage: %s <directory_name>\n", argv[0]);
        exit(1);
    }

    if ((dirop = opendir(argv[1])) == NULL) {
        printf("Cannot open directory %s\n", argv[1]);
        exit(1);
    }

    while ((dired = readdir(dirop)) != NULL) {
        printf("%10lu %s\n", dired->d_ino, dired->d_name);
    }

    closedir(dirop);
    return 0;
}
```

---

# 11. C Program – Zombie Process

**COMPILE:**
```
gcc -o zombie 11_zombie_process.c
```
**RUN:**
```
./zombie
```
**SAMPLE INPUT:**
```
(no input required)
```
**EXPECTED OUTPUT:**
```
Child process (PID: 12346) is exiting...
Parent process (PID: 12345) is waiting...
(after 10 seconds)
Parent process (PID: 12345) exiting...
```
> NOTE: During the 10-second sleep, run `ps aux | grep Z` in another terminal to observe the zombie (Z) state.

**Program:**
```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } 
    else if (pid == 0) {
        printf("Child process (PID: %d) is exiting...\n", getpid());
        _exit(0);
    }
    else {
        printf("Parent process (PID: %d) is waiting...\n", getpid());
        sleep(10);
        printf("Parent process (PID: %d) exiting...\n", getpid());
    }

    return 0;
}
```

---

# 12. C Program – Message Queue (Create / Write / Read)

**COMPILE:**
```
gcc -o msgq 12_message_queue.c
```
**RUN:**
```
./msgq
```
**SAMPLE INPUT (interactive):**
```
Enter message type (positive integer): 1
Enter message text: HelloWorld
```
**EXPECTED OUTPUT:**
```
Message Queue Created with ID: 0
Enter message type (positive integer): 1
Enter message text: HelloWorld
Message Sent: HelloWorld
Message Received: HelloWorld
Message Queue Removed
```

**Program:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    int msqid;
    int len, ret;
    struct msgbuf msgsend = {0, "\0"}, msgrecv;
    
    msqid = msgget((key_t)1234, IPC_CREAT | 0666);
    if (msqid == -1) { perror("msgget:"); exit(1); }
    printf("Message Queue Created with ID: %d\n", msqid);

    printf("Enter message type (positive integer): ");
    if (scanf("%ld", &msgsend.mtype) != 1) { fprintf(stderr, "Invalid message type input.\n"); exit(1); }

    printf("Enter message text: ");
    if (scanf("%s", msgsend.mtext) != 1) { fprintf(stderr, "Invalid message text input.\n"); exit(1); }

    len = strlen(msgsend.mtext);
    ret = msgsnd(msqid, &msgsend, len, 0);
    if (ret == -1) { perror("msgsnd:"); exit(1); }
    printf("Message Sent: %s\n", msgsend.mtext);

    ret = msgrcv(msqid, &msgrecv, sizeof(msgrecv.mtext), msgsend.mtype, 0);
    if (ret == -1) { perror("msgrcv:"); exit(1); }
    printf("Message Received: %s\n", msgrecv.mtext);

    ret = msgctl(msqid, IPC_RMID, NULL);
    if (ret == -1) { perror("msgctl:"); exit(1); }
    printf("Message Queue Removed\n");

    return 0;
}
```

---

# 13. C Program – File Locking using Semaphores

**COMPILE:**
```
gcc -o semlok 13_file_locking_semaphore.c
```
**RUN:**
```
./semlok
```
**SAMPLE INPUT:**
```
(no input required)
```
**EXPECTED OUTPUT:**
```
File locked.
(waits 3 seconds)
File unlocked.
```

**Program:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

#define SEM_KEY 1234

void lock_file(int semid) {
    struct sembuf sb = {0, -1, 0};
    if (semop(semid, &sb, 1) == -1) { perror("semop - lock"); exit(1); }
    printf("File locked.\n");
}

void unlock_file(int semid) {
    struct sembuf sb = {0, 1, 0};
    if (semop(semid, &sb, 1) == -1) { perror("semop - unlock"); exit(1); }
    printf("File unlocked.\n");
}

int main() {
    int semid;
    union semun sem_union;

    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) { perror("semget"); exit(1); }

    sem_union.val = 1;
    if (semctl(semid, 0, SETVAL, sem_union) == -1) { perror("semctl"); exit(1); }

    lock_file(semid);
    sleep(3);
    unlock_file(semid);

    if (semctl(semid, 0, IPC_RMID, sem_union) == -1) { perror("semctl - IPC_RMID"); exit(1); }

    return 0;
}
```

---

# 14. C Program – Record Locking

**COMPILE:**
```
gcc -o reclock 14_record_locking.c
```
**RUN:**
```
./reclock
(Run a second instance in another terminal while first is sleeping to see "already locked" message)
```
**SAMPLE INPUT:**
```
(no input required; operates on "record_file.txt" created automatically)
```
**EXPECTED OUTPUT (first instance):**
```
Record locked successfully.
(waits 5 seconds)
Record unlocked successfully.
```
**EXPECTED OUTPUT (second instance run concurrently):**
```
Record is already locked by another process.
```

**Program:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define FILENAME "record_file.txt"

int main() {
    int fd;
    struct flock lock;

    fd = open(FILENAME, O_RDWR | O_CREAT, 0666);
    if (fd == -1) { perror("Failed to open file"); exit(1); }

    lock.l_type   = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start  = 0;
    lock.l_len    = 100;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        if (errno == EACCES || errno == EAGAIN)
            printf("Record is already locked by another process.\n");
        else
            perror("Failed to lock record");
        close(fd);
        exit(1);
    }

    printf("Record locked successfully.\n");
    sleep(5);

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) { perror("Failed to unlock record"); close(fd); exit(1); }

    printf("Record unlocked successfully.\n");
    close(fd);
    return 0;
}
```

---

# 15. C Program – Two Processes Communicating via PIPE

**COMPILE:**
```
gcc -o pipe_comm 15_pipe_communication.c
```
**RUN:**
```
./pipe_comm
```
**SAMPLE INPUT:**
```
(no input required; parent generates a random number 0-9)
```
**EXPECTED OUTPUT:**
```
Wrote 7          <- parent writes random number to pipe
Received 7       <- child reads from pipe
Wrote 28         <- child writes (7 * 4 = 28) back
Result is 28     <- parent reads and prints the result
```

**Program:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int p1[2], p2[2];
   
    if (pipe(p1) == -1) return 1;
    if (pipe(p2) == -1) return 2;

    int pid = fork();
    if (pid == -1) return 3;
   
    if (pid == 0) {
        close(p1[1]); close(p2[0]);
        int x;
        if (read(p1[0], &x, sizeof(int)) == -1) return 3;
        printf("Received %d\n", x);
        x *= 4;
        if (write(p2[1], &x, sizeof(int)) == -1) return 4;
        printf("Wrote %d\n", x);
        close(p1[0]); close(p2[1]);
    } else {
        close(p1[0]); close(p2[1]);
        srand(time(NULL));
        int y = rand() % 10;
        if (write(p1[1], &y, sizeof(y)) == -1) return 5;
        printf("Wrote %d\n", y);
        if (read(p2[0], &y, sizeof(y)) == -1) return 6;
        printf("Result is %d\n", y);
        close(p1[1]); close(p2[0]);
        wait(NULL);
    }
   
    return 0;
}
```
