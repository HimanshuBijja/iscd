echo 'enter a word to be deleted'
read word
echo 'enter file name'
read fname
echo 'lines in' $fname 'after deleting the word' $word ':'
sed "/$word/d" $fname

# ==============================================================
# HOW TO EXECUTE (STEP-BY-STEP):
# 1. Open terminal and navigate to the program directory:
#       cd /path/to/LP
# 2. Grant execute permission using chmod:
#       chmod +x 03_delete_word_simple.sh
# 3. Run the script:
#       sh 03_delete_word_simple.sh
#       (or ./03_delete_word_simple.sh)
#
# SAMPLE INPUT:
#       enter a word to be deleted
#       banana
#       enter file name
#       07a_file2.txt
#
# SAMPLE OUTPUT:
#       lines in 07a_file2.txt after deleting the word banana :
#       apple orange apple
# ==============================================================
