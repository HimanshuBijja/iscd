{
    char_count += length($0)
    word_count += NF
    line_count++
}
END {
    print "Lines:", line_count
    print "Words:", word_count
    print "Characters:", char_count
}

# ==============================================================
# HOW TO EXECUTE (STEP-BY-STEP):
# 1. Open terminal and navigate to the directory:
#       cd /path/to/LP
# 2. Run the AWK script on the input file:
#       awk -f 08b_char_word_line_count.awk 08b_file2.txt
#
# SAMPLE INPUT FILE (08b_file2.txt):
#        hi how r u
#       this is hw
#
# SAMPLE OUTPUT:
#       Lines: 2
#       Words: 7
#       Characters: 21
# ==============================================================
