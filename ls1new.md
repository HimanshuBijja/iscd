MID-1  LP LAB RECORD
===========================

# 2. Shell script to display lines between given line numbers

**HOW TO RUN:**
```
chmod +x 02_lines_between.sh
sh 02_lines_between.sh
```
**SAMPLE INPUT:**
```
enter file name: 08a_file1.txt
enter starting position: 2
enter ending position: 6
```
**EXPECTED OUTPUT:**
```
The lines between 2 and 6 from 08a_file1.txt
how r u
this
is
hello
```

**Program:**
```sh
echo "enter file name"
read f
echo 'enter starting position'
read st
echo 'enter ending position'
read end
echo 'The lines between' $st 'and' $end 'from' $f
if [ $st -lt $end ]
then
n1=`expr $st + 1`
n2=`expr $end - 1`
sed -n "$n1,$n2 p" $f
elif [ $st -gt $end ]
then
n3=`expr $st - 1`
n4=`expr $end + 1`
sed -n "$n4,$n3 p" $f
fi
```

---

# 3. Shell script to delete lines containing a specified word

## Version 1 – Interactive (single file)

**HOW TO RUN:**
```
chmod +x 03_delete_word_simple.sh
sh 03_delete_word_simple.sh
```
**SAMPLE INPUT:**
```
enter a word to be deleted: banana
enter file name: 07a_file2.txt
```
**EXPECTED OUTPUT:**
```
lines in 07a_file2.txt after deleting the word banana :
apple orange apple
```

**Program:**
```sh
echo 'enter a word to be deleted'
read word
echo 'enter file name'
read fname
echo 'lines in' $fname 'after deleting the word' $word ':'
sed "/$word/d" $fname
```

## Version 2 – Argument-based (multiple files, in-place)

**HOW TO RUN:**
```
chmod +x 03_delete_word_args.sh
sh 03_delete_word_args.sh 07a_file2.txt 07a_file3.txt
```
**SAMPLE INPUT (interactive prompt after running):**
```
Enter the word to be searched in files: banana
```
**EXPECTED OUTPUT:**
```
(Lines containing "banana" are deleted from both files in-place.
 Remaining content of 07a_file2.txt: apple orange apple
 Remaining content of 07a_file3.txt: orange orange)
```

**Program:**
```sh
if [ $# -eq 0 ]
then
echo "Please enter one or more filenames as argument"
exit
fi
echo "Enter the word to be searched in files"
read word
for file in $*
do
sed "/$word/d" $file | tee tmp
mv tmp $file
done
```

---

# 4. Shell script to list files with read, write and execute permissions

**HOW TO RUN:**
```
chmod +x 04_rwx_files.sh
sh 04_rwx_files.sh
```
**SAMPLE INPUT:**
```
(no input required; runs in the current directory)
```
**EXPECTED OUTPUT:**
```
07c_factorial.sh
04_rwx_files.sh
(lists filenames that have rwx permissions for the current user)
```

**Program:**
```sh
for i in *
do
if [ -r $i -a -w $i -a -x $i ]
then
echo $i
fi
done
```

---

# 6. Shell script to check if argument is file or directory

**HOW TO RUN:**
```
chmod +x 06_file_or_dir.sh
sh 06_file_or_dir.sh 08a_file1.txt /home noexist
```
**SAMPLE INPUT:**
```
(arguments passed directly: 08a_file1.txt /home noexist)
```
**EXPECTED OUTPUT:**
```
08a_file1.txt is a file
no.of lines in 08a_file1.txt :
10 08a_file1.txt
/home is a directory
noexist Does not exist
```

**Program:**
```sh
for fname in $*
do
if [ -f $fname ]
then
echo $fname 'is a file'
echo 'no.of lines in' $fname ':'
wc -l $fname
elif [ -d $fname ]
then
echo $fname 'is a directory'
else
echo 'Does not exist'
fi
done
```

---

# 7a. Shell script to count word occurrences across files

