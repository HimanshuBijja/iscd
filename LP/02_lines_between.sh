echo "enter file name"
read f
echo 'enter starting position'
read st
echo 'enter ending position'
read end
echo 'The lines between' $st 'and' $end 'from' $f
if [ $st -lt $end ]
then
n1=`expr $st + 1`
n2=`expr $end - 1`
sed -n "$n1,$n2 p" $f
elif [ $st -gt $end ]
then
n3=`expr $st - 1`
n4=`expr $end + 1`
sed -n "$n4,$n3 p" $f
fi

# ==============================================================
# HOW TO EXECUTE (STEP-BY-STEP):
# 1. Open the terminal and navigate to the directory where the file is stored:
#       cd /path/to/LP
# 2. Grant execute permission using chmod:
#       chmod +x 02_lines_between.sh
# 3. Execute the script:
#       sh 02_lines_between.sh
#       (or ./02_lines_between.sh)
#
# SAMPLE INPUT:
#       enter file name
#       08a_file1.txt
#       enter starting position
#       2
#       enter ending position
#       6
#
# SAMPLE OUTPUT:
#       The lines between 2 and 6 from 08a_file1.txt
#       this
#       is
#       hello
# ==============================================================
