# Linux Programming (LP) Lab Programs

This repository contains individual source files for all Linux Programming lab exercises, including basic Linux commands, shell scripts, AWK scripts, and C programs using POSIX system calls and IPC mechanisms.

Each file contains the source code, followed by complete step-by-step execution instructions and sample input/output in comments at the end of each file.

---

## File Directory

| Program / File | Type | Description | Execution Command |
|---|---|---|---|
| `01_basic_linux_commands.md` | Guide | Reference guide for File Handling, Process Utilities, Disk Utilities, Filters, Grep, Sed, and Awk | Markdown / Terminal |
| `02_lines_between.sh` | Shell Script | Displays all lines between starting and ending line numbers in a given file | `sh 02_lines_between.sh` |
| `03_delete_word_simple.sh` | Shell Script | Deletes lines containing a specified word from a single file interactively | `sh 03_delete_word_simple.sh` |
| `03_delete_word_args.sh` | Shell Script | Deletes lines containing a word across multiple files passed as command-line arguments (in-place) | `./03_delete_word_args.sh f1.txt f2.txt` |
| `04_rwx_files.sh` | Shell Script | Lists all files in current directory with read, write, and execute permissions | `sh 04_rwx_files.sh` |
| `05a_wc.c` | C Program | Emulates `wc` (counts lines, words, characters) | `gcc 05a_wc.c -o 05a_wc && ./05a_wc <file>` |
| `05b_cat.c` | C Program | Emulates `cat` (concatenates/displays file contents) | `gcc 05b_cat.c -o 05b_cat && ./05b_cat <file>` |
| `05c_cp.c` | C Program | Emulates `cp` using low-level I/O system calls (`open`, `read`, `write`, `close`) | `gcc 05c_cp.c -o 05c_cp && ./05c_cp <src> <dest>` |
| `06_file_or_dir.sh` | Shell Script | Takes arguments, checks if file or directory, and prints line count for files | `sh 06_file_or_dir.sh <file1> <dir1> ...` |
| `07a_word_count.sh` | Shell Script | Counts occurrences of words from source file in target files | `sh 07a_word_count.sh 07a_file1.txt 07a_file2.txt 07a_file3.txt` |
| `07b_list_dirs.sh` | Shell Script | Lists only directory files in a given directory path | `sh 07b_list_dirs.sh` |
| `07c_factorial.sh` | Shell Script | Computes factorial of a number using while loop and `expr` | `sh 07c_factorial.sh` |
| `08a_no_vowels.awk` | AWK Script | Counts number of lines in a file that contain no vowels | `awk -f 08a_no_vowels.awk 08a_file1.txt` |
| `08b_char_word_line_count.awk` | AWK Script | Counts characters, words, and lines in a file | `awk -f 08b_char_word_line_count.awk 08b_file2.txt` |
| `09a_rename.c` | C Program | Emulates file rename using `rename()` system call | `gcc 09a_rename.c -o 09a_rename && ./09a_rename <old> <new>` |
| `09b_link.c` | C Program | Creates hard link using `link()` system call | `gcc 09b_link.c -o 09b_link && ./09b_link <src> <link>` |
| `10_ls_l.c` | C Program | Emulates directory listing (`ls -l` inode + name) using `opendir()`, `readdir()` | `gcc 10_ls_l.c -o 10_ls_l && ./10_ls_l <dir>` |
| `11_zombie_process.c` | C Program | Creates a zombie process using `fork()` and delayed `wait()` | `gcc 11_zombie_process.c -o 11_zombie_process && ./11_zombie_process` |
| `12_message_queue.c` | C Program | Demonstrates IPC message queue: `msgget()`, `msgsnd()`, `msgrcv()`, `msgctl()` | `gcc 12_message_queue.c -o 12_message_queue && ./12_message_queue` |
| `13_file_locking_semaphore.c` | C Program | Illustrates file locking using System V semaphores (`semget`, `semop`, `semctl`) | `gcc 13_file_locking_semaphore.c -o 13_file_locking_semaphore && ./13_file_locking_semaphore` |
| `14_record_locking.c` | C Program | Implements record locking using `fcntl()` (`F_SETLK`, `F_WRLCK`, `F_UNLCK`) | `gcc 14_record_locking.c -o 14_record_locking && ./14_record_locking` |
| `15_pipe_communication.c` | C Program | Demonstrates bidirectional IPC between parent and child processes using pipes | `gcc 15_pipe_communication.c -o 15_pipe_communication && ./15_pipe_communication` |

---

## Sample Data Files

- `07a_file1.txt`, `07a_file2.txt`, `07a_file3.txt`: Sample text files for word occurrence testing (`07a_word_count.sh`).
- `08a_file1.txt`: Sample text file with vowel and non-vowel lines (`08a_no_vowels.awk`).
- `08b_file2.txt`: Sample text file for word, line, and character count (`08b_char_word_line_count.awk`).
