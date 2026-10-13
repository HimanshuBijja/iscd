# Q2: Shell script that accepts a file name, starting and ending line numbers
#     and displays all the lines between the given line numbers.
#
# HOW TO RUN:
#   chmod +x 02_lines_between.sh
#   sh 02_lines_between.sh
#   (or) ./02_lines_between.sh
#
# SAMPLE INPUT:
#   enter file name: 08a_file1.txt
#   enter starting position: 2
#   enter ending position: 6
#
# EXPECTED OUTPUT:
#   The lines between 2 and 6 from 08a_file1.txt
#   how r u
#   this
#   is
#   hello

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
