# Q4: Shell script that displays all files in the current directory
#     to which the user has read, write and execute permissions.
#
# HOW TO RUN:
#   chmod +x 04_rwx_files.sh
#   sh 04_rwx_files.sh
#   (or) ./04_rwx_files.sh
#
# SAMPLE INPUT:
#   (no input required; runs in the current directory)
#
# EXPECTED OUTPUT:
#   (lists filenames that have all three permissions for the current user)
#   07c_factorial.sh
#   04_rwx_files.sh
#   (etc.)

for i in *
do
if [ -r $i -a -w $i -a -x $i ]
then
echo $i
fi
done
