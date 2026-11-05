!/[aeiouAEIOU]/ {
    count++  
}
END {
    print count
}

# ==============================================================
# HOW TO EXECUTE (STEP-BY-STEP):
# 1. Open terminal and navigate to the directory:
#       cd /path/to/LP
# 2. Run the AWK script on the input file:
#       awk -f 08a_no_vowels.awk 08a_file1.txt
#
# SAMPLE INPUT FILE (08a_file1.txt):
#       hi
#       how r u
#       this 
#       is 
#       hello
#       bajj
#       dfdf
#       hhhh
#       rrrr
#       ttt
#
# SAMPLE OUTPUT:
#       4
# (Lines without any vowels: dfdf, hhhh, rrrr, ttt -> Total: 4)
# ==============================================================