**HOW TO RUN:**
```
chmod +x 07a_word_count.sh
sh 07a_word_count.sh 07a_file1.txt 07a_file2.txt 07a_file3.txt
```
**SAMPLE INPUT:**
```
source file (07a_file1.txt): apple, banana, orange
target files: 07a_file2.txt, 07a_file3.txt
```
**EXPECTED OUTPUT:**
```
Word 'apple' found 4 times in the target files.
Word 'banana' found 3 times in the target files.
Word 'orange' found 4 times in the target files.
```

**Program (shell.sh):**
```sh
if [ $# -lt 2 ]; then
    echo "Usage: $0 source_file target_file1 [target_file2 ...]"
    exit 1
fi
source_file=$1
shift  
if [ ! -f "$source_file" ]; then
    echo "Source file '$source_file' does not exist."
    exit 1
fi
for word in $(tr -s '[:space:]' '\n' < "$source_file"); do
    total_count=0
for target_file in "$@"; do
        if [ ! -f "$target_file" ]; then
            echo "Target file '$target_file' does not exist."
            continue
        fi
         count=$(grep -oiw "$word" "$target_file" | wc -l)
        total_count=$((total_count + count))
done
if [ $total_count -gt 0 ]; then
        echo "Word '$word' found $total_count times in the target files."
    else
        echo "Word '$word' not found in any target files."
    fi
done
```

**file1.txt:**
```
apple
banana
orange
```

**file2.txt:**
```
apple orange apple
banana orange banana
```

**file3.txt:**
```
apple apple banana
orange orange
```

---

# 7b. Shell script to list all subdirectories in a directory

**HOW TO RUN:**
```
chmod +x 07b_list_dirs.sh
sh 07b_list_dirs.sh
```
**SAMPLE INPUT:**
```
enter a directory name: /home/user
```
**EXPECTED OUTPUT:**
```
The list of directory files in the directory /home/user are
drwxr-xr-x 2 user user 4096 Oct 13 07:00 Documents
drwxr-xr-x 2 user user 4096 Oct 13 07:00 Downloads
(lists only subdirectories, not regular files)
```

**Program:**
```sh
echo 'enter a directory name'
read dname
echo 'The list of directory files in the directory' $dname 'are'
cd $dname
ls -l | grep '^d'
```

---

# 7c. Shell script to find the factorial of a number

**HOW TO RUN:**
```
chmod +x 07c_factorial.sh
sh 07c_factorial.sh
```
**SAMPLE INPUT:**
```
enter n: 5
```
**EXPECTED OUTPUT:**
```
The factorial of 5 is 120
```

**Program:**
```sh
echo "enter n"
read n
i=1
fact=1
while [ $i -le $n ]
do
fact=`expr $fact \* $i`
i=`expr $i + 1`
done
echo 'The factorial of' $n 'is' $fact
```

---

# 8a. AWK script to count lines without vowels

**HOW TO RUN:**
```
awk -f 08a_no_vowels.awk 08a_file1.txt
```
**SAMPLE INPUT (08a_file1.txt):**
```
hi        <- has vowel 'i'
how r u   <- has vowels 'o','u'
this      <- has vowel 'i'
is        <- has vowel 'i'
hello     <- has vowels 'e','o'
bajj      <- has vowel 'a'
dfdf      <- NO vowels
hhhh      <- NO vowels
rrrr      <- NO vowels
ttt       <- NO vowels
```
**EXPECTED OUTPUT:**
```
4
```

**Program (word.awk):**
```awk
!/[aeiouAEIOU]/ {
    count++  
}
END {
    print count
}
```

---

# 8b. AWK script to count characters, words and lines

**HOW TO RUN:**
```
awk -f 08b_char_word_line_count.awk 08b_file2.txt
```
**SAMPLE INPUT (08b_file2.txt):**
```
 hi how r u
this is hw
```
**EXPECTED OUTPUT:**
```
Lines: 2
Words: 7
Characters: 22
```

**Program (word2.awk):**
```awk
{
char_count += length($0)
word_count += NF
line_count++
}
END {
    print "Lines:", line_count
    print "Words:", word_count
    print "Characters:", char_count
}
```
