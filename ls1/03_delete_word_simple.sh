# Q3: Shell script that deletes all lines containing a specified word (interactive version).
#
# HOW TO RUN:
#   chmod +x 03_delete_word_simple.sh
#   sh 03_delete_word_simple.sh
#   (or) ./03_delete_word_simple.sh
#
# SAMPLE INPUT:
#   enter a word to be deleted: banana
#   enter file name: 07a_file2.txt
#
# EXPECTED OUTPUT:
#   lines in 07a_file2.txt after deleting the word banana :
#   apple orange apple

echo 'enter a word to be deleted'
read word
echo 'enter file name'
read fname
echo 'lines in' $fname 'after deleting the word' $word ':'
sed "/$word/d" $fname
