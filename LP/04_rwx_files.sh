for i in *
do
if [ -r $i -a -w $i -a -x $i ]
then
echo $i
fi
done

# ==============================================================
# HOW TO EXECUTE (STEP-BY-STEP):
# 1. Open terminal and navigate to the directory:
#       cd /path/to/LP
# 2. Grant execute permission using chmod:
#       chmod +x 04_rwx_files.sh
# 3. Create or assign read, write, and execute permissions to a test file:
#       touch test_rwx.sh
#       chmod 777 test_rwx.sh
# 4. Run the script:
#       sh 04_rwx_files.sh
#       (or ./04_rwx_files.sh)
#
# SAMPLE OUTPUT:
#       04_rwx_files.sh
#       test_rwx.sh
# (Lists all files in the current directory having read, write, and execute permissions)
# ==============================================================
