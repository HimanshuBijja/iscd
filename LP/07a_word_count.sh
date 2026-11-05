if [ $# -lt 2 ]; then
    echo "Usage: $0 source_file target_file1 [target_file2 ...]"
    exit 1
fi
source_file=$1
shift  
if [ ! -f "$source_file" ]; then
    echo "Source file '$source_file' does not exist."
    exit 1
fi
for word in $(tr -s '[:space:]' '\n' < "$source_file"); do
    total_count=0
    for target_file in "$@"; do
        if [ ! -f "$target_file" ]; then
            echo "Target file '$target_file' does not exist."
            continue
        fi
        count=$(grep -oiw "$word" "$target_file" | wc -l)
        total_count=$((total_count + count))
    done
    if [ $total_count -gt 0 ]; then
        echo "Word '$word' found $total_count times in the target files."
    else
        echo "Word '$word' not found in any target files."
    fi
done

# ==============================================================
# HOW TO EXECUTE (STEP-BY-STEP):
# 1. Open terminal and navigate to the directory:
#       cd /path/to/LP
# 2. Grant execute permission using chmod:
#       chmod +x 07a_word_count.sh
# 3. Run the script with source file followed by target file(s):
#       ./07a_word_count.sh 07a_file1.txt 07a_file2.txt 07a_file3.txt
#
# SAMPLE INPUT:
#       source_file: 07a_file1.txt (contains: apple, banana, orange)
#       target_files: 07a_file2.txt, 07a_file3.txt
#
# SAMPLE OUTPUT:
#       Word 'apple' found 4 times in the target files.
#       Word 'banana' found 3 times in the target files.
#       Word 'orange' found 4 times in the target files.
# ==============================================================
