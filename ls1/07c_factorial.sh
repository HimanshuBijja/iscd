# Q7c: Shell script to find the factorial of a given number.
#
# HOW TO RUN:
#   chmod +x 07c_factorial.sh
#   sh 07c_factorial.sh
#   (or) ./07c_factorial.sh
#
# SAMPLE INPUT:
#   enter n: 5
#
# EXPECTED OUTPUT:
#   The factorial of 5 is 120

echo "enter n"
read n
i=1
fact=1
while [ $i -le $n ]
do
fact=`expr $fact \* $i`
i=`expr $i + 1`
done
echo 'The factorial of' $n 'is' $fact
