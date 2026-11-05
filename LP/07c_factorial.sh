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

# ==============================================================
# HOW TO EXECUTE (STEP-BY-STEP):
# 1. Open terminal and navigate to the directory:
#       cd /path/to/LP
# 2. Grant execute permission using chmod:
#       chmod +x 07c_factorial.sh
# 3. Run the script:
#       sh 07c_factorial.sh
#       (or ./07c_factorial.sh)
#
# SAMPLE INPUT:
#       enter n
#       5
#
# SAMPLE OUTPUT:
#       The factorial of 5 is 120
# ==============================================================
