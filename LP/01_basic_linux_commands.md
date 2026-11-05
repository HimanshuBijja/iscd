# Basic Linux Commands Guide

This document provides a reference for essential Linux commands covering file handling, process utilities, disk utilities, filters, and text processing utilities (`grep`, `sed`, `awk`).

---

## 1. File Handling Commands

| Command | Description | Syntax / Usage |
|---|---|---|
| `cat` | Concatenate and display file contents | `cat filename`<br>`cat file1 file2 > merged.txt` |
| `touch` | Create an empty file or update modification timestamp | `touch filename` |
| `rm` | Remove files or directories (`-r` recursive, `-f` force) | `rm filename`<br>`rm -r directory_name` |
| `mv` | Move or rename files and directories | `mv oldname newname`<br>`mv filename /path/to/dest/` |
| `vi` / `vim` | Open text file in vi/vim editor | `vi filename` |
| `chmod` | Change file/directory permissions (octal or symbolic) | `chmod 755 filename`<br>`chmod +x script.sh` |
| `cp` | Copy files or directories (`-r` for directories) | `cp source destination`<br>`cp -r src_dir dest_dir` |
| `mkdir` | Create a new directory (`-p` for parents) | `mkdir dir_name`<br>`mkdir -p dir1/dir2` |
| `cd` | Change current working directory | `cd directory_name`<br>`cd ..` (parent directory) |
| `ls` | List files and directories (`-l` long format, `-a` all) | `ls -l`<br>`ls -la` |
| `find` | Search for files and directories in hierarchy | `find /path -name filename`<br>`find . -type f -name "*.sh"` |
| `chown` | Change file owner and optionally group | `chown user filename`<br>`chown user:group filename` |
| `chgrp` | Change file group ownership | `chgrp group_name filename` |

---

## 2. Process Utilities

| Command | Description | Syntax / Usage |
|---|---|---|
| `ps` | Report a snapshot of the current processes | `ps aux`<br>`ps -ef` |
| `who` | Show who is currently logged on | `who` |
| `who am i` | Show current user login session details | `who am i` |
| `top` | Display real-time dynamic view of active processes | `top` (press `q` to quit) |

---

## 3. Disk Utilities

| Command | Description | Syntax / Usage |
|---|---|---|
| `df` | Report file system disk space usage (`-h` human readable) | `df -h` |
| `du` | Estimate file or directory space usage (`-s` summary, `-h` human readable) | `du -sh directory_name` |

---

## 4. Filters

| Command | Description | Syntax / Usage |
|---|---|---|
| `head` | Output the first part (default 10 lines) of files | `head filename`<br>`head -n 5 filename` |
| `tail` | Output the last part (default 10 lines) of files | `tail filename`<br>`tail -n 5 filename` |
| `cut` | Remove sections from each line of files | `cut -d':' -f1 /etc/passwd` |
| `paste` | Merge lines of files side-by-side | `paste file1 file2` |
| `sort` | Sort lines of text files | `sort filename`<br>`sort -r filename` (reverse) |
| `tr` | Translate or delete characters from standard input | `tr 'a-z' 'A-Z' < filename` |
| `wc` | Print newline, word, and byte counts for files | `wc filename`<br>`wc -l filename` (lines only) |
| `cmp` | Compare two files byte by byte | `cmp file1 file2` |

---

## 5. Pattern Searching (`grep`)

- Search for pattern in a file:
  ```bash
  grep 'pattern' filename
  ```
- Case-insensitive search:
  ```bash
  grep -i 'pattern' filename
  ```
- Count matching lines:
  ```bash
  grep -c 'pattern' filename
  ```
- Display line numbers with matches:
  ```bash
  grep -n 'pattern' filename
  ```

---

## 6. Stream Editor (`sed`)

- Replace first occurrence of old with new on each line:
  ```bash
  sed 's/old/new/' filename
  ```
- Replace all occurrences globally:
  ```bash
  sed 's/old/new/g' filename
  ```
- Delete lines matching a pattern:
  ```bash
  sed '/pattern/d' filename
  ```
- Print specific lines (e.g., lines 2 to 5):
  ```bash
  sed -n '2,5p' filename
  ```

---

## 7. Pattern Scanning and Processing (`awk`)

- Print the first field of each line:
  ```bash
  awk '{print $1}' filename
  ```
- Print lines matching a condition:
  ```bash
  awk '$1 > 50 {print $1, $2}' filename
  ```
- Custom field delimiter (e.g., comma):
  ```bash
  awk -F',' '{print $1, $2}' filename
  ```
- Count total lines and print at END:
  ```bash
  awk 'END {print NR}' filename
  ```

---

## HOW TO EXECUTE (STEP-BY-STEP):
1. Open a Linux terminal (or WSL / Git Bash).
2. Create test files using `touch` or `cat > test.txt`.
3. Try any of the commands listed above.

## SAMPLE RUN & OUTPUT:
```bash
$ touch sample.txt
$ echo -e "apple\nbanana\norange" > sample.txt
$ cat sample.txt
apple
banana
orange

$ wc sample.txt
 3  3 20 sample.txt

$ grep "banana" sample.txt
banana

$ sed 's/banana/grape/' sample.txt
apple
grape
orange
```
