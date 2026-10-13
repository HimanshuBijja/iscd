# Q7b: Shell script to list all directory files (subdirectories) in a directory.
#
# HOW TO RUN:
#   chmod +x 07b_list_dirs.sh
#   sh 07b_list_dirs.sh
#   (or) ./07b_list_dirs.sh
#
# SAMPLE INPUT:
#   enter a directory name: /home/user
#
# EXPECTED OUTPUT:
#   The list of directory files in the directory /home/user are
#   drwxr-xr-x 2 user user 4096 Oct 13 07:00 Documents
#   drwxr-xr-x 2 user user 4096 Oct 13 07:00 Downloads
#   (lists only subdirectories, not regular files)

echo 'enter a directory name'
read dname
echo 'The list of directory files in the directory' $dname 'are'
cd $dname
ls -l | grep '^d'
