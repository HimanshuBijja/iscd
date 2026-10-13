# Q8b: AWK script to find the number of characters, words and lines in a file.
#
# HOW TO RUN:
#   awk -f 08b_char_word_line_count.awk 08b_file2.txt
#
# SAMPLE INPUT (08b_file2.txt):
#    hi how r u
#   this is hw
#
# EXPECTED OUTPUT:
#   Lines: 2
#   Words: 7
#   Characters: 22

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
