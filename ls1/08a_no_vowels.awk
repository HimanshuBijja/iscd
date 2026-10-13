# Q8a: AWK script to count the number of lines in a file that do NOT contain vowels.
#
# HOW TO RUN:
#   awk -f 08a_no_vowels.awk 08a_file1.txt
#
# SAMPLE INPUT (08a_file1.txt):
#   hi        <- has vowel 'i'
#   how r u   <- has vowels 'o','u'
#   this      <- has vowel 'i'
#   is        <- has vowel 'i'
#   hello     <- has vowels 'e','o'
#   bajj      <- has vowel 'a'
#   dfdf      <- NO vowels
#   hhhh      <- NO vowels
#   rrrr      <- NO vowels
#   ttt       <- NO vowels
#
# EXPECTED OUTPUT:
#   4

!/[aeiouAEIOU]/ {
    count++  
}
END {
    print count
}
