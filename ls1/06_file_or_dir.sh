# Q6: Shell script that receives file names as arguments, checks if each
#     argument is a file or directory, reports accordingly, and prints
#     the number of lines if it is a file.
#
# HOW TO RUN:
#   chmod +x 06_file_or_dir.sh
#   sh 06_file_or_dir.sh 08a_file1.txt 07a_file1.txt /home
#   (or) ./06_file_or_dir.sh 08a_file1.txt /home
#
# SAMPLE INPUT:
#   (arguments passed directly: 08a_file1.txt /home noexist)
#
# EXPECTED OUTPUT:
#   08a_file1.txt is a file
#   no.of lines in 08a_file1.txt :
#   10 08a_file1.txt
#   /home is a directory
#   noexist Does not exist

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
