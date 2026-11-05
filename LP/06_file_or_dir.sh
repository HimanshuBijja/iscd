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

# ==============================================================
# HOW TO EXECUTE (STEP-BY-STEP):
# 1. Open terminal and navigate to the directory:
#       cd /path/to/LP
# 2. Grant execute permission using chmod:
#       chmod +x 06_file_or_dir.sh
# 3. Run the script with multiple names (files, directories, non-existent):
#       ./06_file_or_dir.sh 08a_file1.txt . non_existent.txt
#
# SAMPLE OUTPUT:
#       08a_file1.txt is a file
#       no.of lines in 08a_file1.txt :
#       10 08a_file1.txt
#       . is a directory
#       Does not exist
# ==============================================================
