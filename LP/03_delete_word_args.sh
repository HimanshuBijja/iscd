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

# ==============================================================
# HOW TO EXECUTE (STEP-BY-STEP):
# 1. Open terminal and navigate to the directory:
#       cd /path/to/LP
# 2. Grant execute permission using chmod:
#       chmod +x 03_delete_word_args.sh
# 3. Run the script with one or more filenames as arguments:
#       ./03_delete_word_args.sh 07a_file2.txt 07a_file3.txt
# 4. When prompted, enter the word to delete from the files:
#       Enter the word to be searched in files: banana
#
# SAMPLE INPUT:
#       Arguments passed: 07a_file2.txt 07a_file3.txt
#       Interactive prompt: banana
#
# SAMPLE OUTPUT:
#       Lines containing "banana" are removed from 07a_file2.txt and 07a_file3.txt in-place.
#       Check file contents with:
#       cat 07a_file2.txt
#       cat 07a_file3.txt
# ==============================================================
