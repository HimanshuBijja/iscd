# Q3: Shell script that deletes all lines containing a specified word
#     across one or more files supplied as arguments (argument version).
#
# HOW TO RUN:
#   chmod +x 03_delete_word_args.sh
#   sh 03_delete_word_args.sh 07a_file2.txt 07a_file3.txt
#   (or) ./03_delete_word_args.sh 07a_file2.txt 07a_file3.txt
#
# SAMPLE INPUT (interactive prompt after running):
#   Enter the word to be searched in files: banana
#
# EXPECTED OUTPUT:
#   (Lines containing "banana" are deleted from both files in-place.
#    Remaining content of 07a_file2.txt: apple orange apple
#    Remaining content of 07a_file3.txt: orange orange)

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
