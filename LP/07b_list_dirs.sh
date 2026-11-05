echo 'enter a directory name'
read dname
echo 'The list of directory files in the directory' $dname 'are'
cd $dname
ls -l | grep '^d'

# ==============================================================
# HOW TO EXECUTE (STEP-BY-STEP):
# 1. Open terminal and navigate to the directory:
#       cd /path/to/LP
# 2. Grant execute permission using chmod:
#       chmod +x 07b_list_dirs.sh
# 3. Run the script:
#       sh 07b_list_dirs.sh
#       (or ./07b_list_dirs.sh)
#
# SAMPLE INPUT:
#       enter a directory name
#       ..
#
# SAMPLE OUTPUT:
#       The list of directory files in the directory .. are
#       drwxr-xr-x 1 user user 4096 Nov 6 00:20 CD
#       drwxr-xr-x 1 user user 4096 Nov 6 00:20 IS
#       drwxr-xr-x 1 user user 4096 Nov 6 00:20 LP
# ==============================================================
